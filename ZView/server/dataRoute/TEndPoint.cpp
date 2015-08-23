            
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TEndPoint.cpp
///@brief 声明 TPackage 生成工厂类
///@author xslt模型代码转换工具
///@date 2013-06-21T07:28:12.012Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "./TEndPoint.h"

#ifndef CTENDPOINT_CPP_
#define CTENDPOINT_CPP_

using namespace ZYSystem;

CTEndPoint::CTEndPoint(){
}

CTEndPoint:: ~CTEndPoint(){
}

inline void CTEndPoint::setlocalTime(TDateTime time) {
	boost::posix_time::ptime t(boost::posix_time::second_clock::local_time());
	std::strcpy(time,(boost::posix_time::to_iso_string(t)).c_str());
}


inline void CTEndPoint::sendTP(SLog* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_Log);
    to.setContent(from,sizeof SLog);
    CDataRoute::getInstance()->send(&to);
}

inline void CTEndPoint::sendTP(SMarketDataProvider* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_MarketDataProvider);
    to.setContent(from,sizeof SMarketDataProvider);
    CDataRoute::getInstance()->send(&to);
}

inline void CTEndPoint::sendTP(SInvestor* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_Investor);
    to.setContent(from,sizeof SInvestor);
    CDataRoute::getInstance()->send(&to);
}

inline void CTEndPoint::sendTP(SMarketData* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_MarketData);
    to.setContent(from,sizeof SMarketData);
    CDataRoute::getInstance()->send(&to);
}

inline void CTEndPoint::sendTP(SKDJ* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_KDJ);
    to.setContent(from,sizeof SKDJ);
    CDataRoute::getInstance()->send(&to);
}

inline void CTEndPoint::sendTP(SMACD* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_MACD);
    to.setContent(from,sizeof SMACD);
    CDataRoute::getInstance()->send(&to);
}

inline void CTEndPoint::sendTP(SModelConfigA* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_ModelConfigA);
    to.setContent(from,sizeof SModelConfigA);
    CDataRoute::getInstance()->send(&to);
}

inline void CTEndPoint::sendTP(SOrderReq* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_OrderReq);
    to.setContent(from,sizeof SOrderReq);
    CDataRoute::getInstance()->send(&to);
}

inline void CTEndPoint::sendTP(STrade* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_Trade);
    to.setContent(from,sizeof STrade);
    CDataRoute::getInstance()->send(&to);
}

inline void CTEndPoint::sendTP(SRealPosition* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_RealPosition);
    to.setContent(from,sizeof SRealPosition);
    CDataRoute::getInstance()->send(&to);
}

inline void CTEndPoint::sendTP(SRealFund* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_RealFund);
    to.setContent(from,sizeof SRealFund);
    CDataRoute::getInstance()->send(&to);
}

inline void CTEndPoint::sendTP(SSubInstrument* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_SubInstrument);
    to.setContent(from,sizeof SSubInstrument);
    CDataRoute::getInstance()->send(&to);
}

inline void CTEndPoint::sendTP(SSingnal* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_Singnal);
    to.setContent(from,sizeof SSingnal);
    CDataRoute::getInstance()->send(&to);
}

inline void CTEndPoint::sendTP(SInstrument* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_Instrument);
    to.setContent(from,sizeof SInstrument);
    CDataRoute::getInstance()->send(&to);
}

inline void CTEndPoint::sendTP(SRiskControler* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_RiskControler);
    to.setContent(from,sizeof SRiskControler);
    CDataRoute::getInstance()->send(&to);
}

inline void CTEndPoint::sendTP(SMoneyChange* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_MoneyChange);
    to.setContent(from,sizeof SMoneyChange);
    CDataRoute::getInstance()->send(&to);
}

inline void CTEndPoint::sendTP(SNewTradingDay* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_NewTradingDay);
    to.setContent(from,sizeof SNewTradingDay);
    CDataRoute::getInstance()->send(&to);
}

inline void CTEndPoint::sendTP(SOrderRsp* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_OrderRsp);
    to.setContent(from,sizeof SOrderRsp);
    CDataRoute::getInstance()->send(&to);
}

inline void CTEndPoint::sendTP(SMarginRate* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_MarginRate);
    to.setContent(from,sizeof SMarginRate);
    CDataRoute::getInstance()->send(&to);
}

inline void CTEndPoint::sendTP(SFeeRate* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_FeeRate);
    to.setContent(from,sizeof SFeeRate);
    CDataRoute::getInstance()->send(&to);
}

inline void CTEndPoint::sendTP(SLogConfig* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_LogConfig);
    to.setContent(from,sizeof SLogConfig);
    CDataRoute::getInstance()->send(&to);
}


#endif //CTENDPOINT_CPP_
        