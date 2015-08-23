<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="2.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:xs="http://www.w3.org/2001/XMLSchema"
	xmlns:fn="http://www.w3.org/2005/xpath-functions">
    
    <xsl:output method="text" indent="no" encoding="utf-8" byte-order-mark="yes"/>
    <xsl:template match="*">
        <xsl:result-document encoding="GBK" method="text" href="./generate/LogDefine.h">
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file LogDefine.h
///@brief 用于定义ZY System的错误类型定义
///@author xslt模型代码转换工具
///@date <xsl:value-of select="current-dateTime()"/>
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "../generate/Structs.h"

#ifndef LOG_DEFINE_H
#define LOG_DEFINE_H

#define SUCCESS 0
<xsl:for-each select="log_group">
    <xsl:variable name="sub_system_code" select="@sub_system_code"/>
    <xsl:variable name="sub_system_id" select="@sub_system_id"/>
    <xsl:for-each select="log">
#define <xsl:value-of select="$sub_system_code"/>_<xsl:value-of select="@logCode"/><xsl:text> </xsl:text><xsl:value-of select="$sub_system_id"/><xsl:value-of select="@logID"/>
    </xsl:for-each>
<xsl:text>
</xsl:text>
</xsl:for-each>
#endif //LOG_DEFINE_H
</xsl:result-document>
    </xsl:template>
</xsl:stylesheet>
