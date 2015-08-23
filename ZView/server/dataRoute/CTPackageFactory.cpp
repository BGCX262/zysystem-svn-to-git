            
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CTPackageFactory.cpp
///@brief 声明 TPackage 生成工厂类
///@author xslt模型代码转换工具
///@date 2013-06-21T07:28:08.221Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "./CTPackageFactory.h"

#ifndef CTPACKAGEFACTORY_CPP_
#define CTPACKAGEFACTORY_CPP_

using namespace ZYSystem;

CTPackageFactory::CTPackageFactory(){
}

CTPackageFactory:: ~CTPackageFactory(){
}


void CTPackageFactory::toStructs(CTPackage* from,SLog* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(SLog* from,CTPackage* to){
    to->setPackageType(TPID_Log);
    to->setContent(from,sizeof SLog);
}

void CTPackageFactory::toStructs(CTPackage* from,SMarketDataProvider* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(SMarketDataProvider* from,CTPackage* to){
    to->setPackageType(TPID_MarketDataProvider);
    to->setContent(from,sizeof SMarketDataProvider);
}

void CTPackageFactory::toStructs(CTPackage* from,SInvestor* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(SInvestor* from,CTPackage* to){
    to->setPackageType(TPID_Investor);
    to->setContent(from,sizeof SInvestor);
}

void CTPackageFactory::toStructs(CTPackage* from,SMarketData* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(SMarketData* from,CTPackage* to){
    to->setPackageType(TPID_MarketData);
    to->setContent(from,sizeof SMarketData);
}

void CTPackageFactory::toStructs(CTPackage* from,SKDJ* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(SKDJ* from,CTPackage* to){
    to->setPackageType(TPID_KDJ);
    to->setContent(from,sizeof SKDJ);
}

void CTPackageFactory::toStructs(CTPackage* from,SMACD* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(SMACD* from,CTPackage* to){
    to->setPackageType(TPID_MACD);
    to->setContent(from,sizeof SMACD);
}

void CTPackageFactory::toStructs(CTPackage* from,SModelConfigA* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(SModelConfigA* from,CTPackage* to){
    to->setPackageType(TPID_ModelConfigA);
    to->setContent(from,sizeof SModelConfigA);
}

void CTPackageFactory::toStructs(CTPackage* from,SOrderReq* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(SOrderReq* from,CTPackage* to){
    to->setPackageType(TPID_OrderReq);
    to->setContent(from,sizeof SOrderReq);
}

void CTPackageFactory::toStructs(CTPackage* from,STrade* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(STrade* from,CTPackage* to){
    to->setPackageType(TPID_Trade);
    to->setContent(from,sizeof STrade);
}

void CTPackageFactory::toStructs(CTPackage* from,SRealPosition* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(SRealPosition* from,CTPackage* to){
    to->setPackageType(TPID_RealPosition);
    to->setContent(from,sizeof SRealPosition);
}

void CTPackageFactory::toStructs(CTPackage* from,SRealFund* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(SRealFund* from,CTPackage* to){
    to->setPackageType(TPID_RealFund);
    to->setContent(from,sizeof SRealFund);
}

void CTPackageFactory::toStructs(CTPackage* from,SSubInstrument* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(SSubInstrument* from,CTPackage* to){
    to->setPackageType(TPID_SubInstrument);
    to->setContent(from,sizeof SSubInstrument);
}

void CTPackageFactory::toStructs(CTPackage* from,SSingnal* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(SSingnal* from,CTPackage* to){
    to->setPackageType(TPID_Singnal);
    to->setContent(from,sizeof SSingnal);
}

void CTPackageFactory::toStructs(CTPackage* from,SInstrument* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(SInstrument* from,CTPackage* to){
    to->setPackageType(TPID_Instrument);
    to->setContent(from,sizeof SInstrument);
}

void CTPackageFactory::toStructs(CTPackage* from,SRiskControler* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(SRiskControler* from,CTPackage* to){
    to->setPackageType(TPID_RiskControler);
    to->setContent(from,sizeof SRiskControler);
}

void CTPackageFactory::toStructs(CTPackage* from,SMoneyChange* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(SMoneyChange* from,CTPackage* to){
    to->setPackageType(TPID_MoneyChange);
    to->setContent(from,sizeof SMoneyChange);
}

void CTPackageFactory::toStructs(CTPackage* from,SNewTradingDay* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(SNewTradingDay* from,CTPackage* to){
    to->setPackageType(TPID_NewTradingDay);
    to->setContent(from,sizeof SNewTradingDay);
}

void CTPackageFactory::toStructs(CTPackage* from,SOrderRsp* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(SOrderRsp* from,CTPackage* to){
    to->setPackageType(TPID_OrderRsp);
    to->setContent(from,sizeof SOrderRsp);
}

void CTPackageFactory::toStructs(CTPackage* from,SMarginRate* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(SMarginRate* from,CTPackage* to){
    to->setPackageType(TPID_MarginRate);
    to->setContent(from,sizeof SMarginRate);
}

void CTPackageFactory::toStructs(CTPackage* from,SFeeRate* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(SFeeRate* from,CTPackage* to){
    to->setPackageType(TPID_FeeRate);
    to->setContent(from,sizeof SFeeRate);
}

void CTPackageFactory::toStructs(CTPackage* from,SLogConfig* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(SLogConfig* from,CTPackage* to){
    to->setPackageType(TPID_LogConfig);
    to->setContent(from,sizeof SLogConfig);
}


#endif //CTPACKAGEFACTORY_CPP_
        