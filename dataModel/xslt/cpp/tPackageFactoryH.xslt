<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:xs="http://www.w3.org/2001/XMLSchema"
	xmlns:fn="http://www.w3.org/2005/xpath-functions">
    <xsl:output method="text" indent="yes" byte-order-mark="yes"/>
    <!-- 文件读取操作类 -->
    <xsl:template match="//Model/Structs">
        <xsl:result-document encoding="GBK" method="text" href="./generate/CTPackageFactory.h">            
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CTPackageFactory.h
///@brief 声明 TPackage 拆包解包类
///@author xslt模型代码转换工具
///@date <xsl:value-of select="current-dateTime()"/>
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "TPackage.h"

#ifndef CTPACKAGEFACTORY_H_
#define CTPACKAGEFACTORY_H_

namespace ZYSystem {
    class CTPackageFactory{
        public:
            <xsl:for-each select="Struct">
            ///@brief CTPackage转换为S<xsl:value-of select="@name"/>
			///@param from CTPackage
            ///@param to S<xsl:value-of select="@name"/>
            void toStructs(CTPackage* from,S<xsl:value-of select="@name"/>* to);
 
            ///@brief S<xsl:value-of select="@name"/>转换为CTPackage
			///@param from S<xsl:value-of select="@name"/>
            ///@param to CTPackage
            void toCTP(S<xsl:value-of select="@name"/>* from,CTPackage* to);
            </xsl:for-each>
            
            ///@brief CTPackageFactory构造函数
            CTPackageFactory();
            
            ///@brief CTPackageFactory析构函数
            ~CTPackageFactory();
    };
}
#endif //CTPACKAGEFACTORY_H_
        </xsl:result-document>
    </xsl:template>
</xsl:stylesheet>