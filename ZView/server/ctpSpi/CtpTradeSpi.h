#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CtpMDSpi.h
///@brief 声明用于上期技术综合交易平台的交易服务接口类
///@author 张弛
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
		///@brief 请求计数器
		TVolume iRequestID;

		///@brief 连接器指针
		CConnector* connector;

		///@brief USER_API参数
		CThostFtdcTraderApi* pUserApi;

		///@brief 前置编号
		TThostFtdcFrontIDType	frontID;

		///@brief 会话编号
		TThostFtdcSessionIDType	sessionID;
		
		///@brief 报单引用
		TThostFtdcOrderRefType	nextOrderRef;

		///@brief 用户登录请求
		void ReqUserLogin();

		///@brief 投资者结算结果确认
		void ReqSettlementInfoConfirm();

		///@brief 请求查询合约
		void ReqQryInstrument();

		///@brief 请求查询资金账户
		void ReqQryTradingAccount();

		///@brief 请求查询投资者持仓
		void ReqQryInvestorPosition();

		///@brief 是否收到成功的响应
		bool IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo);

		///@brief 是否我的报单回报
		bool IsMyOrder(CThostFtdcOrderField *pOrder);

		///@brief 是否正在交易的报单
		bool IsTradingOrder(CThostFtdcOrderField *pOrder);

	public:
		///@brief 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
		virtual void OnFrontConnected();

		///@brief 登录请求响应
		virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
									CThostFtdcRspInfoField *pRspInfo, 
									int nRequestID,									
									bool bIsLast);

		///@brief 投资者结算结果确认响应
		virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm,
												CThostFtdcRspInfoField *pRspInfo,
												int nRequestID,
												bool bIsLast);

		///@brief 请求查询资金账户响应
		virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount,
											CThostFtdcRspInfoField *pRspInfo,
											int nRequestID,
											bool bIsLast);

		///@brief 请求查询投资者持仓响应
		virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition,
											  CThostFtdcRspInfoField *pRspInfo,
											  int nRequestID,
											  bool bIsLast);

		///@brief 报单录入请求响应
		virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder,
									  CThostFtdcRspInfoField *pRspInfo,
									  int nRequestID,
									  bool bIsLast);

		///@brief 报单操作请求响应
		virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction,
									  CThostFtdcRspInfoField *pRspInfo,
									  int nRequestID,
									  bool bIsLast);

		///@brief 错误应答
		virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo,
			                    int nRequestID,
								bool bIsLast);

		///@brief 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
		virtual void OnFrontDisconnected(int nReason);

		///@brief 心跳超时警告。当长时间未收到报文时，该方法被调用。
		virtual void OnHeartBeatWarning(int nTimeLapse);

		///@brief 报单通知
		virtual void OnRtnOrder(CThostFtdcOrderField *pOrder);

		///@brief 成交通知
		virtual void OnRtnTrade(CThostFtdcTradeField *pTrade);

		///@brief 报单录入请求
		void ReqOrderInsert(SOrderReq* newOrder);

		///@brief 报单操作请求
		void ReqOrderAction(CThostFtdcOrderField *pOrder);

		///@brief 与远端的交易服务器断开
		void disconnect();

		///@brief CtpTradeSpi 构造函数
		CtpTradeSpi(CConnector *connectorIN);

		~CtpTradeSpi(void);
	};
}
#endif // CTPTRADESPI_H_
