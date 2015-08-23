#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TDataService.h
///@brief 声明 交易数据服务，用于提供TDataSet的各种查询、插入、更新方法，支持交易业务。
///@author 张弛
///@date 20120124
/////////////////////////////////////////////////////////////////////////
#include "../generate/Gen.h"
#include "TDataSet.h"

#ifndef TDATASERVICE_H_
#define TDATASERVICE_H_

namespace ZYSystem {
	class TDataService
	{
	private:
		TDataSet dataSet;

	public:
		///@brief 增加 合约
		///@param instrument_in 资金变化
		///@return 0为通过,其他值为错误原因
		TID instrumentAdd(SInstrument* instrument_in);

		///@brief 基于instrumentID查找 合约代码
		///@param instrument_in 合约
		///@param instrumentID 合约代码
		///@return 0为通过,其他值为错误原因
		TID instrumentSelectByInstrumentID(SInstrument* instrument_in,TInstrumentID instrumentID);

		///@brief 增加 投资者
		///@param investor_in 投资者
		///@return 0为通过,其他值为错误原因
		TID investorAdd(SInvestor* investor_in);
		
		///@brief 增加 实时资金
		///@param realFund_in 实时资金
		///@return 0为通过,其他值为错误原因
		TID realFundAdd(SRealFund* realFund_in);

		///@brief 通过investorID查找客户资金SRealFund
		///@param investorID 投资者代码
		///@return 0为通过,其他值为错误原因
		TID realFundSelectByInvestorID(SRealFund* realFund_out,TInvestorID investorID);

		///@brief 增加 持仓
		///@param realPosition_in 持仓
		///@return 0为通过,其他值为错误原因
		TID realPositionAdd(SRealPosition* realPosition_in);

		///@brief 基于investorID，instrumentID查找 持仓
		///@param realPositio_out 持仓
		///@param investorID 投资者代码
		///@param instrumentID 合约代码
		///@param direction 持仓方向
		///@return 0为通过,其他值为错误原因
		TID realPositionSelectByInvestorIDInstrumentIDDirection(SRealPosition* realPosition_out,
																TInvestorID investorID,
																TInstrumentID instrumentID,
																TDirection direction);

		///@brief 基于investorID,instrumentID删除 持仓
		///@param investorID 投资者代码
		///@param instrumentID 合约代码
		///@param direction 持仓方向
		///@return 0为通过,其他值为错误原因
		TID realPositionDeleteByInvestorIDInstrumentIDDirection(TInvestorID investorID,
																TInstrumentID instrumentID,
																TDirection direction);

		///@brief 增加 成交
		///@param trade_in 成交
		///@return 0为通过,其他值为错误原因
		TID tradeAdd(STrade* trade_in);

		///@brief 增加 报单请求
		///@param orderReq_in 报单请求
		///@return 0为通过,其他值为错误原因
		TID orderReqChangeAdd(SOrderReq* orderReq_in);

		///@brief 通过localOrderID查找orderReq
		///@param localOrderID 投资者代码
		///@return 0为通过,其他值为错误原因
		TID orderReqSelectByLocalOrderID(SOrderReq* orderReq_out,TLocalOrderID localOrderID);

		///@brief 通过localOrderID 删除 orderReq
		///@param localOrderID 投资者代码
		///@return 0为通过,其他值为错误原因
		TID orderReqDeleteByLocalOrderID(TLocalOrderID localOrderID);

		///@brief 增加 保证金率
		///@param marginRate_in 保证金率
		///@return 0为通过,其他值为错误原因
		TID marginRateAdd(SMarginRate* marginRate_in);

		///@brief 基于investorID，instrumentID查找 合约保证金率
		///@param marginRate_out 保证金率
		///@param investorID 投资者代码
		///@param instrumentID 合约代码
		///@return 0为通过,其他值为错误原因
		TID marginRateSelectByInvestorIDInstrumentID(SMarginRate* marginRate_out,TInvestorID investorID,TInstrumentID instrumentID);

		///@brief 基于investorID,instrumentID删除 合约保证金率
		///@param investorID 投资者代码
		///@param instrumentID 合约代码
		///@return 0为通过,其他值为错误原因
		TID marginRateDeleteByInvestorIDInstrumentID(TInvestorID investorID,TInstrumentID instrumentID);

		///@brief 增加 手续费率
		///@param feeRate_in 手续费率
		///@return 0为通过,其他值为错误原因
		TID feeRateAdd(SFeeRate* feeRate_in);

		///@brief 基于investorID，instrumentID查找 客户手续费率
		///@param feeRate_in 手续费率
		///@param investorID 投资者代码
		///@param instrumentID 合约代码
		///@return 0为通过,其他值为错误原因
		TID feeRateSelectByInvestorIDInstrumentID(SFeeRate* feeRate_out,TInvestorID investorID,TInstrumentID instrumentID);

		///@brief 基于investorID,instrumentID删除 客户手续费率
		///@param investorID 投资者代码
		///@param instrumentID 合约代码
		///@return 0为通过,其他值为错误原因
		TID feeRateDeleteByInvestorIDInstrumentID(TInvestorID investorID,TInstrumentID instrumentID);

		///@brief 增加 交易信号
		///@param singnal_in 交易信号
		///@return 0为通过,其他值为错误原因
		TID singnalAdd(SSingnal* singnal_in);

		///@brief 增加 资金变化
		///@param moneyChange_in 资金变化
		///@return 0为通过,其他值为错误原因
		TID moneyChangeAdd(SMoneyChange* moneyChange_in);

		TDataService();
		~TDataService();
	};

}

#endif //TDATASERVICE_H_