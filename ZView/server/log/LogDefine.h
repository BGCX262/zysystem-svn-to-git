
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file LogDefine.h
///@brief 用于定义ZY System的错误类型定义
///@author xslt模型代码转换工具
///@date 2013-06-21T07:28:18.377Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "../generate/Structs.h"

#ifndef LOG_DEFINE_H
#define LOG_DEFINE_H

#define SUCCESS 0

#define MAIN_NoConfigFile 1001
#define MAIN_ConfigFileFound 1002
#define MAIN_ConfigFileErr 1003
#define MAIN_ConfigFileSvrNumber 1004
#define MAIN_MdrLoadSucc 1005
#define MAIN_MdrLoadFail 1006
#define MAIN_MdrLoadFinish 1007
#define MAIN_ConfigFileInvNumber 1008
#define MAIN_InvLoadSucc 1009
#define MAIN_InvLoadFail 1010
#define MAIN_InvLoadFinish 1011
#define MAIN_XpathValueErr 1012
#define MAIN_LogPath 1013
#define MAIN_MdrInstrument 1014

#define PROTFOLIO_NotEnoughPoistion 2002
#define PROTFOLIO_NotFindPosition 2003
#define PROTFOLIO_OpenOrderNotFrozen 2004
#define PROTFOLIO_FrozenedPositionNotEnough 2005
#define PROTFOLIO_PositionNotEnoughToFrozen 2006
#define PROTFOLIO_OpenNotFrozen 2007
#define PROTFOLIO_OpenNotUnfrozen 2008
#define PROTFOLIO_FrozenedMoneyNotEnough 2009
#define PROTFOLIO_NotFindInsturmentBySingnal 2010
#define PROTFOLIO_InsturmentsNull 2011
#define PROTFOLIO_OrdersNull 2012
#define PROTFOLIO_NotFindOrderByTrade 2013
#define PROTFOLIO_MarginNotEnough 2014
#define PROTFOLIO_NotFindInsturmentByTrade 2015

#define CONNECTOR_HIS_TradingDayIs 3001
#define CONNECTOR_NewMDIsEmpty 3002
#define CONNECTOR_CtpMDIsEmpty 3003
#define CONNECTOR_CtpTradeIsEmpty 3004

#define DATAROUTE_MsgQueClosed 4001
#define DATAROUTE_MsgEmpty 4002
#define DATAROUTE_MsgQueMaxSizeLessOne 4003
#define DATAROUTE_QueSizeAfterPush 4004
#define DATAROUTE_QueSizeAfterPop 4005

#define SPI_MD_Connected 5001
#define SPI_MD_Disconnected 5002
#define SPI_MD_LoginSucc 5003
#define SPI_MD_LoginFail 5004
#define SPI_MD_ServerErr 5005
#define SPI_MD_NewInsturments 5006
#define SPI_MD_TradingDayIs 5007
#define SPI_T_Connected 5008
#define SPI_T_Disconnected 5009
#define SPI_T_LoginSucc 5010
#define SPI_T_LoginFail 5011
#define SPI_T_ServerErr 5012
#define SPI_T_TradingDayIs 5013
#define SPI_T_SettInfoConfirmSucc 5014
#define SPI_T_SettInfoConfirmFail 5015
#define SPI_T_QryInstrumentSucc 5016
#define SPI_T_QryInstrumentFail 5017
#define SPI_T_QryInstrumentFC 5018
#define SPI_T_QryTradingAccountSucc 5019
#define SPI_T_QryTradingAccountFail 5020
#define SPI_T_QryTradingAccountFC 5021
#define SPI_T_QryInvestorPositionSucc 5022
#define SPI_T_QryInvestorPositionFail 5023
#define SPI_T_QryInvestorPositionFC 5024
#define SPI_T_OrderInsertSucc 5025
#define SPI_T_OrderInsertFail 5026
#define SPI_T_OrderActionSucc 5027
#define SPI_T_OrderActionFail 5028
#define SPI_T_RtnOrder 5029
#define SPI_T_OrderCanceled 5030
#define SPI_T_RtnTrade 5031
#define SPI_T_HeartBeat 5032

#define TCORE_DS_RealFundSelectByInvestorIDFatal 6001
#define TCORE_DS_NotEnoughAvailableForOut 6002
#define TCORE_ModelInIsNull 6003
#define TCORE_DS_OrderReqSelectByLocalOrderIDFatal 6004
#define TCORE_DS_InstrumentSelectByInstrumentIDFatal 6005
#define TCORE_DS_MarginRateSelectByInvestorIDInstrumentIDFatal 6006
#define TCORE_DS_FeeRateSelectByInvestorIDInstrumentIDFatal 6007
#define TCORE_DS_RealPositionSelectByInvestorIDInstrumentIDDirectionFatal 6008

#endif //LOG_DEFINE_H
