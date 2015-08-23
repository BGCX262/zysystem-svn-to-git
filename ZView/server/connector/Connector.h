#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file Connector.h
///@brief 市场行情接收器基类,按照连接的行情商不同泛化子类,此类不能被实例
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "../dataRoute/TEndPoint.h"
#include "../util/CMDBufferQueue.h"

#ifndef CCONNECTOR_H_
#define CCONNECTOR_H_

namespace ZYSystem {

	class CConnector:public CTEndPoint{

	protected:
		///@brief 行情接收器构造函数
		///@param in 行情提供者配置信息
		CConnector(SMarketDataProvider* in);

		~CConnector(void);

	public:
		///@brief 交易账户
		SInvestor *investor;
		
		///@brief 行情配置
		SMarketDataProvider *config;

		///@brief 连接到远端的行情服务器
		virtual void connect()=0;
		
		///@brief 与远端的行情服务器断开
		virtual void disconnect()=0;

		///@brief 订阅指定标地行情
		///@param instruments 需要订阅的行情合约
		virtual TID subscribeMarketData(SSubInstrument* instruments)=0;

		///@brief 订阅指定标地行情
		///@param SOrder 需要订阅的行情合约
		virtual TID newOrder(SOrderReq* newOrder)=0;

		///@brief 收到新行情
		///@param SOrder 需要订阅的行情合约
		virtual TID newMarketData(SMarketData* newMarketData)=0;

		///@brief 收到新的账户信息
		///@param SInvestor 需要订阅的行情合约
		virtual TID newInvestor(SInvestor* newInvestor);
	};
}

#endif // CCONNECTOR_H_