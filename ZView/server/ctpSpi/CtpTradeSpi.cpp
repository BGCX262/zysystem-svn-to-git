/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CtpTradeSpi.cpp
///@brief ʵ�� �������ڼ����ۺϽ���ƽ̨�Ľ��׷���ӿ���
///@author �ų�
///@date 20120802
/////////////////////////////////////////////////////////////////////////
#include "CtpTradeSpi.h"

#ifndef CTPTRADESPI_CPP_
#define CTPTRADESPI_CPP_

using namespace ZYSystem;

CtpTradeSpi::CtpTradeSpi(CConnector *connectorIN){
	this->connector = connectorIN;

	//�����ڽ���ϵͳ������
	pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi();			// ����UserApi
	pUserApi->RegisterSpi((CThostFtdcTraderSpi*) this);				// ע���¼���
	pUserApi->SubscribePublicTopic(THOST_TERT_QUICK);				// ע�ṫ����
	pUserApi->SubscribePrivateTopic(THOST_TERT_QUICK);				// ע��˽����
	pUserApi->RegisterFront(connectorIN->config->Td_url);			// connect
	pUserApi->Init();
	pUserApi->Join();
}


CtpTradeSpi::~CtpTradeSpi(void){
	pUserApi->Release();
}

void CtpTradeSpi::disconnect(){
	pUserApi->Release();
};

// �����ж�
bool IsFlowControl(TID iResult)
{
	return ((iResult == -2) || (iResult == -3));
}

void CtpTradeSpi::OnFrontConnected()
{
	ZYSYSTEM_LOG0(SPI_T_Connected);
	
	///�û���¼����
	CThostFtdcReqUserLoginField req;
	memset(&req, 0, sizeof(req));
	strcpy(req.BrokerID, connector->investor->BrokerID);
	strcpy(req.UserID, connector->investor->InvestorID);
	strcpy(req.Password, connector->investor->InvestorPassword);

	TID iResult = pUserApi->ReqUserLogin(&req, ++iRequestID);	
	if (iResult != SUCCESS) {
		ZYSYSTEM_LOG0(SPI_T_LoginFail);
	}
}

void CtpTradeSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
							     CThostFtdcRspInfoField *pRspInfo,
								 int nRequestID,
								 bool bIsLast){
	ZYSYSTEM_LOG0(SPI_T_LoginSucc);

	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		// ����Ự����
		frontID = pRspUserLogin->FrontID;
		sessionID = pRspUserLogin->SessionID;
		int nNextOrderRef = atoi(pRspUserLogin->MaxOrderRef);
		nNextOrderRef++;
		std::sprintf(nextOrderRef,"%d",nNextOrderRef);
		
		///��ȡ��ǰ������
		ZYSYSTEM_LOG1(SPI_T_TradingDayIs,pUserApi->GetTradingDay());

		///Ͷ���߽�����ȷ��
		CThostFtdcSettlementInfoConfirmField req;
		memset(&req, 0, sizeof(req));
		strcpy(req.BrokerID, connector->investor->BrokerID);
		strcpy(req.InvestorID, connector->investor->InvestorID);
		TID iResult = pUserApi->ReqSettlementInfoConfirm(&req, ++iRequestID);
		if (iResult != SUCCESS) {
			ZYSYSTEM_LOG0(SPI_T_SettInfoConfirmFail);
		}
	}
}

void CtpTradeSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, 
											 CThostFtdcRspInfoField *pRspInfo,
											 int nRequestID,
											 bool bIsLast)
{
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		ZYSYSTEM_LOG0(SPI_T_SettInfoConfirmSucc);
		//��Ͷ�����ʽ��˺�
		ReqQryTradingAccount();
	}
}

void CtpTradeSpi::ReqQryTradingAccount()
{
	boost::posix_time::time_duration* td =new boost::posix_time::time_duration(0,0,1,0);
	
	CThostFtdcQryTradingAccountField req;
	memset(&req, 0, sizeof(req));
	strcpy(req.BrokerID, connector->investor->BrokerID);
	strcpy(req.InvestorID, connector->investor->InvestorID);
	while (true)
	{
		TID iResult = pUserApi->ReqQryTradingAccount(&req, ++iRequestID);
		if (!IsFlowControl(iResult))
		{
			if (iResult != SUCCESS) {
				ZYSYSTEM_LOG0(SPI_T_QryTradingAccountFail);
			}
			break;
		}
		else
		{
			ZYSYSTEM_LOG0(SPI_T_QryTradingAccountFC);
			boost::this_thread::sleep(*td);
		}
	} // while
}

void CtpTradeSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		ZYSYSTEM_LOG0(SPI_T_QryTradingAccountSucc);
		///���ʽ���Ϣд��ϵͳ
		
		///�����ѯͶ���ֲ߳�
		ReqQryInvestorPosition();
	}
}

void CtpTradeSpi::ReqQryInvestorPosition()
{
	boost::posix_time::time_duration* td =new boost::posix_time::time_duration(0,0,1,0);

	CThostFtdcQryInvestorPositionField req;
	memset(&req, 0, sizeof(req));
	strcpy(req.BrokerID, connector->investor->BrokerID);
	strcpy(req.InvestorID, connector->investor->InvestorID);
	while (true) {
		TID iResult = pUserApi->ReqQryInvestorPosition(&req, ++iRequestID);
		if (!IsFlowControl(iResult))
		{
			if (iResult != SUCCESS) {
				ZYSYSTEM_LOG0(SPI_T_QryInvestorPositionFail);
			}
			break;
		}
		else {
			ZYSYSTEM_LOG0(SPI_T_QryInvestorPositionFC);	
			boost::this_thread::sleep(*td);

		}
	} // while
}

void CtpTradeSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		ZYSYSTEM_LOG0(SPI_T_QryInvestorPositionFC);
		///����ѯ���ĳֲ���Ϣ�ͻر��غ���
		
	}
}

void CtpTradeSpi::ReqOrderInsert(SOrderReq* newOrder)
{
	CThostFtdcInputOrderField req;
	memset(&req, 0, sizeof(req));
	///���͹�˾����
	strcpy(req.BrokerID, connector->investor->BrokerID);
	///Ͷ���ߴ���
	strcpy(req.InvestorID, connector->investor->InvestorID);
	///��Լ����
	strcpy(req.InstrumentID, newOrder->InstrumentID);
	///��������
	std::strcpy(req.OrderRef,nextOrderRef);
	int nNextOrderRef = atoi(nextOrderRef);
	nNextOrderRef++;
	std::sprintf(nextOrderRef,"%d",nNextOrderRef);

	///�����۸�����: �޼�
	req.OrderPriceType = THOST_FTDC_OPT_LimitPrice;
	///��������: 
	req.Direction = THOST_FTDC_D_Buy;
	///��Ͽ�ƽ��־: ����
	req.CombOffsetFlag[0] = THOST_FTDC_OF_Open;
	///���Ͷ���ױ���־
	req.CombHedgeFlag[0] = THOST_FTDC_HF_Speculation;
	///�۸�
	req.LimitPrice = newOrder->Price;
	///����: 1
	req.VolumeTotalOriginal = newOrder->VolumeRemain;
	///��Ч������: ������Ч
	req.TimeCondition = THOST_FTDC_TC_GFD;

	///�ɽ�������: �κ�����
	req.VolumeCondition = THOST_FTDC_VC_AV;
	///��С�ɽ���: 1
	req.MinVolume = 1;
	///��������: ����
	req.ContingentCondition = THOST_FTDC_CC_Immediately;
	///ֹ���
//	TThostFtdcPriceType	StopPrice;
	///ǿƽԭ��: ��ǿƽ
	req.ForceCloseReason = THOST_FTDC_FCC_NotForceClose;
	///�Զ������־: ��
	req.IsAutoSuspend = 0;
	req.UserForceClose = 0;

	TID iResult = pUserApi->ReqOrderInsert(&req, ++iRequestID);
	if (iResult != SUCCESS) {
		ZYSYSTEM_LOG0(SPI_T_OrderInsertFail);
	}
}

void CtpTradeSpi::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder,
								   CThostFtdcRspInfoField *pRspInfo, 
								   int nRequestID,
								   bool bIsLast) {
	if (bIsLast && !IsErrorRspInfo(pRspInfo)){
		ZYSYSTEM_LOG0(SPI_T_OrderInsertSucc);
	}
}

void CtpTradeSpi::ReqOrderAction(CThostFtdcOrderField *pOrder)
{
	static bool ORDER_ACTION_SENT = false;		//�Ƿ����˱���
	if (ORDER_ACTION_SENT)
		return;

	CThostFtdcInputOrderActionField req;
	memset(&req, 0, sizeof(req));
	///���͹�˾����
	strcpy(req.BrokerID, pOrder->BrokerID);
	///Ͷ���ߴ���
	strcpy(req.InvestorID, pOrder->InvestorID);
	///������������
//	TThostFtdcOrderActionRefType	OrderActionRef;
	///��������
	strcpy(req.OrderRef, pOrder->OrderRef);
	///������
//	TThostFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	req.FrontID = frontID;
	///�Ự���
	req.SessionID = sessionID;
	///����������
//	TThostFtdcExchangeIDType	ExchangeID;
	///�������
//	TThostFtdcOrderSysIDType	OrderSysID;
	///������־
	req.ActionFlag = THOST_FTDC_AF_Delete;
	///�۸�
//	TThostFtdcPriceType	LimitPrice;
	///�����仯
//	TThostFtdcVolumeType	VolumeChange;
	///�û�����
//	TThostFtdcUserIDType	UserID;
	///��Լ����
	strcpy(req.InstrumentID, pOrder->InstrumentID);

	TID iResult = pUserApi->ReqOrderAction(&req, ++iRequestID);
	if (iResult != SUCCESS) {
		ZYSYSTEM_LOG0(SPI_T_OrderActionFail);
	}
	ORDER_ACTION_SENT = true;
}

void CtpTradeSpi::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (bIsLast && !IsErrorRspInfo(pRspInfo)){
		ZYSYSTEM_LOG0(SPI_T_OrderActionSucc);
	}
}

///����֪ͨ
void CtpTradeSpi::OnRtnOrder(CThostFtdcOrderField *pOrder){
	ZYSYSTEM_LOG0(SPI_T_RtnOrder);
	if (IsMyOrder(pOrder))
	{
		if (IsTradingOrder(pOrder))
			ReqOrderAction(pOrder);
		else if (pOrder->OrderStatus == THOST_FTDC_OST_Canceled)
			ZYSYSTEM_LOG0(SPI_T_OrderCanceled);
	}
}

///�ɽ�֪ͨ
void CtpTradeSpi::OnRtnTrade(CThostFtdcTradeField *pTrade){
	ZYSYSTEM_LOG0(SPI_T_RtnTrade);
}

void CtpTradeSpi:: OnFrontDisconnected(int nReason)
{
	ZYSYSTEM_LOG1(SPI_T_Disconnected,nReason);
}
		
void CtpTradeSpi::OnHeartBeatWarning(int nTimeLapse)
{
	ZYSYSTEM_LOG1(SPI_T_HeartBeat,nTimeLapse);
}

void CtpTradeSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	IsErrorRspInfo(pRspInfo);
}

bool CtpTradeSpi::IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo)
{
	// ���ErrorID != 0, ˵���յ��˴������Ӧ
	bool bResult = ((pRspInfo) && (pRspInfo->ErrorID != 0));
	if (bResult) {
		ZYSYSTEM_LOG2(SPI_T_ServerErr,pRspInfo->ErrorID,pRspInfo->ErrorMsg);
	}
	return bResult;
}

bool CtpTradeSpi::IsMyOrder(CThostFtdcOrderField *pOrder)
{
	return ((pOrder->FrontID == frontID) &&
			(pOrder->SessionID == sessionID) &&
			(strcmp(pOrder->OrderRef, nextOrderRef) == 0));
}

bool CtpTradeSpi::IsTradingOrder(CThostFtdcOrderField *pOrder)
{
	return ((pOrder->OrderStatus != THOST_FTDC_OST_PartTradedNotQueueing) &&
			(pOrder->OrderStatus != THOST_FTDC_OST_Canceled) &&
			(pOrder->OrderStatus != THOST_FTDC_OST_AllTraded));
}


#endif //CTPTRADESPI_CPP_
