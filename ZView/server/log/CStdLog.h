
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CStdLog.h
///@brief 定义了日志输出类，日志的输出要求
///        1.多级别日志输出，可以控制输出需要的级别
///		   2.输出流可被重定向的
///       CLogger是一个抽象的日志接口，用于应用程序输出日志
///       它在全局只有一个实例，默认实例为向stdout输出日志，
///       应用程序可以继承CLogger，实现自已的日志类
///@author xslt模型代码转换工具
///@date 2013-06-21T07:28:20.031Z
////////////////////////////////////////////////////////////////////////
#pragma once

#include "../generate/Structs.h"

#ifndef CSTDLOG_H_
#define CSTDLOG_H_

///业务日志
///是否使用业务状态日志
extern bool ZYSystemMainLog;

#define Debug_Log(sz)                   ZYSystem::CStdLogger::GetInstance()->output(LL_Debug,"%s",sz)

#define LOG0(sz)					ZYSystem::CStdLogger::GetInstance()->outputInfo(sz)
#define LOG1(sz, p1)				ZYSystem::CStdLogger::GetInstance()->outputInfo(sz, p1)
#define LOG2(sz, p1, p2)			ZYSystem::CStdLogger::GetInstance()->outputInfo(sz, p1, p2)
#define LOG3(sz, p1, p2, p3)		ZYSystem::CStdLogger::GetInstance()->outputInfo(sz, p1, p2, p3)

///日志的分类情况，可以通过注释掉下面的宏，完成禁止某项日志的输出

#define CHECK_LOG(logFlag,logCommand)      {if(logFlag) logCommand;}

///各组日志的控制
#define ZYSYSTEM_LOG0(sz)			CHECK_LOG(ZYSystemMainLog,LOG0(sz))
#define ZYSYSTEM_LOG1(sz,p1)		CHECK_LOG(ZYSystemMainLog,LOG1(sz,p1))
#define ZYSYSTEM_LOG2(sz,p1,p2)		CHECK_LOG(ZYSystemMainLog,LOG2(sz,p1,p2))
#define ZYSYSTEM_LOG3(sz,p1,p2,p3)	CHECK_LOG(ZYSystemMainLog,LOG3(sz,p1,p2,p3))

///错误码检查
#define CHECK_SUCCESS(tid) if(tid!=SUCCESS) {ZYSYSTEM_LOG0(tid);return tid;}
#define CHECK_SUCCESS_NoRet(tid) if(tid!=SUCCESS) {ZYSYSTEM_LOG0(tid)}

namespace ZYSystem {
    class CStdLogger
    {
    private:
        ///@brief 结构体日志输出锁
		boost::mutex mtxStruct;
    protected:
        ///@brief 信息存储体
        std::hash_map<TID,SLog> infoVector;
        
        ///@brief 构造函数
        CStdLogger();
        
	    ///@brief 析构函数
        ~CStdLogger();

	    ///@brief CStdLogger实例
	    static CStdLogger *m_pInstance;
    
    public:
        ///@brief 日志配置信息
	    static SLogConfig* logConfig;
    
        ///@brief 设置日志配置信息
        ///@param	logConfig_in 日志配置信息
	    static void setLogConfig(SLogConfig* logConfig_in);
    
	    ///@brief 获取CLogger实例
	    ///@return 获取的CLogger实例
	    static CStdLogger* GetInstance();

	    ///@brief 进行日志输出
	    ///@param	format	输出格式key
	    ///@param	...	具体的输出项
	    void outputInfo(int format,...);

	    ///@brief 进行日志输出
	    ///@param	level	日志级别，值越小，级别越高
	    ///@param	format	输出格式，按照printf的格式要求
	    ///@param	...	具体的输出项
	    virtual void output(TLogLevel level,char *format,...) = 0;
        
        ///@brief 进行日志输出
	    ///@param	level	日志级别，值越小，级别越高
	    ///@param	format	输出格式，按照printf的格式要求
	    ///@param	v	具体的输出项
	    virtual void outputVL(TLogLevel level,char *format,va_list v) = 0;


        ///@brief 记录 日志信息 日志
	    ///@param *in 被记录的 日志信息 指针
        void logSLog(SLog *in);

        ///@brief 记录 行情提供者 日志
	    ///@param *in 被记录的 行情提供者 指针
        void logSMarketDataProvider(SMarketDataProvider *in);

        ///@brief 记录 投资者 日志
	    ///@param *in 被记录的 投资者 指针
        void logSInvestor(SInvestor *in);

        ///@brief 记录 行情 日志
	    ///@param *in 被记录的 行情 指针
        void logSMarketData(SMarketData *in);

        ///@brief 记录 KDJ指标 日志
	    ///@param *in 被记录的 KDJ指标 指针
        void logSKDJ(SKDJ *in);

        ///@brief 记录 MACD指标 日志
	    ///@param *in 被记录的 MACD指标 指针
        void logSMACD(SMACD *in);

        ///@brief 记录 计算模型A配置 日志
	    ///@param *in 被记录的 计算模型A配置 指针
        void logSModelConfigA(SModelConfigA *in);

        ///@brief 记录 报单请求 日志
	    ///@param *in 被记录的 报单请求 指针
        void logSOrderReq(SOrderReq *in);

        ///@brief 记录 成交 日志
	    ///@param *in 被记录的 成交 指针
        void logSTrade(STrade *in);

        ///@brief 记录 盘中仓位 日志
	    ///@param *in 被记录的 盘中仓位 指针
        void logSRealPosition(SRealPosition *in);

        ///@brief 记录 盘中资金 日志
	    ///@param *in 被记录的 盘中资金 指针
        void logSRealFund(SRealFund *in);

        ///@brief 记录 订阅的合约包 日志
	    ///@param *in 被记录的 订阅的合约包 指针
        void logSSubInstrument(SSubInstrument *in);

        ///@brief 记录 交易信号 日志
	    ///@param *in 被记录的 交易信号 指针
        void logSSingnal(SSingnal *in);

        ///@brief 记录 合约 日志
	    ///@param *in 被记录的 合约 指针
        void logSInstrument(SInstrument *in);

        ///@brief 记录 风险管理器 日志
	    ///@param *in 被记录的 风险管理器 指针
        void logSRiskControler(SRiskControler *in);

        ///@brief 记录 出入金 日志
	    ///@param *in 被记录的 出入金 指针
        void logSMoneyChange(SMoneyChange *in);

        ///@brief 记录 新交易日 日志
	    ///@param *in 被记录的 新交易日 指针
        void logSNewTradingDay(SNewTradingDay *in);

        ///@brief 记录 报单响应 日志
	    ///@param *in 被记录的 报单响应 指针
        void logSOrderRsp(SOrderRsp *in);

        ///@brief 记录 合约保证金率 日志
	    ///@param *in 被记录的 合约保证金率 指针
        void logSMarginRate(SMarginRate *in);

        ///@brief 记录 合约手续费率 日志
	    ///@param *in 被记录的 合约手续费率 指针
        void logSFeeRate(SFeeRate *in);

        ///@brief 记录 日志配置信息 日志
	    ///@param *in 被记录的 日志配置信息 指针
        void logSLogConfig(SLogConfig *in);

    private:
        ///@brief 设置各种出错信息
        void setOutputLogInfo();
    };
}


#define  LOG_SLog(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSLog(in))

#define  LOG_SMarketDataProvider(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSMarketDataProvider(in))

#define  LOG_SInvestor(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSInvestor(in))

#define  LOG_SMarketData(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSMarketData(in))

#define  LOG_SKDJ(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSKDJ(in))

#define  LOG_SMACD(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSMACD(in))

#define  LOG_SModelConfigA(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSModelConfigA(in))

#define  LOG_SOrderReq(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSOrderReq(in))

#define  LOG_STrade(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSTrade(in))

#define  LOG_SRealPosition(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSRealPosition(in))

#define  LOG_SRealFund(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSRealFund(in))

#define  LOG_SSubInstrument(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSSubInstrument(in))

#define  LOG_SSingnal(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSSingnal(in))

#define  LOG_SInstrument(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSInstrument(in))

#define  LOG_SRiskControler(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSRiskControler(in))

#define  LOG_SMoneyChange(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSMoneyChange(in))

#define  LOG_SNewTradingDay(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSNewTradingDay(in))

#define  LOG_SOrderRsp(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSOrderRsp(in))

#define  LOG_SMarginRate(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSMarginRate(in))

#define  LOG_SFeeRate(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSFeeRate(in))

#define  LOG_SLogConfig(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logSLogConfig(in))


#endif
		