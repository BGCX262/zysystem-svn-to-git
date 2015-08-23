<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0" 
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
	xmlns:xs="http://www.w3.org/2001/XMLSchema" 
	xmlns:fn="http://www.w3.org/2005/xpath-functions">
	<xsl:output method="text" indent="yes" byte-order-mark="yes"/>
    <xsl:variable name="logDefine" select="document('../../LogDefine.xml')"/>
    <xsl:variable name="baseType" select="document('../../BaseType.xml')"/>
    <!-- 生成结构体 -->
	<xsl:template match="/Model/Structs">
<xsl:result-document encoding="GBK" method="text" href="./generate/CStdLog.cpp">
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CStdLog.cpp
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

#include "CStdLog.h"
#include "ScreenLogger.h"
#include "FileLogger.h"

#ifndef CSTDLOG_CPP_
#define CSTDLOG_CPP_

///业务日志
///是否使用业务状态日志
using namespace ZYSystem;

bool ZYSystemMainLog = true;

CStdLogger* CStdLogger::m_pInstance;
SLogConfig* CStdLogger::logConfig;

CStdLogger::CStdLogger(){
    setOutputLogInfo();
}

CStdLogger::~CStdLogger(){};

CStdLogger* CStdLogger::GetInstance(){
    return m_pInstance;
};

void CStdLogger::setLogConfig(SLogConfig* logConfig_in){
    if (m_pInstance == NULL) {
        logConfig = new SLogConfig();
        std::memcpy(logConfig,logConfig_in,sizeof SLogConfig);
        
        if (logConfig_in->LogOutputType == LOT_FileOutput) {
          m_pInstance = new CFileLogger();
        } else {
          m_pInstance = new ScreenLogger();
        }
    }
}

void CStdLogger::outputInfo(int format,...){
    SLog log = this->infoVector[format];
    
	va_list v;
    va_start(v,format);
	outputVL(log.LogLevel,log.LogMsg,v);
    va_end(v);
};

<xsl:for-each select="Struct">
void CStdLogger::logS<xsl:value-of select="@name"/>(S<xsl:value-of select="@name"/> *in){
    boost::mutex::scoped_lock lock(mtxStruct);
    output(LL_Debug,"-------------------------------------------------------------");
    output(LL_Debug,"{<xsl:value-of select="@description"/>}:");
    <xsl:for-each select="Entity">
        <xsl:variable name="entityName" select="@name"/>
        <xsl:for-each select="//Model/Entitys/Entity[@name = $entityName]/Field">
            <xsl:variable name="type" select="@type"/>
            <xsl:variable name="metaType" select="fn:node-name($baseType//DataTypes/*[@typename=$type])"/>
            <xsl:choose>
                <xsl:when test="fn:compare(fn:string($metaType),'String')=0">
    output(LL_Debug,"  <xsl:value-of select="@label"/>:[%s]",in-&gt;<xsl:value-of select="@name"/>);
                </xsl:when>
                <xsl:when test="fn:compare(fn:string($metaType),'Float')=0">
    output(LL_Debug,"  <xsl:value-of select="@label"/>:[%f]",in-&gt;<xsl:value-of select="@name"/>);
                </xsl:when>
                <xsl:when test="fn:compare(fn:string($metaType),'EnumChar')=0">
    switch (in-&gt;<xsl:value-of select="@name"/>) {
        <xsl:variable name="typename" select="@type"/>
        <xsl:variable name="label" select="@label"/>
        <xsl:for-each select="$baseType/DataTypes/EnumChar[@typename = $typename]/Enum">
        case <xsl:value-of select="parent::*/attribute::prefix"/>_<xsl:value-of select="@name"/>: {output(LL_Debug,"  <xsl:value-of select="$label"/>:[<xsl:value-of select="@value"/>-<xsl:value-of select="@label"/>]"); break;}
        </xsl:for-each>
    }
                </xsl:when>
                <xsl:otherwise>
    output(LL_Debug,"  <xsl:value-of select="@label"/>:[%d]",in-&gt;<xsl:value-of select="@name"/>);
                </xsl:otherwise>
            </xsl:choose>
        </xsl:for-each>
    </xsl:for-each>
    output(LL_Debug,"-------------------------------------------------------------");
    }
</xsl:for-each>
void CStdLogger::setOutputLogInfo(){
<xsl:for-each select="$logDefine//log_group">
    <xsl:variable name="sub_system_code" select="@sub_system_code"/>
    <xsl:variable name="sub_system_id" select="@sub_system_id"/>
    <xsl:for-each select="log">
        <xsl:variable name="log_name" select="concat('log_',$sub_system_code,@logCode)"/>
        SLog <xsl:value-of select="$log_name"/>;
        <xsl:value-of select="$log_name"/>.LogID = <xsl:value-of select="$sub_system_id"/><xsl:value-of select="@logID"/>;
        <xsl:value-of select="$log_name"/>.LogLevel = <xsl:value-of select="@logLevel"/>;
        std::strcpy(<xsl:value-of select="$log_name"/>.LogCode,"<xsl:value-of select="$sub_system_code"/>_<xsl:value-of select="@logCode"/>");
        std::strcpy(<xsl:value-of select="$log_name"/>.LogMsg,"[<xsl:value-of select="$sub_system_id"/><xsl:value-of select="@logID"/>$<xsl:value-of select="$sub_system_code"/>_<xsl:value-of select="@logCode"/>]:<xsl:value-of select="@logMsg"/>");
        infoVector[<xsl:value-of select="$sub_system_id"/><xsl:value-of select="@logID"/>]=<xsl:value-of select="$log_name"/>;
        <xsl:text>
    </xsl:text>
    </xsl:for-each>
</xsl:for-each>
}
#endif//CSTDLOG_CPP_
		</xsl:result-document>
	</xsl:template>
</xsl:stylesheet>
