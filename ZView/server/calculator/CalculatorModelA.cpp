/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CCalModelA.cpp
///@brief 实现计算模型A
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "CalculatorModelA.h"

#ifndef CCALMODEL_CPP_
#define CCALMODEL_CPP_

using namespace ZYSystem;

CCalModelA::CCalModelA(SModelConfigA config_in){
	//设置配置
	config = SModelConfigA();
	std::memcpy(&config,&config_in,sizeof SModelConfigA);
	calculateCycle = boost::posix_time::seconds(config.CalculateCycle);

	//KDJ指标计算器
	indexKDJ = new CIndexKDJ(config.DataPath);

	//MACD指标计算器
	indexMACD = new CIndexMACD(config.DataPath);

	timeTranslator = CTimeTranslator::getInstance();
	lastCycleTime = boost::posix_time::ptime();

	//初始化afterCycle
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
	//如果lastCycleTime不是datetime,则说明是第一次进入循环
	if (lastCycleTime.is_not_a_date_time()) {
		//先同步成行情时间
		lastCycleTime = thisTime + calculateCycle;
		//再校准成循环起点
		lastCycleTime = lastCycleTime 
					- boost::posix_time::milliseconds(
						 (lastCycleTime.time_of_day()
						- boost::posix_time::time_duration(9,0,0)).total_milliseconds()
						% calculateCycle.total_milliseconds()
					);
	}
	
	//只有比较行情中的时间比本地记录的最后一次计算时间大一个周期，那么才能计算
	if (thisTime >= lastCycleTime) {
		//更新时间
		lastCycleTime = lastCycleTime + calculateCycle;

		//计算指标
		tmp_kdj = indexKDJ->calculate(&afterCycle);
		tmp_macd = indexMACD ->calculate(&afterCycle);

		//计算指标，发送交易指令
		getOrder(marketdata_in);

		//一分钟线
		maketDataCycle->addRecord(&afterCycle);

		//最后清空积累行情数据
		afterCycle.LastPrice = 0;
		afterCycle.HighestPrice = 0;
		afterCycle.LowestPrice = 9999999;
		afterCycle.OpenPrice = 0;
		std::strcpy(afterCycle.UpdateTime,"");
		lastCycleTime = boost::posix_time::ptime();
	}  

	//如果开盘价是0，则代表一个新循环开始，那么不但要更新开盘价，还要更新计算周期的时间
	if (afterCycle.OpenPrice == 0) {
		afterCycle.OpenPrice = marketdata_in->LastPrice;
		std::strcpy(afterCycle.TradingDay,marketdata_in->TradingDay);
		afterCycle.UpdateMillisec = marketdata_in->UpdateMillisec;
		std::strcpy(afterCycle.UpdateTime,marketdata_in->UpdateTime);
		std::strcpy(afterCycle.InstrumentID,marketdata_in->InstrumentID);
	}

	//更新最新、最高、最低、开盘
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
	//kdj和macd的交易日都没有设置的话,就不用计算计算指令了
	if ((std::strlen(last_kdj.TradingDay) == 0) || (std::strlen(last_macd.TradingDay) == 0)) {
		std::memcpy(&last_kdj,&tmp_kdj,sizeof SKDJ);
		std::memcpy(&last_macd,&tmp_macd,sizeof SMACD);
		return ;
	}

	SSingnal singnal = SSingnal();

	//初始化一些必要的参数
	std::strcpy(singnal.TradingDay,tmp_kdj.TradingDay);
	std::strcpy(singnal.InstrumentID,tmp_kdj.InstrumentID);
	std::strcpy(singnal.InvestorID,config.InvestorID);
	std::strcpy(singnal.TriggerTime,in->UpdateTime);

	//这个交易规则其实是一个关于kdj和macd的斜率运算
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

	//*开仓指令
	//当kdj的k，d和macd中的Idx_diff，Idx_dea斜率的符号一致的时候，就应该可以开仓
	if ((d_value_k < config.MIN_k) && (d_value_d < config.MIN_d) 
		&& (d_value_diff < config.MIN_diff) && (d_value_dea < config.MIN_dea)) {
		//卖出开仓
		singnal.OffsetFlag = OF_Open;
		singnal.Direction = D_Sell;
		direction = D_Sell;

	}else if ((d_value_k > config.MAX_k) && (d_value_d > config.MAX_d) 
		&& (d_value_diff > config.MAX_diff) && (d_value_dea > config.MAX_dea)) {
		singnal.OffsetFlag = OF_Open;
		singnal.Direction = D_Buy;
		direction = D_Buy;

	} else {
		//*平仓指令
		//当kdj的k，d和macd中的Idx_diff，Idx_dea斜率的符号不一致的时候，就应该平仓
		return;
		/*
		singnal.OffsetFlag = OF_Close;
		if (direction == D_Buy) {
			singnal.Direction = D_Sell;
		} else {
			singnal.Direction = D_Buy;
		}*/		
	}
	
	//更新最后的kdj和macd
	std::memcpy(&last_kdj,&tmp_kdj,sizeof SKDJ);
	std::memcpy(&last_macd,&tmp_macd,sizeof SMACD);

	singnal.SingnalReason = SR_ModelA;
	//setlocalTime(singnal.LocalTime);

	//如果有资产管理器,那么就把报单指令发出去
	//sendTP(&singnal);
}

#endif //CCALMODEL_CPP_
