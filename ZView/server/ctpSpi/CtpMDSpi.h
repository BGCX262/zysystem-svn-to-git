#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CtpMDSpi.h
///@brief �����������ڼ����ۺϽ���ƽ̨���������ӿ���
///@author �ų�
///@date 20120802
/////////////////////////////////////////////////////////////////////////

#include "../System.h"
#include "../connector/Connector.h"

#ifndef CTPMDSPI_H_
#define CTPMDSPI_H_

namespace ZYSystem {

	class CtpMDSpi:public CThostFtdcMdSpi{
	private:
		///@brief ���������
		TVolume iRequestID;

		///@brief ������ָ��
		CConnector* connector;

		///@brief USER_API����
		CThostFtdcMdApi* pUserApi;

		///@brief �Ƿ��д�����Ӧ��Ϣ
		///@param *pRspInfo ��Ӧ��Ϣ
		///@return ��/��
		bool IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo);

	public:
		///@brief ����Ӧ����
		///@param *pRspInfo ��Ӧ��Ϣ
		///@param nRequestID �������
		///@param bIsLast �Ƿ�������Ϣ
		virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo,int nRequestID,bool bIsLast);

		///@brief ���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
		///@param nReason ����ԭ��
		///        0x1001 �����ʧ��
		///        0x1002 ����дʧ��
		///        0x2001 ����������ʱ
		///        0x2002 ��������ʧ��
		///        0x2003 �յ�������
		virtual void OnFrontDisconnected(int nReason);

		///@brief ������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
		///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
		virtual void OnHeartBeatWarning(int nTimeLapse);

		///@brief ���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
		virtual void OnFrontConnected();

		///@brief ��¼������Ӧ����
		///@param *pRspUserLogin ��¼������Ϣ
		///@param *pRspInfo ������Ӧ��Ϣ
		///@param nRequestID ������
		///@param bIsLast �Ƿ���������Ϣ
		virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
									CThostFtdcRspInfoField *pRspInfo,
									int nRequestID,
									bool bIsLast);

		///@brief ������鴦��
		///@param *pDepthMarketData ���������Ϣ
		virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);

		///@brief ��Զ�˵�����������Ͽ�
		virtual void disconnect();

		///@brief ��Զ�˵������������
		virtual void connect();
	
		///@brief ����ָ���������
		///@param instruments ��Ҫ���ĵ������Լ
		virtual TID subscribeMarketData(SSubInstrument* instruments);

		///@brief CtpMDSpi ���캯��
		CtpMDSpi(CConnector *connectorIN);
		~CtpMDSpi(void);
	};
}
#endif // CTPMDSPI_H_