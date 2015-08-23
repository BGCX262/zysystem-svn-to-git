#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file System.h
///@brief ϵͳ����ʹ�õĹ��ÿ��ļ� 
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////

#ifndef SYSTEM_H_
#define SYSTEM_H_

//ͨ�ÿ�
#include <stdarg.h>
#include <iostream>
#include <vector>
#include <hash_map>
#include <queue>

//tinyxpath ��
#include <tinyxpath/xpath_processor.h>
#include <tinyxpath/xpath_static.h>

//boost��
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

///@brief sfit �ۺϽ���ƽ̨ tradeApi
#include <tradeApi/ThostFtdcUserApiDataType.h>
#include <tradeApi/ThostFtdcMdApi.h>
#include <tradeApi/ThostFtdcTraderApi.h>

///@brief ����ʱ��
#define MAKERT_OPEN_TIME "08:59:01"

///@brief ��ͼ۳�ʼ��ֵ
#define LOWESTPRICE_INIT 999999

///@brief TPackage�����ݳ���
#define TPACKAGE_LEN 1000

///@brief ����·����ת�����еĳ���
#define DATAROUTE_QUE_LEN 10000

///@brief ����·����ת�����еĳ���
#define DATAROUTE_MDQUE_LEN 700000

#endif //SYSTEM_H_