
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TypeDefine.h
///@brief 用于定义ZY System的基础数据类型，基于程序生成，不要手工修改
///@author xslt模型代码转换工具
///@date 2013-06-21T07:28:24.882Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "../System.h"

#ifndef TYPE_DEFINE_H
#define TYPE_DEFINE_H

namespace ZYSystem {
    typedef unsigned int TCount;
            
    ///@typedef char TDate[9]
    ///@brief 日期
    typedef char TDate[9];
            
    ///@typedef char TTime[9]
    ///@brief 时间
    typedef char TTime[9];
            
    ///@typedef char TDateTime[16]
    ///@brief 日期时间
    typedef char TDateTime[16];
            
    ///@typedef char TURL[121]
    ///@brief 连接字符串
    typedef char TURL[121];
            
    ///@typedef char TInstrumentIDs[301]
    ///@brief 合约代码串，用于订阅合约
    typedef char TInstrumentIDs[301];
            
    ///@typedef char TFile[257]
    ///@brief 文件路径，包含文件名
    typedef char TFile[257];
            
    ///@typedef char TXPath[81]
    ///@brief XPath查询字符串
    typedef char TXPath[81];
            
    ///@typedef char TXPathValue[61]
    ///@brief XPath查询返回值
    typedef char TXPathValue[61];
            
    ///@typedef char TPath[201]
    ///@brief 路径，包含不文件名
    typedef char TPath[201];
            
    ///@typedef char TMemo[257]
    ///@brief 备注
    typedef char TMemo[257];
            
    ///@typedef char TCode[51]
    ///@brief 代码
    typedef char TCode[51];
            
    ///@typedef char TExchangeID[9]
    ///@brief 交易所代码
    typedef char TExchangeID[9];
            
    ///@typedef char TInstrumentID[31]
    ///@brief 合约代码
    typedef char TInstrumentID[31];
            
    ///@typedef char TConnectionID[11]
    ///@brief 连接代码
    typedef char TConnectionID[11];
            
    ///@typedef char TBrokerID[11]
    ///@brief 经纪公司代码
    typedef char TBrokerID[11];
            
    ///@typedef char TInvestorID[13]
    ///@brief 投资者代码
    typedef char TInvestorID[13];
            
    ///@typedef char TPassword[41]
    ///@brief 密码
    typedef char TPassword[41];
            
    ///@typedef int TID
    ///@brief 唯一序号
    typedef int TID;
            
    ///@typedef int TPID
    ///@brief 消息包的类型识别码
    typedef int TPID;
            
    ///@typedef int TPLength
    ///@brief 消息包长度
    typedef int TPLength;
            
    ///@typedef int TQueueIndex
    ///@brief 消息队列的索引
    typedef int TQueueIndex;
            
    ///@typedef int TLocalOrderID
    ///@brief 本地报单编号
    typedef int TLocalOrderID;
            
    ///@typedef int TVolume
    ///@brief 数量
    typedef int TVolume;
            
    ///@typedef int TMillisec
    ///@brief 毫秒
    typedef int TMillisec;
            
    ///@typedef int TTimeCycle
    ///@brief 时间缩放比例(秒)
    typedef int TTimeCycle;
            
    ///@typedef double TRatio
    ///@brief 比率
    typedef double TRatio;
            
    ///@typedef double TMoney
    ///@brief 资金
    typedef double TMoney;
            
    ///@typedef double TPrice
    ///@brief 价格
    typedef double TPrice;
            
    ///@typedef double TLargeVolume
    ///@brief 大额数量
    typedef double TLargeVolume;
            
    ///@typedef double TIndexValue
    ///@brief 计算模型的指标
    typedef double TIndexValue;
            
    ///@typedef enum TMarketDataType
    ///@brief 行情来源类型
    enum TMarketDataType  {
        MDT_Sfit = 1, /**< 上期技术*/          
        MDT_His = 2, /**< 历史行情重演*/          
        MDT_Sim = 3, /**< 模拟交易*/          
        MDT_OnlyMD = 4, /**< 仅收行情*/          
        MDT_defaultValue = 0
    };
            
    ///@typedef enum TDirection
    ///@brief 买卖方向
    enum TDirection  {
        D_Buy = 0, /**< 买*/          
        D_Sell = 1, /**< 卖*/          
        D_defaultValue = 0
    };
            
    ///@typedef enum TOffsetFlag
    ///@brief 开平标志
    enum TOffsetFlag  {
        OF_Open = 0, /**< 开仓*/          
        OF_Close = 1, /**< 平仓*/          
        OF_ForceClose = 2, /**< 强平*/          
        OF_CloseToday = 3, /**< 平今*/          
        OF_CloseYesterday = 4, /**< 平昨*/          
        OF_ForceOff = 5, /**< 强减*/          
        OF_LocalForceClose = 6, /**< 本地强平*/          
        OF_defaultValue = 0
    };
            
    ///@typedef enum THedgeFlag
    ///@brief 投机套保标志
    enum THedgeFlag  {
        HF_Speculation = 1, /**< 投机*/          
        HF_Arbitrage = 2, /**< 套利*/          
        HF_Hedge = 3, /**< 套保*/          
        HF_defaultValue = 0
    };
            
    ///@typedef enum TModelType
    ///@brief 模型类型
    enum TModelType  {
        MT_A = 1, /**< 模型A*/          
        MT_defaultValue = 0
    };
            
    ///@typedef enum TRunModel
    ///@brief 运行模式
    enum TRunModel  {
        RM_Normal = 1, /**< 正常交易*/          
        RM_Receive = 2, /**< 行情接收*/          
        RM_Repeat = 3, /**< 重演*/          
        RM_defaultValue = 0
    };
            
    ///@typedef enum TLogLevel
    ///@brief 日志输出级别
    enum TLogLevel  {
        LL_SysHalt = 0, /**< 系统失败*/          
        LL_Alert = 1, /**< 系统警报*/          
        LL_Error = 2, /**< 运行错误*/          
        LL_Warning = 3, /**< 运行警告*/          
        LL_Info = 4, /**< 运行信息*/          
        LL_Debug = 5, /**< 调试信息*/          
        LL_defaultValue = 0
    };
            
    ///@typedef enum TFundDirection
    ///@brief 出入金方向
    enum TFundDirection  {
        FD_In = 1, /**< 入金*/          
        FD_Out = 2, /**< 出金*/          
        FD_defaultValue = 0
    };
            
    ///@typedef enum TSingnalReason
    ///@brief 交易信号来源
    enum TSingnalReason  {
        SR_RiskControler = 1, /**< 风险控制*/          
        SR_ModelA = 2, /**< 交易模型A*/          
        SR_defaultValue = 0
    };
            
    ///@typedef enum TOrderStatus
    ///@brief 报单状态
    enum TOrderStatus  {
        OST_AllTraded = 0, /**< 全部成交*/          
        OST_PartTradedQueueing = 1, /**< 部分成交还在队列中*/          
        OST_PartTradedNotQueueing = 2, /**< 部分成交不在队列中*/          
        OST_NoTradeQueueing = 3, /**< 未成交还在队列中*/          
        OST_NoTradeNotQueueing = 4, /**< 未成交不在队列中*/          
        OST_Canceled = 5, /**< 撤单*/          
        OST_Unknown = 6, /**< 未知*/          
        OST_NotTouched = 7, /**< 尚未触发*/          
        OST_Touched = 8, /**< 已触发*/          
        OST_defaultValue = 0
    };
            
    ///@typedef enum TOrderSubmitStatus
    ///@brief 报单提交状态
    enum TOrderSubmitStatus  {
        OSS_InsertSubmitted = 0, /**< 已经提交*/          
        OSS_CancelSubmitted = 1, /**< 撤单已经提交*/          
        OSS_ModifySubmitted = 2, /**< 修改已经提交*/          
        OSS_Accepted = 3, /**< 已经接受*/          
        OSS_InsertRejected = 4, /**< 报单已经被拒绝*/          
        OSS_CancelRejected = 5, /**< 撤单已经被拒绝*/          
        OSS_ModifyRejected = 6, /**< 改单已经被拒绝*/          
        OSS_defaultValue = 0
    };
            
    ///@typedef enum TLogOutputType
    ///@brief 报单提交状态
    enum TLogOutputType  {
        LOT_ScreenOutput = 1, /**< 屏幕输出*/          
        LOT_FileOutput = 2, /**< 文件输出*/          
        LOT_defaultValue = 0
    };
            
}
#endif // TYPE_DEFINE_H
        