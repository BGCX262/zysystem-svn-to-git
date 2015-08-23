/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ScreenLogger.h
///@brief ��Ļ��־���
///@author �ų�
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

		///@brief ���������־ÿ�п�ͷ��ʱ��
	    inline void outputTime();

		virtual void outputVL(TLogLevel level, char *format,va_list v);

	    virtual void output(TLogLevel level, char *format,...);

    public:
	    ScreenLogger();
	    ~ScreenLogger();
    };
}
#endif //SCREENLOGGER_H_