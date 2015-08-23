<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:xs="http://www.w3.org/2001/XMLSchema"
	xmlns:fn="http://www.w3.org/2005/xpath-functions">
    <xsl:output method="text" indent="yes" byte-order-mark="yes"/>
    <!-- 文件读取操作类 -->
    <xsl:template match="//Model/Structs">
        <xsl:result-document encoding="GBK" method="text" href="./generate/CTPackageFactory.cpp">            
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CTPackageFactory.cpp
///@brief 声明 TPackage 生成工厂类
///@author xslt模型代码转换工具
///@date <xsl:value-of select="current-dateTime()"/>
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "./CTPackageFactory.h"

#ifndef CTPACKAGEFACTORY_CPP_
#define CTPACKAGEFACTORY_CPP_

using namespace ZYSystem;

CTPackageFactory::CTPackageFactory(){
}

CTPackageFactory:: ~CTPackageFactory(){
}

<xsl:for-each select="Struct">
void CTPackageFactory::toStructs(CTPackage* from,S<xsl:value-of select="@name"/>* to){
    from->getContent(to);
}

void CTPackageFactory::toCTP(S<xsl:value-of select="@name"/>* from,CTPackage* to){
    to->setPackageType(TPID_<xsl:value-of select="@name"/>);
    to->setContent(from,sizeof S<xsl:value-of select="@name"/>);
}
</xsl:for-each>

#endif //CTPACKAGEFACTORY_CPP_
        </xsl:result-document>
    </xsl:template>
</xsl:stylesheet>
