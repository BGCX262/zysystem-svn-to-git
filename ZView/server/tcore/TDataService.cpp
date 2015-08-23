/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CCapital.cpp
///@brief 实现 交易数据服务，用于提供TDataSet的各种查询、插入、更新方法，支持交易业务。
///@author 张弛
///@date 20120124
/////////////////////////////////////////////////////////////////////////
#include "TDataService.h"

#ifndef TDATASERVICE_CPP_
#define TDATASERVICE_CPP_

using namespace ZYSystem;

TDataService::TDataService(){
	dataSet = TDataSet();
}

TDataService::~TDataService(){

}

TID TDataService::instrumentAdd(SInstrument* instrument_in){
	dataSet.instruments.push_back(*instrument_in);
	return SUCCESS;
}

TID TDataService::instrumentSelectByInstrumentID(SInstrument* instrument_out,
	                                             TInstrumentID instrumentID){
	for (TCount i = 0;i < dataSet.instruments.size(); i++ ) {
		if (std::strcmp(dataSet.instruments.at(i).InstrumentID,instrumentID) == 0) {
			instrument_out = &(dataSet.instruments.at(i));
			return SUCCESS;
		}
	}

	return TCORE_DS_InstrumentSelectByInstrumentIDFatal;
}

TID TDataService::investorAdd(SInvestor* investor_in){
	dataSet.investors.push_back(*investor_in);
	return SUCCESS;
}
		
TID TDataService::realFundAdd(SRealFund* realFund_in){
	dataSet.realFunds.push_back(*realFund_in);
	return SUCCESS;
}

TID TDataService::realFundSelectByInvestorID(SRealFund* realFund_out,TInvestorID investorID){
	for (TCount i = 0;i < dataSet.realFunds.size(); i++ ) {
		if (std::strcmp(dataSet.realFunds.at(i).InvestorID,investorID) == 0) {
			realFund_out = &(dataSet.realFunds.at(i));
			return SUCCESS;
		}
	}

	return TCORE_DS_RealFundSelectByInvestorIDFatal;
}

TID TDataService::realPositionAdd(SRealPosition* realPosition_in){
	dataSet.realPositions.push_back(*realPosition_in);
	return SUCCESS;
}

TID TDataService::realPositionSelectByInvestorIDInstrumentIDDirection(SRealPosition* realPosition_out,
																	  TInvestorID investorID,
															          TInstrumentID instrumentID,
															          TDirection direction){
	for (TCount i = 0;i < dataSet.realPositions.size(); i++ ) {

		if ((std::strcmp(dataSet.realPositions.at(i).InstrumentID,instrumentID) == 0)
			&& (std::strcmp(dataSet.realPositions.at(i).InvestorID,investorID) == 0)
			&& (dataSet.realPositions.at(i).Direction == direction)) {

			realPosition_out = &(dataSet.realPositions.at(i));
			return SUCCESS;
		}
	}

	return TCORE_DS_RealPositionSelectByInvestorIDInstrumentIDDirectionFatal;
}

TID TDataService::realPositionDeleteByInvestorIDInstrumentIDDirection(TInvestorID investorID,
																	  TInstrumentID instrumentID,
															          TDirection direction){
	for (TCount i = 0;i < dataSet.realPositions.size(); i++ ) {

		if ((std::strcmp(dataSet.realPositions.at(i).InvestorID,investorID) == 0)
			&& (std::strcmp(dataSet.realPositions.at(i).InstrumentID,instrumentID) == 0)
			&& (dataSet.realPositions.at(i).Direction == direction)) {

			std::vector<SRealPosition>::iterator it = dataSet.realPositions.begin() + i;
			dataSet.realPositions.erase(it);
;			return SUCCESS;
		}
	}

	return SUCCESS;
}

TID TDataService::tradeAdd(STrade* trade_in){
	dataSet.trades.push_back(*trade_in);
	return SUCCESS;
}

TID TDataService::orderReqChangeAdd(SOrderReq* orderReq_in){
	dataSet.orderReqs.push_back(*orderReq_in);
	return SUCCESS;
}

TID TDataService::orderReqSelectByLocalOrderID(SOrderReq* orderReq_out,TLocalOrderID localOrderID){
	for (TCount i = 0;i < dataSet.orderReqs.size(); i++ ) {
		if (dataSet.orderReqs.at(i).LocalOrderID == localOrderID) {
			orderReq_out = &(dataSet.orderReqs.at(i));
			return SUCCESS;
		}
	}

	return TCORE_DS_OrderReqSelectByLocalOrderIDFatal;
}

TID TDataService::orderReqDeleteByLocalOrderID(TLocalOrderID localOrderID){
	for (TCount i = 0;i < dataSet.orderReqs.size(); i++ ) {
		if (dataSet.orderReqs.at(i).LocalOrderID == localOrderID) {
			std::vector<SOrderReq>::iterator it = dataSet.orderReqs.begin() + i;
			dataSet.orderReqs.erase(it);
;			return SUCCESS;
		}
	}

	return SUCCESS;
}

TID TDataService::marginRateAdd(SMarginRate* marginRate_in){
	dataSet.marginRates.push_back(*marginRate_in);
	return SUCCESS;
}

TID TDataService::marginRateSelectByInvestorIDInstrumentID(SMarginRate* marginRate_out,
	                                                       TInvestorID investorID,
														   TInstrumentID instrumentID){
	for (TCount i = 0;i < dataSet.marginRates.size(); i++ ) {

		if ((std::strcmp(dataSet.marginRates.at(i).InstrumentID,instrumentID) == 0)
			&& (std::strcmp(dataSet.marginRates.at(i).InvestorID,investorID) == 0)) {

			marginRate_out = &(dataSet.marginRates.at(i));
			return SUCCESS;

		}
	}

	return TCORE_DS_MarginRateSelectByInvestorIDInstrumentIDFatal;
}

TID TDataService::marginRateDeleteByInvestorIDInstrumentID(TInvestorID investorID,
	                                                       TInstrumentID instrumentID) {
	for (TCount i = 0;i < dataSet.marginRates.size(); i++ ) {

		if ((std::strcmp(dataSet.marginRates.at(i).InvestorID,investorID) == 0)
			&& (std::strcmp(dataSet.marginRates.at(i).InstrumentID,instrumentID) == 0)) {

			std::vector<SMarginRate>::iterator it = dataSet.marginRates.begin() + i;
			dataSet.marginRates.erase(it);
;			return SUCCESS;
		}
	}

	return SUCCESS;
}

TID TDataService::feeRateAdd(SFeeRate* feeRate_in){
	dataSet.feeRates.push_back(*feeRate_in);
	return SUCCESS;
}

TID TDataService::feeRateSelectByInvestorIDInstrumentID(SFeeRate* feeRate_out,
														 TInvestorID investorID,
														 TInstrumentID instrumentID) {
	for (TCount i = 0;i < dataSet.feeRates.size(); i++ ) {

		if ((std::strcmp(dataSet.feeRates.at(i).InstrumentID,instrumentID) == 0)
			&& (std::strcmp(dataSet.feeRates.at(i).InvestorID,investorID) == 0)) {

			feeRate_out = &(dataSet.feeRates.at(i));
			return SUCCESS;

		}
	}

	return TCORE_DS_FeeRateSelectByInvestorIDInstrumentIDFatal;

}

TID TDataService::feeRateDeleteByInvestorIDInstrumentID(TInvestorID investorID,
										                 TInstrumentID instrumentID) {
	for (TCount i = 0;i < dataSet.feeRates.size(); i++ ) {

		if ((std::strcmp(dataSet.feeRates.at(i).InvestorID,investorID) == 0)
			&& (std::strcmp(dataSet.feeRates.at(i).InstrumentID,instrumentID) == 0)) {

			std::vector<SFeeRate>::iterator it = dataSet.feeRates.begin() + i;
			dataSet.feeRates.erase(it);
;			return SUCCESS;
		}
	}

	return SUCCESS;
}

TID TDataService::singnalAdd(SSingnal* singnal_in){
	dataSet.singnals.push_back(*singnal_in);
	return SUCCESS;
}

TID TDataService::moneyChangeAdd(SMoneyChange* moneyChange_in){
	dataSet.moneyChanges.push_back(*moneyChange_in);
	return SUCCESS;
}

#endif //TDATASERVICE_CPP_