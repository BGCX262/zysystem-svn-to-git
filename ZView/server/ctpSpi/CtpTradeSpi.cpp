/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CtpTradeSpi.cpp
///@brief 实现 用于上期技术综合交易平台的交易服务接口类
///@author 张弛
///@date 20120802
/////////////////////////////////////////////////////////////////////////
#include "CtpTradeSpi.h"

#ifndef CTPTRADESPI_CPP_
#define CTPTRADESPI_CPP_

using namespace ZYSystem;

CtpTradeSpi::CtpTradeSpi(CConnector *connectorIN){
	this->connector = connectorIN;

	//创建于交易系统的连接
	pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi();			// 创建UserApi
	pUserApi->RegisterSpi((CThostFtdcTraderSpi*) this);				// 注册事件类
	pUserApi->SubscribePublicTopic(THOST_TERT_QUICK);				// 注册公有流
	pUserApi->SubscribePrivateTopic(THOST_TERT_QUICK);				// 注册私有流
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

// 流控判断
bool IsFlowControl(TID iResult)
{
	return ((iResult == -2) || (iResult == -3));
}

void CtpTradeSpi::OnFrontConnected()
{
	ZYSYSTEM_LOG0(SPI_T_Connected);
	
	///用户登录请求
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
		// 保存会话参数
		frontID = pRspUserLogin->FrontID;
		sessionID = pRspUserLogin->SessionID;
		int nNextOrderRef = atoi(pRspUserLogin->MaxOrderRef);
		nNextOrderRef++;
		std::sprintf(nextOrderRef,"%d",nNextOrderRef);
		
		///获取当前交易日
		ZYSYSTEM_LOG1(SPI_T_TradingDayIs,pUserApi->GetTradingDay());

		///投资者结算结果确认
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
		//查投资者资金账号
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
		///将资金信息写入系统
		
		///请求查询投资者持仓
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
		///将查询到的持仓信息送回本地核心
		
	}
}

void CtpTradeSpi::ReqOrderInsert(SOrderReq* newOrder)
{
	CThostFtdcInputOrderField req;
	memset(&req, 0, sizeof(req));
	///经纪公司代码
	strcpy(req.BrokerID, connector->investor->BrokerID);
	///投资者代码
	strcpy(req.InvestorID, connector->investor->InvestorID);
	///合约代码
	strcpy(req.InstrumentID, newOrder->InstrumentID);
	///报单引用
	std::strcpy(req.OrderRef,nextOrderRef);
	int nNextOrderRef = atoi(nextOrderRef);
	nNextOrderRef++;
	std::sprintf(nextOrderRef,"%d",nNextOrderRef);

	///报单价格条件: 限价
	req.OrderPriceType = THOST_FTDC_OPT_LimitPrice;
	///买卖方向: 
	req.Direction = THOST_FTDC_D_Buy;
	///组合开平标志: 开仓
	req.CombOffsetFlag[0] = THOST_FTDC_OF_Open;
	///组合投机套保标志
	req.CombHedgeFlag[0] = THOST_FTDC_HF_Speculation;
	///价格
	req.LimitPrice = newOrder->Price;
	///数量: 1
	req.VolumeTotalOriginal = newOrder->VolumeRemain;
	///有效期类型: 当日有效
	req.TimeCondition = THOST_FTDC_TC_GFD;

	///成交量类型: 任何数量
	req.VolumeCondition = THOST_FTDC_VC_AV;
	///最小成交量: 1
	req.MinVolume = 1;
	///触发条件: 立即
	req.ContingentCondition = THOST_FTDC_CC_Immediately;
	///止损价
//	TThostFtdcPriceType	StopPrice;
	///强平原因: 非强平
	req.ForceCloseReason = THOST_FTDC_FCC_NotForceClose;
	///自动挂起标志: 否
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
	static bool ORDER_ACTION_SENT = false;		//是否发送了报单
	if (ORDER_ACTION_SENT)
		return;

	CThostFtdcInputOrderActionField req;
	memset(&req, 0, sizeof(req));
	///经纪公司代码
	strcpy(req.BrokerID, pOrder->BrokerID);
	///投资者代码
	strcpy(req.InvestorID, pOrder->InvestorID);
	///报单操作引用
//	TThostFtdcOrderActionRefType	OrderActionRef;
	///报单引用
	strcpy(req.OrderRef, pOrder->OrderRef);
	///请求编号
//	TThostFtdcRequestIDType	RequestID;
	///前置编号
	req.FrontID = frontID;
	///会话编号
	req.SessionID = sessionID;
	///交易所代码
//	TThostFtdcExchangeIDType	ExchangeID;
	///报单编号
//	TThostFtdcOrderSysIDType	OrderSysID;
	///操作标志
	req.ActionFlag = THOST_FTDC_AF_Delete;
	///价格
//	TThostFtdcPriceType	LimitPrice;
	///数量变化
//	TThostFtdcVolumeType	VolumeChange;
	///用户代码
//	TThostFtdcUserIDType	UserID;
	///合约代码
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

///报单通知
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

///成交通知
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
	// 如果ErrorID != 0, 说明收到了错误的响应
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
