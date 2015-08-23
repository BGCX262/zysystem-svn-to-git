/////////////////////////////////////////////////////////////////////////
///@file SimConnector.cpp
///@brief ʵ������ģ�⽻��������
///@author �ų�
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

//���ӵ�Զ�˷�����
void CSimConnector::connect(void){
	ctpMDSpi->connect();	
}

//�Ͽ�����
void CSimConnector::disconnect(void){
	ctpMDSpi->disconnect();
}

//����ָ���������
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