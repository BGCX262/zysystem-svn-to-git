#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TCore.h
///@brief 声明 交易核心,实现各种交易业务，同时也包括调用策略处理组件
///@author 张弛
///@date 20130512
/////////////////////////////////////////////////////////////////////////
#include "../dataRoute/TEndPoint.h"
#include "TDataService.h"

#ifndef TCORE_H_
#define TCORE_H_


namespace ZYSystem {
	class TCore:public CTEndPoint
	{
	private:
		///@brief 数据服务
		TDataService tDataService;

	public:
		///@brief 资金变化请求
		///@param moneyChange_in 资金变化
		///@return 0为通过,其他值为错误原因
		TID changeFund(SMoneyChange* moneyChange_in);

		///@brief 新行情
		///@param marketData_in 行情变化
		///@return 0为通过,其他值为错误原因
		TID newMarketData(SMarketData* marketData_in);

		///@brief 新成交
		///@param trade_in 成交回报
		///@return 0为通过,其他值为错误原因
		TID newTrade(STrade* trade_in);

		///@brief 新报单响应
		///@param orderRsp_in 报单响应
		///@return 0为通过,其他值为错误原因
		TID newOrderRespone(SOrderRsp* orderRsp_in);

		///@brief 新手续费率
		///@param feeRate_in 手续费
		///@return 0为通过,其他值为错误原因
		TID newFeeRate(SFeeRate* feeRate_in);

		///@brief 新保证金率
		///@param marginRate_in 冻结金额
		///@return 0为通过,其他值为错误原因
		TID newMarginRate(SMarginRate* marginRate_in);

		///@brief 创建账户，在程序开始正常处理以前被调用
		///@param money_in 冻结金额
		///@return 0为通过,其他值为错误原因
		TID createInvestor(SInvestor* investor_in);

		///@brief 构造
		///@remark
		TCore();
		~TCore();
	};
}

#endif //TCORE_H_