/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CtpMDSpi.cpp
///@brief 实现 用于上期技术综合交易平台的行情服务接口类
///@author 张弛
///@date 20120802
/////////////////////////////////////////////////////////////////////////
#include "CtpMDSpi.h"

#ifndef CTPMDSPI_CPP_
#define CTPMDSPI_CPP_

using namespace ZYSystem;

CtpMDSpi::CtpMDSpi(CConnector* connectorIN) {
	this->connector = connectorIN;
	pUserApi = CThostFtdcMdApi::CreateFtdcMdApi(CStdLogger::logConfig->LogPath,true);	// 创建UserApi
}


CtpMDSpi::~CtpMDSpi(void)
{
	pUserApi->Release();
}

void CtpMDSpi::connect(){
	// 初始化UserApi
	pUserApi->RegisterSpi(this);													// 注册事件类
	pUserApi->RegisterFront(connector->config->Md_url);								// connect  
	pUserApi->Init();
	pUserApi->Join();
}

void CtpMDSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo,int nRequestID, bool bIsLast)
{
	// 如果ErrorID != 0, 说明收到了错误的响应
	IsErrorRspInfo(pRspInfo);
}

void CtpMDSpi::OnFrontDisconnected(int nReason)
{
	ZYSYSTEM_LOG0(SPI_MD_Disconnected);
}

void CtpMDSpi::OnHeartBeatWarning(int nTimeLapse){

}

void CtpMDSpi::OnFrontConnected()
{
	ZYSYSTEM_LOG0(SPI_MD_Connected);	
	
	///用户登录请求
	CThostFtdcReqUserLoginField req;
	
	strcpy(req.BrokerID, connector->investor->BrokerID);
	strcpy(req.UserID, connector->investor->InvestorID);
	strcpy(req.Password, connector->investor->InvestorPassword);
	
	TID iResult = pUserApi->ReqUserLogin(&req, ++iRequestID);
	if (iResult == SUCCESS) {
		ZYSYSTEM_LOG0(SPI_MD_LoginSucc);
	} else {
		ZYSYSTEM_LOG0(SPI_MD_LoginFail);
	}
}

void CtpMDSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	IsErrorRspInfo(pRspInfo);
}


void CtpMDSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
	SMarketData data = SMarketData();
	
	strcpy(data.TradingDay,pDepthMarketData->TradingDay);
	strcpy(data.InstrumentID,pDepthMarketData->InstrumentID);
	strcpy(data.ExchangeID,pDepthMarketData->ExchangeID);
	data.LastPrice = pDepthMarketData->LastPrice;
	data.PreSettlementPrice = pDepthMarketData->PreSettlementPrice;
	data.PreClosePrice = pDepthMarketData->PreClosePrice;
	data.PreOpenInterest = pDepthMarketData->PreOpenInterest;
	data.OpenPrice = pDepthMarketData->OpenPrice;
	data.HighestPrice = pDepthMarketData->HighestPrice;

	data.LowestPrice = pDepthMarketData->LowestPrice;
	data.Volume = pDepthMarketData->Volume;
	data.Turnover = pDepthMarketData->Turnover;
	data.OpenInterest = pDepthMarketData->OpenInterest;
	data.ClosePrice = pDepthMarketData->ClosePrice;
	data.SettlementPrice = pDepthMarketData->SettlementPrice;
	data.UpperLimitPrice = pDepthMarketData->UpperLimitPrice;
	data.LowerLimitPrice = pDepthMarketData->LowerLimitPrice;
	strcpy(data.UpdateTime,pDepthMarketData->UpdateTime);
	data.UpdateMillisec = pDepthMarketData->UpdateMillisec;
	data.BidPrice1 = pDepthMarketData->BidPrice1;
	data.BidVolume1 = pDepthMarketData->BidVolume1;
	data.AskPrice1 = pDepthMarketData->AskPrice1;
	data.AskVolume1 = pDepthMarketData->AskVolume1;
	data.AveragePrice = pDepthMarketData->AveragePrice;

	connector->newMarketData(&data);
}

//断开连接
void CtpMDSpi::disconnect(void){
	pUserApi->Release();
}

//订阅指定标地行情
TID CtpMDSpi::subscribeMarketData(SSubInstrument* instruments){
	std::vector<std::string> SplitVec;
	std::string instrument_s(instruments->InstrumentID);

	boost::algorithm::split(SplitVec,
							instrument_s,
							boost::is_any_of(";"),
							boost::algorithm::token_compress_on);
	char** temp = NULL;
	TID iResult = 0;
	try {
		temp =new char* [SplitVec.size()];
		if (temp != NULL) {
			for(int unsigned i = 0;i < SplitVec.size();i++){
				temp[i] =new char[9];
				strcpy(temp[i],SplitVec[i].c_str());
			}
			iResult = pUserApi->SubscribeMarketData(temp,SplitVec.size());

			if (iResult != SUCCESS) {
				ZYSYSTEM_LOG1(SPI_MD_ServerErr,iResult);
			} else {
				ZYSYSTEM_LOG1(SPI_MD_NewInsturments,instrument_s.c_str());
			}
		}else {
			throw temp;
		}	
	}catch(...){
		delete[] temp;
	}
	
	return SUCCESS;
}

bool CtpMDSpi::IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo)
{
	// 如果ErrorID != 0, 说明收到了错误的响应
	bool bResult = ((pRspInfo) && (pRspInfo->ErrorID != 0));
	if (bResult) {
		ZYSYSTEM_LOG1(SPI_MD_ServerErr,pRspInfo->ErrorMsg);
	}	 
	return bResult;
}

#endif //CTPMDSPI_CPP_