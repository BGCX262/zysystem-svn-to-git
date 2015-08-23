--******************************
--�����г������
--******************************
drop table t_DayMarketDataA1;

create table t_DayMarketDataA1
(
	TradingDay char(8) not null
	,ExchangeID char(8) not null
	,InstrumentID char(30) not null
	,ProductID char(4) not null
	,DeliveryYear char(2)
	,DeliveryMonth char(2)
	,OpenPrice number(12,3) 
	,HighestPrice number(12,3) 
	,LowestPrice number(12,3) 
	,ClosePrice number(12,3) 
	,SettlementPrice number(12,3)
	,Volume number(10) 
	,Position number(10)  
	,constraint pk_MarketData primary key (TradingDay,InstrumentID,ExchangeID)
) rowdependencies;

comment on table t_DayMarketDataA1 is '�г�����';
	comment on column t_DayMarketDataA1.TradingDay is '������';
	comment on column t_DayMarketDataA1.ExchangeID is '����������';
	comment on column t_DayMarketDataA1.InstrumentID is '��Լ����';
	comment on column t_DayMarketDataA1.ProductID is 'Ʒ�ִ���';
	comment on column t_DayMarketDataA1.DeliveryYear is '�������';
	comment on column t_DayMarketDataA1.DeliveryMonth is '�����·�';
	comment on column t_DayMarketDataA1.OpenPrice is '����';
	comment on column t_DayMarketDataA1.HighestPrice is '��߼�';
	comment on column t_DayMarketDataA1.LowestPrice is '��ͼ�';
	comment on column t_DayMarketDataA1.ClosePrice is '������';
	comment on column t_DayMarketDataA1.Volume is '����';
	comment on column t_DayMarketDataA1.Position is '�ֲ���';
	comment on column t_DayMarketDataA1.SettlementPrice is '���ν����';

		
	
--******************************
--���� SHFE�г������
--******************************
drop table SHFE_MarketData;

create table SHFE_MarketData
(
	TradingDay char(8)  not null
  ,ProductID char(4) not null
	,DeliveryDate char(4) not null
	,PreSettlementPrice number(12,3) 
	,OpenPrice number(12,3) 
	,HighestPrice number(12,3) 
	,LowestPrice number(12,3) 
	,ClosePrice number(12,3) 
	,SettlementPrice number(12,3) 
	,UpDownPrice1 number(12,3) 
	,UpDownPrice2 number(12,3) 
	,Volume number(10) 
	,Position number(10)
	,PositionChg number(10)
	,constraint pk_SHFEMarketData primary key (TradingDay,ProductID,DeliveryDate)
) rowdependencies;

comment on table SHFE_MarketData is '�г�����';
	comment on column SHFE_MarketData.TradingDay is '������';
	comment on column SHFE_MarketData.ProductID is 'Ʒ�ִ���';
	comment on column SHFE_MarketData.DeliveryDate is '�����·�';
	comment on column SHFE_MarketData.PreSettlementPrice is '�ϴν����';
	comment on column SHFE_MarketData.OpenPrice is '����';
	comment on column SHFE_MarketData.HighestPrice is '��߼�';
	comment on column SHFE_MarketData.LowestPrice is '��ͼ�';
	comment on column SHFE_MarketData.ClosePrice is '������';
	comment on column SHFE_MarketData.SettlementPrice is '���ν����';
	comment on column SHFE_MarketData.UpDownPrice1 is '�ǵ�1';
	comment on column SHFE_MarketData.UpDownPrice2 is '�ǵ�2';	
	comment on column SHFE_MarketData.Volume is '����';
	comment on column SHFE_MarketData.Position is '�ֲ���';
	comment on column SHFE_MarketData.PositionChg is '�ֲ����仯';
	
	
--******************************
--���� DCE�г������
--******************************
drop table DCE_MarketData;

create table DCE_MarketData
(
	TradingDay char(8) not null
	,ProductID char(4) not null
	,DeliveryDate char(4) not null
	,OpenPrice number(12,3) 
	,HighestPrice number(12,3) 
	,LowestPrice number(12,3) 
	,ClosePrice number(12,3) 
	,PreSettlementPrice number(12,3) 
	,SettlementPrice number(12,3) 
	,UpDownPrice1 number(12,3) 
	,UpDownPrice2 number(12,3) 
	,Volume number(10) 
	,Position number(10) 
	,PositionChg number(10) 
	,Turnover number(19,6) 
	,constraint pk_DCEMarketData primary key (TradingDay,ProductID,DeliveryDate)
) rowdependencies;

comment on table DCE_MarketData is 'DCE�г�����';
	comment on column DCE_MarketData.TradingDay is '������';
	comment on column DCE_MarketData.ProductID is 'Ʒ�ִ���';
	comment on column DCE_MarketData.DeliveryDate is '������';
	comment on column DCE_MarketData.OpenPrice is '����';
	comment on column DCE_MarketData.HighestPrice is '��߼�';
	comment on column DCE_MarketData.LowestPrice is '��ͼ�';
	comment on column DCE_MarketData.ClosePrice is '������';
	comment on column DCE_MarketData.PreSettlementPrice is '�ϴν����';
	comment on column DCE_MarketData.SettlementPrice is '���ν����';
	comment on column DCE_MarketData.UpDownPrice1 is '�ǵ�1';
	comment on column DCE_MarketData.UpDownPrice2 is '�ǵ�2';	
	comment on column DCE_MarketData.Volume is '����';
	comment on column DCE_MarketData.Position is '�ֲ���';
	comment on column DCE_MarketData.PositionChg is '�ֲ����仯';
	comment on column DCE_MarketData.Turnover is '�ɽ����';
	
	
--******************************
--���� CZCE�г������
--******************************
drop table CZCE_MarketData;

create table CZCE_MarketData
(
	TradingDay char(8) not null
	,InstrumentID char(30) not null
	,PreSettlementPrice number(12,3) 
	,OpenPrice number(12,3) 
	,HighestPrice number(12,3) 
	,LowestPrice number(12,3) 
	,ClosePrice number(12,3) 
	,SettlementPrice number(12,3)
	,UpDownPrice1 number(12,3) 
	,UpDownPrice2 number(12,3) 
	,Volume number(10) 
	,Position number(10) 
	,PositionChg number(10)  
	,Turnover number(19,6)
	,DeliveryPrice number(12,3)  
	,constraint pk_CZCEMarketData primary key (TradingDay,InstrumentID)
) rowdependencies;

comment on table CZCE_MarketData is 'CZCE�г�����';
	comment on column CZCE_MarketData.TradingDay is '������';
	comment on column CZCE_MarketData.InstrumentID is '��Լ����';
	comment on column CZCE_MarketData.PreSettlementPrice is '�ϴν����';
	comment on column CZCE_MarketData.OpenPrice is '����';
	comment on column CZCE_MarketData.HighestPrice is '��߼�';
	comment on column CZCE_MarketData.LowestPrice is '��ͼ�';
	comment on column CZCE_MarketData.ClosePrice is '������';
	comment on column CZCE_MarketData.SettlementPrice is '���ν����';
	comment on column CZCE_MarketData.UpDownPrice1 is '�ǵ�1';
	comment on column CZCE_MarketData.UpDownPrice2 is '�ǵ�2';	
	comment on column CZCE_MarketData.Volume is '����';
	comment on column CZCE_MarketData.Position is '�ֲ���';
	comment on column CZCE_MarketData.PositionChg is '�ֲ����仯';
	comment on column CZCE_MarketData.Turnover is '�ɽ����';
	comment on column CZCE_MarketData.DeliveryPrice is '��������';
	
--******************************
--���� CFFEX�г������
--******************************
drop table CFFEX_MarketData;

create table CFFEX_MarketData
(
	TradingDay char(8) not null 
	,InstrumentID char(30) not null
	,OpenPrice number(12,3) 
	,HighestPrice number(12,3) 
	,LowestPrice number(12,3) 
	,Volume number(10) 
	,Turnover number(19,6) 
	,Position number(10)  
	,ClosePrice number(12,3) 
	,SettlementPrice number(12,3) 
	,UpDownPrice1 number(12,3) 
	,UpDownPrice2 number(12,3) 
	,constraint pk_CFFEXMarketData primary key (TradingDay,InstrumentID)
) rowdependencies;

comment on table CFFEX_MarketData is 'CFFEX �г�����';
	comment on column CFFEX_MarketData.TradingDay is '������';
	comment on column CFFEX_MarketData.InstrumentID is '��Լ����';
	comment on column CFFEX_MarketData.OpenPrice is '����';
	comment on column CFFEX_MarketData.HighestPrice is '��߼�';
	comment on column CFFEX_MarketData.LowestPrice is '��ͼ�';
	comment on column CFFEX_MarketData.Volume is '�ɽ���';
	comment on column CFFEX_MarketData.Turnover is '�ɽ����';
	comment on column CFFEX_MarketData.Position is '�ֲ���';
	comment on column CFFEX_MarketData.ClosePrice is '������';
	comment on column CFFEX_MarketData.SettlementPrice is '���ν����';
	comment on column CFFEX_MarketData.UpDownPrice1 is '�ǵ�1';
	comment on column CFFEX_MarketData.UpDownPrice2 is '�ǵ�2';



--******************************
--���� ��ʷ���� ��
--******************************
drop table t_HistoryData;

create table t_HistoryData
(
	InstrumentID char(30) not null
	,TradingDay char(8) not null	
	,OpenPrice number(12,3) 
	,HighestPrice number(12,3) 
	,LowestPrice number(12,3) 
	,ClosePrice number(12,3) 
	,Volume number(10) 
	,constraint pk_HistoryData primary key (InstrumentID,TradingDay)
) rowdependencies;

comment on table t_HistoryData is '�г�����';
	comment on column t_HistoryData.InstrumentID is '��Լ����';
	comment on column t_HistoryData.TradingDay is '������';
	comment on column t_HistoryData.OpenPrice is '����';
	comment on column t_HistoryData.HighestPrice is '��߼�';
	comment on column t_HistoryData.LowestPrice is '��ͼ�';
	comment on column t_HistoryData.ClosePrice is '������';
	comment on column t_HistoryData.Volume is '����';
	
	
--******************************
--���� Mathlab��ʷ���� ��
--******************************
drop table t_MathlabHisData;

create table t_MathlabHisData
(
	TradingDay char(8) not null
	,ExchangeID char(8) not null
	,ProductID char(4) not null
	,DeliveryMonth char(2) not null
	,OpenPrice number(12,3) 
	,HighestPrice number(12,3) 
	,LowestPrice number(12,3) 
	,ClosePrice number(12,3) 
	,Volume number(10) 
	,constraint pk_MathlabHisData primary key (TradingDay,ExchangeID,ProductID,DeliveryMonth)
) rowdependencies;

comment on table t_DayMarketDataA1 is '�г�����';
	comment on column t_MathlabHisData.TradingDay is '������';
	comment on column t_MathlabHisData.ExchangeID is '����������';
	comment on column t_MathlabHisData.ProductID is 'Ʒ�ִ���';
	comment on column t_MathlabHisData.DeliveryMonth is '�����·�';
	comment on column t_MathlabHisData.OpenPrice is '����';
	comment on column t_MathlabHisData.HighestPrice is '��߼�';
	comment on column t_MathlabHisData.LowestPrice is '��ͼ�';
	comment on column t_MathlabHisData.ClosePrice is '������';
	comment on column t_MathlabHisData.Volume is '����';
	
	
--******************************
--���� Mathlab��Լ ӳ���
--******************************
drop table t_MathlabInsMap;

create table t_MathlabInsMap
(
	InstrumentID char(30) not null
	,ExchangeID char(8) not null
	,ProductID char(4) not null
	,DeliveryMonth char(2) not null 
	,InstrumentName varchar2(60)
	,constraint pk_MathlabInsMap primary key (InstrumentID)
) rowdependencies;

  comment on table t_MathlabInsMap is '�г�����';
  comment on column t_MathlabInsMap.InstrumentID is '������';
	comment on column t_MathlabInsMap.ExchangeID is '����������';
	comment on column t_MathlabInsMap.ProductID is 'Ʒ�ִ���';
	comment on column t_MathlabInsMap.DeliveryMonth is '�����·�';
	comment on column t_MathlabInsMap.InstrumentName is '��Լ����';