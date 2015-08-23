/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ASPConnector.cpp
///@brief ʵ���ۺϽ���ƽ̨������ӿ�
///@author �ų�
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

//���ӵ�Զ�˷�����
void CASPConnector::connect(void){
	ctpMDSpi = new CtpMDSpi(this);
	ctpTradeSpi = new CtpTradeSpi(this);
}

//�Ͽ�����
void CASPConnector::disconnect(void){
	ctpMDSpi->disconnect();
	ctpTradeSpi->disconnect();
}

//����ָ���������
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