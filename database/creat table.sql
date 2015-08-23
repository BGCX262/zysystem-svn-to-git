--******************************
--创建市场行情表
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

comment on table t_DayMarketDataA1 is '市场行情';
	comment on column t_DayMarketDataA1.TradingDay is '交易日';
	comment on column t_DayMarketDataA1.ExchangeID is '交易所代码';
	comment on column t_DayMarketDataA1.InstrumentID is '合约代码';
	comment on column t_DayMarketDataA1.ProductID is '品种代码';
	comment on column t_DayMarketDataA1.DeliveryYear is '交割年份';
	comment on column t_DayMarketDataA1.DeliveryMonth is '交割月份';
	comment on column t_DayMarketDataA1.OpenPrice is '今开盘';
	comment on column t_DayMarketDataA1.HighestPrice is '最高价';
	comment on column t_DayMarketDataA1.LowestPrice is '最低价';
	comment on column t_DayMarketDataA1.ClosePrice is '今收盘';
	comment on column t_DayMarketDataA1.Volume is '数量';
	comment on column t_DayMarketDataA1.Position is '持仓量';
	comment on column t_DayMarketDataA1.SettlementPrice is '本次结算价';

		
	
--******************************
--创建 SHFE市场行情表
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

comment on table SHFE_MarketData is '市场行情';
	comment on column SHFE_MarketData.TradingDay is '交易日';
	comment on column SHFE_MarketData.ProductID is '品种代码';
	comment on column SHFE_MarketData.DeliveryDate is '交割月份';
	comment on column SHFE_MarketData.PreSettlementPrice is '上次结算价';
	comment on column SHFE_MarketData.OpenPrice is '今开盘';
	comment on column SHFE_MarketData.HighestPrice is '最高价';
	comment on column SHFE_MarketData.LowestPrice is '最低价';
	comment on column SHFE_MarketData.ClosePrice is '今收盘';
	comment on column SHFE_MarketData.SettlementPrice is '本次结算价';
	comment on column SHFE_MarketData.UpDownPrice1 is '涨跌1';
	comment on column SHFE_MarketData.UpDownPrice2 is '涨跌2';	
	comment on column SHFE_MarketData.Volume is '数量';
	comment on column SHFE_MarketData.Position is '持仓量';
	comment on column SHFE_MarketData.PositionChg is '持仓量变化';
	
	
--******************************
--创建 DCE市场行情表
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

comment on table DCE_MarketData is 'DCE市场行情';
	comment on column DCE_MarketData.TradingDay is '交易日';
	comment on column DCE_MarketData.ProductID is '品种代码';
	comment on column DCE_MarketData.DeliveryDate is '交割期';
	comment on column DCE_MarketData.OpenPrice is '今开盘';
	comment on column DCE_MarketData.HighestPrice is '最高价';
	comment on column DCE_MarketData.LowestPrice is '最低价';
	comment on column DCE_MarketData.ClosePrice is '今收盘';
	comment on column DCE_MarketData.PreSettlementPrice is '上次结算价';
	comment on column DCE_MarketData.SettlementPrice is '本次结算价';
	comment on column DCE_MarketData.UpDownPrice1 is '涨跌1';
	comment on column DCE_MarketData.UpDownPrice2 is '涨跌2';	
	comment on column DCE_MarketData.Volume is '数量';
	comment on column DCE_MarketData.Position is '持仓量';
	comment on column DCE_MarketData.PositionChg is '持仓量变化';
	comment on column DCE_MarketData.Turnover is '成交金额';
	
	
--******************************
--创建 CZCE市场行情表
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

comment on table CZCE_MarketData is 'CZCE市场行情';
	comment on column CZCE_MarketData.TradingDay is '交易日';
	comment on column CZCE_MarketData.InstrumentID is '合约代码';
	comment on column CZCE_MarketData.PreSettlementPrice is '上次结算价';
	comment on column CZCE_MarketData.OpenPrice is '今开盘';
	comment on column CZCE_MarketData.HighestPrice is '最高价';
	comment on column CZCE_MarketData.LowestPrice is '最低价';
	comment on column CZCE_MarketData.ClosePrice is '今收盘';
	comment on column CZCE_MarketData.SettlementPrice is '本次结算价';
	comment on column CZCE_MarketData.UpDownPrice1 is '涨跌1';
	comment on column CZCE_MarketData.UpDownPrice2 is '涨跌2';	
	comment on column CZCE_MarketData.Volume is '数量';
	comment on column CZCE_MarketData.Position is '持仓量';
	comment on column CZCE_MarketData.PositionChg is '持仓量变化';
	comment on column CZCE_MarketData.Turnover is '成交金额';
	comment on column CZCE_MarketData.DeliveryPrice is '交割结算价';
	
--******************************
--创建 CFFEX市场行情表
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

comment on table CFFEX_MarketData is 'CFFEX 市场行情';
	comment on column CFFEX_MarketData.TradingDay is '交易日';
	comment on column CFFEX_MarketData.InstrumentID is '合约代码';
	comment on column CFFEX_MarketData.OpenPrice is '今开盘';
	comment on column CFFEX_MarketData.HighestPrice is '最高价';
	comment on column CFFEX_MarketData.LowestPrice is '最低价';
	comment on column CFFEX_MarketData.Volume is '成交量';
	comment on column CFFEX_MarketData.Turnover is '成交金额';
	comment on column CFFEX_MarketData.Position is '持仓量';
	comment on column CFFEX_MarketData.ClosePrice is '今收盘';
	comment on column CFFEX_MarketData.SettlementPrice is '本次结算价';
	comment on column CFFEX_MarketData.UpDownPrice1 is '涨跌1';
	comment on column CFFEX_MarketData.UpDownPrice2 is '涨跌2';



--******************************
--创建 历史数据 表
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

comment on table t_HistoryData is '市场行情';
	comment on column t_HistoryData.InstrumentID is '合约代码';
	comment on column t_HistoryData.TradingDay is '交易日';
	comment on column t_HistoryData.OpenPrice is '今开盘';
	comment on column t_HistoryData.HighestPrice is '最高价';
	comment on column t_HistoryData.LowestPrice is '最低价';
	comment on column t_HistoryData.ClosePrice is '今收盘';
	comment on column t_HistoryData.Volume is '数量';
	
	
--******************************
--创建 Mathlab历史数据 表
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

comment on table t_DayMarketDataA1 is '市场行情';
	comment on column t_MathlabHisData.TradingDay is '交易日';
	comment on column t_MathlabHisData.ExchangeID is '交易所代码';
	comment on column t_MathlabHisData.ProductID is '品种代码';
	comment on column t_MathlabHisData.DeliveryMonth is '交割月份';
	comment on column t_MathlabHisData.OpenPrice is '今开盘';
	comment on column t_MathlabHisData.HighestPrice is '最高价';
	comment on column t_MathlabHisData.LowestPrice is '最低价';
	comment on column t_MathlabHisData.ClosePrice is '今收盘';
	comment on column t_MathlabHisData.Volume is '数量';
	
	
--******************************
--创建 Mathlab合约 映射表
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

  comment on table t_MathlabInsMap is '市场行情';
  comment on column t_MathlabInsMap.InstrumentID is '交易日';
	comment on column t_MathlabInsMap.ExchangeID is '交易所代码';
	comment on column t_MathlabInsMap.ProductID is '品种代码';
	comment on column t_MathlabInsMap.DeliveryMonth is '交割月份';
	comment on column t_MathlabInsMap.InstrumentName is '合约名称';