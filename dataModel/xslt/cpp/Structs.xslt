<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0" 
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
	xmlns:xs="http://www.w3.org/2001/XMLSchema" 
	xmlns:fn="http://www.w3.org/2005/xpath-functions">
	<xsl:output method="text" indent="yes" byte-order-mark="yes"/>
	<!-- 生成结构体 -->
	<xsl:template match="/Model/Structs">
 <xsl:result-document encoding="GBK" method="text" href="./generate/Structs.h">
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file Structs.h
///@brief 定义公用的结构体,基于程序生成，不要手工修改
///@author xslt模型代码转换工具
///@date <xsl:value-of select="current-dateTime()"/>
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "TypeDefine.h"

#ifndef STRUCTS_H_
#define STRUCTS_H_

namespace ZYSystem {

<xsl:for-each select="Struct">
///@struct <xsl:value-of select="@description"/>
#define TPID_<xsl:value-of select="@name"/><xsl:text> </xsl:text><xsl:value-of select="@tpid"/>
struct S<xsl:value-of select="@name"/> {
	<xsl:for-each select="Entity">
		<xsl:variable name="entityName" select="@name"/>	
		<xsl:for-each select="//Model/Entitys/Entity[@name = $entityName]/Field">
	///@brief <xsl:value-of select="@label"/>,<xsl:value-of select="@description"/>
	<xsl:text>&#x0009;</xsl:text>
	T<xsl:value-of select="@type"/><xsl:text> </xsl:text><xsl:value-of select="@name"/>;
		</xsl:for-each>
	</xsl:for-each>
};	
</xsl:for-each>
}
#endif
		</xsl:result-document>
	</xsl:template>
</xsl:stylesheet>
