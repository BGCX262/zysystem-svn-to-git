#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file Connector.h
///@brief �г��������������,�������ӵ������̲�ͬ��������,���಻�ܱ�ʵ��
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "../dataRoute/TEndPoint.h"
#include "../util/CMDBufferQueue.h"

#ifndef CCONNECTOR_H_
#define CCONNECTOR_H_

namespace ZYSystem {

	class CConnector:public CTEndPoint{

	protected:
		///@brief ������������캯��
		///@param in �����ṩ��������Ϣ
		CConnector(SMarketDataProvider* in);

		~CConnector(void);

	public:
		///@brief �����˻�
		SInvestor *investor;
		
		///@brief ��������
		SMarketDataProvider *config;

		///@brief ���ӵ�Զ�˵����������
		virtual void connect()=0;
		
		///@brief ��Զ�˵�����������Ͽ�
		virtual void disconnect()=0;

		///@brief ����ָ���������
		///@param instruments ��Ҫ���ĵ������Լ
		virtual TID subscribeMarketData(SSubInstrument* instruments)=0;

		///@brief ����ָ���������
		///@param SOrder ��Ҫ���ĵ������Լ
		virtual TID newOrder(SOrderReq* newOrder)=0;

		///@brief �յ�������
		///@param SOrder ��Ҫ���ĵ������Լ
		virtual TID newMarketData(SMarketData* newMarketData)=0;

		///@brief �յ��µ��˻���Ϣ
		///@param SInvestor ��Ҫ���ĵ������Լ
		virtual TID newInvestor(SInvestor* newInvestor);
	};
}

#endif // CCONNECTOR_H_