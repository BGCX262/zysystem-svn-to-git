/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file MDOnlyConnector.cpp
///@brief 实现 仅用于行情接收的连接器
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "MDOnlyConnector.h"

#ifndef CMDONLYCONNECTOR_CPP_
#define CMDONLYCONNECTOR_CPP_

using namespace ZYSystem;


CMDOnlyConnector::CMDOnlyConnector(SMarketDataProvider *configIN):CConnector(configIN){		
	LOG_SMarketDataProvider(configIN);  
	ctpMDSpi = NULL;
}

CMDOnlyConnector::~CMDOnlyConnector() {
	delete ctpMDSpi;
}

//连接到远端服务器
void CMDOnlyConnector::connect(void){
	ctpMDSpi = new CtpMDSpi(this);
}

//断开连接
void CMDOnlyConnector::disconnect(void){
	ctpMDSpi->disconnect();
}

//订阅指定标地行情
TID CMDOnlyConnector::subscribeMarketData(SSubInstrument* instruments){
	if (ctpMDSpi != NULL) {
		ctpMDSpi->subscribeMarketData(instruments);
	} else {
		ZYSYSTEM_LOG0(CONNECTOR_CtpMDIsEmpty);
	}
	return SUCCESS;
}

TID CMDOnlyConnector::newOrder(SOrderReq* newOrder) {
	//空方法
	return SUCCESS;
}

TID CMDOnlyConnector::newMarketData(SMarketData* newMarketData) {
	if (newMarketData != NULL){
		this->sendTP(newMarketData);
	} else {
		ZYSYSTEM_LOG0(CONNECTOR_NewMDIsEmpty);
	}
	return SUCCESS;
}

#endif //CMDONLYCONNECTOR_H_