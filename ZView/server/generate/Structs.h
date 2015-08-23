
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file Structs.h
///@brief ���幫�õĽṹ��,���ڳ������ɣ���Ҫ�ֹ��޸�
///@author xsltģ�ʹ���ת������
///@date 2013-06-21T07:28:26.879Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "TypeDefine.h"

#ifndef STRUCTS_H_
#define STRUCTS_H_

namespace ZYSystem {


///@struct ��־��Ϣ����
#define TPID_Log 1
struct SLog {
	
	///@brief ������,ÿ����־��Ψһ���	
	TID LogID;
		
	///@brief ��־����,������־Ӧ����ʲô״�������	
	TLogLevel LogLevel;
		
	///@brief ��־����,��־�Ĵ��룬����define�ͷ�����	
	TCode LogCode;
		
	///@brief ��־��Ϣ,��־�ľ���������Ϣ	
	TMemo LogMsg;
		
};	

///@struct �����ṩ��������Ϣ
#define TPID_MarketDataProvider 2
struct SMarketDataProvider {
	
	///@brief ���������,�����������ʶ�����	
	TConnectionID ConnectionID;
		
	///@brief Զ����������ַ,Զ������������ĵ�ַ	
	TURL Td_url;
		
	///@brief Զ�̽��׷����ַ,Զ�̽��׷������ĵ�ַ	
	TURL Md_url;
		
	///@brief ��������,������������յ���������	
	TMarketDataType ConnectionType;
		
	///@brief Ͷ���ߴ���,Ͷ����ʵ���Ψһ��ʶ	
	TInvestorID InvestorID;
		
};	

///@struct Ͷ����
#define TPID_Investor 3
struct SInvestor {
	
	///@brief Ͷ���ߴ���,Ͷ����ʵ���Ψһ��ʶ	
	TInvestorID InvestorID;
		
	///@brief ��������,Ͷ�������ڵ�¼ϵͳ�����׵�����	
	TPassword InvestorPassword;
		
	///@brief �ʽ��˺�,��Ͷ���߹������ʽ��˺�	
	TInvestorID AccountID;
		
	///@brief �ʽ�����,Ͷ���������ʽ�ת������	
	TPassword AccountPassword;
		
	///@brief ���͹�˾����,Ͷ�������ڵľ��͹�˾���ۺϽ���ƽ̨�ı�ʶ	
	TBrokerID BrokerID;
		
};	

///@struct ϵͳ���յ�����������
#define TPID_MarketData 4
struct SMarketData {
	
	///@brief ������,������	
	TDate TradingDay;
		
	///@brief ��Լ����,��Լ��ϵͳ�еı��	
	TInstrumentID InstrumentID;
		
	///@brief ����������,һ���������ı��	
	TExchangeID ExchangeID;
		
	///@brief ���¼�,���ոú�Լ�����ڼ�����³ɽ��۸�	
	TPrice LastPrice;
		
	///@brief �ϴν����,��һ�յĽ����	
	TPrice PreSettlementPrice;
		
	///@brief ������,��һ�����̼�	
	TPrice PreClosePrice;
		
	///@brief ��ֲ���,ǰ���ֲ�����˫�����	
	TLargeVolume PreOpenInterest;
		
	///@brief ����,���ڻ���Լ����ǰ������ھ����Ͼ��۲����ĳɽ��۸�	
	TPrice OpenPrice;
		
	///@brief ��߼�,ָһ��ʱ���ڸú�Լ�ɽ����е���߳ɽ��۸�	
	TPrice HighestPrice;
		
	///@brief ��ͼ�,ָһ��ʱ���ڸú�Լ�ɽ����е���ͳɽ��۸�	
	TPrice LowestPrice;
		
	///@brief ����,�ú�Լ�ڵ��ս����ڼ����гɽ���Լ��˫������	
	TVolume Volume;
		
	///@brief �ɽ����,�ú�Լ��ɽ��׵���ֵ	
	TMoney Turnover;
		
	///@brief �ֲ���,���ֲ�����˫�����	
	TLargeVolume OpenInterest;
		
	///@brief ������,�ú�Լ���ս��׵����һ�ʳɽ��۸�	
	TPrice ClosePrice;
		
	///@brief ���ν����,�ú�Լ���ճɽ��۸񰴳ɽ����ļ�Ȩƽ���ۣ������޳ɽ��ģ�����һ�ս����	
	TPrice SettlementPrice;
		
	///@brief ��ͣ���,��ͣ���	
	TPrice UpperLimitPrice;
		
	///@brief ��ͣ���,��ͣ���	
	TPrice LowerLimitPrice;
		
	///@brief ����ʵ��,��Ȩ�õ�������ʵ��	
	TRatio PreDelta;
		
	///@brief ����ʵ��,��Ȩ�õĽ�����ʵ��	
	TRatio CurrDelta;
		
	///@brief ����޸�ʱ��,����޸�ʱ��	
	TTime UpdateTime;
		
	///@brief ����޸ĺ���,����޸ĺ���	
	TMillisec UpdateMillisec;
		
	///@brief �����һ,�����һ	
	TPrice BidPrice1;
		
	///@brief ������һ,������һ	
	TVolume BidVolume1;
		
	///@brief ������һ,������һ	
	TPrice AskPrice1;
		
	///@brief ������һ,������һ	
	TVolume AskVolume1;
		
	///@brief ���վ���,���վ���	
	TPrice AveragePrice;
		
};	

///@struct KDJָ��
#define TPID_KDJ 5
struct SKDJ {
	
	///@brief ������,������	
	TDate TradingDay;
		
	///@brief ��Լ����,��Լ��ϵͳ�еı��	
	TInstrumentID InstrumentID;
		
	///@brief ����������,һ���������ı��	
	TExchangeID ExchangeID;
		
	///@brief ����޸�ʱ��,����޸�ʱ��	
	TTime UpdateTime;
		
	///@brief ����޸ĺ���,����޸ĺ���	
	TMillisec UpdateMillisec;
		
	///@brief k��ֵ,k��ֵ	
	TIndexValue Idx_k;
		
	///@brief dָ��,dָ��	
	TIndexValue Idx_d;
		
	///@brief jָ��,jָ��	
	TIndexValue Idx_j;
		
};	

///@struct MACDָ��
#define TPID_MACD 6
struct SMACD {
	
	///@brief ������,������	
	TDate TradingDay;
		
	///@brief ��Լ����,��Լ��ϵͳ�еı��	
	TInstrumentID InstrumentID;
		
	///@brief ����������,һ���������ı��	
	TExchangeID ExchangeID;
		
	///@brief ����޸�ʱ��,����޸�ʱ��	
	TTime UpdateTime;
		
	///@brief ����޸ĺ���,����޸ĺ���	
	TMillisec UpdateMillisec;
		
	///@brief diff��ֵ,diff��ֵ	
	TIndexValue Idx_diff;
		
	///@brief deaָ��,deaָ��	
	TIndexValue Idx_dea;
		
	///@brief barָ��,barָ��	
	TIndexValue Idx_bar;
		
};	

///@struct ����ģ������
#define TPID_ModelConfigA 7
struct SModelConfigA {
	
	///@brief Ͷ���ߴ���,Ͷ����ʵ���Ψһ��ʶ	
	TInvestorID InvestorID;
		
	///@brief �����ļ�·��,ģ�ͼ���Ľ�����ݴ��·��	
	TPath DataPath;
		
	///@brief ģ�ͼ����ѭ��ʱ��,����ģ�Ͷ���ʱ�����һ�μ���	
	TTimeCycle CalculateCycle;
		
	///@brief ģ������,����ģ�;�������	
	TModelType ModelType;
		
	///@brief k��ֵ,k��ֵ	
	TIndexValue Idx_k;
		
	///@brief dָ��,dָ��	
	TIndexValue Idx_d;
		
	///@brief jָ��,jָ��	
	TIndexValue Idx_j;
		
	///@brief diff��ֵ,diff��ֵ	
	TIndexValue Idx_diff;
		
	///@brief deaָ��,deaָ��	
	TIndexValue Idx_dea;
		
	///@brief barָ��,barָ��	
	TIndexValue Idx_bar;
		
	///@brief k��ֵ���ֵ,k��ֵ���ֵ	
	TIndexValue MAX_k;
		
	///@brief dָ�����ֵ,dָ�����ֵ	
	TIndexValue MAX_d;
		
	///@brief jָ�����ֵ,jָ�����ֵ	
	TIndexValue MAX_j;
		
	///@brief diff��ֵ���ֵ,diff��ֵ���ֵ	
	TIndexValue MAX_diff;
		
	///@brief deaָ�����ֵ,deaָ�����ֵ	
	TIndexValue MAX_dea;
		
	///@brief barָ�����ֵ,barָ�����ֵ	
	TIndexValue MAX_bar;
		
	///@brief k��ֵ��С��ֵ,k��ֵ��С��ֵ	
	TIndexValue MIN_k;
		
	///@brief dָ����С��ֵ,dָ����С��ֵ	
	TIndexValue MIN_d;
		
	///@brief jָ����С��ֵ,jָ����С��ֵ	
	TIndexValue MIN_j;
		
	///@brief diff��ֵ��С��ֵ,diff��ֵ��С��ֵ	
	TIndexValue MIN_diff;
		
	///@brief deaָ����С��ֵ,deaָ����С��ֵ	
	TIndexValue MIN_dea;
		
	///@brief barָ����С��ֵ,barָ����С��ֵ	
	TIndexValue MIN_bar;
		
};	

///@struct ��������
#define TPID_OrderReq 8
struct SOrderReq {
	
	///@brief ����ί�б��,����ϵͳ����ÿ��ί�еı��	
	TLocalOrderID LocalOrderID;
		
	///@brief ������,������	
	TDate TradingDay;
		
	///@brief Ͷ���ߴ���,������������	
	TInvestorID InvestorID;
		
	///@brief ��Լ����,������Լ����	
	TInstrumentID InstrumentID;
		
	///@brief ��ƽ���,��ƽ���	
	TOffsetFlag OffsetFlag;
		
	///@brief �ֲַ���,��λ�Ķ�ձ��	
	TDirection Direction;
		
	///@brief ���̼۸�,�����۸��ݲ�֧���м۵�	
	TPrice Price;
		
	///@brief ����״̬,����״̬	
	TOrderStatus OrderStatus;
		
	///@brief �����ύ״̬,�����ύ״̬	
	TOrderSubmitStatus OrderSubmitStatus;
		
	///@brief ��������ʱ��,ϵͳ���еı�������ʱ��	
	TDateTime LocalTime;
		
	///@brief ����ʱ��,��ʵ�Ǳ���ʱ������ʱ��,�����Ǳ���ϵͳʱ��	
	TTime OrderTime;
		
	///@brief �ɽ�����,�Ѿ��ɽ�������	
	TVolume VolumeTraded;
		
	///@brief δ�ɽ���,����δ�ɽ�������	
	TVolume VolumeRemain;
		
};	

///@struct �ɽ�
#define TPID_Trade 9
struct STrade {
	
	///@brief ������,������	
	TDate TradingDay;
		
	///@brief Ͷ���ߴ���,�ɽ���������	
	TInvestorID InvestorID;
		
	///@brief ��Լ����,�ɽ���Լ����	
	TInstrumentID InstrumentID;
		
	///@brief ��ƽ���,��ƽ���	
	TOffsetFlag OffsetFlag;
		
	///@brief �ֲַ���,��λ�Ķ�ձ��	
	TDirection Direction;
		
	///@brief �ɽ�����,�ɽ�����	
	TVolume DoneVolume;
		
	///@brief �ɽ���,�ɽ���	
	TPrice DonePrice;
		
	///@brief �ɽ�ʱ��,�ɽ�ʱ��	
	TTime TradeTime;
		
	///@brief ����ί�б��,������ί��ָ����	
	TLocalOrderID LocalOrderID;
		
};	

///@struct ���в�λ
#define TPID_RealPosition 10
struct SRealPosition {
	
	///@brief Ͷ���ߴ���,�ֲֵ�������	
	TInvestorID InvestorID;
		
	///@brief ��Լ����,�ֲ����ڵĺ�Լ	
	TInstrumentID InstrumentID;
		
	///@brief �ֲַ���,��λ�Ķ�ձ��	
	TDirection Direction;
		
	///@brief ���־���,��ʳֲֿ���ʱ�ļ۸�	
	TPrice OpenPriceAvg;
		
	///@brief ʵʱ�ֲ�����,��������ƽ�ֵ�����	
	TVolume RealVolume;
		
	///@brief ����ֲ�����,��ʱ�ѱ�ʹ�õ�����	
	TVolume FrozenVolume;
		
	///@brief �ֱֲ�֤��,�ڵ�ǰ�г��³ֱֲ�֤��	
	TMoney HoldMargin;
		
};	

///@struct �����ʽ�
#define TPID_RealFund 11
struct SRealFund {
	
	///@brief Ͷ���ߴ���,�ʽ��������	
	TInvestorID InvestorID;
		
	///@brief ����Ȩ��,�ͻ��������ʲ���ֵ	
	TMoney LastEquity;
		
	///@brief ��Ȩ��,�ͻ����ʲ���ֵ	
	TMoney Equity;
		
	///@brief �����ʽ�,�������ڿ��ֵ��ʽ�	
	TMoney AvailableFund;
		
	///@brief ���ᱣ֤��,��������ڱ����ı�֤��	
	TMoney FrozenMargin;
		
	///@brief ����������,��������ڱ�����������	
	TMoney FrozenFee;
		
	///@brief ����������,��Ϊ��ƽ�ֶ��������н�������	
	TMoney Fee;
		
	///@brief ƽ��ӯ��,ƽ���Ժ������ӯ��	
	TMoney CloseProfit;
		
	///@brief �ֲ�ӯ��,�ֲֲ����Ķ�̬ӯ��	
	TMoney HoldProfit;
		
	///@brief �ֱֲ�֤��,�ֱֲ�֤��	
	TMoney Margin;
		
	///@brief ����,����	
	TMoney FundIn;
		
	///@brief ���,���	
	TMoney FundOut;
		
};	

///@struct ���ĵĺ�Լ��
#define TPID_SubInstrument 12
struct SSubInstrument {
	
	///@brief ��Լ����,�ֲ����ڵĺ�Լ	
	TInstrumentID InstrumentID;
		
};	

///@struct �����ź�
#define TPID_Singnal 13
struct SSingnal {
	
	///@brief ������,������	
	TDate TradingDay;
		
	///@brief Ͷ���ߴ���,������������	
	TInvestorID InvestorID;
		
	///@brief ��Լ����,������Լ����	
	TInstrumentID InstrumentID;
		
	///@brief ��ƽ���,��ƽ���	
	TOffsetFlag OffsetFlag;
		
	///@brief �ֲַ���,��λ�Ķ�ձ��	
	TDirection Direction;
		
	///@brief ��������,��������	
	TVolume Volume;
		
	///@brief ���̼۸�,�����۸��ݲ�֧���м۵�	
	TPrice Price;
		
	///@brief �����źŵ�ԭ��,�����﷢���Ľ����ź�	
	TSingnalReason SingnalReason;
		
	///@brief ����ʱ��,��ʵ�Ǵ��������ź�ʱ������ʱ��,�����Ǳ���ϵͳʱ��	
	TTime TriggerTime;
		
	///@brief ��������ʱ��,ϵͳ���еı�������ʱ��	
	TDateTime LocalTime;
		
};	

///@struct ��Լ
#define TPID_Instrument 14
struct SInstrument {
	
	///@brief ��Լ����,��Լ��Ψһ��ʶ	
	TInstrumentID InstrumentID;
		
	///@brief ��Լ����,���ڱ��ÿ�ֱֲֳ���������	
	TVolume Multiple;
		
	///@brief ��ͣ���,��ͣ���	
	TPrice UpperLimitPrice;
		
	///@brief ��ͣ���,��ͣ���	
	TPrice LowerLimitPrice;
		
};	

///@struct ���չ���������
#define TPID_RiskControler 15
struct SRiskControler {
	
	///@brief ֹӯ�۲�,ӯ���ļ۲���˼�λ���ƽ��	
	TPrice FullPrice;
		
	///@brief ֹ��۲�,����ļ۲���˼�λ���ƽ��	
	TPrice StopLossPrice;
		
};	

///@struct �ʻ��ĳ����
#define TPID_MoneyChange 16
struct SMoneyChange {
	
	///@brief Ͷ���ߴ���,�ʽ����仯��Ͷ�����˻�	
	TInvestorID InvestorID;
		
	///@brief �ʽ�仯����,�ʽ�仯����	
	TFundDirection FundDirection;
		
	///@brief �ʽ�仯��,�ʽ�仯��	
	TMoney Change;
		
};	

///@struct �½�����
#define TPID_NewTradingDay 17
struct SNewTradingDay {
	
	///@brief ������,������	
	TDate TradingDay;
		
};	

///@struct ������Ӧ
#define TPID_OrderRsp 18
struct SOrderRsp {
	
	///@brief ����ί�б��,����ϵͳ����ÿ��ί�еı��	
	TLocalOrderID LocalOrderID;
		
	///@brief ������,������	
	TDate TradingDay;
		
	///@brief Ͷ���ߴ���,������������	
	TInvestorID InvestorID;
		
	///@brief ��Լ����,������Լ����	
	TInstrumentID InstrumentID;
		
	///@brief ��ƽ���,��ƽ���	
	TOffsetFlag OffsetFlag;
		
	///@brief �ֲַ���,��λ�Ķ�ձ��	
	TDirection Direction;
		
	///@brief ���̼۸�,�����۸��ݲ�֧���м۵�	
	TPrice Price;
		
	///@brief ����״̬,����״̬	
	TOrderStatus OrderStatus;
		
	///@brief �����ύ״̬,�����ύ״̬	
	TOrderSubmitStatus OrderSubmitStatus;
		
	///@brief ��������ʱ��,ϵͳ���еı�������ʱ��	
	TDateTime LocalTime;
		
	///@brief ����ʱ��,��ʵ�Ǳ���ʱ������ʱ��,�����Ǳ���ϵͳʱ��	
	TTime OrderTime;
		
	///@brief �ɽ�����,�Ѿ��ɽ�������	
	TVolume VolumeTraded;
		
	///@brief δ�ɽ���,����δ�ɽ�������	
	TVolume VolumeRemain;
		
};	

///@struct ��Լ��֤����
#define TPID_MarginRate 19
struct SMarginRate {
	
	///@brief Ͷ���ߴ���,�ʽ��������	
	TInvestorID InvestorID;
		
	///@brief ��Լ����,��Լ��Ψһ��ʶ	
	TInstrumentID InstrumentID;
		
	///@brief ����֤����,����ÿ�ֱ�����ֵ�ı�����ȡ��֤��	
	TRatio MarginRatioByMoney;
		
	///@brief ÿ�ֱ�֤����,ÿ����ȡ�Ķ��֤��	
	TMoney MarginRatioByVolume;
		
};	

///@struct ��Լ��������
#define TPID_FeeRate 20
struct SFeeRate {
	
	///@brief Ͷ���ߴ���,�ʽ��������	
	TInvestorID InvestorID;
		
	///@brief ��Լ����,��Լ��Ψһ��ʶ	
	TInstrumentID InstrumentID;
		
	///@brief ���ְ������������,����ʱ����ÿ�ֱ�����ֵ�ı�����ȡ������	
	TRatio OpenFeeRatioByMoney;
		
	///@brief ����ÿ�������ѽ��,����ʱÿ����ȡ�Ķ���������	
	TMoney OpenFeeRatioByVolume;
		
	///@brief ƽ�ְ������������,ƽ��ʱ����ÿ�ֱ�����ֵ�ı�����ȡ������	
	TRatio CloseFeeRatioByMoney;
		
	///@brief ƽ��ÿ�������ѽ��,ƽ��ʱÿ����ȡ�Ķ���������	
	TMoney CloseFeeRatioByVolume;
		
	///@brief ƽ�񰴽����������,ƽ���ʱ����ÿ�ֱ�����ֵ�ı�����ȡ������	
	TRatio CloseTodayFeeRatioByMoney;
		
	///@brief ƽ��ÿ�������ѽ��,ƽ���ʱÿ����ȡ�Ķ���������	
	TMoney CloseTodayFeeRatioByVolume;
		
};	

///@struct ��־������Ϣ
#define TPID_LogConfig 21
struct SLogConfig {
	
	///@brief ��־�������,��־����Ķ�������	
	TLogOutputType LogOutputType;
		
	///@brief ��־����,��־���������	
	TLogLevel LogLevel;
		
	///@brief ��־·��,��־����ļ��������Ĵ��·��	
	TPath LogPath;
		
};	

}
#endif
		