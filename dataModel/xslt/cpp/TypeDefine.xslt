<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="2.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:xs="http://www.w3.org/2001/XMLSchema"
	xmlns:fn="http://www.w3.org/2005/xpath-functions">
    <xsl:output method="text" indent="no" encoding="utf-8" byte-order-mark="yes"/>
    <xsl:template match="/DataTypes">
        <xsl:result-document encoding="GBK" method="text" href="./generate/TypeDefine.h">
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TypeDefine.h
///@brief 用于定义ZY System的基础数据类型，基于程序生成，不要手工修改
///@author xslt模型代码转换工具
///@date <xsl:value-of select="current-dateTime()"/>
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "../System.h"

#ifndef TYPE_DEFINE_H
#define TYPE_DEFINE_H

namespace ZYSystem {
    typedef unsigned int TCount;
            <xsl:for-each select="String">
    ///@typedef char T<xsl:value-of select="@typename"/>[<xsl:value-of select="@length + 1"/>]
    ///@brief <xsl:value-of select="@label"/>
    typedef char T<xsl:value-of select="@typename"/>[<xsl:value-of select="@length + 1"/>];
            </xsl:for-each>
            <xsl:for-each select="Int">
    ///@typedef int T<xsl:value-of select="@typename"/>
    ///@brief <xsl:value-of select="@label"/>
    typedef int T<xsl:value-of select="@typename"/>;
            </xsl:for-each>
            <xsl:for-each select="Float">
    ///@typedef double T<xsl:value-of select="@typename"/>
    ///@brief <xsl:value-of select="@label"/>
    typedef double T<xsl:value-of select="@typename"/>;
            </xsl:for-each>
            <xsl:for-each select="EnumChar">
    ///@typedef enum T<xsl:value-of select="@typename"/>
    ///@brief <xsl:value-of select="@label"/>
    enum T<xsl:value-of select="@typename"/>  {
        <xsl:for-each select="Enum">
        <xsl:value-of select="parent::*/attribute::prefix"/>_<xsl:value-of select="@name"/> = <xsl:value-of select="@value"/>, /**&lt; <xsl:value-of select="@label"/>*/          
        </xsl:for-each>
        <xsl:value-of select="Enum/parent::*/attribute::prefix"/>_defaultValue = 0
    };
            </xsl:for-each>
}
#endif // TYPE_DEFINE_H
        </xsl:result-document>
    </xsl:template>
</xsl:stylesheet>