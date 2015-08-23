<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:xs="http://www.w3.org/2001/XMLSchema"
	xmlns:fn="http://www.w3.org/2005/xpath-functions">
    <xsl:output method="text" indent="yes" byte-order-mark="yes"/>
    <xsl:variable name="baseType" select="document('BaseType.xml')"/>
    <!-- 生成结构体 -->
    <xsl:template match="/Model/Structs">
        <xsl:result-document encoding="GBK" method="text" href="./generate/Gen.h">
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file Gen.h
///@brief 定义所有生成的头文件
///@author xslt模型代码转换工具
///@date <xsl:value-of select="current-dateTime()"/>
/////////////////////////////////////////////////////////////////////////
#pragma once

#ifndef GEN_H_
#define GEN_H_

// 我们的通用log库
#include "../log/CStdLog.h"
#include "../log/LogDefine.h"

<xsl:for-each select="Struct[@hasWriter='true']">
#include "C<xsl:value-of select="@name"/>Writer.h"
</xsl:for-each>
<xsl:for-each select="Struct[@hasReader='true']">
#include "C<xsl:value-of select="@name"/>Reader.h"
</xsl:for-each>
#endif //GEN_H_
        </xsl:result-document>
    </xsl:template>
</xsl:stylesheet>