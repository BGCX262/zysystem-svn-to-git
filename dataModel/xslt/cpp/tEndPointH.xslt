<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:xs="http://www.w3.org/2001/XMLSchema"
	xmlns:fn="http://www.w3.org/2005/xpath-functions">
    <xsl:output method="text" indent="yes" byte-order-mark="yes"/>
    <!-- 文件读取操作类 -->
    <xsl:template match="//Model/Structs">
        <xsl:result-document encoding="GBK" method="text" href="./generate/TEndPoint.h">            
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TEndPoint.h
///@brief 声明 TPackage 拆包解包类
///@author xslt模型代码转换工具
///@date <xsl:value-of select="current-dateTime()"/>
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "CDataRoute.h"

#ifndef CTENDPOINT_H_
#define CTENDPOINT_H_

namespace ZYSystem {
    class CTEndPoint{
        protected:
            ///@brief 设置本地时间
			///@param time 本地时间
            inline virtual void setlocalTime(TDateTime time);
            
            <xsl:for-each select="Struct">    
            ///@brief 发送S<xsl:value-of select="@name"/>
			///@param from S<xsl:value-of select="@name"/>
            inline virtual void sendTP(S<xsl:value-of select="@name"/>* from);
            </xsl:for-each>
        public:
            ///@brief CTEndPoint构造函数
            CTEndPoint();
            
            ///@brief CTEndPoint析构函数
            ~CTEndPoint();
    };
}
#endif //CTENDPOINT_H_
        </xsl:result-document>
    </xsl:template>
</xsl:stylesheet>