            
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CTPackageFactory.h
///@brief ���� TPackage ��������
///@author xsltģ�ʹ���ת������
///@date 2013-06-21T07:28:06.458Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "TPackage.h"

#ifndef CTPACKAGEFACTORY_H_
#define CTPACKAGEFACTORY_H_

namespace ZYSystem {
    class CTPackageFactory{
        public:
            
            ///@brief CTPackageת��ΪSLog
			///@param from CTPackage
            ///@param to SLog
            void toStructs(CTPackage* from,SLog* to);
 
            ///@brief SLogת��ΪCTPackage
			///@param from SLog
            ///@param to CTPackage
            void toCTP(SLog* from,CTPackage* to);
            
            ///@brief CTPackageת��ΪSMarketDataProvider
			///@param from CTPackage
            ///@param to SMarketDataProvider
            void toStructs(CTPackage* from,SMarketDataProvider* to);
 
            ///@brief SMarketDataProviderת��ΪCTPackage
			///@param from SMarketDataProvider
            ///@param to CTPackage
            void toCTP(SMarketDataProvider* from,CTPackage* to);
            
            ///@brief CTPackageת��ΪSInvestor
			///@param from CTPackage
            ///@param to SInvestor
            void toStructs(CTPackage* from,SInvestor* to);
 
            ///@brief SInvestorת��ΪCTPackage
			///@param from SInvestor
            ///@param to CTPackage
            void toCTP(SInvestor* from,CTPackage* to);
            
            ///@brief CTPackageת��ΪSMarketData
			///@param from CTPackage
            ///@param to SMarketData
            void toStructs(CTPackage* from,SMarketData* to);
 
            ///@brief SMarketDataת��ΪCTPackage
			///@param from SMarketData
            ///@param to CTPackage
            void toCTP(SMarketData* from,CTPackage* to);
            
            ///@brief CTPackageת��ΪSKDJ
			///@param from CTPackage
            ///@param to SKDJ
            void toStructs(CTPackage* from,SKDJ* to);
 
            ///@brief SKDJת��ΪCTPackage
			///@param from SKDJ
            ///@param to CTPackage
            void toCTP(SKDJ* from,CTPackage* to);
            
            ///@brief CTPackageת��ΪSMACD
			///@param from CTPackage
            ///@param to SMACD
            void toStructs(CTPackage* from,SMACD* to);
 
            ///@brief SMACDת��ΪCTPackage
			///@param from SMACD
            ///@param to CTPackage
            void toCTP(SMACD* from,CTPackage* to);
            
            ///@brief CTPackageת��ΪSModelConfigA
			///@param from CTPackage
            ///@param to SModelConfigA
            void toStructs(CTPackage* from,SModelConfigA* to);
 
            ///@brief SModelConfigAת��ΪCTPackage
			///@param from SModelConfigA
            ///@param to CTPackage
            void toCTP(SModelConfigA* from,CTPackage* to);
            
            ///@brief CTPackageת��ΪSOrderReq
			///@param from CTPackage
            ///@param to SOrderReq
            void toStructs(CTPackage* from,SOrderReq* to);
 
            ///@brief SOrderReqת��ΪCTPackage
			///@param from SOrderReq
            ///@param to CTPackage
            void toCTP(SOrderReq* from,CTPackage* to);
            
            ///@brief CTPackageת��ΪSTrade
			///@param from CTPackage
            ///@param to STrade
            void toStructs(CTPackage* from,STrade* to);
 
            ///@brief STradeת��ΪCTPackage
			///@param from STrade
            ///@param to CTPackage
            void toCTP(STrade* from,CTPackage* to);
            
            ///@brief CTPackageת��ΪSRealPosition
			///@param from CTPackage
            ///@param to SRealPosition
            void toStructs(CTPackage* from,SRealPosition* to);
 
            ///@brief SRealPositionת��ΪCTPackage
			///@param from SRealPosition
            ///@param to CTPackage
            void toCTP(SRealPosition* from,CTPackage* to);
            
            ///@brief CTPackageת��ΪSRealFund
			///@param from CTPackage
            ///@param to SRealFund
            void toStructs(CTPackage* from,SRealFund* to);
 
            ///@brief SRealFundת��ΪCTPackage
			///@param from SRealFund
            ///@param to CTPackage
            void toCTP(SRealFund* from,CTPackage* to);
            
            ///@brief CTPackageת��ΪSSubInstrument
			///@param from CTPackage
            ///@param to SSubInstrument
            void toStructs(CTPackage* from,SSubInstrument* to);
 
            ///@brief SSubInstrumentת��ΪCTPackage
			///@param from SSubInstrument
            ///@param to CTPackage
            void toCTP(SSubInstrument* from,CTPackage* to);
            
            ///@brief CTPackageת��ΪSSingnal
			///@param from CTPackage
            ///@param to SSingnal
            void toStructs(CTPackage* from,SSingnal* to);
 
            ///@brief SSingnalת��ΪCTPackage
			///@param from SSingnal
            ///@param to CTPackage
            void toCTP(SSingnal* from,CTPackage* to);
            
            ///@brief CTPackageת��ΪSInstrument
			///@param from CTPackage
            ///@param to SInstrument
            void toStructs(CTPackage* from,SInstrument* to);
 
            ///@brief SInstrumentת��ΪCTPackage
			///@param from SInstrument
            ///@param to CTPackage
            void toCTP(SInstrument* from,CTPackage* to);
            
            ///@brief CTPackageת��ΪSRiskControler
			///@param from CTPackage
            ///@param to SRiskControler
            void toStructs(CTPackage* from,SRiskControler* to);
 
            ///@brief SRiskControlerת��ΪCTPackage
			///@param from SRiskControler
            ///@param to CTPackage
            void toCTP(SRiskControler* from,CTPackage* to);
            
            ///@brief CTPackageת��ΪSMoneyChange
			///@param from CTPackage
            ///@param to SMoneyChange
            void toStructs(CTPackage* from,SMoneyChange* to);
 
            ///@brief SMoneyChangeת��ΪCTPackage
			///@param from SMoneyChange
            ///@param to CTPackage
            void toCTP(SMoneyChange* from,CTPackage* to);
            
            ///@brief CTPackageת��ΪSNewTradingDay
			///@param from CTPackage
            ///@param to SNewTradingDay
            void toStructs(CTPackage* from,SNewTradingDay* to);
 
            ///@brief SNewTradingDayת��ΪCTPackage
			///@param from SNewTradingDay
            ///@param to CTPackage
            void toCTP(SNewTradingDay* from,CTPackage* to);
            
            ///@brief CTPackageת��ΪSOrderRsp
			///@param from CTPackage
            ///@param to SOrderRsp
            void toStructs(CTPackage* from,SOrderRsp* to);
 
            ///@brief SOrderRspת��ΪCTPackage
			///@param from SOrderRsp
            ///@param to CTPackage
            void toCTP(SOrderRsp* from,CTPackage* to);
            
            ///@brief CTPackageת��ΪSMarginRate
			///@param from CTPackage
            ///@param to SMarginRate
            void toStructs(CTPackage* from,SMarginRate* to);
 
            ///@brief SMarginRateת��ΪCTPackage
			///@param from SMarginRate
            ///@param to CTPackage
            void toCTP(SMarginRate* from,CTPackage* to);
            
            ///@brief CTPackageת��ΪSFeeRate
			///@param from CTPackage
            ///@param to SFeeRate
            void toStructs(CTPackage* from,SFeeRate* to);
 
            ///@brief SFeeRateת��ΪCTPackage
			///@param from SFeeRate
            ///@param to CTPackage
            void toCTP(SFeeRate* from,CTPackage* to);
            
            ///@brief CTPackageת��ΪSLogConfig
			///@param from CTPackage
            ///@param to SLogConfig
            void toStructs(CTPackage* from,SLogConfig* to);
 
            ///@brief SLogConfigת��ΪCTPackage
			///@param from SLogConfig
            ///@param to CTPackage
            void toCTP(SLogConfig* from,CTPackage* to);
            
            
            ///@brief CTPackageFactory���캯��
            CTPackageFactory();
            
            ///@brief CTPackageFactory��������
            ~CTPackageFactory();
    };
}
#endif //CTPACKAGEFACTORY_H_
        