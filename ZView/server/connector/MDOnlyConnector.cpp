/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file MDOnlyConnector.cpp
///@brief ʵ�� ������������յ�������
///@author �ų�
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

//���ӵ�Զ�˷�����
void CMDOnlyConnector::connect(void){
	ctpMDSpi = new CtpMDSpi(this);
}

//�Ͽ�����
void CMDOnlyConnector::disconnect(void){
	ctpMDSpi->disconnect();
}

//����ָ���������
TID CMDOnlyConnector::subscribeMarketData(SSubInstrument* instruments){
	if (ctpMDSpi != NULL) {
		ctpMDSpi->subscribeMarketData(instruments);
	} else {
		ZYSYSTEM_LOG0(CONNECTOR_CtpMDIsEmpty);
	}
	return SUCCESS;
}

TID CMDOnlyConnector::newOrder(SOrderReq* newOrder) {
	//�շ���
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