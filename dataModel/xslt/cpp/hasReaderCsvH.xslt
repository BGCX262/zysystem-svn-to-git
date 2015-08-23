<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:xs="http://www.w3.org/2001/XMLSchema"
	xmlns:fn="http://www.w3.org/2005/xpath-functions">
    <xsl:output method="text" indent="yes" byte-order-mark="yes"/>
    <!-- 文件读取操作类 -->
    <xsl:template match="//Model/Structs">
        <xsl:for-each select="Struct[@hasReader='true']">
            <xsl:variable name="name" select="@name"/>
            <xsl:result-document encoding="GBK" method="text" href="./generate/C{$name}Reader.h">
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file C<xsl:value-of select="@name"/>Reader.h
///@brief 声明 <xsl:value-of select="@description"/> 文件读取器
///@author xslt模型代码转换工具
///@date <xsl:value-of select="current-dateTime()"/>
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "./Structs.h"
#include "../util/DataFile.h"

#ifndef C<xsl:value-of select="upper-case(@name)"/>READER_H_
#define C<xsl:value-of select="upper-case(@name)"/>READER_H_

namespace ZYSystem {
    class C<xsl:value-of select="@name"/>Reader:public CDataFile{
        private:
            //存储文件
            boost::iostreams::stream&lt;boost::iostreams::file_source&gt; in;
            std::vector&lt;std::string&gt; splitVec;

        public:
            //这里的dataPath_In是最终路径
            C<xsl:value-of select="@name"/>Reader(const TPath dataPath_In,TFile fileName_in ="<xsl:value-of select="@name"/>");
            ~C<xsl:value-of select="@name"/>Reader(void);

            //新增记录
            //@param in 需要存储的结构体
            TID readRecord(S<xsl:value-of select="@name"/>* out);
    };
}
#endif //C<xsl:value-of select="upper-case(@name)"/>READER_H_
            </xsl:result-document>
        </xsl:for-each>
    </xsl:template>
</xsl:stylesheet>
