#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ASPConnector.h
///@brief 调用综合交易平台的行情接口
///@author 张弛
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
		///@brief 连接到远端的行情服务器
		virtual void connect();

		///@brief 与远端的行情服务器断开
		virtual void disconnect();
	
		///@brief 订阅指定标地行情
		///@param instruments 需要订阅的行情合约
		virtual TID subscribeMarketData(SSubInstrument* instruments);

        ///@brief 订阅指定标地行情
		///@param newOrder 需要订阅的行情合约
		virtual TID newOrder(SOrderReq* newOrder);

		///@brief 收到新行情
		///@param newMarketData 需要订阅的行情合约
		virtual TID newMarketData(SMarketData* newMarketData);
		
		///@brief CASPConnector 构造函数
		///@param config 行情提供者配置信息
		CASPConnector(SMarketDataProvider* config);
		
		///@brief 设置所需的投资者
		~CASPConnector();
	private:
		///@brief CTP行情服务
		CtpMDSpi* ctpMDSpi;

		///@brief CTP交易服务
		CtpTradeSpi* ctpTradeSpi;

		///@brief 行情落地
		CMarketDataWriter* marketDataWriter;
	};
}

#endif //CASPCONNECTOR_H_
