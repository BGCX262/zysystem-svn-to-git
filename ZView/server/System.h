#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file System.h
///@brief 系统中所使用的公用库文件 
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////

#ifndef SYSTEM_H_
#define SYSTEM_H_

//通用库
#include <stdarg.h>
#include <iostream>
#include <vector>
#include <hash_map>
#include <queue>

//tinyxpath 库
#include <tinyxpath/xpath_processor.h>
#include <tinyxpath/xpath_static.h>

//boost库
#include <boost/thread.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/signals2.hpp>
#include <boost/shared_array.hpp>
#include <boost/iostreams/device/mapped_file.hpp>

///@brief sfit 综合交易平台 tradeApi
#include <tradeApi/ThostFtdcUserApiDataType.h>
#include <tradeApi/ThostFtdcMdApi.h>
#include <tradeApi/ThostFtdcTraderApi.h>

///@brief 开盘时间
#define MAKERT_OPEN_TIME "08:59:01"

///@brief 最低价初始化值
#define LOWESTPRICE_INIT 999999

///@brief TPackage包内容长度
#define TPACKAGE_LEN 1000

///@brief 数据路由里转发队列的长度
#define DATAROUTE_QUE_LEN 10000

///@brief 数据路由里转发队列的长度
#define DATAROUTE_MDQUE_LEN 700000

#endif //SYSTEM_H_