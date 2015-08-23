
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CStdLog.h
///@brief ��������־����࣬��־�����Ҫ��
///        1.�༶����־��������Կ��������Ҫ�ļ���
///		   2.������ɱ��ض����
///       CLogger��һ���������־�ӿڣ�����Ӧ�ó��������־
///       ����ȫ��ֻ��һ��ʵ����Ĭ��ʵ��Ϊ��stdout�����־��
///       Ӧ�ó�����Լ̳�CLogger��ʵ�����ѵ���־��
///@author xsltģ�ʹ���ת������
///@date 2013-06-21T07:28:20.031Z
////////////////////////////////////////////////////////////////////////
#pragma once

#include "../generate/Structs.h"

#ifndef CSTDLOG_H_
#define CSTDLOG_H_

///ҵ����־
///�Ƿ�ʹ��ҵ��״̬��־
extern bool ZYSystemMainLog;

#define Debug_Log(sz)                   ZYSystem::CStdLogger::GetInstance()->output(LL_Debug,"%s",sz)

#define LOG0(sz)					ZYSystem::CStdLogger::GetInstance()->outputInfo(sz)
#define LOG1(sz, p1)				ZYSystem::CStdLogger::GetInstance()->outputInfo(sz, p1)
#define LOG2(sz, p1, p2)			ZYSystem::CStdLogger::GetInstance()->outputInfo(sz, p1, p2)
#define LOG3(sz, p1, p2, p3)		ZYSystem::CStdLogger::GetInstance()->outputInfo(sz, p1, p2, p3)

///��־�ķ������������ͨ��ע�͵�����ĺ꣬��ɽ�ֹĳ����־�����

#define CHECK_LOG(logFlag,logCommand)      {if(logFlag) logCommand;}

///������־�Ŀ���
#define ZYSYSTEM_LOG0(sz)			CHECK_LOG(ZYSystemMainLog,LOG0(sz))
#define ZYSYSTEM_LOG1(sz,p1)		CHECK_LOG(ZYSystemMainLog,LOG1(sz,p1))
#define ZYSYSTEM_LOG2(sz,p1,p2)		CHECK_LOG(ZYSystemMainLog,LOG2(sz,p1,p2))
#define ZYSYSTEM_LOG3(sz,p1,p2,p3)	CHECK_LOG(ZYSystemMainLog,LOG3(sz,p1,p2,p3))

///��������
#define CHECK_SUCCESS(tid) if(tid!=SUCCESS) {ZYSYSTEM_LOG0(tid);return tid;}
#define CHECK_SUCCESS_NoRet(tid) if(tid!=SUCCESS) {ZYSYSTEM_LOG0(tid)}

namespace ZYSystem {
    class CStdLogger
    {
    private:
        ///@brief �ṹ����־�����
		boost::mutex mtxStruct;
    protected:
        ///@brief ��Ϣ�洢��
        std::hash_map<TID,SLog> infoVector;
        
        ///@brief ���캯��
        CStdLogger();
        
	    ///@brief ��������
        ~CStdLogger();

	    ///@brief CStdLoggerʵ��
	    static CStdLogger *m_pInstance;
    
    public:
        ///@brief ��־������Ϣ
	    static SLogConfig* logConfig;
    
        ///@brief ������־������Ϣ
        ///@param	logConfig_in ��־������Ϣ
	    static void setLogConfig(SLogConfig* logConfig_in);
    
	    ///@brief ��ȡCLoggerʵ��
	    ///@return ��ȡ��CLoggerʵ��
	    static CStdLogger* GetInstance();

	    ///@brief ������־���
	    ///@param	format	�����ʽkey
	    ///@param	...	����������
	    void outputInfo(int format,...);

	    ///@brief ������־���
	    ///@param	level	��־����ֵԽС������Խ��
	    ///@param	format	�����ʽ������printf�ĸ�ʽҪ��
	    ///@param	...	����������
	    virtual void output(TLogLevel level,char *format,...) = 0;
        
        ///@brief ������־���
	    ///@param	level	��־����ֵԽС������Խ��
	    ///@param	format	�����ʽ������printf�ĸ�ʽҪ��
	    ///@param	v	����������
	    virtual void outputVL(TLogLevel level,char *format,va_list v) = 0;


        ///@brief ��¼ ��־��Ϣ ��־
	    ///@param *in ����¼�� ��־��Ϣ ָ��
        void logSLog(SLog *in);

        ///@brief ��¼ �����ṩ�� ��־
	    ///@param *in ����¼�� �����ṩ�� ָ��
        void logSMarketDataProvider(SMarketDataProvider *in);

        ///@brief ��¼ Ͷ���� ��־
	    ///@param *in ����¼�� Ͷ���� ָ��
        void logSInvestor(SInvestor *in);

        ///@brief ��¼ ���� ��־
	    ///@param *in ����¼�� ���� ָ��
        void logSMarketData(SMarketData *in);

        ///@brief ��¼ KDJָ�� ��־
	    ///@param *in ����¼�� KDJָ�� ָ��
        void logSKDJ(SKDJ *in);

        ///@brief ��¼ MACDָ�� ��־
	    ///@param *in ����¼�� MACDָ�� ָ��
        void logSMACD(SMACD *in);

        ///@brief ��¼ ����ģ��A���� ��־
	    ///@param *in ����¼�� ����ģ��A���� ָ��
        void logSModelConfigA(SModelConfigA *in);

        ///@brief ��¼ �������� ��־
	    ///@param *in ����¼�� �������� ָ��
        void logSOrderReq(SOrderReq *in);

        ///@brief ��¼ �ɽ� ��־
	    ///@param *in ����¼�� �ɽ� ָ��
        void logSTrade(STrade *in);

        ///@brief ��¼ ���в�λ ��־
	    ///@param *in ����¼�� ���в�λ ָ��
        void logSRealPosition(SRealPosition *in);

        ///@brief ��¼ �����ʽ� ��־
	    ///@param *in ����¼�� �����ʽ� ָ��
        void logSRealFund(SRealFund *in);

        ///@brief ��¼ ���ĵĺ�Լ�� ��־
	    ///@param *in ����¼�� ���ĵĺ�Լ�� ָ��
        void logSSubInstrument(SSubInstrument *in);

        ///@brief ��¼ �����ź� ��־
	    ///@param *in ����¼�� �����ź� ָ��
        void logSSingnal(SSingnal *in);

        ///@brief ��¼ ��Լ ��־
	    ///@param *in ����¼�� ��Լ ָ��
        void logSInstrument(SInstrument *in);

        ///@brief ��¼ ���չ����� ��־
	    ///@param *in ����¼�� ���չ����� ָ��
        void logSRiskControler(SRiskControler *in);

        ///@brief ��¼ ����� ��־
	    ///@param *in ����¼�� ����� ָ��
        void logSMoneyChange(SMoneyChange *in);

        ///@brief ��¼ �½����� ��־
	    ///@param *in ����¼�� �½����� ָ��
        void logSNewTradingDay(SNewTradingDay *in);

        ///@brief ��¼ ������Ӧ ��־
	    ///@param *in ����¼�� ������Ӧ ָ��
        void logSOrderRsp(SOrderRsp *in);

        ///@brief ��¼ ��Լ��֤���� ��־
	    ///@param *in ����¼�� ��Լ��֤���� ָ��
        void logSMarginRate(SMarginRate *in);

        ///@brief ��¼ ��Լ�������� ��־
	    ///@param *in ����¼�� ��Լ�������� ָ��
        void logSFeeRate(SFeeRate *in);

        ///@brief ��¼ ��־������Ϣ ��־
	    ///@param *in ����¼�� ��־������Ϣ ָ��
        void logSLogConfig(SLogConfig *in);

    private:
        ///@brief ���ø��ֳ�����Ϣ
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
		