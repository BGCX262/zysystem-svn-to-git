<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:xs="http://www.w3.org/2001/XMLSchema"
	xmlns:fn="http://www.w3.org/2005/xpath-functions">
  <xsl:output method="text" indent="yes" byte-order-mark="yes"/>
  <!-- DBF操作类 -->
  <xsl:template match="//Model/Structs">
    <xsl:for-each select="Struct[@hasWriter='true']">
      <xsl:variable name="name" select="@name"/>
      <xsl:result-document encoding="GBK" method="text" href="./generate/C{$name}Writer.h">
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file C<xsl:value-of select="@name"/>Writer.h
///@brief 声明 <xsl:value-of select="@description"/> 文件记录器
///@author xslt模型代码转换工具
///@date <xsl:value-of select="current-dateTime()"/>
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "./Structs.h"
#include "../util/DataFile.h"

#ifndef C<xsl:value-of select="upper-case(@name)"/>WRITER_H_
#define C<xsl:value-of select="upper-case(@name)"/>WRITER_H_

namespace ZYSystem {
    class C<xsl:value-of select="@name"/>Writer:public CDataFile{
        private:
            //存储文件
            boost::iostreams::stream&lt;boost::iostreams::file_sink&gt; out;
              
            //创建文件title
            void makeTitle();
            
            TDate nowTradingDay;
            TPath dataPath;
			TFile fileName;
			std::ios::openmode mode;

        public:
            C<xsl:value-of select="@name"/>Writer(const TPath dataPath_In,TFile fileName_in ="<xsl:value-of select="@name"/>");
            ~C<xsl:value-of select="@name"/>Writer(void);

            //新增记录
            //@param in 需要存储的结构体
            void addRecord(S<xsl:value-of select="@name"/>* in);
            
            //设置文件操作模式
            //@param mode 文件操作模式
            void setMode(std::ios::openmode mode_in = std::ios::ate);
    };
}
#endif //C<xsl:value-of select="upper-case(@name)"/>WRITER_H_
      </xsl:result-document>
    </xsl:for-each>
  </xsl:template>
</xsl:stylesheet>
