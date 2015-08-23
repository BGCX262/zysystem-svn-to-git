/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file FileLogger.h
///@brief 文件日志输出
///@author 张弛
///@date 2012-02-22T08:25:11.269Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "../generate/Gen.h"

#ifndef FILELOGGER_H_
#define FILELOGGER_H_

namespace ZYSystem {
    class CFileLogger :public CStdLogger
    {
    private:
		///@brief 日志文件
	    FILE *logFile;

	    static const char outTime[38];

		///@brief 输出用于日志每行开头的时间
	    inline void outputTime();

		virtual void outputVL(TLogLevel level, char *format,va_list v);

	    virtual void output(TLogLevel level, char *format,...);

    public:
	    CFileLogger();
	    ~CFileLogger();
    };
}
#endif //FILELOGGER_H_
		