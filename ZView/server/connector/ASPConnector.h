#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ASPConnector.h
///@brief �����ۺϽ���ƽ̨������ӿ�
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "Connector.h"
#include "../ctpSpi/CtpMDSpi.h"
#include "../ctpSpi/CtpTradeSpi.h"

#ifndef CASPCONNECTOR_H_
#define CASPCONNECTOR_H_

namespace ZYSystem {

	class CASPConnector : public CConnector
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
		
		///@brief CASPConnector ���캯��
		///@param config �����ṩ��������Ϣ
		CASPConnector(SMarketDataProvider* config);
		
		///@brief ���������Ͷ����
		~CASPConnector();
	private:
		///@brief CTP�������
		CtpMDSpi* ctpMDSpi;

		///@brief CTP���׷���
		CtpTradeSpi* ctpTradeSpi;

		///@brief �������
		CMarketDataWriter* marketDataWriter;
	};
}

#endif //CASPCONNECTOR_H_
