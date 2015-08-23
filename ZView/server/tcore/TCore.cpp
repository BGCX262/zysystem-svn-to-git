/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TCore.cpp
///@brief 实现 交易核心,实现各种交易业务，同时也包括调用策略处理组件
///@author 张弛
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
	
	//记录出入金流水
	error_code = tDataService.moneyChangeAdd(moneyChange_in);
	CHECK_SUCCESS(error_code);
	
	//查找出入金投资者所对应的实时资金记录
	SRealFund* realFund = NULL;
	error_code = tDataService.realFundSelectByInvestorID(realFund,moneyChange_in->InvestorID);
	
	if (moneyChange_in->FundDirection == FD_In) {
		//如果没有找到，则说明没有该投资者的资金记录在TDataSet中，应该补0值记录
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
		
		//入金增加客户权益
		realFund->FundIn = realFund->FundIn + moneyChange_in->Change;
		realFund->Equity = realFund->Equity + moneyChange_in->Change;
		realFund->AvailableFund = realFund->AvailableFund + moneyChange_in->Change;

	} else {
		//在出金的时候首先处理查询产生的出错码
		CHECK_SUCCESS(error_code);

		//余额不足的情况下，不能出金
		if (realFund->AvailableFund < moneyChange_in->Change) {
			return TCORE_DS_NotEnoughAvailableForOut;
		}	

		//出金减少客户权益
		realFund->FundOut = realFund->FundOut + moneyChange_in->Change;
		realFund->Equity = realFund->Equity - moneyChange_in->Change;
		realFund->AvailableFund = realFund->AvailableFund - moneyChange_in->Change;
	}

	return error_code;
}

TID TCore::newMarketData(SMarketData* marketData_in){
	TID error_code = SUCCESS;

	//计算持仓的的盈亏，止盈止损

	//交易信号存储

	//转换为报单

	//报单存储
			
	//冻结资金

	//发出报单请求

	return error_code;
}

TID TCore::newTrade(STrade* trade_in){
	TID error_code = SUCCESS;

	//成交落地
	error_code = tDataService.tradeAdd(trade_in);
	CHECK_SUCCESS(error_code);

	//找报单表，更新报单的状态
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

	//根据开平标记 计算 需要调整的仓位和资金 
	if (trade_in->OffsetFlag == OF_Open) {
		//开仓
		
		//根据成交的成交数量和报单的价格等信息计算解开手续费和保证金冻结
		realFund->FrozenMargin = realFund->FrozenMargin 
							   - orderReq->Price * trade_in->DoneVolume * instrument->Multiple * marginRate->MarginRatioByVolume
				               - trade_in->DoneVolume * marginRate->MarginRatioByMoney;

		realFund->FrozenFee = realFund->FrozenFee 
			                - orderReq->Price * trade_in->DoneVolume * instrument->Multiple * feeRate->OpenFeeRatioByMoney
							- trade_in->DoneVolume * feeRate->OpenFeeRatioByVolume;

		//根据成交单的成交数量和成交价计算手续费和保证金
		realFund->Margin = realFund->Margin 
					     + trade_in->DonePrice * trade_in->DoneVolume * instrument->Multiple * marginRate->MarginRatioByVolume
				         + trade_in->DoneVolume * marginRate->MarginRatioByMoney;

		realFund->Fee = realFund->Fee 
			          + trade_in->DonePrice * trade_in->DoneVolume * instrument->Multiple * feeRate->OpenFeeRatioByMoney
					  + trade_in->DoneVolume * feeRate->OpenFeeRatioByVolume;

		//持仓增加
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
		//平仓

		//根据成交的成交数量和报单的价格等信息计算解开手续费
		realFund->FrozenFee = realFund->FrozenFee 
							- orderReq->Price * trade_in->DoneVolume * instrument->Multiple * feeRate->OpenFeeRatioByMoney
							- trade_in->DoneVolume * feeRate->OpenFeeRatioByVolume;

		//根据成交单的成交数量和成交价计算手续费和保证金
		realFund->Margin = realFund->Margin 
					     - realPosition->OpenPriceAvg * trade_in->DoneVolume * instrument->Multiple * marginRate->MarginRatioByVolume
				         - trade_in->DoneVolume * marginRate->MarginRatioByMoney;

		realFund->Fee = realFund->Fee 
			          + trade_in->DonePrice * trade_in->DoneVolume * instrument->Multiple * feeRate->OpenFeeRatioByMoney
					  + trade_in->DoneVolume * feeRate->OpenFeeRatioByVolume;

		realFund->CloseProfit = (trade_in->DonePrice - realPosition->OpenPriceAvg)
							  * trade_in->DoneVolume * instrument->Multiple;
		//持仓减少
		realPosition->FrozenVolume = realPosition->FrozenVolume - trade_in->DoneVolume;
		realPosition->RealVolume = realPosition->RealVolume - trade_in->DoneVolume;

	}
	
	//冻结保证金，手续费减少，保证金增加，可用减少，权益减少手续费
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
	
	//修改报单状态
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
	//资金变化：资金解冻等在成交处理完成

	return error_code;
}

TID TCore::newFeeRate(SFeeRate* feeRate_in){
	TID error_code = SUCCESS;
	//如果没有该投资者的特定合约手续费率，则更插入，否则更新
	error_code = tDataService.feeRateDeleteByInvestorIDInstrumentID(feeRate_in->InvestorID,feeRate_in->InstrumentID);
	CHECK_SUCCESS(error_code);

	error_code = tDataService.feeRateAdd(feeRate_in);
	CHECK_SUCCESS(error_code);

	return error_code;
}

TID TCore::newMarginRate(SMarginRate* marginRate_in){
	TID error_code = SUCCESS;
	
	//如果没有该投资者的特定合约手续费率，则更插入，否则更新
	error_code = tDataService.marginRateDeleteByInvestorIDInstrumentID(marginRate_in->InvestorID,marginRate_in->InstrumentID);
	CHECK_SUCCESS(error_code);

	error_code = tDataService.marginRateAdd(marginRate_in);
	CHECK_SUCCESS(error_code);

	return error_code;
}

TID TCore::createInvestor(SInvestor* investor_in){
	TID error_code = SUCCESS;
	//增加新的客户
	error_code = tDataService.investorAdd(investor_in);
	CHECK_SUCCESS(error_code);

	//为客户更新插入新的资金记录
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