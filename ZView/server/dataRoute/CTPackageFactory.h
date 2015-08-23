            
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CTPackageFactory.h
///@brief 声明 TPackage 拆包解包类
///@author xslt模型代码转换工具
///@date 2013-06-21T07:28:06.458Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "TPackage.h"

#ifndef CTPACKAGEFACTORY_H_
#define CTPACKAGEFACTORY_H_

namespace ZYSystem {
    class CTPackageFactory{
        public:
            
            ///@brief CTPackage转换为SLog
			///@param from CTPackage
            ///@param to SLog
            void toStructs(CTPackage* from,SLog* to);
 
            ///@brief SLog转换为CTPackage
			///@param from SLog
            ///@param to CTPackage
            void toCTP(SLog* from,CTPackage* to);
            
            ///@brief CTPackage转换为SMarketDataProvider
			///@param from CTPackage
            ///@param to SMarketDataProvider
            void toStructs(CTPackage* from,SMarketDataProvider* to);
 
            ///@brief SMarketDataProvider转换为CTPackage
			///@param from SMarketDataProvider
            ///@param to CTPackage
            void toCTP(SMarketDataProvider* from,CTPackage* to);
            
            ///@brief CTPackage转换为SInvestor
			///@param from CTPackage
            ///@param to SInvestor
            void toStructs(CTPackage* from,SInvestor* to);
 
            ///@brief SInvestor转换为CTPackage
			///@param from SInvestor
            ///@param to CTPackage
            void toCTP(SInvestor* from,CTPackage* to);
            
            ///@brief CTPackage转换为SMarketData
			///@param from CTPackage
            ///@param to SMarketData
            void toStructs(CTPackage* from,SMarketData* to);
 
            ///@brief SMarketData转换为CTPackage
			///@param from SMarketData
            ///@param to CTPackage
            void toCTP(SMarketData* from,CTPackage* to);
            
            ///@brief CTPackage转换为SKDJ
			///@param from CTPackage
            ///@param to SKDJ
            void toStructs(CTPackage* from,SKDJ* to);
 
            ///@brief SKDJ转换为CTPackage
			///@param from SKDJ
            ///@param to CTPackage
            void toCTP(SKDJ* from,CTPackage* to);
            
            ///@brief CTPackage转换为SMACD
			///@param from CTPackage
            ///@param to SMACD
            void toStructs(CTPackage* from,SMACD* to);
 
            ///@brief SMACD转换为CTPackage
			///@param from SMACD
            ///@param to CTPackage
            void toCTP(SMACD* from,CTPackage* to);
            
            ///@brief CTPackage转换为SModelConfigA
			///@param from CTPackage
            ///@param to SModelConfigA
            void toStructs(CTPackage* from,SModelConfigA* to);
 
            ///@brief SModelConfigA转换为CTPackage
			///@param from SModelConfigA
            ///@param to CTPackage
            void toCTP(SModelConfigA* from,CTPackage* to);
            
            ///@brief CTPackage转换为SOrderReq
			///@param from CTPackage
            ///@param to SOrderReq
            void toStructs(CTPackage* from,SOrderReq* to);
 
            ///@brief SOrderReq转换为CTPackage
			///@param from SOrderReq
            ///@param to CTPackage
            void toCTP(SOrderReq* from,CTPackage* to);
            
            ///@brief CTPackage转换为STrade
			///@param from CTPackage
            ///@param to STrade
            void toStructs(CTPackage* from,STrade* to);
 
            ///@brief STrade转换为CTPackage
			///@param from STrade
            ///@param to CTPackage
            void toCTP(STrade* from,CTPackage* to);
            
            ///@brief CTPackage转换为SRealPosition
			///@param from CTPackage
            ///@param to SRealPosition
            void toStructs(CTPackage* from,SRealPosition* to);
 
            ///@brief SRealPosition转换为CTPackage
			///@param from SRealPosition
            ///@param to CTPackage
            void toCTP(SRealPosition* from,CTPackage* to);
            
            ///@brief CTPackage转换为SRealFund
			///@param from CTPackage
            ///@param to SRealFund
            void toStructs(CTPackage* from,SRealFund* to);
 
            ///@brief SRealFund转换为CTPackage
			///@param from SRealFund
            ///@param to CTPackage
            void toCTP(SRealFund* from,CTPackage* to);
            
            ///@brief CTPackage转换为SSubInstrument
			///@param from CTPackage
            ///@param to SSubInstrument
            void toStructs(CTPackage* from,SSubInstrument* to);
 
            ///@brief SSubInstrument转换为CTPackage
			///@param from SSubInstrument
            ///@param to CTPackage
            void toCTP(SSubInstrument* from,CTPackage* to);
            
            ///@brief CTPackage转换为SSingnal
			///@param from CTPackage
            ///@param to SSingnal
            void toStructs(CTPackage* from,SSingnal* to);
 
            ///@brief SSingnal转换为CTPackage
			///@param from SSingnal
            ///@param to CTPackage
            void toCTP(SSingnal* from,CTPackage* to);
            
            ///@brief CTPackage转换为SInstrument
			///@param from CTPackage
            ///@param to SInstrument
            void toStructs(CTPackage* from,SInstrument* to);
 
            ///@brief SInstrument转换为CTPackage
			///@param from SInstrument
            ///@param to CTPackage
            void toCTP(SInstrument* from,CTPackage* to);
            
            ///@brief CTPackage转换为SRiskControler
			///@param from CTPackage
            ///@param to SRiskControler
            void toStructs(CTPackage* from,SRiskControler* to);
 
            ///@brief SRiskControler转换为CTPackage
			///@param from SRiskControler
            ///@param to CTPackage
            void toCTP(SRiskControler* from,CTPackage* to);
            
            ///@brief CTPackage转换为SMoneyChange
			///@param from CTPackage
            ///@param to SMoneyChange
            void toStructs(CTPackage* from,SMoneyChange* to);
 
            ///@brief SMoneyChange转换为CTPackage
			///@param from SMoneyChange
            ///@param to CTPackage
            void toCTP(SMoneyChange* from,CTPackage* to);
            
            ///@brief CTPackage转换为SNewTradingDay
			///@param from CTPackage
            ///@param to SNewTradingDay
            void toStructs(CTPackage* from,SNewTradingDay* to);
 
            ///@brief SNewTradingDay转换为CTPackage
			///@param from SNewTradingDay
            ///@param to CTPackage
            void toCTP(SNewTradingDay* from,CTPackage* to);
            
            ///@brief CTPackage转换为SOrderRsp
			///@param from CTPackage
            ///@param to SOrderRsp
            void toStructs(CTPackage* from,SOrderRsp* to);
 
            ///@brief SOrderRsp转换为CTPackage
			///@param from SOrderRsp
            ///@param to CTPackage
            void toCTP(SOrderRsp* from,CTPackage* to);
            
            ///@brief CTPackage转换为SMarginRate
			///@param from CTPackage
            ///@param to SMarginRate
            void toStructs(CTPackage* from,SMarginRate* to);
 
            ///@brief SMarginRate转换为CTPackage
			///@param from SMarginRate
            ///@param to CTPackage
            void toCTP(SMarginRate* from,CTPackage* to);
            
            ///@brief CTPackage转换为SFeeRate
			///@param from CTPackage
            ///@param to SFeeRate
            void toStructs(CTPackage* from,SFeeRate* to);
 
            ///@brief SFeeRate转换为CTPackage
			///@param from SFeeRate
            ///@param to CTPackage
            void toCTP(SFeeRate* from,CTPackage* to);
            
            ///@brief CTPackage转换为SLogConfig
			///@param from CTPackage
            ///@param to SLogConfig
            void toStructs(CTPackage* from,SLogConfig* to);
 
            ///@brief SLogConfig转换为CTPackage
			///@param from SLogConfig
            ///@param to CTPackage
            void toCTP(SLogConfig* from,CTPackage* to);
            
            
            ///@brief CTPackageFactory构造函数
            CTPackageFactory();
            
            ///@brief CTPackageFactory析构函数
            ~CTPackageFactory();
    };
}
#endif //CTPACKAGEFACTORY_H_
        