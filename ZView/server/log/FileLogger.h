/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file FileLogger.h
///@brief �ļ���־���
///@author �ų�
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
		///@brief ��־�ļ�
	    FILE *logFile;

	    static const char outTime[38];

		///@brief ���������־ÿ�п�ͷ��ʱ��
	    inline void outputTime();

		virtual void outputVL(TLogLevel level, char *format,va_list v);

	    virtual void output(TLogLevel level, char *format,...);

    public:
	    CFileLogger();
	    ~CFileLogger();
    };
}
#endif //FILELOGGER_H_
		