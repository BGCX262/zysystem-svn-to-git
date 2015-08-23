/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ScreenLogger.h
///@brief 屏幕日志输出
///@author 张弛
///@date 2012-02-22T08:25:11.269Z
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "../generate/Gen.h"

#ifndef SCREENLOGGER_H_
#define SCREENLOGGER_H_

namespace ZYSystem {
    class ScreenLogger :public CStdLogger
    {
    private:
	    static ScreenLogger m_screenLogger;
	    static const char outTime[38];

		///@brief 输出用于日志每行开头的时间
	    inline void outputTime();

		virtual void outputVL(TLogLevel level, char *format,va_list v);

	    virtual void output(TLogLevel level, char *format,...);

    public:
	    ScreenLogger();
	    ~ScreenLogger();
    };
}
#endif //SCREENLOGGER_H_