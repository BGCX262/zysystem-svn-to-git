/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TDataSet.cpp
///@brief 实现 交易数据集合，用于存储各种交易数据集合。
///@author 张弛
///@date 20120124
/////////////////////////////////////////////////////////////////////////
#include "TDataSet.h"

#ifndef TDATASET_CPP_
#define TDATASET_CPP_

using namespace ZYSystem;

TDataSet::TDataSet(){
	
	instruments = std::vector<SInstrument>();

	investors = std::vector<SInvestor>();

	realFunds = std::vector<SRealFund>();

	realPositions = std::vector<SRealPosition>();

	trades = std::vector<STrade>();

	orderReqs = std::vector<SOrderReq>();

	marginRates = std::vector<SMarginRate>();

	feeRates = std::vector<SFeeRate>();

	singnals = std::vector<SSingnal>();

	moneyChanges = std::vector<SMoneyChange>();
}

TDataSet::~TDataSet(){
}
#endif //CREALPOSITION_CPP_