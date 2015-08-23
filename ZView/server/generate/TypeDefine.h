
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TypeDefine.h
///@brief ���ڶ���ZY System�Ļ����������ͣ����ڳ������ɣ���Ҫ�ֹ��޸�
///@author xsltģ�ʹ���ת������
///@date 2013-06-21T07:28:24.882Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "../System.h"

#ifndef TYPE_DEFINE_H
#define TYPE_DEFINE_H

namespace ZYSystem {
    typedef unsigned int TCount;
            
    ///@typedef char TDate[9]
    ///@brief ����
    typedef char TDate[9];
            
    ///@typedef char TTime[9]
    ///@brief ʱ��
    typedef char TTime[9];
            
    ///@typedef char TDateTime[16]
    ///@brief ����ʱ��
    typedef char TDateTime[16];
            
    ///@typedef char TURL[121]
    ///@brief �����ַ���
    typedef char TURL[121];
            
    ///@typedef char TInstrumentIDs[301]
    ///@brief ��Լ���봮�����ڶ��ĺ�Լ
    typedef char TInstrumentIDs[301];
            
    ///@typedef char TFile[257]
    ///@brief �ļ�·���������ļ���
    typedef char TFile[257];
            
    ///@typedef char TXPath[81]
    ///@brief XPath��ѯ�ַ���
    typedef char TXPath[81];
            
    ///@typedef char TXPathValue[61]
    ///@brief XPath��ѯ����ֵ
    typedef char TXPathValue[61];
            
    ///@typedef char TPath[201]
    ///@brief ·�����������ļ���
    typedef char TPath[201];
            
    ///@typedef char TMemo[257]
    ///@brief ��ע
    typedef char TMemo[257];
            
    ///@typedef char TCode[51]
    ///@brief ����
    typedef char TCode[51];
            
    ///@typedef char TExchangeID[9]
    ///@brief ����������
    typedef char TExchangeID[9];
            
    ///@typedef char TInstrumentID[31]
    ///@brief ��Լ����
    typedef char TInstrumentID[31];
            
    ///@typedef char TConnectionID[11]
    ///@brief ���Ӵ���
    typedef char TConnectionID[11];
            
    ///@typedef char TBrokerID[11]
    ///@brief ���͹�˾����
    typedef char TBrokerID[11];
            
    ///@typedef char TInvestorID[13]
    ///@brief Ͷ���ߴ���
    typedef char TInvestorID[13];
            
    ///@typedef char TPassword[41]
    ///@brief ����
    typedef char TPassword[41];
            
    ///@typedef int TID
    ///@brief Ψһ���
    typedef int TID;
            
    ///@typedef int TPID
    ///@brief ��Ϣ��������ʶ����
    typedef int TPID;
            
    ///@typedef int TPLength
    ///@brief ��Ϣ������
    typedef int TPLength;
            
    ///@typedef int TQueueIndex
    ///@brief ��Ϣ���е�����
    typedef int TQueueIndex;
            
    ///@typedef int TLocalOrderID
    ///@brief ���ر������
    typedef int TLocalOrderID;
            
    ///@typedef int TVolume
    ///@brief ����
    typedef int TVolume;
            
    ///@typedef int TMillisec
    ///@brief ����
    typedef int TMillisec;
            
    ///@typedef int TTimeCycle
    ///@brief ʱ�����ű���(��)
    typedef int TTimeCycle;
            
    ///@typedef double TRatio
    ///@brief ����
    typedef double TRatio;
            
    ///@typedef double TMoney
    ///@brief �ʽ�
    typedef double TMoney;
            
    ///@typedef double TPrice
    ///@brief �۸�
    typedef double TPrice;
            
    ///@typedef double TLargeVolume
    ///@brief �������
    typedef double TLargeVolume;
            
    ///@typedef double TIndexValue
    ///@brief ����ģ�͵�ָ��
    typedef double TIndexValue;
            
    ///@typedef enum TMarketDataType
    ///@brief ������Դ����
    enum TMarketDataType  {
        MDT_Sfit = 1, /**< ���ڼ���*/          
        MDT_His = 2, /**< ��ʷ��������*/          
        MDT_Sim = 3, /**< ģ�⽻��*/          
        MDT_OnlyMD = 4, /**< ��������*/          
        MDT_defaultValue = 0
    };
            
    ///@typedef enum TDirection
    ///@brief ��������
    enum TDirection  {
        D_Buy = 0, /**< ��*/          
        D_Sell = 1, /**< ��*/          
        D_defaultValue = 0
    };
            
    ///@typedef enum TOffsetFlag
    ///@brief ��ƽ��־
    enum TOffsetFlag  {
        OF_Open = 0, /**< ����*/          
        OF_Close = 1, /**< ƽ��*/          
        OF_ForceClose = 2, /**< ǿƽ*/          
        OF_CloseToday = 3, /**< ƽ��*/          
        OF_CloseYesterday = 4, /**< ƽ��*/          
        OF_ForceOff = 5, /**< ǿ��*/          
        OF_LocalForceClose = 6, /**< ����ǿƽ*/          
        OF_defaultValue = 0
    };
            
    ///@typedef enum THedgeFlag
    ///@brief Ͷ���ױ���־
    enum THedgeFlag  {
        HF_Speculation = 1, /**< Ͷ��*/          
        HF_Arbitrage = 2, /**< ����*/          
        HF_Hedge = 3, /**< �ױ�*/          
        HF_defaultValue = 0
    };
            
    ///@typedef enum TModelType
    ///@brief ģ������
    enum TModelType  {
        MT_A = 1, /**< ģ��A*/          
        MT_defaultValue = 0
    };
            
    ///@typedef enum TRunModel
    ///@brief ����ģʽ
    enum TRunModel  {
        RM_Normal = 1, /**< ��������*/          
        RM_Receive = 2, /**< �������*/          
        RM_Repeat = 3, /**< ����*/          
        RM_defaultValue = 0
    };
            
    ///@typedef enum TLogLevel
    ///@brief ��־�������
    enum TLogLevel  {
        LL_SysHalt = 0, /**< ϵͳʧ��*/          
        LL_Alert = 1, /**< ϵͳ����*/          
        LL_Error = 2, /**< ���д���*/          
        LL_Warning = 3, /**< ���о���*/          
        LL_Info = 4, /**< ������Ϣ*/          
        LL_Debug = 5, /**< ������Ϣ*/          
        LL_defaultValue = 0
    };
            
    ///@typedef enum TFundDirection
    ///@brief �������
    enum TFundDirection  {
        FD_In = 1, /**< ���*/          
        FD_Out = 2, /**< ����*/          
        FD_defaultValue = 0
    };
            
    ///@typedef enum TSingnalReason
    ///@brief �����ź���Դ
    enum TSingnalReason  {
        SR_RiskControler = 1, /**< ���տ���*/          
        SR_ModelA = 2, /**< ����ģ��A*/          
        SR_defaultValue = 0
    };
            
    ///@typedef enum TOrderStatus
    ///@brief ����״̬
    enum TOrderStatus  {
        OST_AllTraded = 0, /**< ȫ���ɽ�*/          
        OST_PartTradedQueueing = 1, /**< ���ֳɽ����ڶ�����*/          
        OST_PartTradedNotQueueing = 2, /**< ���ֳɽ����ڶ�����*/          
        OST_NoTradeQueueing = 3, /**< δ�ɽ����ڶ�����*/          
        OST_NoTradeNotQueueing = 4, /**< δ�ɽ����ڶ�����*/          
        OST_Canceled = 5, /**< ����*/          
        OST_Unknown = 6, /**< δ֪*/          
        OST_NotTouched = 7, /**< ��δ����*/          
        OST_Touched = 8, /**< �Ѵ���*/          
        OST_defaultValue = 0
    };
            
    ///@typedef enum TOrderSubmitStatus
    ///@brief �����ύ״̬
    enum TOrderSubmitStatus  {
        OSS_InsertSubmitted = 0, /**< �Ѿ��ύ*/          
        OSS_CancelSubmitted = 1, /**< �����Ѿ��ύ*/          
        OSS_ModifySubmitted = 2, /**< �޸��Ѿ��ύ*/          
        OSS_Accepted = 3, /**< �Ѿ�����*/          
        OSS_InsertRejected = 4, /**< �����Ѿ����ܾ�*/          
        OSS_CancelRejected = 5, /**< �����Ѿ����ܾ�*/          
        OSS_ModifyRejected = 6, /**< �ĵ��Ѿ����ܾ�*/          
        OSS_defaultValue = 0
    };
            
    ///@typedef enum TLogOutputType
    ///@brief �����ύ״̬
    enum TLogOutputType  {
        LOT_ScreenOutput = 1, /**< ��Ļ���*/          
        LOT_FileOutput = 2, /**< �ļ����*/          
        LOT_defaultValue = 0
    };
            
}
#endif // TYPE_DEFINE_H
        