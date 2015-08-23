/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ASPConnector.cpp
///@brief 实现综合交易平台的行情接口
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "ASPConnector.h"

#ifndef CASPCONNECTOR_CPP_
#define CASPCONNECTOR_CPP_

using namespace ZYSystem;

CASPConnector::CASPConnector(SMarketDataProvider* configIN):CConnector(configIN) {		
	LOG_SMarketDataProvider(configIN);
	ctpMDSpi = NULL;
	ctpTradeSpi = NULL;
}

CASPConnector::~CASPConnector() {
	delete ctpMDSpi;
	delete ctpTradeSpi;
}

//连接到远端服务器
void CASPConnector::connect(void){
	ctpMDSpi = new CtpMDSpi(this);
	ctpTradeSpi = new CtpTradeSpi(this);
}

//断开连接
void CASPConnector::disconnect(void){
	ctpMDSpi->disconnect();
	ctpTradeSpi->disconnect();
}

//订阅指定标地行情
TID CASPConnector::subscribeMarketData(SSubInstrument* instruments){
	if (ctpMDSpi != NULL) {
		ctpMDSpi->subscribeMarketData(instruments);
	} else {
		ZYSYSTEM_LOG0(CONNECTOR_CtpMDIsEmpty);
	}
	return SUCCESS;
}

TID CASPConnector::newOrder(SOrderReq* newOrder) {
	if (ctpTradeSpi != NULL) {
		ctpTradeSpi->ReqOrderInsert(newOrder);
	} else {
		ZYSYSTEM_LOG0(CONNECTOR_CtpTradeIsEmpty);
	}
	return SUCCESS;
}

TID CASPConnector::newMarketData(SMarketData* newMarketData) {
	if (newMarketData != NULL){
		this->sendTP(newMarketData);
	} else {
		ZYSYSTEM_LOG0(CONNECTOR_NewMDIsEmpty);
	}
	return SUCCESS;
}

#endif // CASPCONNECTOR_CPP_