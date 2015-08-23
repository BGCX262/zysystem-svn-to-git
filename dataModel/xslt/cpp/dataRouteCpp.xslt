<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0" 
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
	xmlns:xs="http://www.w3.org/2001/XMLSchema" 
	xmlns:fn="http://www.w3.org/2005/xpath-functions">
	<xsl:output method="text" indent="yes" byte-order-mark="yes"/>
	<!-- 生成结构体 -->
	<xsl:template match="/Model/Structs">
 <xsl:result-document encoding="GBK" method="text" href="./generate/CDataRoute.cpp">
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CDataRoute.cpp
///@brief 数据路由实现,负责将接收到的行情数据转发到计算器和行情落地到文件
///@author xslt模型代码转换工具
///@date <xsl:value-of select="current-dateTime()"/>
/////////////////////////////////////////////////////////////////////////
#include "CDataRoute.h"

#ifndef CDATAROUTE_CPP_
#define CDATAROUTE_CPP_

using namespace ZYSystem;

CDataRoute* CDataRoute::instance = NULL;

CDataRoute::CDataRoute(){
  packageFactory = CTPackageFactory();
  queue =new CMsgQueue(DATAROUTE_QUE_LEN);
  MDqueue =new CMsgQueue(DATAROUTE_MDQUE_LEN);
  <xsl:for-each select="Struct[@name != 'MarketData']">
  <xsl:if test="@log = 'true'"><xsl:value-of select="@name"/>W = new C<xsl:value-of select="@name"/>Writer(CDataFile::dataPath);
  </xsl:if>
  </xsl:for-each>
}

CDataRoute::~CDataRoute(void)
{
}

CDataRoute* CDataRoute::getInstance(){
	if (instance == NULL) {
		instance =new CDataRoute();
	}
	return instance;
}

void CDataRoute::send(CTPackage* in){
	if (in->getPackageType() == TPID_MarketData) {
		MDqueue->push(in);
	} else {
		queue->push(in);
	}
}

void CDataRoute::setConnector(boost::function0&lt;void&gt; connectConnector_in){
  connectConnector = connectConnector_in;
}

<xsl:for-each select="Struct">
void CDataRoute::subscribe(boost::function&lt;TID (S<xsl:value-of select="@name"/>*)&gt; f){
	sig_S<xsl:value-of select="@name"/>.connect(f);
}
</xsl:for-each>

void CDataRoute::startup(){

  boost::thread thrd(connectConnector);
	thrd.detach();

	CTPackage p = CTPackage();
	//1毫秒
	boost::posix_time::time_duration td = boost::posix_time::time_duration(0,0,1);
  void* s;
     
	while(1){ 
		//队列处理
	    while(MDqueue->getSize() != 0 || queue->getSize() != 0 ){    
            while(queue->getSize() != 0){
			    queue->pop(&amp;p);

			    switch (p.getPackageType()) {                
<xsl:for-each select="Struct[@name != 'MarketData']">
                case TPID_<xsl:value-of select="@name"/>: {
                  s =new S<xsl:value-of select="@name"/>();
					        packageFactory.toStructs(&amp;p,(S<xsl:value-of select="@name"/>*) s);
                  <xsl:if test="@log = 'true'"><xsl:value-of select="@name"/>W->addRecord((S<xsl:value-of select="@name"/>*) s);</xsl:if>
				          sig_S<xsl:value-of select="@name"/>((S<xsl:value-of select="@name"/>*)s);
				          break;
				    }
</xsl:for-each>
				default:{}
			    }               
                free(s);
		    }
            
            if (MDqueue->getSize() != 0) {
                MDqueue->pop(&amp;p);
                s =new SMarketData();
                packageFactory.toStructs(&amp;p,(SMarketData*) s);
                sig_SMarketData((SMarketData*)s); 
                delete s;
            }
	    }
		boost::this_thread::sleep(td);
	};
}
#endif //CDATAROUTE_CPP_
		</xsl:result-document>
	</xsl:template>
</xsl:stylesheet>
