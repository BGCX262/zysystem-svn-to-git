/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TCore.cpp
///@brief ʵ�� ���׺���,ʵ�ָ��ֽ���ҵ��ͬʱҲ�������ò��Դ������
///@author �ų�
///@date 20130512
/////////////////////////////////////////////////////////////////////////
#include "TCore.h"

#ifndef TCORE_CPP_
#define TCORE_CPP_

using namespace ZYSystem;

TCore::TCore(){
	tDataService = TDataService();
}


TCore::~TCore(){


}

TID TCore::changeFund(SMoneyChange* moneyChange_in){
	TID error_code = SUCCESS;
	
	//��¼�������ˮ
	error_code = tDataService.moneyChangeAdd(moneyChange_in);
	CHECK_SUCCESS(error_code);
	
	//���ҳ����Ͷ��������Ӧ��ʵʱ�ʽ��¼
	SRealFund* realFund = NULL;
	error_code = tDataService.realFundSelectByInvestorID(realFund,moneyChange_in->InvestorID);
	
	if (moneyChange_in->FundDirection == FD_In) {
		//���û���ҵ�����˵��û�и�Ͷ���ߵ��ʽ��¼��TDataSet�У�Ӧ�ò�0ֵ��¼
		if (error_code == TCORE_DS_RealFundSelectByInvestorIDFatal) {
			realFund = new SRealFund();

			std::strcpy(realFund->InvestorID,moneyChange_in->InvestorID);
			realFund->Equity = 0;
			realFund->AvailableFund = 0;
			realFund->FrozenMargin = 0;
			realFund->FrozenFee = 0;
			realFund->Fee = 0;
			realFund->CloseProfit = 0;
			realFund->HoldProfit = 0;
			realFund->Margin = 0;
			realFund->FundIn = 0;
			realFund->FundOut = 0;

			tDataService.realFundAdd(realFund);

		} else {
			CHECK_SUCCESS(error_code);
		}
		
		//������ӿͻ�Ȩ��
		realFund->FundIn = realFund->FundIn + moneyChange_in->Change;
		realFund->Equity = realFund->Equity + moneyChange_in->Change;
		realFund->AvailableFund = realFund->AvailableFund + moneyChange_in->Change;

	} else {
		//�ڳ����ʱ�����ȴ����ѯ�����ĳ�����
		CHECK_SUCCESS(error_code);

		//���������£����ܳ���
		if (realFund->AvailableFund < moneyChange_in->Change) {
			return TCORE_DS_NotEnoughAvailableForOut;
		}	

		//������ٿͻ�Ȩ��
		realFund->FundOut = realFund->FundOut + moneyChange_in->Change;
		realFund->Equity = realFund->Equity - moneyChange_in->Change;
		realFund->AvailableFund = realFund->AvailableFund - moneyChange_in->Change;
	}

	return error_code;
}

TID TCore::newMarketData(SMarketData* marketData_in){
	TID error_code = SUCCESS;

	//����ֲֵĵ�ӯ����ֹӯֹ��

	//�����źŴ洢

	//ת��Ϊ����

	//�����洢
			
	//�����ʽ�

	//������������

	return error_code;
}

TID TCore::newTrade(STrade* trade_in){
	TID error_code = SUCCESS;

	//�ɽ����
	error_code = tDataService.tradeAdd(trade_in);
	CHECK_SUCCESS(error_code);

	//�ұ��������±�����״̬
	SOrderReq* orderReq = NULL;
	error_code = tDataService.orderReqSelectByLocalOrderID(orderReq,trade_in->LocalOrderID);
	if (error_code != TCORE_DS_OrderReqSelectByLocalOrderIDFatal) {
		if (trade_in->DoneVolume == orderReq->VolumeRemain ) {
			orderReq->OrderStatus = OST_AllTraded;
		} else {
			orderReq->OrderStatus = OST_PartTradedQueueing;
		}

		orderReq->VolumeTraded = orderReq->VolumeTraded + trade_in->DoneVolume;
		orderReq->VolumeRemain = orderReq->VolumeRemain - trade_in->DoneVolume;
	}

	SInstrument* instrument = NULL;
	error_code = tDataService.instrumentSelectByInstrumentID(instrument,trade_in->InstrumentID);
	CHECK_SUCCESS(error_code);

	SRealFund* realFund = NULL;
	error_code = tDataService.realFundSelectByInvestorID(realFund,trade_in->InvestorID);
	CHECK_SUCCESS(error_code);

	SMarginRate* marginRate = NULL;
	error_code = tDataService.marginRateSelectByInvestorIDInstrumentID(marginRate,trade_in->InvestorID,trade_in->InstrumentID);
	CHECK_SUCCESS(error_code);	

	SFeeRate* feeRate = NULL;
	error_code = tDataService.feeRateSelectByInvestorIDInstrumentID(feeRate,trade_in->InvestorID,trade_in->InstrumentID);
	CHECK_SUCCESS(error_code);	

	SRealPosition* realPosition = NULL;

	//���ݿ�ƽ��� ���� ��Ҫ�����Ĳ�λ���ʽ� 
	if (trade_in->OffsetFlag == OF_Open) {
		//����
		
		//���ݳɽ��ĳɽ������ͱ����ļ۸����Ϣ����⿪�����Ѻͱ�֤�𶳽�
		realFund->FrozenMargin = realFund->FrozenMargin 
							   - orderReq->Price * trade_in->DoneVolume * instrument->Multiple * marginRate->MarginRatioByVolume
				               - trade_in->DoneVolume * marginRate->MarginRatioByMoney;

		realFund->FrozenFee = realFund->FrozenFee 
			                - orderReq->Price * trade_in->DoneVolume * instrument->Multiple * feeRate->OpenFeeRatioByMoney
							- trade_in->DoneVolume * feeRate->OpenFeeRatioByVolume;

		//���ݳɽ����ĳɽ������ͳɽ��ۼ��������Ѻͱ�֤��
		realFund->Margin = realFund->Margin 
					     + trade_in->DonePrice * trade_in->DoneVolume * instrument->Multiple * marginRate->MarginRatioByVolume
				         + trade_in->DoneVolume * marginRate->MarginRatioByMoney;

		realFund->Fee = realFund->Fee 
			          + trade_in->DonePrice * trade_in->DoneVolume * instrument->Multiple * feeRate->OpenFeeRatioByMoney
					  + trade_in->DoneVolume * feeRate->OpenFeeRatioByVolume;

		//�ֲ�����
		error_code = tDataService.realPositionSelectByInvestorIDInstrumentIDDirection(realPosition,
																					  trade_in->InvestorID,
																					  trade_in->InstrumentID,
																					  trade_in->Direction);
		if (error_code == TCORE_DS_RealPositionSelectByInvestorIDInstrumentIDDirectionFatal) {
			realPosition = new SRealPosition();

			std::strcpy(realPosition->InvestorID,trade_in->InvestorID);
			std::strcpy(realPosition->InstrumentID,trade_in->InstrumentID);
			realPosition->Direction = trade_in->Direction;
			realPosition->OpenPriceAvg = trade_in->DonePrice;
			realPosition->RealVolume = trade_in->DoneVolume;
			realPosition->FrozenVolume = 0;
			realPosition->HoldMargin = trade_in->DonePrice * trade_in->DoneVolume * instrument->Multiple * marginRate->MarginRatioByVolume
									 + trade_in->DoneVolume * marginRate->MarginRatioByMoney;

		} else {
			CHECK_SUCCESS(error_code);
			realPosition->RealVolume = realPosition->RealVolume + trade_in->DoneVolume;
			realPosition->HoldMargin = realPosition->HoldMargin
									 + trade_in->DonePrice * trade_in->DoneVolume * instrument->Multiple * marginRate->MarginRatioByVolume
									 + trade_in->DoneVolume * marginRate->MarginRatioByMoney;
			realPosition->OpenPriceAvg = realPosition->HoldMargin / realPosition->RealVolume;
		} 
	} else {
		//ƽ��

		//���ݳɽ��ĳɽ������ͱ����ļ۸����Ϣ����⿪������
		realFund->FrozenFee = realFund->FrozenFee 
							- orderReq->Price * trade_in->DoneVolume * instrument->Multiple * feeRate->OpenFeeRatioByMoney
							- trade_in->DoneVolume * feeRate->OpenFeeRatioByVolume;

		//���ݳɽ����ĳɽ������ͳɽ��ۼ��������Ѻͱ�֤��
		realFund->Margin = realFund->Margin 
					     - realPosition->OpenPriceAvg * trade_in->DoneVolume * instrument->Multiple * marginRate->MarginRatioByVolume
				         - trade_in->DoneVolume * marginRate->MarginRatioByMoney;

		realFund->Fee = realFund->Fee 
			          + trade_in->DonePrice * trade_in->DoneVolume * instrument->Multiple * feeRate->OpenFeeRatioByMoney
					  + trade_in->DoneVolume * feeRate->OpenFeeRatioByVolume;

		realFund->CloseProfit = (trade_in->DonePrice - realPosition->OpenPriceAvg)
							  * trade_in->DoneVolume * instrument->Multiple;
		//�ֲּ���
		realPosition->FrozenVolume = realPosition->FrozenVolume - trade_in->DoneVolume;
		realPosition->RealVolume = realPosition->RealVolume - trade_in->DoneVolume;

	}
	
	//���ᱣ֤�������Ѽ��٣���֤�����ӣ����ü��٣�Ȩ�����������
	realFund->AvailableFund = realFund->LastEquity + realFund->FundIn - realFund->FundOut
							- realFund->FrozenMargin - realFund->FrozenFee
							- realFund->Margin - realFund->Fee
							+ realFund ->CloseProfit + realFund ->HoldProfit;

	realFund->Equity = realFund->LastEquity + realFund->FundIn - realFund->FundOut
				     - realFund->Fee
					 + realFund ->CloseProfit + realFund ->HoldProfit;
	
	return error_code;
}

TID TCore::newOrderRespone(SOrderRsp* orderRsp_in){
	TID error_code = SUCCESS;
	
	//�޸ı���״̬
	SOrderReq* orderReq = new SOrderReq();
	error_code = tDataService.orderReqDeleteByLocalOrderID(orderRsp_in->LocalOrderID);

	orderReq->LocalOrderID = orderRsp_in->LocalOrderID;
	std::strcpy(orderReq->TradingDay,orderRsp_in->TradingDay);
	std::strcpy(orderReq->InvestorID,orderRsp_in->InvestorID);
	std::strcpy(orderReq->InstrumentID,orderRsp_in->InstrumentID);
	std::strcpy(orderReq->TradingDay,orderRsp_in->TradingDay);
	orderReq->OffsetFlag = orderRsp_in->OffsetFlag;
	orderReq->Direction = orderRsp_in->Direction;
	orderReq->VolumeTraded = orderRsp_in->VolumeTraded;
	orderReq->VolumeRemain = orderRsp_in->VolumeRemain;
	orderReq->Price = orderRsp_in->Price;
	std::strcpy(orderReq->OrderTime,orderRsp_in->OrderTime);
	std::strcpy(orderReq->LocalTime,orderRsp_in->LocalTime);
	orderReq->OrderStatus = orderRsp_in->OrderStatus;
	orderReq->OrderSubmitStatus = orderRsp_in->OrderSubmitStatus;

	tDataService.orderReqChangeAdd(orderReq);
	//�ʽ�仯���ʽ�ⶳ���ڳɽ��������

	return error_code;
}

TID TCore::newFeeRate(SFeeRate* feeRate_in){
	TID error_code = SUCCESS;
	//���û�и�Ͷ���ߵ��ض���Լ�������ʣ�������룬�������
	error_code = tDataService.feeRateDeleteByInvestorIDInstrumentID(feeRate_in->InvestorID,feeRate_in->InstrumentID);
	CHECK_SUCCESS(error_code);

	error_code = tDataService.feeRateAdd(feeRate_in);
	CHECK_SUCCESS(error_code);

	return error_code;
}

TID TCore::newMarginRate(SMarginRate* marginRate_in){
	TID error_code = SUCCESS;
	
	//���û�и�Ͷ���ߵ��ض���Լ�������ʣ�������룬�������
	error_code = tDataService.marginRateDeleteByInvestorIDInstrumentID(marginRate_in->InvestorID,marginRate_in->InstrumentID);
	CHECK_SUCCESS(error_code);

	error_code = tDataService.marginRateAdd(marginRate_in);
	CHECK_SUCCESS(error_code);

	return error_code;
}

TID TCore::createInvestor(SInvestor* investor_in){
	TID error_code = SUCCESS;
	//�����µĿͻ�
	error_code = tDataService.investorAdd(investor_in);
	CHECK_SUCCESS(error_code);

	//Ϊ�ͻ����²����µ��ʽ��¼
	SRealFund* realFund =new SRealFund();

	std::strcpy(realFund->InvestorID,investor_in->InvestorID);
	realFund->Equity = 0;
	realFund->AvailableFund = 0;
	realFund->FrozenMargin = 0;
	realFund->FrozenFee = 0;
	realFund->Fee = 0;
	realFund->CloseProfit = 0;
	realFund->HoldProfit = 0;
	realFund->Margin = 0;
	realFund->FundIn = 0;
	realFund->FundOut = 0;

	tDataService.realFundAdd(realFund);

	return error_code;
}
#endif //TCORE_CPP_