#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CtpMDSpi.h
///@brief �����������ڼ����ۺϽ���ƽ̨�Ľ��׷���ӿ���
///@author �ų�
///@date 20120802
/////////////////////////////////////////////////////////////////////////

#include "../System.h"
#include "../connector/Connector.h"

#ifndef CTPTRADESPI_H_
#define CTPTRADESPI_H_

namespace ZYSystem {

	class CtpTradeSpi:public CThostFtdcTraderSpi
	{
	private:
		///@brief ���������
		TVolume iRequestID;

		///@brief ������ָ��
		CConnector* connector;

		///@brief USER_API����
		CThostFtdcTraderApi* pUserApi;

		///@brief ǰ�ñ��
		TThostFtdcFrontIDType	frontID;

		///@brief �Ự���
		TThostFtdcSessionIDType	sessionID;
		
		///@brief ��������
		TThostFtdcOrderRefType	nextOrderRef;

		///@brief �û���¼����
		void ReqUserLogin();

		///@brief Ͷ���߽�����ȷ��
		void ReqSettlementInfoConfirm();

		///@brief �����ѯ��Լ
		void ReqQryInstrument();

		///@brief �����ѯ�ʽ��˻�
		void ReqQryTradingAccount();

		///@brief �����ѯͶ���ֲ߳�
		void ReqQryInvestorPosition();

		///@brief �Ƿ��յ��ɹ�����Ӧ
		bool IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo);

		///@brief �Ƿ��ҵı����ر�
		bool IsMyOrder(CThostFtdcOrderField *pOrder);

		///@brief �Ƿ����ڽ��׵ı���
		bool IsTradingOrder(CThostFtdcOrderField *pOrder);

	public:
		///@brief ���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
		virtual void OnFrontConnected();

		///@brief ��¼������Ӧ
		virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
									CThostFtdcRspInfoField *pRspInfo, 
									int nRequestID,									
									bool bIsLast);

		///@brief Ͷ���߽�����ȷ����Ӧ
		virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm,
												CThostFtdcRspInfoField *pRspInfo,
												int nRequestID,
												bool bIsLast);

		///@brief �����ѯ�ʽ��˻���Ӧ
		virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount,
											CThostFtdcRspInfoField *pRspInfo,
											int nRequestID,
											bool bIsLast);

		///@brief �����ѯͶ���ֲ߳���Ӧ
		virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition,
											  CThostFtdcRspInfoField *pRspInfo,
											  int nRequestID,
											  bool bIsLast);

		///@brief ����¼��������Ӧ
		virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder,
									  CThostFtdcRspInfoField *pRspInfo,
									  int nRequestID,
									  bool bIsLast);

		///@brief ��������������Ӧ
		virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction,
									  CThostFtdcRspInfoField *pRspInfo,
									  int nRequestID,
									  bool bIsLast);

		///@brief ����Ӧ��
		virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo,
			                    int nRequestID,
								bool bIsLast);

		///@brief ���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
		virtual void OnFrontDisconnected(int nReason);

		///@brief ������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
		virtual void OnHeartBeatWarning(int nTimeLapse);

		///@brief ����֪ͨ
		virtual void OnRtnOrder(CThostFtdcOrderField *pOrder);

		///@brief �ɽ�֪ͨ
		virtual void OnRtnTrade(CThostFtdcTradeField *pTrade);

		///@brief ����¼������
		void ReqOrderInsert(SOrderReq* newOrder);

		///@brief ������������
		void ReqOrderAction(CThostFtdcOrderField *pOrder);

		///@brief ��Զ�˵Ľ��׷������Ͽ�
		void disconnect();

		///@brief CtpTradeSpi ���캯��
		CtpTradeSpi(CConnector *connectorIN);

		~CtpTradeSpi(void);
	};
}
#endif // CTPTRADESPI_H_
