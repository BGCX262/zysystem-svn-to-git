            
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TEndPoint.h
///@brief 声明 TPackage 拆包解包类
///@author xslt模型代码转换工具
///@date 2013-06-21T07:28:10.28Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "CDataRoute.h"

#ifndef CTENDPOINT_H_
#define CTENDPOINT_H_

namespace ZYSystem {
    class CTEndPoint{
        protected:
            ///@brief 设置本地时间
			///@param time 本地时间
            inline virtual void setlocalTime(TDateTime time);
            
                
            ///@brief 发送SLog
			///@param from SLog
            inline virtual void sendTP(SLog* from);
                
            ///@brief 发送SMarketDataProvider
			///@param from SMarketDataProvider
            inline virtual void sendTP(SMarketDataProvider* from);
                
            ///@brief 发送SInvestor
			///@param from SInvestor
            inline virtual void sendTP(SInvestor* from);
                
            ///@brief 发送SMarketData
			///@param from SMarketData
            inline virtual void sendTP(SMarketData* from);
                
            ///@brief 发送SKDJ
			///@param from SKDJ
            inline virtual void sendTP(SKDJ* from);
                
            ///@brief 发送SMACD
			///@param from SMACD
            inline virtual void sendTP(SMACD* from);
                
            ///@brief 发送SModelConfigA
			///@param from SModelConfigA
            inline virtual void sendTP(SModelConfigA* from);
                
            ///@brief 发送SOrderReq
			///@param from SOrderReq
            inline virtual void sendTP(SOrderReq* from);
                
            ///@brief 发送STrade
			///@param from STrade
            inline virtual void sendTP(STrade* from);
                
            ///@brief 发送SRealPosition
			///@param from SRealPosition
            inline virtual void sendTP(SRealPosition* from);
                
            ///@brief 发送SRealFund
			///@param from SRealFund
            inline virtual void sendTP(SRealFund* from);
                
            ///@brief 发送SSubInstrument
			///@param from SSubInstrument
            inline virtual void sendTP(SSubInstrument* from);
                
            ///@brief 发送SSingnal
			///@param from SSingnal
            inline virtual void sendTP(SSingnal* from);
                
            ///@brief 发送SInstrument
			///@param from SInstrument
            inline virtual void sendTP(SInstrument* from);
                
            ///@brief 发送SRiskControler
			///@param from SRiskControler
            inline virtual void sendTP(SRiskControler* from);
                
            ///@brief 发送SMoneyChange
			///@param from SMoneyChange
            inline virtual void sendTP(SMoneyChange* from);
                
            ///@brief 发送SNewTradingDay
			///@param from SNewTradingDay
            inline virtual void sendTP(SNewTradingDay* from);
                
            ///@brief 发送SOrderRsp
			///@param from SOrderRsp
            inline virtual void sendTP(SOrderRsp* from);
                
            ///@brief 发送SMarginRate
			///@param from SMarginRate
            inline virtual void sendTP(SMarginRate* from);
                
            ///@brief 发送SFeeRate
			///@param from SFeeRate
            inline virtual void sendTP(SFeeRate* from);
                
            ///@brief 发送SLogConfig
			///@param from SLogConfig
            inline virtual void sendTP(SLogConfig* from);
            
        public:
            ///@brief CTEndPoint构造函数
            CTEndPoint();
            
            ///@brief CTEndPoint析构函数
            ~CTEndPoint();
    };
}
#endif //CTENDPOINT_H_
        