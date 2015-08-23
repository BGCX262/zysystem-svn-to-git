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
			<xsl:result-document encoding="GBK" method="text" href="./generate/C{$name}Writer.cpp">
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file C<xsl:value-of select="@name"/>Writer.cpp
///@brief 实现 <xsl:value-of select="@description"/> 文件记录器
///@author xslt模型代码转换工具
///@date <xsl:value-of select="current-dateTime()"/>
/////////////////////////////////////////////////////////////////////////
#include "C<xsl:value-of select="@name"/>Writer.h"

using namespace ZYSystem;

#ifndef C<xsl:value-of select="upper-case(@name)"/>WRITER_CPP_
#define C<xsl:value-of select="upper-case(@name)"/>WRITER_CPP_

C<xsl:value-of select="@name"/>Writer::C<xsl:value-of select="@name"/>Writer(const TPath dataPath_In,TFile fileName_in){
		if(!boost::filesystem::exists(dataPath_In)) {
				boost::filesystem::create_directories(dataPath_In);
		}

        std::strcpy(this-&gt;nowTradingDay,"");
		std::strcpy(this-&gt;dataPath,dataPath_In);
		std::strcpy(this-&gt;fileName,fileName_in);
		mode = std::ios::out;
}

C<xsl:value-of select="@name"/>Writer::~C<xsl:value-of select="@name"/>Writer(void){
		out.flush();
		out.close();
}

void C<xsl:value-of select="@name"/>Writer::addRecord(S<xsl:value-of select="@name"/>* in){
		if (std::strlen(nowTradingDay) == 0 || std::strcmp(nowTradingDay,in->TradingDay) != 0 ) {		
			if (out.is_open()) {
				out.close();
			}			
			
			std::strcpy(nowTradingDay,in-&gt;TradingDay);

			TFile thisFileName;
			sprintf(thisFileName,"%s%s/%s.csv",dataPath,nowTradingDay,fileName);
			boost::iostreams::file_sink thisfile(thisFileName,mode);
			out.open(thisfile);

            if (boost::filesystem::exists(thisFileName) &amp;&amp; 
				(boost::filesystem::file_size(thisFileName) &gt; 10)) {
					out &lt;&lt; std::endl &lt;&lt; "new data after restart" &lt;&lt; boost::posix_time::second_clock::local_time() &lt;&lt; std::endl;
			} else {
				makeTitle();
			}
		}
        
        out &lt;&lt; std::endl;
		<xsl:for-each select="Entity">
		<xsl:variable name="entityName" select="@name"/>
				<xsl:for-each select="//Model/Entitys/Entity[@name = $entityName]/Field">
        out &lt;&lt; in-&gt;<xsl:value-of select="@name"/> &lt;&lt; ",";
				</xsl:for-each>
		</xsl:for-each>
		out.flush();
}

void C<xsl:value-of select="@name"/>Writer::makeTitle(){
	<xsl:for-each select="Entity">
		<xsl:variable name="entityName" select="@name"/>	
		<xsl:for-each select="//Model/Entitys/Entity[@name = $entityName]/Field">
		out &lt;&lt; "<xsl:value-of select="@name"/>,";
				</xsl:for-each>
	</xsl:for-each>
		out.flush();
}

void C<xsl:value-of select="@name"/>Writer::setMode(std::ios::openmode mode_in){
    mode = mode_in;
}

#endif //C<xsl:value-of select="upper-case(@name)"/>WRITER_CPP_
			</xsl:result-document>
		</xsl:for-each>
	</xsl:template>
</xsl:stylesheet>
