            
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TEndPoint.h
///@brief ���� TPackage ��������
///@author xsltģ�ʹ���ת������
///@date 2013-06-21T07:28:10.28Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "CDataRoute.h"

#ifndef CTENDPOINT_H_
#define CTENDPOINT_H_

namespace ZYSystem {
    class CTEndPoint{
        protected:
            ///@brief ���ñ���ʱ��
			///@param time ����ʱ��
            inline virtual void setlocalTime(TDateTime time);
            
                
            ///@brief ����SLog
			///@param from SLog
            inline virtual void sendTP(SLog* from);
                
            ///@brief ����SMarketDataProvider
			///@param from SMarketDataProvider
            inline virtual void sendTP(SMarketDataProvider* from);
                
            ///@brief ����SInvestor
			///@param from SInvestor
            inline virtual void sendTP(SInvestor* from);
                
            ///@brief ����SMarketData
			///@param from SMarketData
            inline virtual void sendTP(SMarketData* from);
                
            ///@brief ����SKDJ
			///@param from SKDJ
            inline virtual void sendTP(SKDJ* from);
                
            ///@brief ����SMACD
			///@param from SMACD
            inline virtual void sendTP(SMACD* from);
                
            ///@brief ����SModelConfigA
			///@param from SModelConfigA
            inline virtual void sendTP(SModelConfigA* from);
                
            ///@brief ����SOrderReq
			///@param from SOrderReq
            inline virtual void sendTP(SOrderReq* from);
                
            ///@brief ����STrade
			///@param from STrade
            inline virtual void sendTP(STrade* from);
                
            ///@brief ����SRealPosition
			///@param from SRealPosition
            inline virtual void sendTP(SRealPosition* from);
                
            ///@brief ����SRealFund
			///@param from SRealFund
            inline virtual void sendTP(SRealFund* from);
                
            ///@brief ����SSubInstrument
			///@param from SSubInstrument
            inline virtual void sendTP(SSubInstrument* from);
                
            ///@brief ����SSingnal
			///@param from SSingnal
            inline virtual void sendTP(SSingnal* from);
                
            ///@brief ����SInstrument
			///@param from SInstrument
            inline virtual void sendTP(SInstrument* from);
                
            ///@brief ����SRiskControler
			///@param from SRiskControler
            inline virtual void sendTP(SRiskControler* from);
                
            ///@brief ����SMoneyChange
			///@param from SMoneyChange
            inline virtual void sendTP(SMoneyChange* from);
                
            ///@brief ����SNewTradingDay
			///@param from SNewTradingDay
            inline virtual void sendTP(SNewTradingDay* from);
                
            ///@brief ����SOrderRsp
			///@param from SOrderRsp
            inline virtual void sendTP(SOrderRsp* from);
                
            ///@brief ����SMarginRate
			///@param from SMarginRate
            inline virtual void sendTP(SMarginRate* from);
                
            ///@brief ����SFeeRate
			///@param from SFeeRate
            inline virtual void sendTP(SFeeRate* from);
                
            ///@brief ����SLogConfig
			///@param from SLogConfig
            inline virtual void sendTP(SLogConfig* from);
            
        public:
            ///@brief CTEndPoint���캯��
            CTEndPoint();
            
            ///@brief CTEndPoint��������
            ~CTEndPoint();
    };
}
#endif //CTENDPOINT_H_
        