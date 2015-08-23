#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TDataSet.h
///@brief 声明 交易数据集合，用于存储各种交易数据集合。
///@author 张弛
///@date 20120124
/////////////////////////////////////////////////////////////////////////
#include "../generate/Gen.h"

#ifndef TDATASET_H_
#define TDATASET_H_

namespace ZYSystem {
	class TDataSet
	{
	public:
		///@brief 合约信息
		std::vector<SInstrument> instruments;

		///@brief 客户账号
		std::vector<SInvestor> investors;

		///@brief 客户实时资金
		std::vector<SRealFund> realFunds;

		///@brief 客户持仓
		std::vector<SRealPosition> realPositions;

		///@brief 客户成交
		std::vector<STrade> trades;

		///@brief 客户报单
		std::vector<SOrderReq> orderReqs;

		///@brief 客户保证金率
		std::vector<SMarginRate> marginRates;

		///@brief 客户手续费率
		std::vector<SFeeRate> feeRates;

		///@brief 交易信号
		std::vector<SSingnal> singnals;

		///@brief 资金变化信息
		std::vector<SMoneyChange> moneyChanges;
		
		TDataSet();
		~TDataSet();
	};
}

#endif //TDATASET_H_