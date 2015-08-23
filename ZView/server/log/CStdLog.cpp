
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CStdLog.cpp
///@brief 定义了日志输出类，日志的输出要求
///        1.多级别日志输出，可以控制输出需要的级别
///		   2.输出流可被重定向的
///       CLogger是一个抽象的日志接口，用于应用程序输出日志
///       它在全局只有一个实例，默认实例为向stdout输出日志，
///       应用程序可以继承CLogger，实现自已的日志类
///@author xslt模型代码转换工具
///@date 2013-06-21T07:28:21.809Z
////////////////////////////////////////////////////////////////////////
#pragma once

#include "CStdLog.h"
#include "ScreenLogger.h"
#include "FileLogger.h"

#ifndef CSTDLOG_CPP_
#define CSTDLOG_CPP_

///业务日志
///是否使用业务状态日志
using namespace ZYSystem;

bool ZYSystemMainLog = true;

CStdLogger* CStdLogger::m_pInstance;
SLogConfig* CStdLogger::logConfig;

CStdLogger::CStdLogger(){
    setOutputLogInfo();
}

CStdLogger::~CStdLogger(){};

CStdLogger* CStdLogger::GetInstance(){
    return m_pInstance;
};

void CStdLogger::setLogConfig(SLogConfig* logConfig_in){
    if (m_pInstance == NULL) {
        logConfig = new SLogConfig();
        std::memcpy(logConfig,logConfig_in,sizeof SLogConfig);
        
        if (logConfig_in->LogOutputType == LOT_FileOutput) {
          m_pInstance = new CFileLogger();
        } else {
          m_pInstance = new ScreenLogger();
        }
    }
}

void CStdLogger::outputInfo(int format,...){
    SLog log = this->infoVector[format];
    
	va_list v;
    va_start(v,format);
	outputVL(log.LogLevel,log.LogMsg,v);
    va_end(v);
};


void CStdLogger::logSLog(SLog *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{日志信息描述}:");
    
    output(LL_Debug,"  错误编号:[%d]",in->LogID);
                
    switch (in->LogLevel) {
        
        case LL_SysHalt: {output(LL_Debug,"  日志级别:[0-系统失败]"); break;}
        
        case LL_Alert: {output(LL_Debug,"  日志级别:[1-系统警报]"); break;}
        
        case LL_Error: {output(LL_Debug,"  日志级别:[2-运行错误]"); break;}
        
        case LL_Warning: {output(LL_Debug,"  日志级别:[3-运行警告]"); break;}
        
        case LL_Info: {output(LL_Debug,"  日志级别:[4-运行信息]"); break;}
        
        case LL_Debug: {output(LL_Debug,"  日志级别:[5-调试信息]"); break;}
        
    }
                
    output(LL_Debug,"  日志代码:[%s]",in->LogCode);
                
    output(LL_Debug,"  日志信息:[%s]",in->LogMsg);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSMarketDataProvider(SMarketDataProvider *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{行情提供者配置信息}:");
    
    output(LL_Debug,"  服务器编号:[%s]",in->ConnectionID);
                
    output(LL_Debug,"  远程行情服务地址:[%s]",in->Td_url);
                
    output(LL_Debug,"  远程交易服务地址:[%s]",in->Md_url);
                
    switch (in->ConnectionType) {
        
        case MDT_Sfit: {output(LL_Debug,"  行情类型:[1-上期技术]"); break;}
        
        case MDT_His: {output(LL_Debug,"  行情类型:[2-历史行情重演]"); break;}
        
        case MDT_Sim: {output(LL_Debug,"  行情类型:[3-模拟交易]"); break;}
        
        case MDT_OnlyMD: {output(LL_Debug,"  行情类型:[4-仅收行情]"); break;}
        
    }
                
    output(LL_Debug,"  投资者代码:[%s]",in->InvestorID);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSInvestor(SInvestor *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{投资者}:");
    
    output(LL_Debug,"  投资者代码:[%s]",in->InvestorID);
                
    output(LL_Debug,"  交易密码:[%s]",in->InvestorPassword);
                
    output(LL_Debug,"  资金账号:[%s]",in->AccountID);
                
    output(LL_Debug,"  资金密码:[%s]",in->AccountPassword);
                
    output(LL_Debug,"  经纪公司代码:[%s]",in->BrokerID);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSMarketData(SMarketData *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{系统接收到的行情数据}:");
    
    output(LL_Debug,"  交易日:[%s]",in->TradingDay);
                
    output(LL_Debug,"  合约代码:[%s]",in->InstrumentID);
                
    output(LL_Debug,"  交易所代码:[%s]",in->ExchangeID);
                
    output(LL_Debug,"  最新价:[%f]",in->LastPrice);
                
    output(LL_Debug,"  上次结算价:[%f]",in->PreSettlementPrice);
                
    output(LL_Debug,"  昨收盘:[%f]",in->PreClosePrice);
                
    output(LL_Debug,"  昨持仓量:[%f]",in->PreOpenInterest);
                
    output(LL_Debug,"  今开盘:[%f]",in->OpenPrice);
                
    output(LL_Debug,"  最高价:[%f]",in->HighestPrice);
                
    output(LL_Debug,"  最低价:[%f]",in->LowestPrice);
                
    output(LL_Debug,"  数量:[%d]",in->Volume);
                
    output(LL_Debug,"  成交金额:[%f]",in->Turnover);
                
    output(LL_Debug,"  持仓量:[%f]",in->OpenInterest);
                
    output(LL_Debug,"  今收盘:[%f]",in->ClosePrice);
                
    output(LL_Debug,"  本次结算价:[%f]",in->SettlementPrice);
                
    output(LL_Debug,"  涨停板价:[%f]",in->UpperLimitPrice);
                
    output(LL_Debug,"  跌停板价:[%f]",in->LowerLimitPrice);
                
    output(LL_Debug,"  昨虚实度:[%f]",in->PreDelta);
                
    output(LL_Debug,"  今虚实度:[%f]",in->CurrDelta);
                
    output(LL_Debug,"  最后修改时间:[%s]",in->UpdateTime);
                
    output(LL_Debug,"  最后修改毫秒:[%d]",in->UpdateMillisec);
                
    output(LL_Debug,"  申买价一:[%f]",in->BidPrice1);
                
    output(LL_Debug,"  申买量一:[%d]",in->BidVolume1);
                
    output(LL_Debug,"  申卖价一:[%f]",in->AskPrice1);
                
    output(LL_Debug,"  申卖量一:[%d]",in->AskVolume1);
                
    output(LL_Debug,"  当日均价:[%f]",in->AveragePrice);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSKDJ(SKDJ *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{KDJ指标}:");
    
    output(LL_Debug,"  交易日:[%s]",in->TradingDay);
                
    output(LL_Debug,"  合约代码:[%s]",in->InstrumentID);
                
    output(LL_Debug,"  交易所代码:[%s]",in->ExchangeID);
                
    output(LL_Debug,"  最后修改时间:[%s]",in->UpdateTime);
                
    output(LL_Debug,"  最后修改毫秒:[%d]",in->UpdateMillisec);
                
    output(LL_Debug,"  k数值:[%f]",in->Idx_k);
                
    output(LL_Debug,"  d指标:[%f]",in->Idx_d);
                
    output(LL_Debug,"  j指标:[%f]",in->Idx_j);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSMACD(SMACD *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{MACD指标}:");
    
    output(LL_Debug,"  交易日:[%s]",in->TradingDay);
                
    output(LL_Debug,"  合约代码:[%s]",in->InstrumentID);
                
    output(LL_Debug,"  交易所代码:[%s]",in->ExchangeID);
                
    output(LL_Debug,"  最后修改时间:[%s]",in->UpdateTime);
                
    output(LL_Debug,"  最后修改毫秒:[%d]",in->UpdateMillisec);
                
    output(LL_Debug,"  diff数值:[%f]",in->Idx_diff);
                
    output(LL_Debug,"  dea指标:[%f]",in->Idx_dea);
                
    output(LL_Debug,"  bar指标:[%f]",in->Idx_bar);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSModelConfigA(SModelConfigA *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{计算模型配置}:");
    
    output(LL_Debug,"  投资者代码:[%s]",in->InvestorID);
                
    output(LL_Debug,"  数据文件路径:[%s]",in->DataPath);
                
    output(LL_Debug,"  模型计算的循环时间:[%d]",in->CalculateCycle);
                
    switch (in->ModelType) {
        
        case MT_A: {output(LL_Debug,"  模型类型:[1-模型A]"); break;}
        
    }
                
    output(LL_Debug,"  k数值:[%f]",in->Idx_k);
                
    output(LL_Debug,"  d指标:[%f]",in->Idx_d);
                
    output(LL_Debug,"  j指标:[%f]",in->Idx_j);
                
    output(LL_Debug,"  diff数值:[%f]",in->Idx_diff);
                
    output(LL_Debug,"  dea指标:[%f]",in->Idx_dea);
                
    output(LL_Debug,"  bar指标:[%f]",in->Idx_bar);
                
    output(LL_Debug,"  k数值最大阀值:[%f]",in->MAX_k);
                
    output(LL_Debug,"  d指标最大阀值:[%f]",in->MAX_d);
                
    output(LL_Debug,"  j指标最大阀值:[%f]",in->MAX_j);
                
    output(LL_Debug,"  diff数值最大阀值:[%f]",in->MAX_diff);
                
    output(LL_Debug,"  dea指标最大阀值:[%f]",in->MAX_dea);
                
    output(LL_Debug,"  bar指标最大阀值:[%f]",in->MAX_bar);
                
    output(LL_Debug,"  k数值最小阀值:[%f]",in->MIN_k);
                
    output(LL_Debug,"  d指标最小阀值:[%f]",in->MIN_d);
                
    output(LL_Debug,"  j指标最小阀值:[%f]",in->MIN_j);
                
    output(LL_Debug,"  diff数值最小阀值:[%f]",in->MIN_diff);
                
    output(LL_Debug,"  dea指标最小阀值:[%f]",in->MIN_dea);
                
    output(LL_Debug,"  bar指标最小阀值:[%f]",in->MIN_bar);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSOrderReq(SOrderReq *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{报单请求}:");
    
    output(LL_Debug,"  本地委托编号:[%d]",in->LocalOrderID);
                
    output(LL_Debug,"  交易日:[%s]",in->TradingDay);
                
    output(LL_Debug,"  投资者代码:[%s]",in->InvestorID);
                
    output(LL_Debug,"  合约代码:[%s]",in->InstrumentID);
                
    switch (in->OffsetFlag) {
        
        case OF_Open: {output(LL_Debug,"  开平标记:[0-开仓]"); break;}
        
        case OF_Close: {output(LL_Debug,"  开平标记:[1-平仓]"); break;}
        
        case OF_ForceClose: {output(LL_Debug,"  开平标记:[2-强平]"); break;}
        
        case OF_CloseToday: {output(LL_Debug,"  开平标记:[3-平今]"); break;}
        
        case OF_CloseYesterday: {output(LL_Debug,"  开平标记:[4-平昨]"); break;}
        
        case OF_ForceOff: {output(LL_Debug,"  开平标记:[5-强减]"); break;}
        
        case OF_LocalForceClose: {output(LL_Debug,"  开平标记:[6-本地强平]"); break;}
        
    }
                
    switch (in->Direction) {
        
        case D_Buy: {output(LL_Debug,"  持仓方向:[0-买]"); break;}
        
        case D_Sell: {output(LL_Debug,"  持仓方向:[1-卖]"); break;}
        
    }
                
    output(LL_Debug,"  报盘价格:[%f]",in->Price);
                
    switch (in->OrderStatus) {
        
        case OST_AllTraded: {output(LL_Debug,"  报单状态:[0-全部成交]"); break;}
        
        case OST_PartTradedQueueing: {output(LL_Debug,"  报单状态:[1-部分成交还在队列中]"); break;}
        
        case OST_PartTradedNotQueueing: {output(LL_Debug,"  报单状态:[2-部分成交不在队列中]"); break;}
        
        case OST_NoTradeQueueing: {output(LL_Debug,"  报单状态:[3-未成交还在队列中]"); break;}
        
        case OST_NoTradeNotQueueing: {output(LL_Debug,"  报单状态:[4-未成交不在队列中]"); break;}
        
        case OST_Canceled: {output(LL_Debug,"  报单状态:[5-撤单]"); break;}
        
        case OST_Unknown: {output(LL_Debug,"  报单状态:[6-未知]"); break;}
        
        case OST_NotTouched: {output(LL_Debug,"  报单状态:[7-尚未触发]"); break;}
        
        case OST_Touched: {output(LL_Debug,"  报单状态:[8-已触发]"); break;}
        
    }
                
    switch (in->OrderSubmitStatus) {
        
        case OSS_InsertSubmitted: {output(LL_Debug,"  报单提交状态:[0-已经提交]"); break;}
        
        case OSS_CancelSubmitted: {output(LL_Debug,"  报单提交状态:[1-撤单已经提交]"); break;}
        
        case OSS_ModifySubmitted: {output(LL_Debug,"  报单提交状态:[2-修改已经提交]"); break;}
        
        case OSS_Accepted: {output(LL_Debug,"  报单提交状态:[3-已经接受]"); break;}
        
        case OSS_InsertRejected: {output(LL_Debug,"  报单提交状态:[4-报单已经被拒绝]"); break;}
        
        case OSS_CancelRejected: {output(LL_Debug,"  报单提交状态:[5-撤单已经被拒绝]"); break;}
        
        case OSS_ModifyRejected: {output(LL_Debug,"  报单提交状态:[6-改单已经被拒绝]"); break;}
        
    }
                
    output(LL_Debug,"  本地日期时间:[%s]",in->LocalTime);
                
    output(LL_Debug,"  报单时间:[%s]",in->OrderTime);
                
    output(LL_Debug,"  成交数量:[%d]",in->VolumeTraded);
                
    output(LL_Debug,"  未成交量:[%d]",in->VolumeRemain);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSTrade(STrade *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{成交}:");
    
    output(LL_Debug,"  交易日:[%s]",in->TradingDay);
                
    output(LL_Debug,"  投资者代码:[%s]",in->InvestorID);
                
    output(LL_Debug,"  合约代码:[%s]",in->InstrumentID);
                
    switch (in->OffsetFlag) {
        
        case OF_Open: {output(LL_Debug,"  开平标记:[0-开仓]"); break;}
        
        case OF_Close: {output(LL_Debug,"  开平标记:[1-平仓]"); break;}
        
        case OF_ForceClose: {output(LL_Debug,"  开平标记:[2-强平]"); break;}
        
        case OF_CloseToday: {output(LL_Debug,"  开平标记:[3-平今]"); break;}
        
        case OF_CloseYesterday: {output(LL_Debug,"  开平标记:[4-平昨]"); break;}
        
        case OF_ForceOff: {output(LL_Debug,"  开平标记:[5-强减]"); break;}
        
        case OF_LocalForceClose: {output(LL_Debug,"  开平标记:[6-本地强平]"); break;}
        
    }
                
    switch (in->Direction) {
        
        case D_Buy: {output(LL_Debug,"  持仓方向:[0-买]"); break;}
        
        case D_Sell: {output(LL_Debug,"  持仓方向:[1-卖]"); break;}
        
    }
                
    output(LL_Debug,"  成交数量:[%d]",in->DoneVolume);
                
    output(LL_Debug,"  成交价:[%f]",in->DonePrice);
                
    output(LL_Debug,"  成交时间:[%s]",in->TradeTime);
                
    output(LL_Debug,"  本地委托编号:[%d]",in->LocalOrderID);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSRealPosition(SRealPosition *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{盘中仓位}:");
    
    output(LL_Debug,"  投资者代码:[%s]",in->InvestorID);
                
    output(LL_Debug,"  合约代码:[%s]",in->InstrumentID);
                
    switch (in->Direction) {
        
        case D_Buy: {output(LL_Debug,"  持仓方向:[0-买]"); break;}
        
        case D_Sell: {output(LL_Debug,"  持仓方向:[1-卖]"); break;}
        
    }
                
    output(LL_Debug,"  开仓均价:[%f]",in->OpenPriceAvg);
                
    output(LL_Debug,"  实时持仓手数:[%d]",in->RealVolume);
                
    output(LL_Debug,"  冻结持仓手数:[%d]",in->FrozenVolume);
                
    output(LL_Debug,"  持仓保证金:[%f]",in->HoldMargin);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSRealFund(SRealFund *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{盘中资金}:");
    
    output(LL_Debug,"  投资者代码:[%s]",in->InvestorID);
                
    output(LL_Debug,"  上日权益:[%f]",in->LastEquity);
                
    output(LL_Debug,"  总权益:[%f]",in->Equity);
                
    output(LL_Debug,"  可用资金:[%f]",in->AvailableFund);
                
    output(LL_Debug,"  冻结保证金:[%f]",in->FrozenMargin);
                
    output(LL_Debug,"  冻结手续费:[%f]",in->FrozenFee);
                
    output(LL_Debug,"  交易手续费:[%f]",in->Fee);
                
    output(LL_Debug,"  平仓盈亏:[%f]",in->CloseProfit);
                
    output(LL_Debug,"  持仓盈亏:[%f]",in->HoldProfit);
                
    output(LL_Debug,"  持仓保证金:[%f]",in->Margin);
                
    output(LL_Debug,"  出金:[%f]",in->FundIn);
                
    output(LL_Debug,"  入金:[%f]",in->FundOut);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSSubInstrument(SSubInstrument *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{订阅的合约包}:");
    
    output(LL_Debug,"  合约代码:[%s]",in->InstrumentID);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSSingnal(SSingnal *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{交易信号}:");
    
    output(LL_Debug,"  交易日:[%s]",in->TradingDay);
                
    output(LL_Debug,"  投资者代码:[%s]",in->InvestorID);
                
    output(LL_Debug,"  合约代码:[%s]",in->InstrumentID);
                
    switch (in->OffsetFlag) {
        
        case OF_Open: {output(LL_Debug,"  开平标记:[0-开仓]"); break;}
        
        case OF_Close: {output(LL_Debug,"  开平标记:[1-平仓]"); break;}
        
        case OF_ForceClose: {output(LL_Debug,"  开平标记:[2-强平]"); break;}
        
        case OF_CloseToday: {output(LL_Debug,"  开平标记:[3-平今]"); break;}
        
        case OF_CloseYesterday: {output(LL_Debug,"  开平标记:[4-平昨]"); break;}
        
        case OF_ForceOff: {output(LL_Debug,"  开平标记:[5-强减]"); break;}
        
        case OF_LocalForceClose: {output(LL_Debug,"  开平标记:[6-本地强平]"); break;}
        
    }
                
    switch (in->Direction) {
        
        case D_Buy: {output(LL_Debug,"  持仓方向:[0-买]"); break;}
        
        case D_Sell: {output(LL_Debug,"  持仓方向:[1-卖]"); break;}
        
    }
                
    output(LL_Debug,"  报单数量:[%d]",in->Volume);
                
    output(LL_Debug,"  报盘价格:[%f]",in->Price);
                
    switch (in->SingnalReason) {
        
        case SR_RiskControler: {output(LL_Debug,"  产生信号的原因:[1-风险控制]"); break;}
        
        case SR_ModelA: {output(LL_Debug,"  产生信号的原因:[2-交易模型A]"); break;}
        
    }
                
    output(LL_Debug,"  触发时间:[%s]",in->TriggerTime);
                
    output(LL_Debug,"  本地日期时间:[%s]",in->LocalTime);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSInstrument(SInstrument *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{合约}:");
    
    output(LL_Debug,"  合约代码:[%s]",in->InstrumentID);
                
    output(LL_Debug,"  合约乘数:[%d]",in->Multiple);
                
    output(LL_Debug,"  涨停板价:[%f]",in->UpperLimitPrice);
                
    output(LL_Debug,"  跌停板价:[%f]",in->LowerLimitPrice);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSRiskControler(SRiskControler *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{风险管理其配置}:");
    
    output(LL_Debug,"  止盈价差:[%f]",in->FullPrice);
                
    output(LL_Debug,"  止损价差:[%f]",in->StopLossPrice);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSMoneyChange(SMoneyChange *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{帐户的出入金}:");
    
    output(LL_Debug,"  投资者代码:[%s]",in->InvestorID);
                
    switch (in->FundDirection) {
        
        case FD_In: {output(LL_Debug,"  资金变化方向:[1-入金]"); break;}
        
        case FD_Out: {output(LL_Debug,"  资金变化方向:[2-出金]"); break;}
        
    }
                
    output(LL_Debug,"  资金变化额:[%f]",in->Change);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSNewTradingDay(SNewTradingDay *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{新交易日}:");
    
    output(LL_Debug,"  交易日:[%s]",in->TradingDay);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSOrderRsp(SOrderRsp *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{报单响应}:");
    
    output(LL_Debug,"  本地委托编号:[%d]",in->LocalOrderID);
                
    output(LL_Debug,"  交易日:[%s]",in->TradingDay);
                
    output(LL_Debug,"  投资者代码:[%s]",in->InvestorID);
                
    output(LL_Debug,"  合约代码:[%s]",in->InstrumentID);
                
    switch (in->OffsetFlag) {
        
        case OF_Open: {output(LL_Debug,"  开平标记:[0-开仓]"); break;}
        
        case OF_Close: {output(LL_Debug,"  开平标记:[1-平仓]"); break;}
        
        case OF_ForceClose: {output(LL_Debug,"  开平标记:[2-强平]"); break;}
        
        case OF_CloseToday: {output(LL_Debug,"  开平标记:[3-平今]"); break;}
        
        case OF_CloseYesterday: {output(LL_Debug,"  开平标记:[4-平昨]"); break;}
        
        case OF_ForceOff: {output(LL_Debug,"  开平标记:[5-强减]"); break;}
        
        case OF_LocalForceClose: {output(LL_Debug,"  开平标记:[6-本地强平]"); break;}
        
    }
                
    switch (in->Direction) {
        
        case D_Buy: {output(LL_Debug,"  持仓方向:[0-买]"); break;}
        
        case D_Sell: {output(LL_Debug,"  持仓方向:[1-卖]"); break;}
        
    }
                
    output(LL_Debug,"  报盘价格:[%f]",in->Price);
                
    switch (in->OrderStatus) {
        
        case OST_AllTraded: {output(LL_Debug,"  报单状态:[0-全部成交]"); break;}
        
        case OST_PartTradedQueueing: {output(LL_Debug,"  报单状态:[1-部分成交还在队列中]"); break;}
        
        case OST_PartTradedNotQueueing: {output(LL_Debug,"  报单状态:[2-部分成交不在队列中]"); break;}
        
        case OST_NoTradeQueueing: {output(LL_Debug,"  报单状态:[3-未成交还在队列中]"); break;}
        
        case OST_NoTradeNotQueueing: {output(LL_Debug,"  报单状态:[4-未成交不在队列中]"); break;}
        
        case OST_Canceled: {output(LL_Debug,"  报单状态:[5-撤单]"); break;}
        
        case OST_Unknown: {output(LL_Debug,"  报单状态:[6-未知]"); break;}
        
        case OST_NotTouched: {output(LL_Debug,"  报单状态:[7-尚未触发]"); break;}
        
        case OST_Touched: {output(LL_Debug,"  报单状态:[8-已触发]"); break;}
        
    }
                
    switch (in->OrderSubmitStatus) {
        
        case OSS_InsertSubmitted: {output(LL_Debug,"  报单提交状态:[0-已经提交]"); break;}
        
        case OSS_CancelSubmitted: {output(LL_Debug,"  报单提交状态:[1-撤单已经提交]"); break;}
        
        case OSS_ModifySubmitted: {output(LL_Debug,"  报单提交状态:[2-修改已经提交]"); break;}
        
        case OSS_Accepted: {output(LL_Debug,"  报单提交状态:[3-已经接受]"); break;}
        
        case OSS_InsertRejected: {output(LL_Debug,"  报单提交状态:[4-报单已经被拒绝]"); break;}
        
        case OSS_CancelRejected: {output(LL_Debug,"  报单提交状态:[5-撤单已经被拒绝]"); break;}
        
        case OSS_ModifyRejected: {output(LL_Debug,"  报单提交状态:[6-改单已经被拒绝]"); break;}
        
    }
                
    output(LL_Debug,"  本地日期时间:[%s]",in->LocalTime);
                
    output(LL_Debug,"  报单时间:[%s]",in->OrderTime);
                
    output(LL_Debug,"  成交数量:[%d]",in->VolumeTraded);
                
    output(LL_Debug,"  未成交量:[%d]",in->VolumeRemain);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSMarginRate(SMarginRate *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{合约保证金率}:");
    
    output(LL_Debug,"  投资者代码:[%s]",in->InvestorID);
                
    output(LL_Debug,"  合约代码:[%s]",in->InstrumentID);
                
    output(LL_Debug,"  按金额保证金率:[%f]",in->MarginRatioByMoney);
                
    output(LL_Debug,"  每手保证金金额:[%f]",in->MarginRatioByVolume);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSFeeRate(SFeeRate *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{合约手续费率}:");
    
    output(LL_Debug,"  投资者代码:[%s]",in->InvestorID);
                
    output(LL_Debug,"  合约代码:[%s]",in->InstrumentID);
                
    output(LL_Debug,"  开仓按金额手续费率:[%f]",in->OpenFeeRatioByMoney);
                
    output(LL_Debug,"  开仓每手手续费金额:[%f]",in->OpenFeeRatioByVolume);
                
    output(LL_Debug,"  平仓按金额手续费率:[%f]",in->CloseFeeRatioByMoney);
                
    output(LL_Debug,"  平仓每手手续费金额:[%f]",in->CloseFeeRatioByVolume);
                
    output(LL_Debug,"  平今按金额手续费率:[%f]",in->CloseTodayFeeRatioByMoney);
                
    output(LL_Debug,"  平今每手手续费金额:[%f]",in->CloseTodayFeeRatioByVolume);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSLogConfig(SLogConfig *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{日志配置信息}:");
    
    switch (in->LogOutputType) {
        
        case LOT_ScreenOutput: {output(LL_Debug,"  日志输出类型:[1-屏幕输出]"); break;}
        
        case LOT_FileOutput: {output(LL_Debug,"  日志输出类型:[2-文件输出]"); break;}
        
    }
                
    switch (in->LogLevel) {
        
        case LL_SysHalt: {output(LL_Debug,"  日志级别:[0-系统失败]"); break;}
        
        case LL_Alert: {output(LL_Debug,"  日志级别:[1-系统警报]"); break;}
        
        case LL_Error: {output(LL_Debug,"  日志级别:[2-运行错误]"); break;}
        
        case LL_Warning: {output(LL_Debug,"  日志级别:[3-运行警告]"); break;}
        
        case LL_Info: {output(LL_Debug,"  日志级别:[4-运行信息]"); break;}
        
        case LL_Debug: {output(LL_Debug,"  日志级别:[5-调试信息]"); break;}
        
    }
                
    output(LL_Debug,"  日志路径:[%s]",in->LogPath);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::setOutputLogInfo(){

        SLog log_MAINNoConfigFile;
        log_MAINNoConfigFile.LogID = 1001;
        log_MAINNoConfigFile.LogLevel = LL_Debug;
        std::strcpy(log_MAINNoConfigFile.LogCode,"MAIN_NoConfigFile");
        std::strcpy(log_MAINNoConfigFile.LogMsg,"[1001$MAIN_NoConfigFile]:没有能打开配置文件,请检查配置文件%s是否存在");
        infoVector[1001]=log_MAINNoConfigFile;
        
    
        SLog log_MAINConfigFileFound;
        log_MAINConfigFileFound.LogID = 1002;
        log_MAINConfigFileFound.LogLevel = LL_Debug;
        std::strcpy(log_MAINConfigFileFound.LogCode,"MAIN_ConfigFileFound");
        std::strcpy(log_MAINConfigFileFound.LogMsg,"[1002$MAIN_ConfigFileFound]:找到配置文件%s");
        infoVector[1002]=log_MAINConfigFileFound;
        
    
        SLog log_MAINConfigFileErr;
        log_MAINConfigFileErr.LogID = 1003;
        log_MAINConfigFileErr.LogLevel = LL_Debug;
        std::strcpy(log_MAINConfigFileErr.LogCode,"MAIN_ConfigFileErr");
        std::strcpy(log_MAINConfigFileErr.LogMsg,"[1003$MAIN_ConfigFileErr]:配置文件中有错:%s");
        infoVector[1003]=log_MAINConfigFileErr;
        
    
        SLog log_MAINConfigFileSvrNumber;
        log_MAINConfigFileSvrNumber.LogID = 1004;
        log_MAINConfigFileSvrNumber.LogLevel = LL_Debug;
        std::strcpy(log_MAINConfigFileSvrNumber.LogCode,"MAIN_ConfigFileSvrNumber");
        std::strcpy(log_MAINConfigFileSvrNumber.LogMsg,"[1004$MAIN_ConfigFileSvrNumber]:在配置文件中发现了%d个服务器");
        infoVector[1004]=log_MAINConfigFileSvrNumber;
        
    
        SLog log_MAINMdrLoadSucc;
        log_MAINMdrLoadSucc.LogID = 1005;
        log_MAINMdrLoadSucc.LogLevel = LL_Debug;
        std::strcpy(log_MAINMdrLoadSucc.LogCode,"MAIN_MdrLoadSucc");
        std::strcpy(log_MAINMdrLoadSucc.LogMsg,"[1005$MAIN_MdrLoadSucc]:成功:加载第%d个行情接收器");
        infoVector[1005]=log_MAINMdrLoadSucc;
        
    
        SLog log_MAINMdrLoadFail;
        log_MAINMdrLoadFail.LogID = 1006;
        log_MAINMdrLoadFail.LogLevel = LL_Debug;
        std::strcpy(log_MAINMdrLoadFail.LogCode,"MAIN_MdrLoadFail");
        std::strcpy(log_MAINMdrLoadFail.LogMsg,"[1006$MAIN_MdrLoadFail]:失败:加载第%d个行情接收器");
        infoVector[1006]=log_MAINMdrLoadFail;
        
    
        SLog log_MAINMdrLoadFinish;
        log_MAINMdrLoadFinish.LogID = 1007;
        log_MAINMdrLoadFinish.LogLevel = LL_Debug;
        std::strcpy(log_MAINMdrLoadFinish.LogCode,"MAIN_MdrLoadFinish");
        std::strcpy(log_MAINMdrLoadFinish.LogMsg,"[1007$MAIN_MdrLoadFinish]:完成:行情接收器加载");
        infoVector[1007]=log_MAINMdrLoadFinish;
        
    
        SLog log_MAINConfigFileInvNumber;
        log_MAINConfigFileInvNumber.LogID = 1008;
        log_MAINConfigFileInvNumber.LogLevel = LL_Debug;
        std::strcpy(log_MAINConfigFileInvNumber.LogCode,"MAIN_ConfigFileInvNumber");
        std::strcpy(log_MAINConfigFileInvNumber.LogMsg,"[1008$MAIN_ConfigFileInvNumber]:在配置文件中发现了%d个投资者");
        infoVector[1008]=log_MAINConfigFileInvNumber;
        
    
        SLog log_MAINInvLoadSucc;
        log_MAINInvLoadSucc.LogID = 1009;
        log_MAINInvLoadSucc.LogLevel = LL_Debug;
        std::strcpy(log_MAINInvLoadSucc.LogCode,"MAIN_InvLoadSucc");
        std::strcpy(log_MAINInvLoadSucc.LogMsg,"[1009$MAIN_InvLoadSucc]:成功:加载第%d个投资者");
        infoVector[1009]=log_MAINInvLoadSucc;
        
    
        SLog log_MAINInvLoadFail;
        log_MAINInvLoadFail.LogID = 1010;
        log_MAINInvLoadFail.LogLevel = LL_Debug;
        std::strcpy(log_MAINInvLoadFail.LogCode,"MAIN_InvLoadFail");
        std::strcpy(log_MAINInvLoadFail.LogMsg,"[1010$MAIN_InvLoadFail]:失败:加载第%d个投资者");
        infoVector[1010]=log_MAINInvLoadFail;
        
    
        SLog log_MAINInvLoadFinish;
        log_MAINInvLoadFinish.LogID = 1011;
        log_MAINInvLoadFinish.LogLevel = LL_Debug;
        std::strcpy(log_MAINInvLoadFinish.LogCode,"MAIN_InvLoadFinish");
        std::strcpy(log_MAINInvLoadFinish.LogMsg,"[1011$MAIN_InvLoadFinish]:完成:投资者加载");
        infoVector[1011]=log_MAINInvLoadFinish;
        
    
        SLog log_MAINXpathValueErr;
        log_MAINXpathValueErr.LogID = 1012;
        log_MAINXpathValueErr.LogLevel = LL_Debug;
        std::strcpy(log_MAINXpathValueErr.LogCode,"MAIN_XpathValueErr");
        std::strcpy(log_MAINXpathValueErr.LogMsg,"[1012$MAIN_XpathValueErr]:错误:xmlpath:%s");
        infoVector[1012]=log_MAINXpathValueErr;
        
    
        SLog log_MAINLogPath;
        log_MAINLogPath.LogID = 1013;
        log_MAINLogPath.LogLevel = LL_Debug;
        std::strcpy(log_MAINLogPath.LogCode,"MAIN_LogPath");
        std::strcpy(log_MAINLogPath.LogMsg,"[1013$MAIN_LogPath]:完成:日志的路径是%s");
        infoVector[1013]=log_MAINLogPath;
        
    
        SLog log_MAINMdrInstrument;
        log_MAINMdrInstrument.LogID = 1014;
        log_MAINMdrInstrument.LogLevel = LL_Debug;
        std::strcpy(log_MAINMdrInstrument.LogCode,"MAIN_MdrInstrument");
        std::strcpy(log_MAINMdrInstrument.LogMsg,"[1014$MAIN_MdrInstrument]:发现:此行情配置了%d个合约");
        infoVector[1014]=log_MAINMdrInstrument;
        
    
        SLog log_PROTFOLIONotEnoughPoistion;
        log_PROTFOLIONotEnoughPoistion.LogID = 2002;
        log_PROTFOLIONotEnoughPoistion.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIONotEnoughPoistion.LogCode,"PROTFOLIO_NotEnoughPoistion");
        std::strcpy(log_PROTFOLIONotEnoughPoistion.LogMsg,"[2002$PROTFOLIO_NotEnoughPoistion]:持仓不足");
        infoVector[2002]=log_PROTFOLIONotEnoughPoistion;
        
    
        SLog log_PROTFOLIONotFindPosition;
        log_PROTFOLIONotFindPosition.LogID = 2003;
        log_PROTFOLIONotFindPosition.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIONotFindPosition.LogCode,"PROTFOLIO_NotFindPosition");
        std::strcpy(log_PROTFOLIONotFindPosition.LogMsg,"[2003$PROTFOLIO_NotFindPosition]:没有找到持仓");
        infoVector[2003]=log_PROTFOLIONotFindPosition;
        
    
        SLog log_PROTFOLIOOpenOrderNotFrozen;
        log_PROTFOLIOOpenOrderNotFrozen.LogID = 2004;
        log_PROTFOLIOOpenOrderNotFrozen.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIOOpenOrderNotFrozen.LogCode,"PROTFOLIO_OpenOrderNotFrozen");
        std::strcpy(log_PROTFOLIOOpenOrderNotFrozen.LogMsg,"[2004$PROTFOLIO_OpenOrderNotFrozen]:没有找到持仓");
        infoVector[2004]=log_PROTFOLIOOpenOrderNotFrozen;
        
    
        SLog log_PROTFOLIOFrozenedPositionNotEnough;
        log_PROTFOLIOFrozenedPositionNotEnough.LogID = 2005;
        log_PROTFOLIOFrozenedPositionNotEnough.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIOFrozenedPositionNotEnough.LogCode,"PROTFOLIO_FrozenedPositionNotEnough");
        std::strcpy(log_PROTFOLIOFrozenedPositionNotEnough.LogMsg,"[2005$PROTFOLIO_FrozenedPositionNotEnough]:可解冻仓位不足");
        infoVector[2005]=log_PROTFOLIOFrozenedPositionNotEnough;
        
    
        SLog log_PROTFOLIOPositionNotEnoughToFrozen;
        log_PROTFOLIOPositionNotEnoughToFrozen.LogID = 2006;
        log_PROTFOLIOPositionNotEnoughToFrozen.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIOPositionNotEnoughToFrozen.LogCode,"PROTFOLIO_PositionNotEnoughToFrozen");
        std::strcpy(log_PROTFOLIOPositionNotEnoughToFrozen.LogMsg,"[2006$PROTFOLIO_PositionNotEnoughToFrozen]:可冻结仓位不足");
        infoVector[2006]=log_PROTFOLIOPositionNotEnoughToFrozen;
        
    
        SLog log_PROTFOLIOOpenNotFrozen;
        log_PROTFOLIOOpenNotFrozen.LogID = 2007;
        log_PROTFOLIOOpenNotFrozen.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIOOpenNotFrozen.LogCode,"PROTFOLIO_OpenNotFrozen");
        std::strcpy(log_PROTFOLIOOpenNotFrozen.LogMsg,"[2007$PROTFOLIO_OpenNotFrozen]:开仓指令不可用于解冻持仓");
        infoVector[2007]=log_PROTFOLIOOpenNotFrozen;
        
    
        SLog log_PROTFOLIOOpenNotUnfrozen;
        log_PROTFOLIOOpenNotUnfrozen.LogID = 2008;
        log_PROTFOLIOOpenNotUnfrozen.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIOOpenNotUnfrozen.LogCode,"PROTFOLIO_OpenNotUnfrozen");
        std::strcpy(log_PROTFOLIOOpenNotUnfrozen.LogMsg,"[2008$PROTFOLIO_OpenNotUnfrozen]:开仓指令不可用于冻结持仓");
        infoVector[2008]=log_PROTFOLIOOpenNotUnfrozen;
        
    
        SLog log_PROTFOLIOFrozenedMoneyNotEnough;
        log_PROTFOLIOFrozenedMoneyNotEnough.LogID = 2009;
        log_PROTFOLIOFrozenedMoneyNotEnough.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIOFrozenedMoneyNotEnough.LogCode,"PROTFOLIO_FrozenedMoneyNotEnough");
        std::strcpy(log_PROTFOLIOFrozenedMoneyNotEnough.LogMsg,"[2009$PROTFOLIO_FrozenedMoneyNotEnough]:冻结的资金不足");
        infoVector[2009]=log_PROTFOLIOFrozenedMoneyNotEnough;
        
    
        SLog log_PROTFOLIONotFindInsturmentBySingnal;
        log_PROTFOLIONotFindInsturmentBySingnal.LogID = 2010;
        log_PROTFOLIONotFindInsturmentBySingnal.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIONotFindInsturmentBySingnal.LogCode,"PROTFOLIO_NotFindInsturmentBySingnal");
        std::strcpy(log_PROTFOLIONotFindInsturmentBySingnal.LogMsg,"[2010$PROTFOLIO_NotFindInsturmentBySingnal]:以交易信号为条件没有找到对应的合约设置");
        infoVector[2010]=log_PROTFOLIONotFindInsturmentBySingnal;
        
    
        SLog log_PROTFOLIOInsturmentsNull;
        log_PROTFOLIOInsturmentsNull.LogID = 2011;
        log_PROTFOLIOInsturmentsNull.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIOInsturmentsNull.LogCode,"PROTFOLIO_InsturmentsNull");
        std::strcpy(log_PROTFOLIOInsturmentsNull.LogMsg,"[2011$PROTFOLIO_InsturmentsNull]:合约集合为空");
        infoVector[2011]=log_PROTFOLIOInsturmentsNull;
        
    
        SLog log_PROTFOLIOOrdersNull;
        log_PROTFOLIOOrdersNull.LogID = 2012;
        log_PROTFOLIOOrdersNull.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIOOrdersNull.LogCode,"PROTFOLIO_OrdersNull");
        std::strcpy(log_PROTFOLIOOrdersNull.LogMsg,"[2012$PROTFOLIO_OrdersNull]:报单集合为空");
        infoVector[2012]=log_PROTFOLIOOrdersNull;
        
    
        SLog log_PROTFOLIONotFindOrderByTrade;
        log_PROTFOLIONotFindOrderByTrade.LogID = 2013;
        log_PROTFOLIONotFindOrderByTrade.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIONotFindOrderByTrade.LogCode,"PROTFOLIO_NotFindOrderByTrade");
        std::strcpy(log_PROTFOLIONotFindOrderByTrade.LogMsg,"[2013$PROTFOLIO_NotFindOrderByTrade]:以成交为条件没有找到对应的报单");
        infoVector[2013]=log_PROTFOLIONotFindOrderByTrade;
        
    
        SLog log_PROTFOLIOMarginNotEnough;
        log_PROTFOLIOMarginNotEnough.LogID = 2014;
        log_PROTFOLIOMarginNotEnough.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIOMarginNotEnough.LogCode,"PROTFOLIO_MarginNotEnough");
        std::strcpy(log_PROTFOLIOMarginNotEnough.LogMsg,"[2014$PROTFOLIO_MarginNotEnough]:占用的保证金不足");
        infoVector[2014]=log_PROTFOLIOMarginNotEnough;
        
    
        SLog log_PROTFOLIONotFindInsturmentByTrade;
        log_PROTFOLIONotFindInsturmentByTrade.LogID = 2015;
        log_PROTFOLIONotFindInsturmentByTrade.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIONotFindInsturmentByTrade.LogCode,"PROTFOLIO_NotFindInsturmentByTrade");
        std::strcpy(log_PROTFOLIONotFindInsturmentByTrade.LogMsg,"[2015$PROTFOLIO_NotFindInsturmentByTrade]:以成交为条件没有找到对应的合约设置");
        infoVector[2015]=log_PROTFOLIONotFindInsturmentByTrade;
        
    
        SLog log_CONNECTORHIS_TradingDayIs;
        log_CONNECTORHIS_TradingDayIs.LogID = 3001;
        log_CONNECTORHIS_TradingDayIs.LogLevel = LL_Debug;
        std::strcpy(log_CONNECTORHIS_TradingDayIs.LogCode,"CONNECTOR_HIS_TradingDayIs");
        std::strcpy(log_CONNECTORHIS_TradingDayIs.LogMsg,"[3001$CONNECTOR_HIS_TradingDayIs]:历史交易日是：%s");
        infoVector[3001]=log_CONNECTORHIS_TradingDayIs;
        
    
        SLog log_CONNECTORNewMDIsEmpty;
        log_CONNECTORNewMDIsEmpty.LogID = 3002;
        log_CONNECTORNewMDIsEmpty.LogLevel = LL_Debug;
        std::strcpy(log_CONNECTORNewMDIsEmpty.LogCode,"CONNECTOR_NewMDIsEmpty");
        std::strcpy(log_CONNECTORNewMDIsEmpty.LogMsg,"[3002$CONNECTOR_NewMDIsEmpty]:新行情为空");
        infoVector[3002]=log_CONNECTORNewMDIsEmpty;
        
    
        SLog log_CONNECTORCtpMDIsEmpty;
        log_CONNECTORCtpMDIsEmpty.LogID = 3003;
        log_CONNECTORCtpMDIsEmpty.LogLevel = LL_Debug;
        std::strcpy(log_CONNECTORCtpMDIsEmpty.LogCode,"CONNECTOR_CtpMDIsEmpty");
        std::strcpy(log_CONNECTORCtpMDIsEmpty.LogMsg,"[3003$CONNECTOR_CtpMDIsEmpty]:CTP行情对象为空");
        infoVector[3003]=log_CONNECTORCtpMDIsEmpty;
        
    
        SLog log_CONNECTORCtpTradeIsEmpty;
        log_CONNECTORCtpTradeIsEmpty.LogID = 3004;
        log_CONNECTORCtpTradeIsEmpty.LogLevel = LL_Debug;
        std::strcpy(log_CONNECTORCtpTradeIsEmpty.LogCode,"CONNECTOR_CtpTradeIsEmpty");
        std::strcpy(log_CONNECTORCtpTradeIsEmpty.LogMsg,"[3004$CONNECTOR_CtpTradeIsEmpty]:CTP交易对象为空");
        infoVector[3004]=log_CONNECTORCtpTradeIsEmpty;
        
    
        SLog log_DATAROUTEMsgQueClosed;
        log_DATAROUTEMsgQueClosed.LogID = 4001;
        log_DATAROUTEMsgQueClosed.LogLevel = LL_Debug;
        std::strcpy(log_DATAROUTEMsgQueClosed.LogCode,"DATAROUTE_MsgQueClosed");
        std::strcpy(log_DATAROUTEMsgQueClosed.LogMsg,"[4001$DATAROUTE_MsgQueClosed]:消息队列已经关闭了");
        infoVector[4001]=log_DATAROUTEMsgQueClosed;
        
    
        SLog log_DATAROUTEMsgEmpty;
        log_DATAROUTEMsgEmpty.LogID = 4002;
        log_DATAROUTEMsgEmpty.LogLevel = LL_Debug;
        std::strcpy(log_DATAROUTEMsgEmpty.LogCode,"DATAROUTE_MsgEmpty");
        std::strcpy(log_DATAROUTEMsgEmpty.LogMsg,"[4002$DATAROUTE_MsgEmpty]:空消息对象");
        infoVector[4002]=log_DATAROUTEMsgEmpty;
        
    
        SLog log_DATAROUTEMsgQueMaxSizeLessOne;
        log_DATAROUTEMsgQueMaxSizeLessOne.LogID = 4003;
        log_DATAROUTEMsgQueMaxSizeLessOne.LogLevel = LL_Debug;
        std::strcpy(log_DATAROUTEMsgQueMaxSizeLessOne.LogCode,"DATAROUTE_MsgQueMaxSizeLessOne");
        std::strcpy(log_DATAROUTEMsgQueMaxSizeLessOne.LogMsg,"[4003$DATAROUTE_MsgQueMaxSizeLessOne]:消息队列最大长度小于1。");
        infoVector[4003]=log_DATAROUTEMsgQueMaxSizeLessOne;
        
    
        SLog log_DATAROUTEQueSizeAfterPush;
        log_DATAROUTEQueSizeAfterPush.LogID = 4004;
        log_DATAROUTEQueSizeAfterPush.LogLevel = LL_Debug;
        std::strcpy(log_DATAROUTEQueSizeAfterPush.LogCode,"DATAROUTE_QueSizeAfterPush");
        std::strcpy(log_DATAROUTEQueSizeAfterPush.LogMsg,"[4004$DATAROUTE_QueSizeAfterPush]:QueSizeAfterPush:%d ");
        infoVector[4004]=log_DATAROUTEQueSizeAfterPush;
        
    
        SLog log_DATAROUTEQueSizeAfterPop;
        log_DATAROUTEQueSizeAfterPop.LogID = 4005;
        log_DATAROUTEQueSizeAfterPop.LogLevel = LL_Debug;
        std::strcpy(log_DATAROUTEQueSizeAfterPop.LogCode,"DATAROUTE_QueSizeAfterPop");
        std::strcpy(log_DATAROUTEQueSizeAfterPop.LogMsg,"[4005$DATAROUTE_QueSizeAfterPop]:QueSizeAfterPop:%d ");
        infoVector[4005]=log_DATAROUTEQueSizeAfterPop;
        
    
        SLog log_SPIMD_Connected;
        log_SPIMD_Connected.LogID = 5001;
        log_SPIMD_Connected.LogLevel = LL_Debug;
        std::strcpy(log_SPIMD_Connected.LogCode,"SPI_MD_Connected");
        std::strcpy(log_SPIMD_Connected.LogMsg,"[5001$SPI_MD_Connected]:CTP行情服务器连接成功");
        infoVector[5001]=log_SPIMD_Connected;
        
    
        SLog log_SPIMD_Disconnected;
        log_SPIMD_Disconnected.LogID = 5002;
        log_SPIMD_Disconnected.LogLevel = LL_Debug;
        std::strcpy(log_SPIMD_Disconnected.LogCode,"SPI_MD_Disconnected");
        std::strcpy(log_SPIMD_Disconnected.LogMsg,"[5002$SPI_MD_Disconnected]:CTP行情服务器已经断开");
        infoVector[5002]=log_SPIMD_Disconnected;
        
    
        SLog log_SPIMD_LoginSucc;
        log_SPIMD_LoginSucc.LogID = 5003;
        log_SPIMD_LoginSucc.LogLevel = LL_Debug;
        std::strcpy(log_SPIMD_LoginSucc.LogCode,"SPI_MD_LoginSucc");
        std::strcpy(log_SPIMD_LoginSucc.LogMsg,"[5003$SPI_MD_LoginSucc]:登录到CTP行情服务器");
        infoVector[5003]=log_SPIMD_LoginSucc;
        
    
        SLog log_SPIMD_LoginFail;
        log_SPIMD_LoginFail.LogID = 5004;
        log_SPIMD_LoginFail.LogLevel = LL_Debug;
        std::strcpy(log_SPIMD_LoginFail.LogCode,"SPI_MD_LoginFail");
        std::strcpy(log_SPIMD_LoginFail.LogMsg,"[5004$SPI_MD_LoginFail]:登录CTP行情服务器失败");
        infoVector[5004]=log_SPIMD_LoginFail;
        
    
        SLog log_SPIMD_ServerErr;
        log_SPIMD_ServerErr.LogID = 5005;
        log_SPIMD_ServerErr.LogLevel = LL_Debug;
        std::strcpy(log_SPIMD_ServerErr.LogCode,"SPI_MD_ServerErr");
        std::strcpy(log_SPIMD_ServerErr.LogMsg,"[5005$SPI_MD_ServerErr]:CTP行情服务器错误：%s");
        infoVector[5005]=log_SPIMD_ServerErr;
        
    
        SLog log_SPIMD_NewInsturments;
        log_SPIMD_NewInsturments.LogID = 5006;
        log_SPIMD_NewInsturments.LogLevel = LL_Debug;
        std::strcpy(log_SPIMD_NewInsturments.LogCode,"SPI_MD_NewInsturments");
        std::strcpy(log_SPIMD_NewInsturments.LogMsg,"[5006$SPI_MD_NewInsturments]:CTP行情服务器订阅了新合约：%s");
        infoVector[5006]=log_SPIMD_NewInsturments;
        
    
        SLog log_SPIMD_TradingDayIs;
        log_SPIMD_TradingDayIs.LogID = 5007;
        log_SPIMD_TradingDayIs.LogLevel = LL_Debug;
        std::strcpy(log_SPIMD_TradingDayIs.LogCode,"SPI_MD_TradingDayIs");
        std::strcpy(log_SPIMD_TradingDayIs.LogMsg,"[5007$SPI_MD_TradingDayIs]:CTP行情服务器的交易日是：%s");
        infoVector[5007]=log_SPIMD_TradingDayIs;
        
    
        SLog log_SPIT_Connected;
        log_SPIT_Connected.LogID = 5008;
        log_SPIT_Connected.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_Connected.LogCode,"SPI_T_Connected");
        std::strcpy(log_SPIT_Connected.LogMsg,"[5008$SPI_T_Connected]:CTP交易服务器连接成功");
        infoVector[5008]=log_SPIT_Connected;
        
    
        SLog log_SPIT_Disconnected;
        log_SPIT_Disconnected.LogID = 5009;
        log_SPIT_Disconnected.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_Disconnected.LogCode,"SPI_T_Disconnected");
        std::strcpy(log_SPIT_Disconnected.LogMsg,"[5009$SPI_T_Disconnected]:CTP交易服务器已经断开:%d");
        infoVector[5009]=log_SPIT_Disconnected;
        
    
        SLog log_SPIT_LoginSucc;
        log_SPIT_LoginSucc.LogID = 5010;
        log_SPIT_LoginSucc.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_LoginSucc.LogCode,"SPI_T_LoginSucc");
        std::strcpy(log_SPIT_LoginSucc.LogMsg,"[5010$SPI_T_LoginSucc]:CTP登录到交易服务器");
        infoVector[5010]=log_SPIT_LoginSucc;
        
    
        SLog log_SPIT_LoginFail;
        log_SPIT_LoginFail.LogID = 5011;
        log_SPIT_LoginFail.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_LoginFail.LogCode,"SPI_T_LoginFail");
        std::strcpy(log_SPIT_LoginFail.LogMsg,"[5011$SPI_T_LoginFail]:CTP登录交易服务器失败");
        infoVector[5011]=log_SPIT_LoginFail;
        
    
        SLog log_SPIT_ServerErr;
        log_SPIT_ServerErr.LogID = 5012;
        log_SPIT_ServerErr.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_ServerErr.LogCode,"SPI_T_ServerErr");
        std::strcpy(log_SPIT_ServerErr.LogMsg,"[5012$SPI_T_ServerErr]:CTP交易服务器错误：[%d]%s");
        infoVector[5012]=log_SPIT_ServerErr;
        
    
        SLog log_SPIT_TradingDayIs;
        log_SPIT_TradingDayIs.LogID = 5013;
        log_SPIT_TradingDayIs.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_TradingDayIs.LogCode,"SPI_T_TradingDayIs");
        std::strcpy(log_SPIT_TradingDayIs.LogMsg,"[5013$SPI_T_TradingDayIs]:CTP交易服务器的交易日是：%s");
        infoVector[5013]=log_SPIT_TradingDayIs;
        
    
        SLog log_SPIT_SettInfoConfirmSucc;
        log_SPIT_SettInfoConfirmSucc.LogID = 5014;
        log_SPIT_SettInfoConfirmSucc.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_SettInfoConfirmSucc.LogCode,"SPI_T_SettInfoConfirmSucc");
        std::strcpy(log_SPIT_SettInfoConfirmSucc.LogMsg,"[5014$SPI_T_SettInfoConfirmSucc]:CTP结算单信息确认成功");
        infoVector[5014]=log_SPIT_SettInfoConfirmSucc;
        
    
        SLog log_SPIT_SettInfoConfirmFail;
        log_SPIT_SettInfoConfirmFail.LogID = 5015;
        log_SPIT_SettInfoConfirmFail.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_SettInfoConfirmFail.LogCode,"SPI_T_SettInfoConfirmFail");
        std::strcpy(log_SPIT_SettInfoConfirmFail.LogMsg,"[5015$SPI_T_SettInfoConfirmFail]:CTP结算单信息确认失败");
        infoVector[5015]=log_SPIT_SettInfoConfirmFail;
        
    
        SLog log_SPIT_QryInstrumentSucc;
        log_SPIT_QryInstrumentSucc.LogID = 5016;
        log_SPIT_QryInstrumentSucc.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_QryInstrumentSucc.LogCode,"SPI_T_QryInstrumentSucc");
        std::strcpy(log_SPIT_QryInstrumentSucc.LogMsg,"[5016$SPI_T_QryInstrumentSucc]:查询CTP合约成功");
        infoVector[5016]=log_SPIT_QryInstrumentSucc;
        
    
        SLog log_SPIT_QryInstrumentFail;
        log_SPIT_QryInstrumentFail.LogID = 5017;
        log_SPIT_QryInstrumentFail.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_QryInstrumentFail.LogCode,"SPI_T_QryInstrumentFail");
        std::strcpy(log_SPIT_QryInstrumentFail.LogMsg,"[5017$SPI_T_QryInstrumentFail]:查询CTP合约失败");
        infoVector[5017]=log_SPIT_QryInstrumentFail;
        
    
        SLog log_SPIT_QryInstrumentFC;
        log_SPIT_QryInstrumentFC.LogID = 5018;
        log_SPIT_QryInstrumentFC.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_QryInstrumentFC.LogCode,"SPI_T_QryInstrumentFC");
        std::strcpy(log_SPIT_QryInstrumentFC.LogMsg,"[5018$SPI_T_QryInstrumentFC]:查询CTP合约受到流控");
        infoVector[5018]=log_SPIT_QryInstrumentFC;
        
    
        SLog log_SPIT_QryTradingAccountSucc;
        log_SPIT_QryTradingAccountSucc.LogID = 5019;
        log_SPIT_QryTradingAccountSucc.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_QryTradingAccountSucc.LogCode,"SPI_T_QryTradingAccountSucc");
        std::strcpy(log_SPIT_QryTradingAccountSucc.LogMsg,"[5019$SPI_T_QryTradingAccountSucc]:查询CTP资金账户成功");
        infoVector[5019]=log_SPIT_QryTradingAccountSucc;
        
    
        SLog log_SPIT_QryTradingAccountFail;
        log_SPIT_QryTradingAccountFail.LogID = 5020;
        log_SPIT_QryTradingAccountFail.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_QryTradingAccountFail.LogCode,"SPI_T_QryTradingAccountFail");
        std::strcpy(log_SPIT_QryTradingAccountFail.LogMsg,"[5020$SPI_T_QryTradingAccountFail]:查询CTP资金账户失败");
        infoVector[5020]=log_SPIT_QryTradingAccountFail;
        
    
        SLog log_SPIT_QryTradingAccountFC;
        log_SPIT_QryTradingAccountFC.LogID = 5021;
        log_SPIT_QryTradingAccountFC.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_QryTradingAccountFC.LogCode,"SPI_T_QryTradingAccountFC");
        std::strcpy(log_SPIT_QryTradingAccountFC.LogMsg,"[5021$SPI_T_QryTradingAccountFC]:查询CTP资金账户受到流控");
        infoVector[5021]=log_SPIT_QryTradingAccountFC;
        
    
        SLog log_SPIT_QryInvestorPositionSucc;
        log_SPIT_QryInvestorPositionSucc.LogID = 5022;
        log_SPIT_QryInvestorPositionSucc.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_QryInvestorPositionSucc.LogCode,"SPI_T_QryInvestorPositionSucc");
        std::strcpy(log_SPIT_QryInvestorPositionSucc.LogMsg,"[5022$SPI_T_QryInvestorPositionSucc]:查询CTP投资者持仓成功");
        infoVector[5022]=log_SPIT_QryInvestorPositionSucc;
        
    
        SLog log_SPIT_QryInvestorPositionFail;
        log_SPIT_QryInvestorPositionFail.LogID = 5023;
        log_SPIT_QryInvestorPositionFail.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_QryInvestorPositionFail.LogCode,"SPI_T_QryInvestorPositionFail");
        std::strcpy(log_SPIT_QryInvestorPositionFail.LogMsg,"[5023$SPI_T_QryInvestorPositionFail]:查询CTP投资者持仓失败");
        infoVector[5023]=log_SPIT_QryInvestorPositionFail;
        
    
        SLog log_SPIT_QryInvestorPositionFC;
        log_SPIT_QryInvestorPositionFC.LogID = 5024;
        log_SPIT_QryInvestorPositionFC.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_QryInvestorPositionFC.LogCode,"SPI_T_QryInvestorPositionFC");
        std::strcpy(log_SPIT_QryInvestorPositionFC.LogMsg,"[5024$SPI_T_QryInvestorPositionFC]:查询CTP投资者持仓受到流控");
        infoVector[5024]=log_SPIT_QryInvestorPositionFC;
        
    
        SLog log_SPIT_OrderInsertSucc;
        log_SPIT_OrderInsertSucc.LogID = 5025;
        log_SPIT_OrderInsertSucc.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_OrderInsertSucc.LogCode,"SPI_T_OrderInsertSucc");
        std::strcpy(log_SPIT_OrderInsertSucc.LogMsg,"[5025$SPI_T_OrderInsertSucc]:CTP报单录入成功");
        infoVector[5025]=log_SPIT_OrderInsertSucc;
        
    
        SLog log_SPIT_OrderInsertFail;
        log_SPIT_OrderInsertFail.LogID = 5026;
        log_SPIT_OrderInsertFail.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_OrderInsertFail.LogCode,"SPI_T_OrderInsertFail");
        std::strcpy(log_SPIT_OrderInsertFail.LogMsg,"[5026$SPI_T_OrderInsertFail]:CTP报单录入失败");
        infoVector[5026]=log_SPIT_OrderInsertFail;
        
    
        SLog log_SPIT_OrderActionSucc;
        log_SPIT_OrderActionSucc.LogID = 5027;
        log_SPIT_OrderActionSucc.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_OrderActionSucc.LogCode,"SPI_T_OrderActionSucc");
        std::strcpy(log_SPIT_OrderActionSucc.LogMsg,"[5027$SPI_T_OrderActionSucc]:CTP报单操作成功");
        infoVector[5027]=log_SPIT_OrderActionSucc;
        
    
        SLog log_SPIT_OrderActionFail;
        log_SPIT_OrderActionFail.LogID = 5028;
        log_SPIT_OrderActionFail.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_OrderActionFail.LogCode,"SPI_T_OrderActionFail");
        std::strcpy(log_SPIT_OrderActionFail.LogMsg,"[5028$SPI_T_OrderActionFail]:CTP报单操作失败");
        infoVector[5028]=log_SPIT_OrderActionFail;
        
    
        SLog log_SPIT_RtnOrder;
        log_SPIT_RtnOrder.LogID = 5029;
        log_SPIT_RtnOrder.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_RtnOrder.LogCode,"SPI_T_RtnOrder");
        std::strcpy(log_SPIT_RtnOrder.LogMsg,"[5029$SPI_T_RtnOrder]:收到CTP报单响应");
        infoVector[5029]=log_SPIT_RtnOrder;
        
    
        SLog log_SPIT_OrderCanceled;
        log_SPIT_OrderCanceled.LogID = 5030;
        log_SPIT_OrderCanceled.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_OrderCanceled.LogCode,"SPI_T_OrderCanceled");
        std::strcpy(log_SPIT_OrderCanceled.LogMsg,"[5030$SPI_T_OrderCanceled]:CTP撤单成功");
        infoVector[5030]=log_SPIT_OrderCanceled;
        
    
        SLog log_SPIT_RtnTrade;
        log_SPIT_RtnTrade.LogID = 5031;
        log_SPIT_RtnTrade.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_RtnTrade.LogCode,"SPI_T_RtnTrade");
        std::strcpy(log_SPIT_RtnTrade.LogMsg,"[5031$SPI_T_RtnTrade]:收到CTP成交响应");
        infoVector[5031]=log_SPIT_RtnTrade;
        
    
        SLog log_SPIT_HeartBeat;
        log_SPIT_HeartBeat.LogID = 5032;
        log_SPIT_HeartBeat.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_HeartBeat.LogCode,"SPI_T_HeartBeat");
        std::strcpy(log_SPIT_HeartBeat.LogMsg,"[5032$SPI_T_HeartBeat]:CTP心跳:%d");
        infoVector[5032]=log_SPIT_HeartBeat;
        
    
        SLog log_TCOREDS_RealFundSelectByInvestorIDFatal;
        log_TCOREDS_RealFundSelectByInvestorIDFatal.LogID = 6001;
        log_TCOREDS_RealFundSelectByInvestorIDFatal.LogLevel = LL_Debug;
        std::strcpy(log_TCOREDS_RealFundSelectByInvestorIDFatal.LogCode,"TCORE_DS_RealFundSelectByInvestorIDFatal");
        std::strcpy(log_TCOREDS_RealFundSelectByInvestorIDFatal.LogMsg,"[6001$TCORE_DS_RealFundSelectByInvestorIDFatal]:基于InvestorID定位RealFund失败");
        infoVector[6001]=log_TCOREDS_RealFundSelectByInvestorIDFatal;
        
    
        SLog log_TCOREDS_NotEnoughAvailableForOut;
        log_TCOREDS_NotEnoughAvailableForOut.LogID = 6002;
        log_TCOREDS_NotEnoughAvailableForOut.LogLevel = LL_Debug;
        std::strcpy(log_TCOREDS_NotEnoughAvailableForOut.LogCode,"TCORE_DS_NotEnoughAvailableForOut");
        std::strcpy(log_TCOREDS_NotEnoughAvailableForOut.LogMsg,"[6002$TCORE_DS_NotEnoughAvailableForOut]:用于出金的可用资金不足");
        infoVector[6002]=log_TCOREDS_NotEnoughAvailableForOut;
        
    
        SLog log_TCOREModelInIsNull;
        log_TCOREModelInIsNull.LogID = 6003;
        log_TCOREModelInIsNull.LogLevel = LL_Debug;
        std::strcpy(log_TCOREModelInIsNull.LogCode,"TCORE_ModelInIsNull");
        std::strcpy(log_TCOREModelInIsNull.LogMsg,"[6003$TCORE_ModelInIsNull]:送入的模型指针为空");
        infoVector[6003]=log_TCOREModelInIsNull;
        
    
        SLog log_TCOREDS_OrderReqSelectByLocalOrderIDFatal;
        log_TCOREDS_OrderReqSelectByLocalOrderIDFatal.LogID = 6004;
        log_TCOREDS_OrderReqSelectByLocalOrderIDFatal.LogLevel = LL_Debug;
        std::strcpy(log_TCOREDS_OrderReqSelectByLocalOrderIDFatal.LogCode,"TCORE_DS_OrderReqSelectByLocalOrderIDFatal");
        std::strcpy(log_TCOREDS_OrderReqSelectByLocalOrderIDFatal.LogMsg,"[6004$TCORE_DS_OrderReqSelectByLocalOrderIDFatal]:基于LocalOrderID定位OrderReq失败");
        infoVector[6004]=log_TCOREDS_OrderReqSelectByLocalOrderIDFatal;
        
    
        SLog log_TCOREDS_InstrumentSelectByInstrumentIDFatal;
        log_TCOREDS_InstrumentSelectByInstrumentIDFatal.LogID = 6005;
        log_TCOREDS_InstrumentSelectByInstrumentIDFatal.LogLevel = LL_Debug;
        std::strcpy(log_TCOREDS_InstrumentSelectByInstrumentIDFatal.LogCode,"TCORE_DS_InstrumentSelectByInstrumentIDFatal");
        std::strcpy(log_TCOREDS_InstrumentSelectByInstrumentIDFatal.LogMsg,"[6005$TCORE_DS_InstrumentSelectByInstrumentIDFatal]:基于InstrumentID定位Instrument失败");
        infoVector[6005]=log_TCOREDS_InstrumentSelectByInstrumentIDFatal;
        
    
        SLog log_TCOREDS_MarginRateSelectByInvestorIDInstrumentIDFatal;
        log_TCOREDS_MarginRateSelectByInvestorIDInstrumentIDFatal.LogID = 6006;
        log_TCOREDS_MarginRateSelectByInvestorIDInstrumentIDFatal.LogLevel = LL_Debug;
        std::strcpy(log_TCOREDS_MarginRateSelectByInvestorIDInstrumentIDFatal.LogCode,"TCORE_DS_MarginRateSelectByInvestorIDInstrumentIDFatal");
        std::strcpy(log_TCOREDS_MarginRateSelectByInvestorIDInstrumentIDFatal.LogMsg,"[6006$TCORE_DS_MarginRateSelectByInvestorIDInstrumentIDFatal]:基于InvestorID、InstrumentID定位MarginRate失败");
        infoVector[6006]=log_TCOREDS_MarginRateSelectByInvestorIDInstrumentIDFatal;
        
    
        SLog log_TCOREDS_FeeRateSelectByInvestorIDInstrumentIDFatal;
        log_TCOREDS_FeeRateSelectByInvestorIDInstrumentIDFatal.LogID = 6007;
        log_TCOREDS_FeeRateSelectByInvestorIDInstrumentIDFatal.LogLevel = LL_Debug;
        std::strcpy(log_TCOREDS_FeeRateSelectByInvestorIDInstrumentIDFatal.LogCode,"TCORE_DS_FeeRateSelectByInvestorIDInstrumentIDFatal");
        std::strcpy(log_TCOREDS_FeeRateSelectByInvestorIDInstrumentIDFatal.LogMsg,"[6007$TCORE_DS_FeeRateSelectByInvestorIDInstrumentIDFatal]:基于InvestorID、InstrumentID定位FeeRate失败");
        infoVector[6007]=log_TCOREDS_FeeRateSelectByInvestorIDInstrumentIDFatal;
        
    
        SLog log_TCOREDS_RealPositionSelectByInvestorIDInstrumentIDDirectionFatal;
        log_TCOREDS_RealPositionSelectByInvestorIDInstrumentIDDirectionFatal.LogID = 6008;
        log_TCOREDS_RealPositionSelectByInvestorIDInstrumentIDDirectionFatal.LogLevel = LL_Debug;
        std::strcpy(log_TCOREDS_RealPositionSelectByInvestorIDInstrumentIDDirectionFatal.LogCode,"TCORE_DS_RealPositionSelectByInvestorIDInstrumentIDDirectionFatal");
        std::strcpy(log_TCOREDS_RealPositionSelectByInvestorIDInstrumentIDDirectionFatal.LogMsg,"[6008$TCORE_DS_RealPositionSelectByInvestorIDInstrumentIDDirectionFatal]:基于InvestorID、InstrumentID定位RealPosition失败");
        infoVector[6008]=log_TCOREDS_RealPositionSelectByInvestorIDInstrumentIDDirectionFatal;
        
    
}
#endif//CSTDLOG_CPP_
		