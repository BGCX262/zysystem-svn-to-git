
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CStdLog.cpp
///@brief ��������־����࣬��־�����Ҫ��
///        1.�༶����־��������Կ��������Ҫ�ļ���
///		   2.������ɱ��ض����
///       CLogger��һ���������־�ӿڣ�����Ӧ�ó��������־
///       ����ȫ��ֻ��һ��ʵ����Ĭ��ʵ��Ϊ��stdout�����־��
///       Ӧ�ó�����Լ̳�CLogger��ʵ�����ѵ���־��
///@author xsltģ�ʹ���ת������
///@date 2013-06-21T07:28:21.809Z
////////////////////////////////////////////////////////////////////////
#pragma once

#include "CStdLog.h"
#include "ScreenLogger.h"
#include "FileLogger.h"

#ifndef CSTDLOG_CPP_
#define CSTDLOG_CPP_

///ҵ����־
///�Ƿ�ʹ��ҵ��״̬��־
using namespace ZYSystem;

bool ZYSystemMainLog = true;

CStdLogger* CStdLogger::m_pInstance;
SLogConfig* CStdLogger::logConfig;

CStdLogger::CStdLogger(){
    setOutputLogInfo();
}

CStdLogger::~CStdLogger(){};

CStdLogger* CStdLogger::GetInstance(){
    return m_pInstance;
};

void CStdLogger::setLogConfig(SLogConfig* logConfig_in){
    if (m_pInstance == NULL) {
        logConfig = new SLogConfig();
        std::memcpy(logConfig,logConfig_in,sizeof SLogConfig);
        
        if (logConfig_in->LogOutputType == LOT_FileOutput) {
          m_pInstance = new CFileLogger();
        } else {
          m_pInstance = new ScreenLogger();
        }
    }
}

void CStdLogger::outputInfo(int format,...){
    SLog log = this->infoVector[format];
    
	va_list v;
    va_start(v,format);
	outputVL(log.LogLevel,log.LogMsg,v);
    va_end(v);
};


void CStdLogger::logSLog(SLog *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{��־��Ϣ����}:");
    
    output(LL_Debug,"  ������:[%d]",in->LogID);
                
    switch (in->LogLevel) {
        
        case LL_SysHalt: {output(LL_Debug,"  ��־����:[0-ϵͳʧ��]"); break;}
        
        case LL_Alert: {output(LL_Debug,"  ��־����:[1-ϵͳ����]"); break;}
        
        case LL_Error: {output(LL_Debug,"  ��־����:[2-���д���]"); break;}
        
        case LL_Warning: {output(LL_Debug,"  ��־����:[3-���о���]"); break;}
        
        case LL_Info: {output(LL_Debug,"  ��־����:[4-������Ϣ]"); break;}
        
        case LL_Debug: {output(LL_Debug,"  ��־����:[5-������Ϣ]"); break;}
        
    }
                
    output(LL_Debug,"  ��־����:[%s]",in->LogCode);
                
    output(LL_Debug,"  ��־��Ϣ:[%s]",in->LogMsg);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSMarketDataProvider(SMarketDataProvider *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{�����ṩ��������Ϣ}:");
    
    output(LL_Debug,"  ���������:[%s]",in->ConnectionID);
                
    output(LL_Debug,"  Զ����������ַ:[%s]",in->Td_url);
                
    output(LL_Debug,"  Զ�̽��׷����ַ:[%s]",in->Md_url);
                
    switch (in->ConnectionType) {
        
        case MDT_Sfit: {output(LL_Debug,"  ��������:[1-���ڼ���]"); break;}
        
        case MDT_His: {output(LL_Debug,"  ��������:[2-��ʷ��������]"); break;}
        
        case MDT_Sim: {output(LL_Debug,"  ��������:[3-ģ�⽻��]"); break;}
        
        case MDT_OnlyMD: {output(LL_Debug,"  ��������:[4-��������]"); break;}
        
    }
                
    output(LL_Debug,"  Ͷ���ߴ���:[%s]",in->InvestorID);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSInvestor(SInvestor *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{Ͷ����}:");
    
    output(LL_Debug,"  Ͷ���ߴ���:[%s]",in->InvestorID);
                
    output(LL_Debug,"  ��������:[%s]",in->InvestorPassword);
                
    output(LL_Debug,"  �ʽ��˺�:[%s]",in->AccountID);
                
    output(LL_Debug,"  �ʽ�����:[%s]",in->AccountPassword);
                
    output(LL_Debug,"  ���͹�˾����:[%s]",in->BrokerID);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSMarketData(SMarketData *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{ϵͳ���յ�����������}:");
    
    output(LL_Debug,"  ������:[%s]",in->TradingDay);
                
    output(LL_Debug,"  ��Լ����:[%s]",in->InstrumentID);
                
    output(LL_Debug,"  ����������:[%s]",in->ExchangeID);
                
    output(LL_Debug,"  ���¼�:[%f]",in->LastPrice);
                
    output(LL_Debug,"  �ϴν����:[%f]",in->PreSettlementPrice);
                
    output(LL_Debug,"  ������:[%f]",in->PreClosePrice);
                
    output(LL_Debug,"  ��ֲ���:[%f]",in->PreOpenInterest);
                
    output(LL_Debug,"  ����:[%f]",in->OpenPrice);
                
    output(LL_Debug,"  ��߼�:[%f]",in->HighestPrice);
                
    output(LL_Debug,"  ��ͼ�:[%f]",in->LowestPrice);
                
    output(LL_Debug,"  ����:[%d]",in->Volume);
                
    output(LL_Debug,"  �ɽ����:[%f]",in->Turnover);
                
    output(LL_Debug,"  �ֲ���:[%f]",in->OpenInterest);
                
    output(LL_Debug,"  ������:[%f]",in->ClosePrice);
                
    output(LL_Debug,"  ���ν����:[%f]",in->SettlementPrice);
                
    output(LL_Debug,"  ��ͣ���:[%f]",in->UpperLimitPrice);
                
    output(LL_Debug,"  ��ͣ���:[%f]",in->LowerLimitPrice);
                
    output(LL_Debug,"  ����ʵ��:[%f]",in->PreDelta);
                
    output(LL_Debug,"  ����ʵ��:[%f]",in->CurrDelta);
                
    output(LL_Debug,"  ����޸�ʱ��:[%s]",in->UpdateTime);
                
    output(LL_Debug,"  ����޸ĺ���:[%d]",in->UpdateMillisec);
                
    output(LL_Debug,"  �����һ:[%f]",in->BidPrice1);
                
    output(LL_Debug,"  ������һ:[%d]",in->BidVolume1);
                
    output(LL_Debug,"  ������һ:[%f]",in->AskPrice1);
                
    output(LL_Debug,"  ������һ:[%d]",in->AskVolume1);
                
    output(LL_Debug,"  ���վ���:[%f]",in->AveragePrice);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSKDJ(SKDJ *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{KDJָ��}:");
    
    output(LL_Debug,"  ������:[%s]",in->TradingDay);
                
    output(LL_Debug,"  ��Լ����:[%s]",in->InstrumentID);
                
    output(LL_Debug,"  ����������:[%s]",in->ExchangeID);
                
    output(LL_Debug,"  ����޸�ʱ��:[%s]",in->UpdateTime);
                
    output(LL_Debug,"  ����޸ĺ���:[%d]",in->UpdateMillisec);
                
    output(LL_Debug,"  k��ֵ:[%f]",in->Idx_k);
                
    output(LL_Debug,"  dָ��:[%f]",in->Idx_d);
                
    output(LL_Debug,"  jָ��:[%f]",in->Idx_j);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSMACD(SMACD *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{MACDָ��}:");
    
    output(LL_Debug,"  ������:[%s]",in->TradingDay);
                
    output(LL_Debug,"  ��Լ����:[%s]",in->InstrumentID);
                
    output(LL_Debug,"  ����������:[%s]",in->ExchangeID);
                
    output(LL_Debug,"  ����޸�ʱ��:[%s]",in->UpdateTime);
                
    output(LL_Debug,"  ����޸ĺ���:[%d]",in->UpdateMillisec);
                
    output(LL_Debug,"  diff��ֵ:[%f]",in->Idx_diff);
                
    output(LL_Debug,"  deaָ��:[%f]",in->Idx_dea);
                
    output(LL_Debug,"  barָ��:[%f]",in->Idx_bar);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSModelConfigA(SModelConfigA *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{����ģ������}:");
    
    output(LL_Debug,"  Ͷ���ߴ���:[%s]",in->InvestorID);
                
    output(LL_Debug,"  �����ļ�·��:[%s]",in->DataPath);
                
    output(LL_Debug,"  ģ�ͼ����ѭ��ʱ��:[%d]",in->CalculateCycle);
                
    switch (in->ModelType) {
        
        case MT_A: {output(LL_Debug,"  ģ������:[1-ģ��A]"); break;}
        
    }
                
    output(LL_Debug,"  k��ֵ:[%f]",in->Idx_k);
                
    output(LL_Debug,"  dָ��:[%f]",in->Idx_d);
                
    output(LL_Debug,"  jָ��:[%f]",in->Idx_j);
                
    output(LL_Debug,"  diff��ֵ:[%f]",in->Idx_diff);
                
    output(LL_Debug,"  deaָ��:[%f]",in->Idx_dea);
                
    output(LL_Debug,"  barָ��:[%f]",in->Idx_bar);
                
    output(LL_Debug,"  k��ֵ���ֵ:[%f]",in->MAX_k);
                
    output(LL_Debug,"  dָ�����ֵ:[%f]",in->MAX_d);
                
    output(LL_Debug,"  jָ�����ֵ:[%f]",in->MAX_j);
                
    output(LL_Debug,"  diff��ֵ���ֵ:[%f]",in->MAX_diff);
                
    output(LL_Debug,"  deaָ�����ֵ:[%f]",in->MAX_dea);
                
    output(LL_Debug,"  barָ�����ֵ:[%f]",in->MAX_bar);
                
    output(LL_Debug,"  k��ֵ��С��ֵ:[%f]",in->MIN_k);
                
    output(LL_Debug,"  dָ����С��ֵ:[%f]",in->MIN_d);
                
    output(LL_Debug,"  jָ����С��ֵ:[%f]",in->MIN_j);
                
    output(LL_Debug,"  diff��ֵ��С��ֵ:[%f]",in->MIN_diff);
                
    output(LL_Debug,"  deaָ����С��ֵ:[%f]",in->MIN_dea);
                
    output(LL_Debug,"  barָ����С��ֵ:[%f]",in->MIN_bar);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSOrderReq(SOrderReq *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{��������}:");
    
    output(LL_Debug,"  ����ί�б��:[%d]",in->LocalOrderID);
                
    output(LL_Debug,"  ������:[%s]",in->TradingDay);
                
    output(LL_Debug,"  Ͷ���ߴ���:[%s]",in->InvestorID);
                
    output(LL_Debug,"  ��Լ����:[%s]",in->InstrumentID);
                
    switch (in->OffsetFlag) {
        
        case OF_Open: {output(LL_Debug,"  ��ƽ���:[0-����]"); break;}
        
        case OF_Close: {output(LL_Debug,"  ��ƽ���:[1-ƽ��]"); break;}
        
        case OF_ForceClose: {output(LL_Debug,"  ��ƽ���:[2-ǿƽ]"); break;}
        
        case OF_CloseToday: {output(LL_Debug,"  ��ƽ���:[3-ƽ��]"); break;}
        
        case OF_CloseYesterday: {output(LL_Debug,"  ��ƽ���:[4-ƽ��]"); break;}
        
        case OF_ForceOff: {output(LL_Debug,"  ��ƽ���:[5-ǿ��]"); break;}
        
        case OF_LocalForceClose: {output(LL_Debug,"  ��ƽ���:[6-����ǿƽ]"); break;}
        
    }
                
    switch (in->Direction) {
        
        case D_Buy: {output(LL_Debug,"  �ֲַ���:[0-��]"); break;}
        
        case D_Sell: {output(LL_Debug,"  �ֲַ���:[1-��]"); break;}
        
    }
                
    output(LL_Debug,"  ���̼۸�:[%f]",in->Price);
                
    switch (in->OrderStatus) {
        
        case OST_AllTraded: {output(LL_Debug,"  ����״̬:[0-ȫ���ɽ�]"); break;}
        
        case OST_PartTradedQueueing: {output(LL_Debug,"  ����״̬:[1-���ֳɽ����ڶ�����]"); break;}
        
        case OST_PartTradedNotQueueing: {output(LL_Debug,"  ����״̬:[2-���ֳɽ����ڶ�����]"); break;}
        
        case OST_NoTradeQueueing: {output(LL_Debug,"  ����״̬:[3-δ�ɽ����ڶ�����]"); break;}
        
        case OST_NoTradeNotQueueing: {output(LL_Debug,"  ����״̬:[4-δ�ɽ����ڶ�����]"); break;}
        
        case OST_Canceled: {output(LL_Debug,"  ����״̬:[5-����]"); break;}
        
        case OST_Unknown: {output(LL_Debug,"  ����״̬:[6-δ֪]"); break;}
        
        case OST_NotTouched: {output(LL_Debug,"  ����״̬:[7-��δ����]"); break;}
        
        case OST_Touched: {output(LL_Debug,"  ����״̬:[8-�Ѵ���]"); break;}
        
    }
                
    switch (in->OrderSubmitStatus) {
        
        case OSS_InsertSubmitted: {output(LL_Debug,"  �����ύ״̬:[0-�Ѿ��ύ]"); break;}
        
        case OSS_CancelSubmitted: {output(LL_Debug,"  �����ύ״̬:[1-�����Ѿ��ύ]"); break;}
        
        case OSS_ModifySubmitted: {output(LL_Debug,"  �����ύ״̬:[2-�޸��Ѿ��ύ]"); break;}
        
        case OSS_Accepted: {output(LL_Debug,"  �����ύ״̬:[3-�Ѿ�����]"); break;}
        
        case OSS_InsertRejected: {output(LL_Debug,"  �����ύ״̬:[4-�����Ѿ����ܾ�]"); break;}
        
        case OSS_CancelRejected: {output(LL_Debug,"  �����ύ״̬:[5-�����Ѿ����ܾ�]"); break;}
        
        case OSS_ModifyRejected: {output(LL_Debug,"  �����ύ״̬:[6-�ĵ��Ѿ����ܾ�]"); break;}
        
    }
                
    output(LL_Debug,"  ��������ʱ��:[%s]",in->LocalTime);
                
    output(LL_Debug,"  ����ʱ��:[%s]",in->OrderTime);
                
    output(LL_Debug,"  �ɽ�����:[%d]",in->VolumeTraded);
                
    output(LL_Debug,"  δ�ɽ���:[%d]",in->VolumeRemain);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSTrade(STrade *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{�ɽ�}:");
    
    output(LL_Debug,"  ������:[%s]",in->TradingDay);
                
    output(LL_Debug,"  Ͷ���ߴ���:[%s]",in->InvestorID);
                
    output(LL_Debug,"  ��Լ����:[%s]",in->InstrumentID);
                
    switch (in->OffsetFlag) {
        
        case OF_Open: {output(LL_Debug,"  ��ƽ���:[0-����]"); break;}
        
        case OF_Close: {output(LL_Debug,"  ��ƽ���:[1-ƽ��]"); break;}
        
        case OF_ForceClose: {output(LL_Debug,"  ��ƽ���:[2-ǿƽ]"); break;}
        
        case OF_CloseToday: {output(LL_Debug,"  ��ƽ���:[3-ƽ��]"); break;}
        
        case OF_CloseYesterday: {output(LL_Debug,"  ��ƽ���:[4-ƽ��]"); break;}
        
        case OF_ForceOff: {output(LL_Debug,"  ��ƽ���:[5-ǿ��]"); break;}
        
        case OF_LocalForceClose: {output(LL_Debug,"  ��ƽ���:[6-����ǿƽ]"); break;}
        
    }
                
    switch (in->Direction) {
        
        case D_Buy: {output(LL_Debug,"  �ֲַ���:[0-��]"); break;}
        
        case D_Sell: {output(LL_Debug,"  �ֲַ���:[1-��]"); break;}
        
    }
                
    output(LL_Debug,"  �ɽ�����:[%d]",in->DoneVolume);
                
    output(LL_Debug,"  �ɽ���:[%f]",in->DonePrice);
                
    output(LL_Debug,"  �ɽ�ʱ��:[%s]",in->TradeTime);
                
    output(LL_Debug,"  ����ί�б��:[%d]",in->LocalOrderID);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSRealPosition(SRealPosition *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{���в�λ}:");
    
    output(LL_Debug,"  Ͷ���ߴ���:[%s]",in->InvestorID);
                
    output(LL_Debug,"  ��Լ����:[%s]",in->InstrumentID);
                
    switch (in->Direction) {
        
        case D_Buy: {output(LL_Debug,"  �ֲַ���:[0-��]"); break;}
        
        case D_Sell: {output(LL_Debug,"  �ֲַ���:[1-��]"); break;}
        
    }
                
    output(LL_Debug,"  ���־���:[%f]",in->OpenPriceAvg);
                
    output(LL_Debug,"  ʵʱ�ֲ�����:[%d]",in->RealVolume);
                
    output(LL_Debug,"  ����ֲ�����:[%d]",in->FrozenVolume);
                
    output(LL_Debug,"  �ֱֲ�֤��:[%f]",in->HoldMargin);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSRealFund(SRealFund *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{�����ʽ�}:");
    
    output(LL_Debug,"  Ͷ���ߴ���:[%s]",in->InvestorID);
                
    output(LL_Debug,"  ����Ȩ��:[%f]",in->LastEquity);
                
    output(LL_Debug,"  ��Ȩ��:[%f]",in->Equity);
                
    output(LL_Debug,"  �����ʽ�:[%f]",in->AvailableFund);
                
    output(LL_Debug,"  ���ᱣ֤��:[%f]",in->FrozenMargin);
                
    output(LL_Debug,"  ����������:[%f]",in->FrozenFee);
                
    output(LL_Debug,"  ����������:[%f]",in->Fee);
                
    output(LL_Debug,"  ƽ��ӯ��:[%f]",in->CloseProfit);
                
    output(LL_Debug,"  �ֲ�ӯ��:[%f]",in->HoldProfit);
                
    output(LL_Debug,"  �ֱֲ�֤��:[%f]",in->Margin);
                
    output(LL_Debug,"  ����:[%f]",in->FundIn);
                
    output(LL_Debug,"  ���:[%f]",in->FundOut);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSSubInstrument(SSubInstrument *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{���ĵĺ�Լ��}:");
    
    output(LL_Debug,"  ��Լ����:[%s]",in->InstrumentID);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSSingnal(SSingnal *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{�����ź�}:");
    
    output(LL_Debug,"  ������:[%s]",in->TradingDay);
                
    output(LL_Debug,"  Ͷ���ߴ���:[%s]",in->InvestorID);
                
    output(LL_Debug,"  ��Լ����:[%s]",in->InstrumentID);
                
    switch (in->OffsetFlag) {
        
        case OF_Open: {output(LL_Debug,"  ��ƽ���:[0-����]"); break;}
        
        case OF_Close: {output(LL_Debug,"  ��ƽ���:[1-ƽ��]"); break;}
        
        case OF_ForceClose: {output(LL_Debug,"  ��ƽ���:[2-ǿƽ]"); break;}
        
        case OF_CloseToday: {output(LL_Debug,"  ��ƽ���:[3-ƽ��]"); break;}
        
        case OF_CloseYesterday: {output(LL_Debug,"  ��ƽ���:[4-ƽ��]"); break;}
        
        case OF_ForceOff: {output(LL_Debug,"  ��ƽ���:[5-ǿ��]"); break;}
        
        case OF_LocalForceClose: {output(LL_Debug,"  ��ƽ���:[6-����ǿƽ]"); break;}
        
    }
                
    switch (in->Direction) {
        
        case D_Buy: {output(LL_Debug,"  �ֲַ���:[0-��]"); break;}
        
        case D_Sell: {output(LL_Debug,"  �ֲַ���:[1-��]"); break;}
        
    }
                
    output(LL_Debug,"  ��������:[%d]",in->Volume);
                
    output(LL_Debug,"  ���̼۸�:[%f]",in->Price);
                
    switch (in->SingnalReason) {
        
        case SR_RiskControler: {output(LL_Debug,"  �����źŵ�ԭ��:[1-���տ���]"); break;}
        
        case SR_ModelA: {output(LL_Debug,"  �����źŵ�ԭ��:[2-����ģ��A]"); break;}
        
    }
                
    output(LL_Debug,"  ����ʱ��:[%s]",in->TriggerTime);
                
    output(LL_Debug,"  ��������ʱ��:[%s]",in->LocalTime);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSInstrument(SInstrument *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{��Լ}:");
    
    output(LL_Debug,"  ��Լ����:[%s]",in->InstrumentID);
                
    output(LL_Debug,"  ��Լ����:[%d]",in->Multiple);
                
    output(LL_Debug,"  ��ͣ���:[%f]",in->UpperLimitPrice);
                
    output(LL_Debug,"  ��ͣ���:[%f]",in->LowerLimitPrice);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSRiskControler(SRiskControler *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{���չ���������}:");
    
    output(LL_Debug,"  ֹӯ�۲�:[%f]",in->FullPrice);
                
    output(LL_Debug,"  ֹ��۲�:[%f]",in->StopLossPrice);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSMoneyChange(SMoneyChange *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{�ʻ��ĳ����}:");
    
    output(LL_Debug,"  Ͷ���ߴ���:[%s]",in->InvestorID);
                
    switch (in->FundDirection) {
        
        case FD_In: {output(LL_Debug,"  �ʽ�仯����:[1-���]"); break;}
        
        case FD_Out: {output(LL_Debug,"  �ʽ�仯����:[2-����]"); break;}
        
    }
                
    output(LL_Debug,"  �ʽ�仯��:[%f]",in->Change);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSNewTradingDay(SNewTradingDay *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{�½�����}:");
    
    output(LL_Debug,"  ������:[%s]",in->TradingDay);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSOrderRsp(SOrderRsp *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{������Ӧ}:");
    
    output(LL_Debug,"  ����ί�б��:[%d]",in->LocalOrderID);
                
    output(LL_Debug,"  ������:[%s]",in->TradingDay);
                
    output(LL_Debug,"  Ͷ���ߴ���:[%s]",in->InvestorID);
                
    output(LL_Debug,"  ��Լ����:[%s]",in->InstrumentID);
                
    switch (in->OffsetFlag) {
        
        case OF_Open: {output(LL_Debug,"  ��ƽ���:[0-����]"); break;}
        
        case OF_Close: {output(LL_Debug,"  ��ƽ���:[1-ƽ��]"); break;}
        
        case OF_ForceClose: {output(LL_Debug,"  ��ƽ���:[2-ǿƽ]"); break;}
        
        case OF_CloseToday: {output(LL_Debug,"  ��ƽ���:[3-ƽ��]"); break;}
        
        case OF_CloseYesterday: {output(LL_Debug,"  ��ƽ���:[4-ƽ��]"); break;}
        
        case OF_ForceOff: {output(LL_Debug,"  ��ƽ���:[5-ǿ��]"); break;}
        
        case OF_LocalForceClose: {output(LL_Debug,"  ��ƽ���:[6-����ǿƽ]"); break;}
        
    }
                
    switch (in->Direction) {
        
        case D_Buy: {output(LL_Debug,"  �ֲַ���:[0-��]"); break;}
        
        case D_Sell: {output(LL_Debug,"  �ֲַ���:[1-��]"); break;}
        
    }
                
    output(LL_Debug,"  ���̼۸�:[%f]",in->Price);
                
    switch (in->OrderStatus) {
        
        case OST_AllTraded: {output(LL_Debug,"  ����״̬:[0-ȫ���ɽ�]"); break;}
        
        case OST_PartTradedQueueing: {output(LL_Debug,"  ����״̬:[1-���ֳɽ����ڶ�����]"); break;}
        
        case OST_PartTradedNotQueueing: {output(LL_Debug,"  ����״̬:[2-���ֳɽ����ڶ�����]"); break;}
        
        case OST_NoTradeQueueing: {output(LL_Debug,"  ����״̬:[3-δ�ɽ����ڶ�����]"); break;}
        
        case OST_NoTradeNotQueueing: {output(LL_Debug,"  ����״̬:[4-δ�ɽ����ڶ�����]"); break;}
        
        case OST_Canceled: {output(LL_Debug,"  ����״̬:[5-����]"); break;}
        
        case OST_Unknown: {output(LL_Debug,"  ����״̬:[6-δ֪]"); break;}
        
        case OST_NotTouched: {output(LL_Debug,"  ����״̬:[7-��δ����]"); break;}
        
        case OST_Touched: {output(LL_Debug,"  ����״̬:[8-�Ѵ���]"); break;}
        
    }
                
    switch (in->OrderSubmitStatus) {
        
        case OSS_InsertSubmitted: {output(LL_Debug,"  �����ύ״̬:[0-�Ѿ��ύ]"); break;}
        
        case OSS_CancelSubmitted: {output(LL_Debug,"  �����ύ״̬:[1-�����Ѿ��ύ]"); break;}
        
        case OSS_ModifySubmitted: {output(LL_Debug,"  �����ύ״̬:[2-�޸��Ѿ��ύ]"); break;}
        
        case OSS_Accepted: {output(LL_Debug,"  �����ύ״̬:[3-�Ѿ�����]"); break;}
        
        case OSS_InsertRejected: {output(LL_Debug,"  �����ύ״̬:[4-�����Ѿ����ܾ�]"); break;}
        
        case OSS_CancelRejected: {output(LL_Debug,"  �����ύ״̬:[5-�����Ѿ����ܾ�]"); break;}
        
        case OSS_ModifyRejected: {output(LL_Debug,"  �����ύ״̬:[6-�ĵ��Ѿ����ܾ�]"); break;}
        
    }
                
    output(LL_Debug,"  ��������ʱ��:[%s]",in->LocalTime);
                
    output(LL_Debug,"  ����ʱ��:[%s]",in->OrderTime);
                
    output(LL_Debug,"  �ɽ�����:[%d]",in->VolumeTraded);
                
    output(LL_Debug,"  δ�ɽ���:[%d]",in->VolumeRemain);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSMarginRate(SMarginRate *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{��Լ��֤����}:");
    
    output(LL_Debug,"  Ͷ���ߴ���:[%s]",in->InvestorID);
                
    output(LL_Debug,"  ��Լ����:[%s]",in->InstrumentID);
                
    output(LL_Debug,"  ����֤����:[%f]",in->MarginRatioByMoney);
                
    output(LL_Debug,"  ÿ�ֱ�֤����:[%f]",in->MarginRatioByVolume);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSFeeRate(SFeeRate *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{��Լ��������}:");
    
    output(LL_Debug,"  Ͷ���ߴ���:[%s]",in->InvestorID);
                
    output(LL_Debug,"  ��Լ����:[%s]",in->InstrumentID);
                
    output(LL_Debug,"  ���ְ������������:[%f]",in->OpenFeeRatioByMoney);
                
    output(LL_Debug,"  ����ÿ�������ѽ��:[%f]",in->OpenFeeRatioByVolume);
                
    output(LL_Debug,"  ƽ�ְ������������:[%f]",in->CloseFeeRatioByMoney);
                
    output(LL_Debug,"  ƽ��ÿ�������ѽ��:[%f]",in->CloseFeeRatioByVolume);
                
    output(LL_Debug,"  ƽ�񰴽����������:[%f]",in->CloseTodayFeeRatioByMoney);
                
    output(LL_Debug,"  ƽ��ÿ�������ѽ��:[%f]",in->CloseTodayFeeRatioByVolume);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::logSLogConfig(SLogConfig *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{��־������Ϣ}:");
    
    switch (in->LogOutputType) {
        
        case LOT_ScreenOutput: {output(LL_Debug,"  ��־�������:[1-��Ļ���]"); break;}
        
        case LOT_FileOutput: {output(LL_Debug,"  ��־�������:[2-�ļ����]"); break;}
        
    }
                
    switch (in->LogLevel) {
        
        case LL_SysHalt: {output(LL_Debug,"  ��־����:[0-ϵͳʧ��]"); break;}
        
        case LL_Alert: {output(LL_Debug,"  ��־����:[1-ϵͳ����]"); break;}
        
        case LL_Error: {output(LL_Debug,"  ��־����:[2-���д���]"); break;}
        
        case LL_Warning: {output(LL_Debug,"  ��־����:[3-���о���]"); break;}
        
        case LL_Info: {output(LL_Debug,"  ��־����:[4-������Ϣ]"); break;}
        
        case LL_Debug: {output(LL_Debug,"  ��־����:[5-������Ϣ]"); break;}
        
    }
                
    output(LL_Debug,"  ��־·��:[%s]",in->LogPath);
                
    output(LL_Debug,"-------------------------------------------------------------");
    }

void CStdLogger::setOutputLogInfo(){

        SLog log_MAINNoConfigFile;
        log_MAINNoConfigFile.LogID = 1001;
        log_MAINNoConfigFile.LogLevel = LL_Debug;
        std::strcpy(log_MAINNoConfigFile.LogCode,"MAIN_NoConfigFile");
        std::strcpy(log_MAINNoConfigFile.LogMsg,"[1001$MAIN_NoConfigFile]:û���ܴ������ļ�,���������ļ�%s�Ƿ����");
        infoVector[1001]=log_MAINNoConfigFile;
        
    
        SLog log_MAINConfigFileFound;
        log_MAINConfigFileFound.LogID = 1002;
        log_MAINConfigFileFound.LogLevel = LL_Debug;
        std::strcpy(log_MAINConfigFileFound.LogCode,"MAIN_ConfigFileFound");
        std::strcpy(log_MAINConfigFileFound.LogMsg,"[1002$MAIN_ConfigFileFound]:�ҵ������ļ�%s");
        infoVector[1002]=log_MAINConfigFileFound;
        
    
        SLog log_MAINConfigFileErr;
        log_MAINConfigFileErr.LogID = 1003;
        log_MAINConfigFileErr.LogLevel = LL_Debug;
        std::strcpy(log_MAINConfigFileErr.LogCode,"MAIN_ConfigFileErr");
        std::strcpy(log_MAINConfigFileErr.LogMsg,"[1003$MAIN_ConfigFileErr]:�����ļ����д�:%s");
        infoVector[1003]=log_MAINConfigFileErr;
        
    
        SLog log_MAINConfigFileSvrNumber;
        log_MAINConfigFileSvrNumber.LogID = 1004;
        log_MAINConfigFileSvrNumber.LogLevel = LL_Debug;
        std::strcpy(log_MAINConfigFileSvrNumber.LogCode,"MAIN_ConfigFileSvrNumber");
        std::strcpy(log_MAINConfigFileSvrNumber.LogMsg,"[1004$MAIN_ConfigFileSvrNumber]:�������ļ��з�����%d��������");
        infoVector[1004]=log_MAINConfigFileSvrNumber;
        
    
        SLog log_MAINMdrLoadSucc;
        log_MAINMdrLoadSucc.LogID = 1005;
        log_MAINMdrLoadSucc.LogLevel = LL_Debug;
        std::strcpy(log_MAINMdrLoadSucc.LogCode,"MAIN_MdrLoadSucc");
        std::strcpy(log_MAINMdrLoadSucc.LogMsg,"[1005$MAIN_MdrLoadSucc]:�ɹ�:���ص�%d�����������");
        infoVector[1005]=log_MAINMdrLoadSucc;
        
    
        SLog log_MAINMdrLoadFail;
        log_MAINMdrLoadFail.LogID = 1006;
        log_MAINMdrLoadFail.LogLevel = LL_Debug;
        std::strcpy(log_MAINMdrLoadFail.LogCode,"MAIN_MdrLoadFail");
        std::strcpy(log_MAINMdrLoadFail.LogMsg,"[1006$MAIN_MdrLoadFail]:ʧ��:���ص�%d�����������");
        infoVector[1006]=log_MAINMdrLoadFail;
        
    
        SLog log_MAINMdrLoadFinish;
        log_MAINMdrLoadFinish.LogID = 1007;
        log_MAINMdrLoadFinish.LogLevel = LL_Debug;
        std::strcpy(log_MAINMdrLoadFinish.LogCode,"MAIN_MdrLoadFinish");
        std::strcpy(log_MAINMdrLoadFinish.LogMsg,"[1007$MAIN_MdrLoadFinish]:���:�������������");
        infoVector[1007]=log_MAINMdrLoadFinish;
        
    
        SLog log_MAINConfigFileInvNumber;
        log_MAINConfigFileInvNumber.LogID = 1008;
        log_MAINConfigFileInvNumber.LogLevel = LL_Debug;
        std::strcpy(log_MAINConfigFileInvNumber.LogCode,"MAIN_ConfigFileInvNumber");
        std::strcpy(log_MAINConfigFileInvNumber.LogMsg,"[1008$MAIN_ConfigFileInvNumber]:�������ļ��з�����%d��Ͷ����");
        infoVector[1008]=log_MAINConfigFileInvNumber;
        
    
        SLog log_MAINInvLoadSucc;
        log_MAINInvLoadSucc.LogID = 1009;
        log_MAINInvLoadSucc.LogLevel = LL_Debug;
        std::strcpy(log_MAINInvLoadSucc.LogCode,"MAIN_InvLoadSucc");
        std::strcpy(log_MAINInvLoadSucc.LogMsg,"[1009$MAIN_InvLoadSucc]:�ɹ�:���ص�%d��Ͷ����");
        infoVector[1009]=log_MAINInvLoadSucc;
        
    
        SLog log_MAINInvLoadFail;
        log_MAINInvLoadFail.LogID = 1010;
        log_MAINInvLoadFail.LogLevel = LL_Debug;
        std::strcpy(log_MAINInvLoadFail.LogCode,"MAIN_InvLoadFail");
        std::strcpy(log_MAINInvLoadFail.LogMsg,"[1010$MAIN_InvLoadFail]:ʧ��:���ص�%d��Ͷ����");
        infoVector[1010]=log_MAINInvLoadFail;
        
    
        SLog log_MAINInvLoadFinish;
        log_MAINInvLoadFinish.LogID = 1011;
        log_MAINInvLoadFinish.LogLevel = LL_Debug;
        std::strcpy(log_MAINInvLoadFinish.LogCode,"MAIN_InvLoadFinish");
        std::strcpy(log_MAINInvLoadFinish.LogMsg,"[1011$MAIN_InvLoadFinish]:���:Ͷ���߼���");
        infoVector[1011]=log_MAINInvLoadFinish;
        
    
        SLog log_MAINXpathValueErr;
        log_MAINXpathValueErr.LogID = 1012;
        log_MAINXpathValueErr.LogLevel = LL_Debug;
        std::strcpy(log_MAINXpathValueErr.LogCode,"MAIN_XpathValueErr");
        std::strcpy(log_MAINXpathValueErr.LogMsg,"[1012$MAIN_XpathValueErr]:����:xmlpath:%s");
        infoVector[1012]=log_MAINXpathValueErr;
        
    
        SLog log_MAINLogPath;
        log_MAINLogPath.LogID = 1013;
        log_MAINLogPath.LogLevel = LL_Debug;
        std::strcpy(log_MAINLogPath.LogCode,"MAIN_LogPath");
        std::strcpy(log_MAINLogPath.LogMsg,"[1013$MAIN_LogPath]:���:��־��·����%s");
        infoVector[1013]=log_MAINLogPath;
        
    
        SLog log_MAINMdrInstrument;
        log_MAINMdrInstrument.LogID = 1014;
        log_MAINMdrInstrument.LogLevel = LL_Debug;
        std::strcpy(log_MAINMdrInstrument.LogCode,"MAIN_MdrInstrument");
        std::strcpy(log_MAINMdrInstrument.LogMsg,"[1014$MAIN_MdrInstrument]:����:������������%d����Լ");
        infoVector[1014]=log_MAINMdrInstrument;
        
    
        SLog log_PROTFOLIONotEnoughPoistion;
        log_PROTFOLIONotEnoughPoistion.LogID = 2002;
        log_PROTFOLIONotEnoughPoistion.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIONotEnoughPoistion.LogCode,"PROTFOLIO_NotEnoughPoistion");
        std::strcpy(log_PROTFOLIONotEnoughPoistion.LogMsg,"[2002$PROTFOLIO_NotEnoughPoistion]:�ֲֲ���");
        infoVector[2002]=log_PROTFOLIONotEnoughPoistion;
        
    
        SLog log_PROTFOLIONotFindPosition;
        log_PROTFOLIONotFindPosition.LogID = 2003;
        log_PROTFOLIONotFindPosition.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIONotFindPosition.LogCode,"PROTFOLIO_NotFindPosition");
        std::strcpy(log_PROTFOLIONotFindPosition.LogMsg,"[2003$PROTFOLIO_NotFindPosition]:û���ҵ��ֲ�");
        infoVector[2003]=log_PROTFOLIONotFindPosition;
        
    
        SLog log_PROTFOLIOOpenOrderNotFrozen;
        log_PROTFOLIOOpenOrderNotFrozen.LogID = 2004;
        log_PROTFOLIOOpenOrderNotFrozen.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIOOpenOrderNotFrozen.LogCode,"PROTFOLIO_OpenOrderNotFrozen");
        std::strcpy(log_PROTFOLIOOpenOrderNotFrozen.LogMsg,"[2004$PROTFOLIO_OpenOrderNotFrozen]:û���ҵ��ֲ�");
        infoVector[2004]=log_PROTFOLIOOpenOrderNotFrozen;
        
    
        SLog log_PROTFOLIOFrozenedPositionNotEnough;
        log_PROTFOLIOFrozenedPositionNotEnough.LogID = 2005;
        log_PROTFOLIOFrozenedPositionNotEnough.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIOFrozenedPositionNotEnough.LogCode,"PROTFOLIO_FrozenedPositionNotEnough");
        std::strcpy(log_PROTFOLIOFrozenedPositionNotEnough.LogMsg,"[2005$PROTFOLIO_FrozenedPositionNotEnough]:�ɽⶳ��λ����");
        infoVector[2005]=log_PROTFOLIOFrozenedPositionNotEnough;
        
    
        SLog log_PROTFOLIOPositionNotEnoughToFrozen;
        log_PROTFOLIOPositionNotEnoughToFrozen.LogID = 2006;
        log_PROTFOLIOPositionNotEnoughToFrozen.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIOPositionNotEnoughToFrozen.LogCode,"PROTFOLIO_PositionNotEnoughToFrozen");
        std::strcpy(log_PROTFOLIOPositionNotEnoughToFrozen.LogMsg,"[2006$PROTFOLIO_PositionNotEnoughToFrozen]:�ɶ����λ����");
        infoVector[2006]=log_PROTFOLIOPositionNotEnoughToFrozen;
        
    
        SLog log_PROTFOLIOOpenNotFrozen;
        log_PROTFOLIOOpenNotFrozen.LogID = 2007;
        log_PROTFOLIOOpenNotFrozen.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIOOpenNotFrozen.LogCode,"PROTFOLIO_OpenNotFrozen");
        std::strcpy(log_PROTFOLIOOpenNotFrozen.LogMsg,"[2007$PROTFOLIO_OpenNotFrozen]:����ָ������ڽⶳ�ֲ�");
        infoVector[2007]=log_PROTFOLIOOpenNotFrozen;
        
    
        SLog log_PROTFOLIOOpenNotUnfrozen;
        log_PROTFOLIOOpenNotUnfrozen.LogID = 2008;
        log_PROTFOLIOOpenNotUnfrozen.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIOOpenNotUnfrozen.LogCode,"PROTFOLIO_OpenNotUnfrozen");
        std::strcpy(log_PROTFOLIOOpenNotUnfrozen.LogMsg,"[2008$PROTFOLIO_OpenNotUnfrozen]:����ָ������ڶ���ֲ�");
        infoVector[2008]=log_PROTFOLIOOpenNotUnfrozen;
        
    
        SLog log_PROTFOLIOFrozenedMoneyNotEnough;
        log_PROTFOLIOFrozenedMoneyNotEnough.LogID = 2009;
        log_PROTFOLIOFrozenedMoneyNotEnough.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIOFrozenedMoneyNotEnough.LogCode,"PROTFOLIO_FrozenedMoneyNotEnough");
        std::strcpy(log_PROTFOLIOFrozenedMoneyNotEnough.LogMsg,"[2009$PROTFOLIO_FrozenedMoneyNotEnough]:������ʽ���");
        infoVector[2009]=log_PROTFOLIOFrozenedMoneyNotEnough;
        
    
        SLog log_PROTFOLIONotFindInsturmentBySingnal;
        log_PROTFOLIONotFindInsturmentBySingnal.LogID = 2010;
        log_PROTFOLIONotFindInsturmentBySingnal.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIONotFindInsturmentBySingnal.LogCode,"PROTFOLIO_NotFindInsturmentBySingnal");
        std::strcpy(log_PROTFOLIONotFindInsturmentBySingnal.LogMsg,"[2010$PROTFOLIO_NotFindInsturmentBySingnal]:�Խ����ź�Ϊ����û���ҵ���Ӧ�ĺ�Լ����");
        infoVector[2010]=log_PROTFOLIONotFindInsturmentBySingnal;
        
    
        SLog log_PROTFOLIOInsturmentsNull;
        log_PROTFOLIOInsturmentsNull.LogID = 2011;
        log_PROTFOLIOInsturmentsNull.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIOInsturmentsNull.LogCode,"PROTFOLIO_InsturmentsNull");
        std::strcpy(log_PROTFOLIOInsturmentsNull.LogMsg,"[2011$PROTFOLIO_InsturmentsNull]:��Լ����Ϊ��");
        infoVector[2011]=log_PROTFOLIOInsturmentsNull;
        
    
        SLog log_PROTFOLIOOrdersNull;
        log_PROTFOLIOOrdersNull.LogID = 2012;
        log_PROTFOLIOOrdersNull.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIOOrdersNull.LogCode,"PROTFOLIO_OrdersNull");
        std::strcpy(log_PROTFOLIOOrdersNull.LogMsg,"[2012$PROTFOLIO_OrdersNull]:��������Ϊ��");
        infoVector[2012]=log_PROTFOLIOOrdersNull;
        
    
        SLog log_PROTFOLIONotFindOrderByTrade;
        log_PROTFOLIONotFindOrderByTrade.LogID = 2013;
        log_PROTFOLIONotFindOrderByTrade.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIONotFindOrderByTrade.LogCode,"PROTFOLIO_NotFindOrderByTrade");
        std::strcpy(log_PROTFOLIONotFindOrderByTrade.LogMsg,"[2013$PROTFOLIO_NotFindOrderByTrade]:�Գɽ�Ϊ����û���ҵ���Ӧ�ı���");
        infoVector[2013]=log_PROTFOLIONotFindOrderByTrade;
        
    
        SLog log_PROTFOLIOMarginNotEnough;
        log_PROTFOLIOMarginNotEnough.LogID = 2014;
        log_PROTFOLIOMarginNotEnough.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIOMarginNotEnough.LogCode,"PROTFOLIO_MarginNotEnough");
        std::strcpy(log_PROTFOLIOMarginNotEnough.LogMsg,"[2014$PROTFOLIO_MarginNotEnough]:ռ�õı�֤����");
        infoVector[2014]=log_PROTFOLIOMarginNotEnough;
        
    
        SLog log_PROTFOLIONotFindInsturmentByTrade;
        log_PROTFOLIONotFindInsturmentByTrade.LogID = 2015;
        log_PROTFOLIONotFindInsturmentByTrade.LogLevel = LL_Debug;
        std::strcpy(log_PROTFOLIONotFindInsturmentByTrade.LogCode,"PROTFOLIO_NotFindInsturmentByTrade");
        std::strcpy(log_PROTFOLIONotFindInsturmentByTrade.LogMsg,"[2015$PROTFOLIO_NotFindInsturmentByTrade]:�Գɽ�Ϊ����û���ҵ���Ӧ�ĺ�Լ����");
        infoVector[2015]=log_PROTFOLIONotFindInsturmentByTrade;
        
    
        SLog log_CONNECTORHIS_TradingDayIs;
        log_CONNECTORHIS_TradingDayIs.LogID = 3001;
        log_CONNECTORHIS_TradingDayIs.LogLevel = LL_Debug;
        std::strcpy(log_CONNECTORHIS_TradingDayIs.LogCode,"CONNECTOR_HIS_TradingDayIs");
        std::strcpy(log_CONNECTORHIS_TradingDayIs.LogMsg,"[3001$CONNECTOR_HIS_TradingDayIs]:��ʷ�������ǣ�%s");
        infoVector[3001]=log_CONNECTORHIS_TradingDayIs;
        
    
        SLog log_CONNECTORNewMDIsEmpty;
        log_CONNECTORNewMDIsEmpty.LogID = 3002;
        log_CONNECTORNewMDIsEmpty.LogLevel = LL_Debug;
        std::strcpy(log_CONNECTORNewMDIsEmpty.LogCode,"CONNECTOR_NewMDIsEmpty");
        std::strcpy(log_CONNECTORNewMDIsEmpty.LogMsg,"[3002$CONNECTOR_NewMDIsEmpty]:������Ϊ��");
        infoVector[3002]=log_CONNECTORNewMDIsEmpty;
        
    
        SLog log_CONNECTORCtpMDIsEmpty;
        log_CONNECTORCtpMDIsEmpty.LogID = 3003;
        log_CONNECTORCtpMDIsEmpty.LogLevel = LL_Debug;
        std::strcpy(log_CONNECTORCtpMDIsEmpty.LogCode,"CONNECTOR_CtpMDIsEmpty");
        std::strcpy(log_CONNECTORCtpMDIsEmpty.LogMsg,"[3003$CONNECTOR_CtpMDIsEmpty]:CTP�������Ϊ��");
        infoVector[3003]=log_CONNECTORCtpMDIsEmpty;
        
    
        SLog log_CONNECTORCtpTradeIsEmpty;
        log_CONNECTORCtpTradeIsEmpty.LogID = 3004;
        log_CONNECTORCtpTradeIsEmpty.LogLevel = LL_Debug;
        std::strcpy(log_CONNECTORCtpTradeIsEmpty.LogCode,"CONNECTOR_CtpTradeIsEmpty");
        std::strcpy(log_CONNECTORCtpTradeIsEmpty.LogMsg,"[3004$CONNECTOR_CtpTradeIsEmpty]:CTP���׶���Ϊ��");
        infoVector[3004]=log_CONNECTORCtpTradeIsEmpty;
        
    
        SLog log_DATAROUTEMsgQueClosed;
        log_DATAROUTEMsgQueClosed.LogID = 4001;
        log_DATAROUTEMsgQueClosed.LogLevel = LL_Debug;
        std::strcpy(log_DATAROUTEMsgQueClosed.LogCode,"DATAROUTE_MsgQueClosed");
        std::strcpy(log_DATAROUTEMsgQueClosed.LogMsg,"[4001$DATAROUTE_MsgQueClosed]:��Ϣ�����Ѿ��ر���");
        infoVector[4001]=log_DATAROUTEMsgQueClosed;
        
    
        SLog log_DATAROUTEMsgEmpty;
        log_DATAROUTEMsgEmpty.LogID = 4002;
        log_DATAROUTEMsgEmpty.LogLevel = LL_Debug;
        std::strcpy(log_DATAROUTEMsgEmpty.LogCode,"DATAROUTE_MsgEmpty");
        std::strcpy(log_DATAROUTEMsgEmpty.LogMsg,"[4002$DATAROUTE_MsgEmpty]:����Ϣ����");
        infoVector[4002]=log_DATAROUTEMsgEmpty;
        
    
        SLog log_DATAROUTEMsgQueMaxSizeLessOne;
        log_DATAROUTEMsgQueMaxSizeLessOne.LogID = 4003;
        log_DATAROUTEMsgQueMaxSizeLessOne.LogLevel = LL_Debug;
        std::strcpy(log_DATAROUTEMsgQueMaxSizeLessOne.LogCode,"DATAROUTE_MsgQueMaxSizeLessOne");
        std::strcpy(log_DATAROUTEMsgQueMaxSizeLessOne.LogMsg,"[4003$DATAROUTE_MsgQueMaxSizeLessOne]:��Ϣ������󳤶�С��1��");
        infoVector[4003]=log_DATAROUTEMsgQueMaxSizeLessOne;
        
    
        SLog log_DATAROUTEQueSizeAfterPush;
        log_DATAROUTEQueSizeAfterPush.LogID = 4004;
        log_DATAROUTEQueSizeAfterPush.LogLevel = LL_Debug;
        std::strcpy(log_DATAROUTEQueSizeAfterPush.LogCode,"DATAROUTE_QueSizeAfterPush");
        std::strcpy(log_DATAROUTEQueSizeAfterPush.LogMsg,"[4004$DATAROUTE_QueSizeAfterPush]:QueSizeAfterPush:%d ");
        infoVector[4004]=log_DATAROUTEQueSizeAfterPush;
        
    
        SLog log_DATAROUTEQueSizeAfterPop;
        log_DATAROUTEQueSizeAfterPop.LogID = 4005;
        log_DATAROUTEQueSizeAfterPop.LogLevel = LL_Debug;
        std::strcpy(log_DATAROUTEQueSizeAfterPop.LogCode,"DATAROUTE_QueSizeAfterPop");
        std::strcpy(log_DATAROUTEQueSizeAfterPop.LogMsg,"[4005$DATAROUTE_QueSizeAfterPop]:QueSizeAfterPop:%d ");
        infoVector[4005]=log_DATAROUTEQueSizeAfterPop;
        
    
        SLog log_SPIMD_Connected;
        log_SPIMD_Connected.LogID = 5001;
        log_SPIMD_Connected.LogLevel = LL_Debug;
        std::strcpy(log_SPIMD_Connected.LogCode,"SPI_MD_Connected");
        std::strcpy(log_SPIMD_Connected.LogMsg,"[5001$SPI_MD_Connected]:CTP������������ӳɹ�");
        infoVector[5001]=log_SPIMD_Connected;
        
    
        SLog log_SPIMD_Disconnected;
        log_SPIMD_Disconnected.LogID = 5002;
        log_SPIMD_Disconnected.LogLevel = LL_Debug;
        std::strcpy(log_SPIMD_Disconnected.LogCode,"SPI_MD_Disconnected");
        std::strcpy(log_SPIMD_Disconnected.LogMsg,"[5002$SPI_MD_Disconnected]:CTP����������Ѿ��Ͽ�");
        infoVector[5002]=log_SPIMD_Disconnected;
        
    
        SLog log_SPIMD_LoginSucc;
        log_SPIMD_LoginSucc.LogID = 5003;
        log_SPIMD_LoginSucc.LogLevel = LL_Debug;
        std::strcpy(log_SPIMD_LoginSucc.LogCode,"SPI_MD_LoginSucc");
        std::strcpy(log_SPIMD_LoginSucc.LogMsg,"[5003$SPI_MD_LoginSucc]:��¼��CTP���������");
        infoVector[5003]=log_SPIMD_LoginSucc;
        
    
        SLog log_SPIMD_LoginFail;
        log_SPIMD_LoginFail.LogID = 5004;
        log_SPIMD_LoginFail.LogLevel = LL_Debug;
        std::strcpy(log_SPIMD_LoginFail.LogCode,"SPI_MD_LoginFail");
        std::strcpy(log_SPIMD_LoginFail.LogMsg,"[5004$SPI_MD_LoginFail]:��¼CTP���������ʧ��");
        infoVector[5004]=log_SPIMD_LoginFail;
        
    
        SLog log_SPIMD_ServerErr;
        log_SPIMD_ServerErr.LogID = 5005;
        log_SPIMD_ServerErr.LogLevel = LL_Debug;
        std::strcpy(log_SPIMD_ServerErr.LogCode,"SPI_MD_ServerErr");
        std::strcpy(log_SPIMD_ServerErr.LogMsg,"[5005$SPI_MD_ServerErr]:CTP�������������%s");
        infoVector[5005]=log_SPIMD_ServerErr;
        
    
        SLog log_SPIMD_NewInsturments;
        log_SPIMD_NewInsturments.LogID = 5006;
        log_SPIMD_NewInsturments.LogLevel = LL_Debug;
        std::strcpy(log_SPIMD_NewInsturments.LogCode,"SPI_MD_NewInsturments");
        std::strcpy(log_SPIMD_NewInsturments.LogMsg,"[5006$SPI_MD_NewInsturments]:CTP����������������º�Լ��%s");
        infoVector[5006]=log_SPIMD_NewInsturments;
        
    
        SLog log_SPIMD_TradingDayIs;
        log_SPIMD_TradingDayIs.LogID = 5007;
        log_SPIMD_TradingDayIs.LogLevel = LL_Debug;
        std::strcpy(log_SPIMD_TradingDayIs.LogCode,"SPI_MD_TradingDayIs");
        std::strcpy(log_SPIMD_TradingDayIs.LogMsg,"[5007$SPI_MD_TradingDayIs]:CTP����������Ľ������ǣ�%s");
        infoVector[5007]=log_SPIMD_TradingDayIs;
        
    
        SLog log_SPIT_Connected;
        log_SPIT_Connected.LogID = 5008;
        log_SPIT_Connected.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_Connected.LogCode,"SPI_T_Connected");
        std::strcpy(log_SPIT_Connected.LogMsg,"[5008$SPI_T_Connected]:CTP���׷��������ӳɹ�");
        infoVector[5008]=log_SPIT_Connected;
        
    
        SLog log_SPIT_Disconnected;
        log_SPIT_Disconnected.LogID = 5009;
        log_SPIT_Disconnected.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_Disconnected.LogCode,"SPI_T_Disconnected");
        std::strcpy(log_SPIT_Disconnected.LogMsg,"[5009$SPI_T_Disconnected]:CTP���׷������Ѿ��Ͽ�:%d");
        infoVector[5009]=log_SPIT_Disconnected;
        
    
        SLog log_SPIT_LoginSucc;
        log_SPIT_LoginSucc.LogID = 5010;
        log_SPIT_LoginSucc.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_LoginSucc.LogCode,"SPI_T_LoginSucc");
        std::strcpy(log_SPIT_LoginSucc.LogMsg,"[5010$SPI_T_LoginSucc]:CTP��¼�����׷�����");
        infoVector[5010]=log_SPIT_LoginSucc;
        
    
        SLog log_SPIT_LoginFail;
        log_SPIT_LoginFail.LogID = 5011;
        log_SPIT_LoginFail.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_LoginFail.LogCode,"SPI_T_LoginFail");
        std::strcpy(log_SPIT_LoginFail.LogMsg,"[5011$SPI_T_LoginFail]:CTP��¼���׷�����ʧ��");
        infoVector[5011]=log_SPIT_LoginFail;
        
    
        SLog log_SPIT_ServerErr;
        log_SPIT_ServerErr.LogID = 5012;
        log_SPIT_ServerErr.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_ServerErr.LogCode,"SPI_T_ServerErr");
        std::strcpy(log_SPIT_ServerErr.LogMsg,"[5012$SPI_T_ServerErr]:CTP���׷���������[%d]%s");
        infoVector[5012]=log_SPIT_ServerErr;
        
    
        SLog log_SPIT_TradingDayIs;
        log_SPIT_TradingDayIs.LogID = 5013;
        log_SPIT_TradingDayIs.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_TradingDayIs.LogCode,"SPI_T_TradingDayIs");
        std::strcpy(log_SPIT_TradingDayIs.LogMsg,"[5013$SPI_T_TradingDayIs]:CTP���׷������Ľ������ǣ�%s");
        infoVector[5013]=log_SPIT_TradingDayIs;
        
    
        SLog log_SPIT_SettInfoConfirmSucc;
        log_SPIT_SettInfoConfirmSucc.LogID = 5014;
        log_SPIT_SettInfoConfirmSucc.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_SettInfoConfirmSucc.LogCode,"SPI_T_SettInfoConfirmSucc");
        std::strcpy(log_SPIT_SettInfoConfirmSucc.LogMsg,"[5014$SPI_T_SettInfoConfirmSucc]:CTP���㵥��Ϣȷ�ϳɹ�");
        infoVector[5014]=log_SPIT_SettInfoConfirmSucc;
        
    
        SLog log_SPIT_SettInfoConfirmFail;
        log_SPIT_SettInfoConfirmFail.LogID = 5015;
        log_SPIT_SettInfoConfirmFail.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_SettInfoConfirmFail.LogCode,"SPI_T_SettInfoConfirmFail");
        std::strcpy(log_SPIT_SettInfoConfirmFail.LogMsg,"[5015$SPI_T_SettInfoConfirmFail]:CTP���㵥��Ϣȷ��ʧ��");
        infoVector[5015]=log_SPIT_SettInfoConfirmFail;
        
    
        SLog log_SPIT_QryInstrumentSucc;
        log_SPIT_QryInstrumentSucc.LogID = 5016;
        log_SPIT_QryInstrumentSucc.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_QryInstrumentSucc.LogCode,"SPI_T_QryInstrumentSucc");
        std::strcpy(log_SPIT_QryInstrumentSucc.LogMsg,"[5016$SPI_T_QryInstrumentSucc]:��ѯCTP��Լ�ɹ�");
        infoVector[5016]=log_SPIT_QryInstrumentSucc;
        
    
        SLog log_SPIT_QryInstrumentFail;
        log_SPIT_QryInstrumentFail.LogID = 5017;
        log_SPIT_QryInstrumentFail.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_QryInstrumentFail.LogCode,"SPI_T_QryInstrumentFail");
        std::strcpy(log_SPIT_QryInstrumentFail.LogMsg,"[5017$SPI_T_QryInstrumentFail]:��ѯCTP��Լʧ��");
        infoVector[5017]=log_SPIT_QryInstrumentFail;
        
    
        SLog log_SPIT_QryInstrumentFC;
        log_SPIT_QryInstrumentFC.LogID = 5018;
        log_SPIT_QryInstrumentFC.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_QryInstrumentFC.LogCode,"SPI_T_QryInstrumentFC");
        std::strcpy(log_SPIT_QryInstrumentFC.LogMsg,"[5018$SPI_T_QryInstrumentFC]:��ѯCTP��Լ�ܵ�����");
        infoVector[5018]=log_SPIT_QryInstrumentFC;
        
    
        SLog log_SPIT_QryTradingAccountSucc;
        log_SPIT_QryTradingAccountSucc.LogID = 5019;
        log_SPIT_QryTradingAccountSucc.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_QryTradingAccountSucc.LogCode,"SPI_T_QryTradingAccountSucc");
        std::strcpy(log_SPIT_QryTradingAccountSucc.LogMsg,"[5019$SPI_T_QryTradingAccountSucc]:��ѯCTP�ʽ��˻��ɹ�");
        infoVector[5019]=log_SPIT_QryTradingAccountSucc;
        
    
        SLog log_SPIT_QryTradingAccountFail;
        log_SPIT_QryTradingAccountFail.LogID = 5020;
        log_SPIT_QryTradingAccountFail.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_QryTradingAccountFail.LogCode,"SPI_T_QryTradingAccountFail");
        std::strcpy(log_SPIT_QryTradingAccountFail.LogMsg,"[5020$SPI_T_QryTradingAccountFail]:��ѯCTP�ʽ��˻�ʧ��");
        infoVector[5020]=log_SPIT_QryTradingAccountFail;
        
    
        SLog log_SPIT_QryTradingAccountFC;
        log_SPIT_QryTradingAccountFC.LogID = 5021;
        log_SPIT_QryTradingAccountFC.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_QryTradingAccountFC.LogCode,"SPI_T_QryTradingAccountFC");
        std::strcpy(log_SPIT_QryTradingAccountFC.LogMsg,"[5021$SPI_T_QryTradingAccountFC]:��ѯCTP�ʽ��˻��ܵ�����");
        infoVector[5021]=log_SPIT_QryTradingAccountFC;
        
    
        SLog log_SPIT_QryInvestorPositionSucc;
        log_SPIT_QryInvestorPositionSucc.LogID = 5022;
        log_SPIT_QryInvestorPositionSucc.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_QryInvestorPositionSucc.LogCode,"SPI_T_QryInvestorPositionSucc");
        std::strcpy(log_SPIT_QryInvestorPositionSucc.LogMsg,"[5022$SPI_T_QryInvestorPositionSucc]:��ѯCTPͶ���ֲֳ߳ɹ�");
        infoVector[5022]=log_SPIT_QryInvestorPositionSucc;
        
    
        SLog log_SPIT_QryInvestorPositionFail;
        log_SPIT_QryInvestorPositionFail.LogID = 5023;
        log_SPIT_QryInvestorPositionFail.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_QryInvestorPositionFail.LogCode,"SPI_T_QryInvestorPositionFail");
        std::strcpy(log_SPIT_QryInvestorPositionFail.LogMsg,"[5023$SPI_T_QryInvestorPositionFail]:��ѯCTPͶ���ֲ߳�ʧ��");
        infoVector[5023]=log_SPIT_QryInvestorPositionFail;
        
    
        SLog log_SPIT_QryInvestorPositionFC;
        log_SPIT_QryInvestorPositionFC.LogID = 5024;
        log_SPIT_QryInvestorPositionFC.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_QryInvestorPositionFC.LogCode,"SPI_T_QryInvestorPositionFC");
        std::strcpy(log_SPIT_QryInvestorPositionFC.LogMsg,"[5024$SPI_T_QryInvestorPositionFC]:��ѯCTPͶ���ֲ߳��ܵ�����");
        infoVector[5024]=log_SPIT_QryInvestorPositionFC;
        
    
        SLog log_SPIT_OrderInsertSucc;
        log_SPIT_OrderInsertSucc.LogID = 5025;
        log_SPIT_OrderInsertSucc.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_OrderInsertSucc.LogCode,"SPI_T_OrderInsertSucc");
        std::strcpy(log_SPIT_OrderInsertSucc.LogMsg,"[5025$SPI_T_OrderInsertSucc]:CTP����¼��ɹ�");
        infoVector[5025]=log_SPIT_OrderInsertSucc;
        
    
        SLog log_SPIT_OrderInsertFail;
        log_SPIT_OrderInsertFail.LogID = 5026;
        log_SPIT_OrderInsertFail.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_OrderInsertFail.LogCode,"SPI_T_OrderInsertFail");
        std::strcpy(log_SPIT_OrderInsertFail.LogMsg,"[5026$SPI_T_OrderInsertFail]:CTP����¼��ʧ��");
        infoVector[5026]=log_SPIT_OrderInsertFail;
        
    
        SLog log_SPIT_OrderActionSucc;
        log_SPIT_OrderActionSucc.LogID = 5027;
        log_SPIT_OrderActionSucc.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_OrderActionSucc.LogCode,"SPI_T_OrderActionSucc");
        std::strcpy(log_SPIT_OrderActionSucc.LogMsg,"[5027$SPI_T_OrderActionSucc]:CTP���������ɹ�");
        infoVector[5027]=log_SPIT_OrderActionSucc;
        
    
        SLog log_SPIT_OrderActionFail;
        log_SPIT_OrderActionFail.LogID = 5028;
        log_SPIT_OrderActionFail.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_OrderActionFail.LogCode,"SPI_T_OrderActionFail");
        std::strcpy(log_SPIT_OrderActionFail.LogMsg,"[5028$SPI_T_OrderActionFail]:CTP��������ʧ��");
        infoVector[5028]=log_SPIT_OrderActionFail;
        
    
        SLog log_SPIT_RtnOrder;
        log_SPIT_RtnOrder.LogID = 5029;
        log_SPIT_RtnOrder.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_RtnOrder.LogCode,"SPI_T_RtnOrder");
        std::strcpy(log_SPIT_RtnOrder.LogMsg,"[5029$SPI_T_RtnOrder]:�յ�CTP������Ӧ");
        infoVector[5029]=log_SPIT_RtnOrder;
        
    
        SLog log_SPIT_OrderCanceled;
        log_SPIT_OrderCanceled.LogID = 5030;
        log_SPIT_OrderCanceled.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_OrderCanceled.LogCode,"SPI_T_OrderCanceled");
        std::strcpy(log_SPIT_OrderCanceled.LogMsg,"[5030$SPI_T_OrderCanceled]:CTP�����ɹ�");
        infoVector[5030]=log_SPIT_OrderCanceled;
        
    
        SLog log_SPIT_RtnTrade;
        log_SPIT_RtnTrade.LogID = 5031;
        log_SPIT_RtnTrade.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_RtnTrade.LogCode,"SPI_T_RtnTrade");
        std::strcpy(log_SPIT_RtnTrade.LogMsg,"[5031$SPI_T_RtnTrade]:�յ�CTP�ɽ���Ӧ");
        infoVector[5031]=log_SPIT_RtnTrade;
        
    
        SLog log_SPIT_HeartBeat;
        log_SPIT_HeartBeat.LogID = 5032;
        log_SPIT_HeartBeat.LogLevel = LL_Debug;
        std::strcpy(log_SPIT_HeartBeat.LogCode,"SPI_T_HeartBeat");
        std::strcpy(log_SPIT_HeartBeat.LogMsg,"[5032$SPI_T_HeartBeat]:CTP����:%d");
        infoVector[5032]=log_SPIT_HeartBeat;
        
    
        SLog log_TCOREDS_RealFundSelectByInvestorIDFatal;
        log_TCOREDS_RealFundSelectByInvestorIDFatal.LogID = 6001;
        log_TCOREDS_RealFundSelectByInvestorIDFatal.LogLevel = LL_Debug;
        std::strcpy(log_TCOREDS_RealFundSelectByInvestorIDFatal.LogCode,"TCORE_DS_RealFundSelectByInvestorIDFatal");
        std::strcpy(log_TCOREDS_RealFundSelectByInvestorIDFatal.LogMsg,"[6001$TCORE_DS_RealFundSelectByInvestorIDFatal]:����InvestorID��λRealFundʧ��");
        infoVector[6001]=log_TCOREDS_RealFundSelectByInvestorIDFatal;
        
    
        SLog log_TCOREDS_NotEnoughAvailableForOut;
        log_TCOREDS_NotEnoughAvailableForOut.LogID = 6002;
        log_TCOREDS_NotEnoughAvailableForOut.LogLevel = LL_Debug;
        std::strcpy(log_TCOREDS_NotEnoughAvailableForOut.LogCode,"TCORE_DS_NotEnoughAvailableForOut");
        std::strcpy(log_TCOREDS_NotEnoughAvailableForOut.LogMsg,"[6002$TCORE_DS_NotEnoughAvailableForOut]:���ڳ���Ŀ����ʽ���");
        infoVector[6002]=log_TCOREDS_NotEnoughAvailableForOut;
        
    
        SLog log_TCOREModelInIsNull;
        log_TCOREModelInIsNull.LogID = 6003;
        log_TCOREModelInIsNull.LogLevel = LL_Debug;
        std::strcpy(log_TCOREModelInIsNull.LogCode,"TCORE_ModelInIsNull");
        std::strcpy(log_TCOREModelInIsNull.LogMsg,"[6003$TCORE_ModelInIsNull]:�����ģ��ָ��Ϊ��");
        infoVector[6003]=log_TCOREModelInIsNull;
        
    
        SLog log_TCOREDS_OrderReqSelectByLocalOrderIDFatal;
        log_TCOREDS_OrderReqSelectByLocalOrderIDFatal.LogID = 6004;
        log_TCOREDS_OrderReqSelectByLocalOrderIDFatal.LogLevel = LL_Debug;
        std::strcpy(log_TCOREDS_OrderReqSelectByLocalOrderIDFatal.LogCode,"TCORE_DS_OrderReqSelectByLocalOrderIDFatal");
        std::strcpy(log_TCOREDS_OrderReqSelectByLocalOrderIDFatal.LogMsg,"[6004$TCORE_DS_OrderReqSelectByLocalOrderIDFatal]:����LocalOrderID��λOrderReqʧ��");
        infoVector[6004]=log_TCOREDS_OrderReqSelectByLocalOrderIDFatal;
        
    
        SLog log_TCOREDS_InstrumentSelectByInstrumentIDFatal;
        log_TCOREDS_InstrumentSelectByInstrumentIDFatal.LogID = 6005;
        log_TCOREDS_InstrumentSelectByInstrumentIDFatal.LogLevel = LL_Debug;
        std::strcpy(log_TCOREDS_InstrumentSelectByInstrumentIDFatal.LogCode,"TCORE_DS_InstrumentSelectByInstrumentIDFatal");
        std::strcpy(log_TCOREDS_InstrumentSelectByInstrumentIDFatal.LogMsg,"[6005$TCORE_DS_InstrumentSelectByInstrumentIDFatal]:����InstrumentID��λInstrumentʧ��");
        infoVector[6005]=log_TCOREDS_InstrumentSelectByInstrumentIDFatal;
        
    
        SLog log_TCOREDS_MarginRateSelectByInvestorIDInstrumentIDFatal;
        log_TCOREDS_MarginRateSelectByInvestorIDInstrumentIDFatal.LogID = 6006;
        log_TCOREDS_MarginRateSelectByInvestorIDInstrumentIDFatal.LogLevel = LL_Debug;
        std::strcpy(log_TCOREDS_MarginRateSelectByInvestorIDInstrumentIDFatal.LogCode,"TCORE_DS_MarginRateSelectByInvestorIDInstrumentIDFatal");
        std::strcpy(log_TCOREDS_MarginRateSelectByInvestorIDInstrumentIDFatal.LogMsg,"[6006$TCORE_DS_MarginRateSelectByInvestorIDInstrumentIDFatal]:����InvestorID��InstrumentID��λMarginRateʧ��");
        infoVector[6006]=log_TCOREDS_MarginRateSelectByInvestorIDInstrumentIDFatal;
        
    
        SLog log_TCOREDS_FeeRateSelectByInvestorIDInstrumentIDFatal;
        log_TCOREDS_FeeRateSelectByInvestorIDInstrumentIDFatal.LogID = 6007;
        log_TCOREDS_FeeRateSelectByInvestorIDInstrumentIDFatal.LogLevel = LL_Debug;
        std::strcpy(log_TCOREDS_FeeRateSelectByInvestorIDInstrumentIDFatal.LogCode,"TCORE_DS_FeeRateSelectByInvestorIDInstrumentIDFatal");
        std::strcpy(log_TCOREDS_FeeRateSelectByInvestorIDInstrumentIDFatal.LogMsg,"[6007$TCORE_DS_FeeRateSelectByInvestorIDInstrumentIDFatal]:����InvestorID��InstrumentID��λFeeRateʧ��");
        infoVector[6007]=log_TCOREDS_FeeRateSelectByInvestorIDInstrumentIDFatal;
        
    
        SLog log_TCOREDS_RealPositionSelectByInvestorIDInstrumentIDDirectionFatal;
        log_TCOREDS_RealPositionSelectByInvestorIDInstrumentIDDirectionFatal.LogID = 6008;
        log_TCOREDS_RealPositionSelectByInvestorIDInstrumentIDDirectionFatal.LogLevel = LL_Debug;
        std::strcpy(log_TCOREDS_RealPositionSelectByInvestorIDInstrumentIDDirectionFatal.LogCode,"TCORE_DS_RealPositionSelectByInvestorIDInstrumentIDDirectionFatal");
        std::strcpy(log_TCOREDS_RealPositionSelectByInvestorIDInstrumentIDDirectionFatal.LogMsg,"[6008$TCORE_DS_RealPositionSelectByInvestorIDInstrumentIDDirectionFatal]:����InvestorID��InstrumentID��λRealPositionʧ��");
        infoVector[6008]=log_TCOREDS_RealPositionSelectByInvestorIDInstrumentIDDirectionFatal;
        
    
}
#endif//CSTDLOG_CPP_
		