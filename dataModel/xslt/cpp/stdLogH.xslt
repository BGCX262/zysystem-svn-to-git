<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0" 
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
	xmlns:xs="http://www.w3.org/2001/XMLSchema" 
	xmlns:fn="http://www.w3.org/2005/xpath-functions">
	<xsl:output method="text" indent="yes" byte-order-mark="yes"/>
    <xsl:variable name="logDefine" select="document('LogDefine.xml')"/>
	<!-- 生成结构体 -->
	<xsl:template match="/Model/Structs">
<xsl:result-document encoding="GBK" method="text" href="./generate/CStdLog.h">
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CStdLog.h
///@brief 定义了日志输出类，日志的输出要求
///        1.多级别日志输出，可以控制输出需要的级别
///		   2.输出流可被重定向的
///       CLogger是一个抽象的日志接口，用于应用程序输出日志
///       它在全局只有一个实例，默认实例为向stdout输出日志，
///       应用程序可以继承CLogger，实现自已的日志类
///@author xslt模型代码转换工具
///@date <xsl:value-of select="current-dateTime()"/>
////////////////////////////////////////////////////////////////////////
#pragma once

#include "../generate/Structs.h"

#ifndef CSTDLOG_H_
#define CSTDLOG_H_

///业务日志
///是否使用业务状态日志
extern bool ZYSystemMainLog;

#define Debug_Log(sz)                   ZYSystem::CStdLogger::GetInstance()->output(LL_Debug,"%s",sz)

#define LOG0(sz)					ZYSystem::CStdLogger::GetInstance()->outputInfo(sz)
#define LOG1(sz, p1)				ZYSystem::CStdLogger::GetInstance()->outputInfo(sz, p1)
#define LOG2(sz, p1, p2)			ZYSystem::CStdLogger::GetInstance()->outputInfo(sz, p1, p2)
#define LOG3(sz, p1, p2, p3)		ZYSystem::CStdLogger::GetInstance()->outputInfo(sz, p1, p2, p3)

///日志的分类情况，可以通过注释掉下面的宏，完成禁止某项日志的输出

#define CHECK_LOG(logFlag,logCommand)      {if(logFlag) logCommand;}

///各组日志的控制
#define ZYSYSTEM_LOG0(sz)			CHECK_LOG(ZYSystemMainLog,LOG0(sz))
#define ZYSYSTEM_LOG1(sz,p1)		CHECK_LOG(ZYSystemMainLog,LOG1(sz,p1))
#define ZYSYSTEM_LOG2(sz,p1,p2)		CHECK_LOG(ZYSystemMainLog,LOG2(sz,p1,p2))
#define ZYSYSTEM_LOG3(sz,p1,p2,p3)	CHECK_LOG(ZYSystemMainLog,LOG3(sz,p1,p2,p3))

///错误码检查
#define CHECK_SUCCESS(tid) if(tid!=SUCCESS) {ZYSYSTEM_LOG0(tid);return tid;}
#define CHECK_SUCCESS_NoRet(tid) if(tid!=SUCCESS) {ZYSYSTEM_LOG0(tid)}

namespace ZYSystem {
    class CStdLogger
    {
    private:
        ///@brief 结构体日志输出锁
		boost::mutex mtxStruct;
    protected:
        ///@brief 信息存储体
        std::hash_map&lt;TID,SLog&gt; infoVector;
        
        ///@brief 构造函数
        CStdLogger();
        
	    ///@brief 析构函数
        ~CStdLogger();

	    ///@brief CStdLogger实例
	    static CStdLogger *m_pInstance;
    
    public:
        ///@brief 日志配置信息
	    static SLogConfig* logConfig;
    
        ///@brief 设置日志配置信息
        ///@param	logConfig_in 日志配置信息
	    static void setLogConfig(SLogConfig* logConfig_in);
    
	    ///@brief 获取CLogger实例
	    ///@return 获取的CLogger实例
	    static CStdLogger* GetInstance();

	    ///@brief 进行日志输出
	    ///@param	format	输出格式key
	    ///@param	...	具体的输出项
	    void outputInfo(int format,...);

	    ///@brief 进行日志输出
	    ///@param	level	日志级别，值越小，级别越高
	    ///@param	format	输出格式，按照printf的格式要求
	    ///@param	...	具体的输出项
	    virtual void output(TLogLevel level,char *format,...) = 0;
        
        ///@brief 进行日志输出
	    ///@param	level	日志级别，值越小，级别越高
	    ///@param	format	输出格式，按照printf的格式要求
	    ///@param	v	具体的输出项
	    virtual void outputVL(TLogLevel level,char *format,va_list v) = 0;

<xsl:for-each select="Struct">
        ///@brief 记录 <xsl:value-of select="@label"/> 日志
	    ///@param *in 被记录的 <xsl:value-of select="@label"/> 指针
        void logS<xsl:value-of select="@name"/>(S<xsl:value-of select="@name"/> *in);
</xsl:for-each>
    private:
        ///@brief 设置各种出错信息
        void setOutputLogInfo();
    };
}

<xsl:for-each select="Struct">
#define  LOG_S<xsl:value-of select="@name"/>(in) CHECK_LOG(ZYSystemMainLog,ZYSystem::CStdLogger::GetInstance()->logS<xsl:value-of select="@name"/>(in))
</xsl:for-each>

#endif
		</xsl:result-document>
	</xsl:template>
</xsl:stylesheet>
