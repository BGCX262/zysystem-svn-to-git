/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file FileLogger.cpp
///@brief 文件日志输出
///@author 张弛
///@date 2012-02-22T08:25:11.269Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "FileLogger.h"

#ifndef FILELOGGER_CPP_
#define FILELOGGER_CPP_

using namespace ZYSystem;

//CFileLogger CFileLogger::m_fileLogger = CFileLogger();

///@brief 输出用于日志每行开头的时间
inline void CFileLogger::outputTime() {
	boost::posix_time::ptime t(boost::posix_time::second_clock::local_time());

	fprintf(logFile,"\n");
	fprintf(logFile,(boost::posix_time::to_iso_string(t)).c_str());
	fprintf(logFile," ");
}

void CFileLogger::output(TLogLevel level, char *format,...){

	//只有小于或等于设置的日志级别，日志才被输出
	if (level <= logConfig->LogLevel) {
		return;
	}                 

	va_list v;
	va_start(v,format);
	outputTime();
	vfprintf(logFile,format,v);
	va_end(v);
	fflush(logFile);
}

void CFileLogger::outputVL(TLogLevel level, char *format,va_list v){

	//只有小于或等于设置的日志级别，日志才被输出
	if (level <= logConfig->LogLevel) {
		return;
	}                 

	outputTime();
	vfprintf(logFile,format,v);
	va_end(v);
	fflush(logFile);
}


CFileLogger::CFileLogger():CStdLogger(){
	if(!boost::filesystem::exists(logConfig->LogPath)) {
		boost::filesystem::create_directories(logConfig->LogPath);
	}

	TPath realPath;
	sprintf(realPath,"%sserver.log",logConfig->LogPath);
	logFile = fopen(realPath,"w");

	m_pInstance = this;
}

CFileLogger::~CFileLogger(){
	std::fclose(logFile);
}
#endif //FILELOGGER_CPP_
