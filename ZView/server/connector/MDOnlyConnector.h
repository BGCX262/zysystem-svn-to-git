#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file MDOnlyConnector.h
///@brief ���� ������������յ�������
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "Connector.h"
#include "../ctpSpi/CtpMDSpi.h"

#ifndef CMDONLYCONNECTOR_H_
#define CMDONLYCONNECTOR_H_

namespace ZYSystem {
	class CMDOnlyConnector:public CConnector
	{
	public:

		///@brief ���ӵ�Զ�˵����������
		virtual void connect();

		///@brief ��Զ�˵�����������Ͽ�
		virtual void disconnect();
	
		///@brief ����ָ���������
		///@param instruments ��Ҫ���ĵ������Լ
		virtual TID subscribeMarketData(SSubInstrument* instruments);

        ///@brief ����ָ���������
		///@param SOrder ��Ҫ���ĵ������Լ
		virtual TID newOrder(SOrderReq* newOrder);

		///@brief �յ�������
		///@param SOrder ��Ҫ���ĵ������Լ
		virtual TID newMarketData(SMarketData* newMarketData);

		///@brief CMDOnlyConnector ���캯��
		///@param config �����ṩ��������Ϣ
		CMDOnlyConnector(SMarketDataProvider* config);
		
		///@brief CMDOnlyConnector ��������
		~CMDOnlyConnector();
	private:
		///@brief CTP�������
		CtpMDSpi* ctpMDSpi;
	
		///@brief ����
		SInvestor *investor;
	};
}

#endif //CMDONLYCONNECTOR_H