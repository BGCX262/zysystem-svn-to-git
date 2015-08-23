#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CtpMDSpi.h
///@brief 声明用于上期技术综合交易平台的行情服务接口类
///@author 张弛
///@date 20120802
/////////////////////////////////////////////////////////////////////////

#include "../System.h"
#include "../connector/Connector.h"

#ifndef CTPMDSPI_H_
#define CTPMDSPI_H_

namespace ZYSystem {

	class CtpMDSpi:public CThostFtdcMdSpi{
	private:
		///@brief 请求计数器
		TVolume iRequestID;

		///@brief 连接器指针
		CConnector* connector;

		///@brief USER_API参数
		CThostFtdcMdApi* pUserApi;

		///@brief 是否有错误响应信息
		///@param *pRspInfo 相应信息
		///@return 是/否
		bool IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo);

	public:
		///@brief 错误应答处理
		///@param *pRspInfo 响应信息
		///@param nRequestID 请求序号
		///@param bIsLast 是否最新信息
		virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo,int nRequestID,bool bIsLast);

		///@brief 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
		///@param nReason 错误原因
		///        0x1001 网络读失败
		///        0x1002 网络写失败
		///        0x2001 接收心跳超时
		///        0x2002 发送心跳失败
		///        0x2003 收到错误报文
		virtual void OnFrontDisconnected(int nReason);

		///@brief 心跳超时警告。当长时间未收到报文时，该方法被调用。
		///@param nTimeLapse 距离上次接收报文的时间
		virtual void OnHeartBeatWarning(int nTimeLapse);

		///@brief 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
		virtual void OnFrontConnected();

		///@brief 登录请求响应处理
		///@param *pRspUserLogin 登录请求信息
		///@param *pRspInfo 处理响应信息
		///@param nRequestID 请求编号
		///@param bIsLast 是否是最新消息
		virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
									CThostFtdcRspInfoField *pRspInfo,
									int nRequestID,
									bool bIsLast);

		///@brief 深度行情处理
		///@param *pDepthMarketData 深度行情信息
		virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);

		///@brief 与远端的行情服务器断开
		virtual void disconnect();

		///@brief 与远端的行情服务连接
		virtual void connect();
	
		///@brief 订阅指定标地行情
		///@param instruments 需要订阅的行情合约
		virtual TID subscribeMarketData(SSubInstrument* instruments);

		///@brief CtpMDSpi 构造函数
		CtpMDSpi(CConnector *connectorIN);
		~CtpMDSpi(void);
	};
}
#endif // CTPMDSPI_H_