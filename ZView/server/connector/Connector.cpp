/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file Connector.cpp
///@brief �г��������������,�������ӵ������̲�ͬ��������,���಻�ܱ�ʵ��
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////

#include "Connector.h"

using namespace ZYSystem;

#ifndef CCONNECTOR_CPP_
#define CCONNECTOR_CPP_

CConnector::CConnector(SMarketDataProvider *in){
    config = new SMarketDataProvider();
	std::memcpy(config,in,sizeof SMarketDataProvider);
};

CConnector::~CConnector(void){
};

TID CConnector::newInvestor(SInvestor* newInvestor) {
	investor = new SInvestor();
	std::memcpy(investor,newInvestor,sizeof SInvestor);
	return SUCCESS;
}
#endif // CCONNECTOR_CPP_

