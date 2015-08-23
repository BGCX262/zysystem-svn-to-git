/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ScreenLogger.cpp
///@brief 文件日志输出
///@author 张弛
///@date 2012-02-22T08:25:11.269Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "ScreenLogger.h"

#ifndef SCREENLOGGER_CPP_
#define SCREENLOGGER_CPP_

using namespace ZYSystem;

///@brief 输出用于日志每行开头的时间
inline void ScreenLogger::outputTime() {
	boost::posix_time::ptime t(boost::posix_time::second_clock::local_time());
    
	printf("\n");
	printf((boost::posix_time::to_iso_string(t)).c_str());
	printf(" ");
}

void ScreenLogger::output(TLogLevel level, char *format,...){

	//只有小于或等于设置的日志级别，日志才被输出
	if (level <= logConfig->LogLevel) {
		return;
	}                 

	va_list v;
	va_start(v,format);
	outputTime();
	vprintf(format,v);
	va_end(v);
}

void ScreenLogger::outputVL(TLogLevel level, char *format,va_list v){

	//只有小于或等于设置的日志级别，日志才被输出
	if (level <= logConfig->LogLevel) {
		return;
	}                 

	outputTime();
	vprintf(format,v);
	va_end(v);
}

ScreenLogger::ScreenLogger():CStdLogger(){
	m_pInstance = this;
}

ScreenLogger::~ScreenLogger(){
}

#endif //SCREENLOGGER_CPP_
