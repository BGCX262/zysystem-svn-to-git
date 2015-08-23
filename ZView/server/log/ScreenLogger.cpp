/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ScreenLogger.cpp
///@brief �ļ���־���
///@author �ų�
///@date 2012-02-22T08:25:11.269Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "ScreenLogger.h"

#ifndef SCREENLOGGER_CPP_
#define SCREENLOGGER_CPP_

using namespace ZYSystem;

///@brief ���������־ÿ�п�ͷ��ʱ��
inline void ScreenLogger::outputTime() {
	boost::posix_time::ptime t(boost::posix_time::second_clock::local_time());
    
	printf("\n");
	printf((boost::posix_time::to_iso_string(t)).c_str());
	printf(" ");
}

void ScreenLogger::output(TLogLevel level, char *format,...){

	//ֻ��С�ڻ�������õ���־������־�ű����
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

	//ֻ��С�ڻ�������õ���־������־�ű����
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
