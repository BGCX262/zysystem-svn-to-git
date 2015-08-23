/////////////////////////////////////////////////////////////////////////
///@file SimConnector.cpp
///@brief 实现行情模拟交易连接器
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "SimConnector.h"

#ifndef CSIMCONNECTOR_CPP_
#define CSIMCONNECTOR_CPP_

using namespace ZYSystem;

CSimConnector::CSimConnector(SMarketDataProvider *configIN):CConnector(configIN) {		
	LOG_SMarketDataProvider(configIN);
	ctpMDSpi =new CtpMDSpi(this);
}

CSimConnector::~CSimConnector() {
	delete ctpMDSpi;
}

//连接到远端服务器
void CSimConnector::connect(void){
	ctpMDSpi->connect();	
}

//断开连接
void CSimConnector::disconnect(void){
	ctpMDSpi->disconnect();
}

//订阅指定标地行情
TID CSimConnector::subscribeMarketData(SSubInstrument* instruments){	
	if (ctpMDSpi != NULL) {
		ctpMDSpi->subscribeMarketData(instruments);
	} else {
		ZYSYSTEM_LOG0(CONNECTOR_CtpMDIsEmpty);
	}
	return SUCCESS;
}

TID CSimConnector::newOrder(SOrderReq* newOrder){
	return SUCCESS;
}

TID CSimConnector::newMarketData(SMarketData* newMarketData) {
	if (newMarketData != NULL){
		this->sendTP(newMarketData);
	} else {
		ZYSYSTEM_LOG0(CONNECTOR_NewMDIsEmpty);
	}
	return SUCCESS;
}

#endif //CSIMCONNECTOR_CPP_