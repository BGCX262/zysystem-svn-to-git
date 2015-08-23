
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file Structs.h
///@brief 定义公用的结构体,基于程序生成，不要手工修改
///@author xslt模型代码转换工具
///@date 2013-06-21T07:28:26.879Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "TypeDefine.h"

#ifndef STRUCTS_H_
#define STRUCTS_H_

namespace ZYSystem {


///@struct 日志信息描述
#define TPID_Log 1
struct SLog {
	
	///@brief 错误编号,每个日志的唯一编号	
	TID LogID;
		
	///@brief 日志级别,描述日志应该在什么状况下输出	
	TLogLevel LogLevel;
		
	///@brief 日志代码,日志的代码，用于define和返回码	
	TCode LogCode;
		
	///@brief 日志信息,日志的具体描述信息	
	TMemo LogMsg;
		
};	

///@struct 行情提供者配置信息
#define TPID_MarketDataProvider 2
struct SMarketDataProvider {
	
	///@brief 服务器编号,行情服务器的识别代码	
	TConnectionID ConnectionID;
		
	///@brief 远程行情服务地址,远程行情服务器的地址	
	TURL Td_url;
		
	///@brief 远程交易服务地址,远程交易服务器的地址	
	TURL Md_url;
		
	///@brief 行情类型,行情服务器接收的行情类型	
	TMarketDataType ConnectionType;
		
	///@brief 投资者代码,投资者实体的唯一标识	
	TInvestorID InvestorID;
		
};	

///@struct 投资者
#define TPID_Investor 3
struct SInvestor {
	
	///@brief 投资者代码,投资者实体的唯一标识	
	TInvestorID InvestorID;
		
	///@brief 交易密码,投资者用于登录系统、交易的密码	
	TPassword InvestorPassword;
		
	///@brief 资金账号,该投资者关联的资金账号	
	TInvestorID AccountID;
		
	///@brief 资金密码,投资者用于资金划转的密码	
	TPassword AccountPassword;
		
	///@brief 经纪公司代码,投资者所在的经纪公司在综合交易平台的标识	
	TBrokerID BrokerID;
		
};	

///@struct 系统接收到的行情数据
#define TPID_MarketData 4
struct SMarketData {
	
	///@brief 交易日,交易日	
	TDate TradingDay;
		
	///@brief 合约代码,合约在系统中的编号	
	TInstrumentID InstrumentID;
		
	///@brief 交易所代码,一个交易所的编号	
	TExchangeID ExchangeID;
		
	///@brief 最新价,当日该合约交易期间的最新成交价格	
	TPrice LastPrice;
		
	///@brief 上次结算价,上一日的结算价	
	TPrice PreSettlementPrice;
		
	///@brief 昨收盘,上一日收盘价	
	TPrice PreClosePrice;
		
	///@brief 昨持仓量,前最后持仓量，双向计算	
	TLargeVolume PreOpenInterest;
		
	///@brief 今开盘,该期货合约开市前五分钟内经集合竞价产生的成交价格	
	TPrice OpenPrice;
		
	///@brief 最高价,指一定时间内该合约成交价中的最高成交价格	
	TPrice HighestPrice;
		
	///@brief 最低价,指一定时间内该合约成交价中的最低成交价格	
	TPrice LowestPrice;
		
	///@brief 数量,该合约在当日交易期价所有成交合约的双边数量	
	TVolume Volume;
		
	///@brief 成交金额,该合约完成交易的市值	
	TMoney Turnover;
		
	///@brief 持仓量,最后持仓量，双向计算	
	TLargeVolume OpenInterest;
		
	///@brief 今收盘,该合约当日交易的最后一笔成交价格	
	TPrice ClosePrice;
		
	///@brief 本次结算价,该合约当日成交价格按成交量的加权平均价，当日无成交的，按上一日结算价	
	TPrice SettlementPrice;
		
	///@brief 涨停板价,涨停板价	
	TPrice UpperLimitPrice;
		
	///@brief 跌停板价,跌停板价	
	TPrice LowerLimitPrice;
		
	///@brief 昨虚实度,期权用的昨日虚实度	
	TRatio PreDelta;
		
	///@brief 今虚实度,期权用的今日虚实度	
	TRatio CurrDelta;
		
	///@brief 最后修改时间,最后修改时间	
	TTime UpdateTime;
		
	///@brief 最后修改毫秒,最后修改毫秒	
	TMillisec UpdateMillisec;
		
	///@brief 申买价一,申买价一	
	TPrice BidPrice1;
		
	///@brief 申买量一,申买量一	
	TVolume BidVolume1;
		
	///@brief 申卖价一,申卖价一	
	TPrice AskPrice1;
		
	///@brief 申卖量一,申卖量一	
	TVolume AskVolume1;
		
	///@brief 当日均价,当日均价	
	TPrice AveragePrice;
		
};	

///@struct KDJ指标
#define TPID_KDJ 5
struct SKDJ {
	
	///@brief 交易日,交易日	
	TDate TradingDay;
		
	///@brief 合约代码,合约在系统中的编号	
	TInstrumentID InstrumentID;
		
	///@brief 交易所代码,一个交易所的编号	
	TExchangeID ExchangeID;
		
	///@brief 最后修改时间,最后修改时间	
	TTime UpdateTime;
		
	///@brief 最后修改毫秒,最后修改毫秒	
	TMillisec UpdateMillisec;
		
	///@brief k数值,k数值	
	TIndexValue Idx_k;
		
	///@brief d指标,d指标	
	TIndexValue Idx_d;
		
	///@brief j指标,j指标	
	TIndexValue Idx_j;
		
};	

///@struct MACD指标
#define TPID_MACD 6
struct SMACD {
	
	///@brief 交易日,交易日	
	TDate TradingDay;
		
	///@brief 合约代码,合约在系统中的编号	
	TInstrumentID InstrumentID;
		
	///@brief 交易所代码,一个交易所的编号	
	TExchangeID ExchangeID;
		
	///@brief 最后修改时间,最后修改时间	
	TTime UpdateTime;
		
	///@brief 最后修改毫秒,最后修改毫秒	
	TMillisec UpdateMillisec;
		
	///@brief diff数值,diff数值	
	TIndexValue Idx_diff;
		
	///@brief dea指标,dea指标	
	TIndexValue Idx_dea;
		
	///@brief bar指标,bar指标	
	TIndexValue Idx_bar;
		
};	

///@struct 计算模型配置
#define TPID_ModelConfigA 7
struct SModelConfigA {
	
	///@brief 投资者代码,投资者实体的唯一标识	
	TInvestorID InvestorID;
		
	///@brief 数据文件路径,模型计算的结果数据存放路径	
	TPath DataPath;
		
	///@brief 模型计算的循环时间,控制模型多少时间进行一次计算	
	TTimeCycle CalculateCycle;
		
	///@brief 模型类型,描述模型具体类型	
	TModelType ModelType;
		
	///@brief k数值,k数值	
	TIndexValue Idx_k;
		
	///@brief d指标,d指标	
	TIndexValue Idx_d;
		
	///@brief j指标,j指标	
	TIndexValue Idx_j;
		
	///@brief diff数值,diff数值	
	TIndexValue Idx_diff;
		
	///@brief dea指标,dea指标	
	TIndexValue Idx_dea;
		
	///@brief bar指标,bar指标	
	TIndexValue Idx_bar;
		
	///@brief k数值最大阀值,k数值最大阀值	
	TIndexValue MAX_k;
		
	///@brief d指标最大阀值,d指标最大阀值	
	TIndexValue MAX_d;
		
	///@brief j指标最大阀值,j指标最大阀值	
	TIndexValue MAX_j;
		
	///@brief diff数值最大阀值,diff数值最大阀值	
	TIndexValue MAX_diff;
		
	///@brief dea指标最大阀值,dea指标最大阀值	
	TIndexValue MAX_dea;
		
	///@brief bar指标最大阀值,bar指标最大阀值	
	TIndexValue MAX_bar;
		
	///@brief k数值最小阀值,k数值最小阀值	
	TIndexValue MIN_k;
		
	///@brief d指标最小阀值,d指标最小阀值	
	TIndexValue MIN_d;
		
	///@brief j指标最小阀值,j指标最小阀值	
	TIndexValue MIN_j;
		
	///@brief diff数值最小阀值,diff数值最小阀值	
	TIndexValue MIN_diff;
		
	///@brief dea指标最小阀值,dea指标最小阀值	
	TIndexValue MIN_dea;
		
	///@brief bar指标最小阀值,bar指标最小阀值	
	TIndexValue MIN_bar;
		
};	

///@struct 报单请求
#define TPID_OrderReq 8
struct SOrderReq {
	
	///@brief 本地委托编号,我们系统给予每笔委托的编号	
	TLocalOrderID LocalOrderID;
		
	///@brief 交易日,交易日	
	TDate TradingDay;
		
	///@brief 投资者代码,报单的所有者	
	TInvestorID InvestorID;
		
	///@brief 合约代码,报单合约代码	
	TInstrumentID InstrumentID;
		
	///@brief 开平标记,开平标记	
	TOffsetFlag OffsetFlag;
		
	///@brief 持仓方向,仓位的多空标记	
	TDirection Direction;
		
	///@brief 报盘价格,报单价格，暂不支持市价单	
	TPrice Price;
		
	///@brief 报单状态,报单状态	
	TOrderStatus OrderStatus;
		
	///@brief 报单提交状态,报单提交状态	
	TOrderSubmitStatus OrderSubmitStatus;
		
	///@brief 本地日期时间,系统运行的本地日期时间	
	TDateTime LocalTime;
		
	///@brief 报单时间,其实是报单时的行情时间,而不是本地系统时间	
	TTime OrderTime;
		
	///@brief 成交数量,已经成交的数量	
	TVolume VolumeTraded;
		
	///@brief 未成交量,订单未成交的数量	
	TVolume VolumeRemain;
		
};	

///@struct 成交
#define TPID_Trade 9
struct STrade {
	
	///@brief 交易日,交易日	
	TDate TradingDay;
		
	///@brief 投资者代码,成交的所有者	
	TInvestorID InvestorID;
		
	///@brief 合约代码,成交合约代码	
	TInstrumentID InstrumentID;
		
	///@brief 开平标记,开平标记	
	TOffsetFlag OffsetFlag;
		
	///@brief 持仓方向,仓位的多空标记	
	TDirection Direction;
		
	///@brief 成交数量,成交手数	
	TVolume DoneVolume;
		
	///@brief 成交价,成交价	
	TPrice DonePrice;
		
	///@brief 成交时间,成交时间	
	TTime TradeTime;
		
	///@brief 本地委托编号,关联的委托指令编号	
	TLocalOrderID LocalOrderID;
		
};	

///@struct 盘中仓位
#define TPID_RealPosition 10
struct SRealPosition {
	
	///@brief 投资者代码,持仓的所有者	
	TInvestorID InvestorID;
		
	///@brief 合约代码,持仓所在的合约	
	TInstrumentID InstrumentID;
		
	///@brief 持仓方向,仓位的多空标记	
	TDirection Direction;
		
	///@brief 开仓均价,这笔持仓开仓时的价格	
	TPrice OpenPriceAvg;
		
	///@brief 实时持仓手数,可以用于平仓的手数	
	TVolume RealVolume;
		
	///@brief 冻结持仓手数,暂时已被使用的手数	
	TVolume FrozenVolume;
		
	///@brief 持仓保证金,在当前市场下持仓保证金	
	TMoney HoldMargin;
		
};	

///@struct 盘中资金
#define TPID_RealFund 11
struct SRealFund {
	
	///@brief 投资者代码,资金的所有者	
	TInvestorID InvestorID;
		
	///@brief 上日权益,客户的上日资产总值	
	TMoney LastEquity;
		
	///@brief 总权益,客户的资产总值	
	TMoney Equity;
		
	///@brief 可用资金,可以用于开仓的资金	
	TMoney AvailableFund;
		
	///@brief 冻结保证金,冻结的用于报单的保证金	
	TMoney FrozenMargin;
		
	///@brief 冻结手续费,冻结的用于报单的手续费	
	TMoney FrozenFee;
		
	///@brief 交易手续费,因为开平仓而产生的中介手续费	
	TMoney Fee;
		
	///@brief 平仓盈亏,平仓以后产生的盈亏	
	TMoney CloseProfit;
		
	///@brief 持仓盈亏,持仓产生的动态盈亏	
	TMoney HoldProfit;
		
	///@brief 持仓保证金,持仓保证金	
	TMoney Margin;
		
	///@brief 出金,出金	
	TMoney FundIn;
		
	///@brief 入金,入金	
	TMoney FundOut;
		
};	

///@struct 订阅的合约包
#define TPID_SubInstrument 12
struct SSubInstrument {
	
	///@brief 合约代码,持仓所在的合约	
	TInstrumentID InstrumentID;
		
};	

///@struct 交易信号
#define TPID_Singnal 13
struct SSingnal {
	
	///@brief 交易日,交易日	
	TDate TradingDay;
		
	///@brief 投资者代码,报单的所有者	
	TInvestorID InvestorID;
		
	///@brief 合约代码,报单合约代码	
	TInstrumentID InstrumentID;
		
	///@brief 开平标记,开平标记	
	TOffsetFlag OffsetFlag;
		
	///@brief 持仓方向,仓位的多空标记	
	TDirection Direction;
		
	///@brief 报单数量,报单手数	
	TVolume Volume;
		
	///@brief 报盘价格,报单价格，暂不支持市价单	
	TPrice Price;
		
	///@brief 产生信号的原因,是哪里发出的交易信号	
	TSingnalReason SingnalReason;
		
	///@brief 触发时间,其实是触发交易信号时的行情时间,而不是本地系统时间	
	TTime TriggerTime;
		
	///@brief 本地日期时间,系统运行的本地日期时间	
	TDateTime LocalTime;
		
};	

///@struct 合约
#define TPID_Instrument 14
struct SInstrument {
	
	///@brief 合约代码,合约的唯一标识	
	TInstrumentID InstrumentID;
		
	///@brief 合约乘数,用于标记每手持仓标的物的数量	
	TVolume Multiple;
		
	///@brief 涨停板价,涨停板价	
	TPrice UpperLimitPrice;
		
	///@brief 跌停板价,跌停板价	
	TPrice LowerLimitPrice;
		
};	

///@struct 风险管理其配置
#define TPID_RiskControler 15
struct SRiskControler {
	
	///@brief 止盈价差,盈利的价差超过此价位后就平仓	
	TPrice FullPrice;
		
	///@brief 止损价差,亏损的价差超过此价位后就平仓	
	TPrice StopLossPrice;
		
};	

///@struct 帐户的出入金
#define TPID_MoneyChange 16
struct SMoneyChange {
	
	///@brief 投资者代码,资金发生变化的投资者账户	
	TInvestorID InvestorID;
		
	///@brief 资金变化方向,资金变化方向	
	TFundDirection FundDirection;
		
	///@brief 资金变化额,资金变化额	
	TMoney Change;
		
};	

///@struct 新交易日
#define TPID_NewTradingDay 17
struct SNewTradingDay {
	
	///@brief 交易日,交易日	
	TDate TradingDay;
		
};	

///@struct 报单响应
#define TPID_OrderRsp 18
struct SOrderRsp {
	
	///@brief 本地委托编号,我们系统给予每笔委托的编号	
	TLocalOrderID LocalOrderID;
		
	///@brief 交易日,交易日	
	TDate TradingDay;
		
	///@brief 投资者代码,报单的所有者	
	TInvestorID InvestorID;
		
	///@brief 合约代码,报单合约代码	
	TInstrumentID InstrumentID;
		
	///@brief 开平标记,开平标记	
	TOffsetFlag OffsetFlag;
		
	///@brief 持仓方向,仓位的多空标记	
	TDirection Direction;
		
	///@brief 报盘价格,报单价格，暂不支持市价单	
	TPrice Price;
		
	///@brief 报单状态,报单状态	
	TOrderStatus OrderStatus;
		
	///@brief 报单提交状态,报单提交状态	
	TOrderSubmitStatus OrderSubmitStatus;
		
	///@brief 本地日期时间,系统运行的本地日期时间	
	TDateTime LocalTime;
		
	///@brief 报单时间,其实是报单时的行情时间,而不是本地系统时间	
	TTime OrderTime;
		
	///@brief 成交数量,已经成交的数量	
	TVolume VolumeTraded;
		
	///@brief 未成交量,订单未成交的数量	
	TVolume VolumeRemain;
		
};	

///@struct 合约保证金率
#define TPID_MarginRate 19
struct SMarginRate {
	
	///@brief 投资者代码,资金的所有者	
	TInvestorID InvestorID;
		
	///@brief 合约代码,合约的唯一标识	
	TInstrumentID InstrumentID;
		
	///@brief 按金额保证金率,按照每手标的物价值的比率收取保证金	
	TRatio MarginRatioByMoney;
		
	///@brief 每手保证金金额,每手收取的定额保证金	
	TMoney MarginRatioByVolume;
		
};	

///@struct 合约手续费率
#define TPID_FeeRate 20
struct SFeeRate {
	
	///@brief 投资者代码,资金的所有者	
	TInvestorID InvestorID;
		
	///@brief 合约代码,合约的唯一标识	
	TInstrumentID InstrumentID;
		
	///@brief 开仓按金额手续费率,开仓时按照每手标的物价值的比率收取手续费	
	TRatio OpenFeeRatioByMoney;
		
	///@brief 开仓每手手续费金额,开仓时每手收取的定额手续费	
	TMoney OpenFeeRatioByVolume;
		
	///@brief 平仓按金额手续费率,平仓时按照每手标的物价值的比率收取手续费	
	TRatio CloseFeeRatioByMoney;
		
	///@brief 平仓每手手续费金额,平仓时每手收取的定额手续费	
	TMoney CloseFeeRatioByVolume;
		
	///@brief 平今按金额手续费率,平今仓时按照每手标的物价值的比率收取手续费	
	TRatio CloseTodayFeeRatioByMoney;
		
	///@brief 平今每手手续费金额,平今仓时每手收取的定额手续费	
	TMoney CloseTodayFeeRatioByVolume;
		
};	

///@struct 日志配置信息
#define TPID_LogConfig 21
struct SLogConfig {
	
	///@brief 日志输出类型,日志输出的对象类型	
	TLogOutputType LogOutputType;
		
	///@brief 日志级别,日志的输出级别	
	TLogLevel LogLevel;
		
	///@brief 日志路径,日志输出文件或者流的存放路径	
	TPath LogPath;
		
};	

}
#endif
		