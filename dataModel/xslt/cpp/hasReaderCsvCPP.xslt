<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:xs="http://www.w3.org/2001/XMLSchema"
	xmlns:fn="http://www.w3.org/2005/xpath-functions">
	<xsl:output method="text" indent="yes" byte-order-mark="yes"/>
	<xsl:variable name="baseType" select="document('../../BaseType.xml')"/>
	<!-- DBF操作类 -->
	<xsl:template match="//Model/Structs">
		<xsl:for-each select="Struct[@hasReader='true']">
			<xsl:variable name="name" select="@name"/>
			<xsl:result-document encoding="GBK" method="text" href="./generate/C{$name}Reader.cpp">
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file C<xsl:value-of select="@name"/>Reader.cpp
///@brief 实现 <xsl:value-of select="@description"/> 文件读取器
///@author xslt模型代码转换工具
///@date <xsl:value-of select="current-dateTime()"/>
/////////////////////////////////////////////////////////////////////////
#include "C<xsl:value-of select="@name"/>Reader.h"

using namespace ZYSystem;

#ifndef C<xsl:value-of select="upper-case(@name)"/>READER_CPP_
#define C<xsl:value-of select="upper-case(@name)"/>READER_CPP_

C<xsl:value-of select="@name"/>Reader::C<xsl:value-of select="@name"/>Reader(const TPath dataPath_In,TFile fileName_in){
	TFile fileName;
	sprintf(fileName,"%s%s.csv",dataPath_In,fileName_in);
	boost::iostreams::file_source thisfile(fileName);
	in.open(thisfile,std::ios::beg);
}

C<xsl:value-of select="@name"/>Reader::~C<xsl:value-of select="@name"/>Reader(void){
    in.close();
}

TID C<xsl:value-of select="@name"/>Reader::readRecord(S<xsl:value-of select="@name"/>* out){
    std::string temp;
    std::getline(in,temp);
    splitVec.clear();
    
    if (temp.empty()) {
        return -1;
    }
    
    if (temp.find(',') == temp.npos) {
        return -1;
    }
    
    boost::algorithm::split(splitVec,temp,boost::is_any_of(","),boost::algorithm::token_compress_off);

    if (splitVec.size() != 0) {
        <xsl:for-each select="Entity">
			<xsl:variable name="entityName" select="@name"/>     
				 <xsl:for-each select="//Model/Entitys/Entity[@name = $entityName]/Field">
					 <xsl:variable name="typeName" select="@type"/>
					 <xsl:if test="position() = 1">
        if("<xsl:value-of select="@name"/>" == splitVec[0]) {
            return -2;
        }
                     </xsl:if>
					 <xsl:if test="contains(name($baseType/DataTypes/*[@typename=$typeName]),'String')">
		strcpy(out-&gt;<xsl:value-of select="@name"/>,splitVec[<xsl:number value="position()-1" format="0" />].c_str());
					 </xsl:if>
					 <xsl:if test="contains(name($baseType/DataTypes/*[@typename=$typeName]),'Int')">
        out-&gt;<xsl:value-of select="@name"/> = boost::lexical_cast&lt;int&gt;(splitVec[<xsl:number value="position()-1" format="0" />].c_str());
					 </xsl:if>
					 <xsl:if test="contains(name($baseType/DataTypes/*[@typename=$typeName]),'Float')">
        out-&gt;<xsl:value-of select="@name"/> = boost::lexical_cast&lt;double&gt;(splitVec[<xsl:number value="position()-1" format="0" />].c_str());
					 </xsl:if>
                     <xsl:if test="contains(name($baseType/DataTypes/*[@typename=$typeName]),'EnumChar')">
        out-&gt;<xsl:value-of select="@name"/> = boost::lexical_cast&lt;int&gt;(splitVec[<xsl:number value="position()-1" format="0" />].c_str());
					 </xsl:if>
			 </xsl:for-each>
		</xsl:for-each>
		return 0;
	} else {
		return -1;
	}    
}

#endif //C<xsl:value-of select="upper-case(@name)"/>READER_CPP_
			</xsl:result-document>
		</xsl:for-each>
	</xsl:template>
</xsl:stylesheet>
