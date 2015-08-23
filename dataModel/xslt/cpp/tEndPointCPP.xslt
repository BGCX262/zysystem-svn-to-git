<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:xs="http://www.w3.org/2001/XMLSchema"
	xmlns:fn="http://www.w3.org/2005/xpath-functions">
    <xsl:output method="text" indent="yes" byte-order-mark="yes"/>
    <!-- 文件读取操作类 -->
    <xsl:template match="//Model/Structs">
        <xsl:result-document encoding="GBK" method="text" href="./generate/TEndPoint.cpp">            
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TEndPoint.cpp
///@brief 声明 TPackage 生成工厂类
///@author xslt模型代码转换工具
///@date <xsl:value-of select="current-dateTime()"/>
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "./TEndPoint.h"

#ifndef CTENDPOINT_CPP_
#define CTENDPOINT_CPP_

using namespace ZYSystem;

CTEndPoint::CTEndPoint(){
}

CTEndPoint:: ~CTEndPoint(){
}

inline void CTEndPoint::setlocalTime(TDateTime time) {
	boost::posix_time::ptime t(boost::posix_time::second_clock::local_time());
	std::strcpy(time,(boost::posix_time::to_iso_string(t)).c_str());
}

<xsl:for-each select="Struct">
inline void CTEndPoint::sendTP(S<xsl:value-of select="@name"/>* from){
    CTPackage to = CTPackage();
    to.setPackageType(TPID_<xsl:value-of select="@name"/>);
    to.setContent(from,sizeof S<xsl:value-of select="@name"/>);
    CDataRoute::getInstance()->send(&amp;to);
}
</xsl:for-each>

#endif //CTENDPOINT_CPP_
        </xsl:result-document>
    </xsl:template>
</xsl:stylesheet>
