/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CCalModelA.cpp
///@brief ʵ�ּ���ģ��A
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "CalculatorModelA.h"

#ifndef CCALMODEL_CPP_
#define CCALMODEL_CPP_

using namespace ZYSystem;

CCalModelA::CCalModelA(SModelConfigA config_in){
	//��������
	config = SModelConfigA();
	std::memcpy(&config,&config_in,sizeof SModelConfigA);
	calculateCycle = boost::posix_time::seconds(config.CalculateCycle);

	//KDJָ�������
	indexKDJ = new CIndexKDJ(config.DataPath);

	//MACDָ�������
	indexMACD = new CIndexMACD(config.DataPath);

	timeTranslator = CTimeTranslator::getInstance();
	lastCycleTime = boost::posix_time::ptime();

	//��ʼ��afterCycle
	afterCycle.UpdateMillisec = 0;
	std::strcpy(afterCycle.UpdateTime,"");
	std::strcpy(afterCycle.ExchangeID,"");
	afterCycle.LastPrice = 0;
	afterCycle.HighestPrice = 0;
	afterCycle.LowestPrice = LOWESTPRICE_INIT;
	afterCycle.OpenPrice = 0;

	maketDataCycle =new CMarketDataWriter(config.DataPath,"oneMinute");

	SKDJ last_kdj = SKDJ();
	SMACD last_macd = SMACD();
}

CCalModelA::~CCalModelA(void)
{
	delete indexKDJ;
	delete indexMACD;
}

TID CCalModelA::recivieMarketData(SSingnal* singnal_in,SMarketData* marketdata_in){
	singnal_in = new SSingnal();

	boost::posix_time::ptime thisTime = timeTranslator->mdkToPtime(marketdata_in);
	//���lastCycleTime����datetime,��˵���ǵ�һ�ν���ѭ��
	if (lastCycleTime.is_not_a_date_time()) {
		//��ͬ��������ʱ��
		lastCycleTime = thisTime + calculateCycle;
		//��У׼��ѭ�����
		lastCycleTime = lastCycleTime 
					- boost::posix_time::milliseconds(
						 (lastCycleTime.time_of_day()
						- boost::posix_time::time_duration(9,0,0)).total_milliseconds()
						% calculateCycle.total_milliseconds()
					);
	}
	
	//ֻ�бȽ������е�ʱ��ȱ��ؼ�¼�����һ�μ���ʱ���һ�����ڣ���ô���ܼ���
	if (thisTime >= lastCycleTime) {
		//����ʱ��
		lastCycleTime = lastCycleTime + calculateCycle;

		//����ָ��
		tmp_kdj = indexKDJ->calculate(&afterCycle);
		tmp_macd = indexMACD ->calculate(&afterCycle);

		//����ָ�꣬���ͽ���ָ��
		getOrder(marketdata_in);

		//һ������
		maketDataCycle->addRecord(&afterCycle);

		//�����ջ�����������
		afterCycle.LastPrice = 0;
		afterCycle.HighestPrice = 0;
		afterCycle.LowestPrice = 9999999;
		afterCycle.OpenPrice = 0;
		std::strcpy(afterCycle.UpdateTime,"");
		lastCycleTime = boost::posix_time::ptime();
	}  

	//������̼���0�������һ����ѭ����ʼ����ô����Ҫ���¿��̼ۣ���Ҫ���¼������ڵ�ʱ��
	if (afterCycle.OpenPrice == 0) {
		afterCycle.OpenPrice = marketdata_in->LastPrice;
		std::strcpy(afterCycle.TradingDay,marketdata_in->TradingDay);
		afterCycle.UpdateMillisec = marketdata_in->UpdateMillisec;
		std::strcpy(afterCycle.UpdateTime,marketdata_in->UpdateTime);
		std::strcpy(afterCycle.InstrumentID,marketdata_in->InstrumentID);
	}

	//�������¡���ߡ���͡�����
	afterCycle.LastPrice = marketdata_in->LastPrice;
	afterCycle.ClosePrice = marketdata_in->LastPrice; 
	if (marketdata_in->LastPrice > afterCycle.HighestPrice) {
		afterCycle.HighestPrice = marketdata_in->LastPrice;
	}

	if (marketdata_in->LastPrice < afterCycle.LowestPrice) {
		afterCycle.LowestPrice = marketdata_in->LastPrice;
	}

	return SUCCESS;
}

void CCalModelA::getOrder(SMarketData* in){
	//kdj��macd�Ľ����ն�û�����õĻ�,�Ͳ��ü������ָ����
	if ((std::strlen(last_kdj.TradingDay) == 0) || (std::strlen(last_macd.TradingDay) == 0)) {
		std::memcpy(&last_kdj,&tmp_kdj,sizeof SKDJ);
		std::memcpy(&last_macd,&tmp_macd,sizeof SMACD);
		return ;
	}

	SSingnal singnal = SSingnal();

	//��ʼ��һЩ��Ҫ�Ĳ���
	std::strcpy(singnal.TradingDay,tmp_kdj.TradingDay);
	std::strcpy(singnal.InstrumentID,tmp_kdj.InstrumentID);
	std::strcpy(singnal.InvestorID,config.InvestorID);
	std::strcpy(singnal.TriggerTime,in->UpdateTime);

	//������׹�����ʵ��һ������kdj��macd��б������
	TIndexValue d_value_k = 0;
	TIndexValue d_value_d = 0;
	TIndexValue d_value_diff = 0;
	TIndexValue d_value_dea = 0;
	
	d_value_k = tmp_kdj.Idx_k - last_kdj.Idx_k;
	d_value_d = tmp_kdj.Idx_d - last_kdj.Idx_d;
	d_value_diff = tmp_macd.Idx_diff - last_macd.Idx_diff;
	d_value_dea = tmp_macd.Idx_dea - last_macd.Idx_dea;
	singnal.Volume = 1;
	singnal.Price = in->LastPrice;

	//*����ָ��
	//��kdj��k��d��macd�е�Idx_diff��Idx_deaб�ʵķ���һ�µ�ʱ�򣬾�Ӧ�ÿ��Կ���
	if ((d_value_k < config.MIN_k) && (d_value_d < config.MIN_d) 
		&& (d_value_diff < config.MIN_diff) && (d_value_dea < config.MIN_dea)) {
		//��������
		singnal.OffsetFlag = OF_Open;
		singnal.Direction = D_Sell;
		direction = D_Sell;

	}else if ((d_value_k > config.MAX_k) && (d_value_d > config.MAX_d) 
		&& (d_value_diff > config.MAX_diff) && (d_value_dea > config.MAX_dea)) {
		singnal.OffsetFlag = OF_Open;
		singnal.Direction = D_Buy;
		direction = D_Buy;

	} else {
		//*ƽ��ָ��
		//��kdj��k��d��macd�е�Idx_diff��Idx_deaб�ʵķ��Ų�һ�µ�ʱ�򣬾�Ӧ��ƽ��
		return;
		/*
		singnal.OffsetFlag = OF_Close;
		if (direction == D_Buy) {
			singnal.Direction = D_Sell;
		} else {
			singnal.Direction = D_Buy;
		}*/		
	}
	
	//��������kdj��macd
	std::memcpy(&last_kdj,&tmp_kdj,sizeof SKDJ);
	std::memcpy(&last_macd,&tmp_macd,sizeof SMACD);

	singnal.SingnalReason = SR_ModelA;
	//setlocalTime(singnal.LocalTime);

	//������ʲ�������,��ô�Ͱѱ���ָ���ȥ
	//sendTP(&singnal);
}

#endif //CCALMODEL_CPP_
