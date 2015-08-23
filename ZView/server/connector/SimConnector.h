#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file SimConnector.h
///@brief ��������ģ�⽻��������
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "Connector.h"
#include "../ctpSpi/CtpMDSpi.h"

#ifndef CSIMCONNECTOR_H_
#define CSIMCONNECTOR_H_

namespace ZYSystem {

	class CSimConnector:public CConnector
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
		///@param newOrder ��Ҫ���ĵ������Լ
		virtual TID newOrder(SOrderReq* newOrder);

		///@brief �յ�������
		///@param newMarketData ��Ҫ���ĵ������Լ
		virtual TID newMarketData(SMarketData* newMarketData);
		
		///@brief CSimConnector ���캯��
		///@param *config �����ṩ��������Ϣ
		CSimConnector(SMarketDataProvider *config);
		
		///@brief CSimConnector ��������
		~CSimConnector();
	private:
		///@brief CTP�������
		CtpMDSpi* ctpMDSpi;

		///@brief �������
		CMarketDataWriter* marketDataWriter;
	};
}

#endif //CSIMCONNECTOR_H_