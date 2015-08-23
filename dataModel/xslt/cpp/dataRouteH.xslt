<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0" 
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
	xmlns:xs="http://www.w3.org/2001/XMLSchema" 
	xmlns:fn="http://www.w3.org/2005/xpath-functions">
	<xsl:output method="text" indent="yes" byte-order-mark="yes"/>
	<!-- 生成结构体 -->
	<xsl:template match="/Model/Structs">
 <xsl:result-document encoding="GBK" method="text" href="./generate/CDataRoute.h">
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CDataRoute.h
///@brief 数据路由声明,负责将接收到的行情数据转发到计算器和行情落地到文件,单例模式
///       其实就是一个系统内部运行的消息总线，沟通各个部件
///@author xslt模型代码转换工具
///@date <xsl:value-of select="current-dateTime()"/>
/////////////////////////////////////////////////////////////////////////
#include "CTPackageFactory.h"
#include "MsgQueue.h"

#ifndef CDATAROUTE_H_
#define CDATAROUTE_H_

namespace ZYSystem {

	class CDataRoute
	{
		private:    
<xsl:for-each select="Struct">
            <xsl:if test="@log = 'true'">
      C<xsl:value-of select="@name"/>Writer* <xsl:value-of select="@name"/>W;
            </xsl:if>   
      ///@brief <xsl:value-of select="@label"/>包转发器
  		boost::signals2::signal&lt;TID (S<xsl:value-of select="@name"/>*)&gt; sig_S<xsl:value-of select="@name"/>;
</xsl:for-each>
			///@brief 转发队列
			CMsgQueue* queue;
      
      ///@brief 连接器
      boost::function0&lt;void&gt; connectConnector;

      ///@brief 行情转发队列
			CMsgQueue* MDqueue;

			///@brief 行情路由实例
			static CDataRoute* instance;

			///@brief 封包、解包
			CTPackageFactory packageFactory;
			
			CDataRoute(void);
		public:
			///@brief 发包接口 
			///@param in 发给数据路由包
			void send(CTPackage* in);
      
      ///@brief 设置用于启动的connnection
      ///@param f 函数
  		void setConnector(boost::function0&lt;void&gt; connectConnector_in);

<xsl:for-each select="Struct">
      ///@brief 订阅<xsl:value-of select="@label"/>
      ///@param f 订阅的方法
  		void subscribe(boost::function&lt;TID (S<xsl:value-of select="@name"/>*)&gt; f);
</xsl:for-each>
               
			///@brief 发包接口 
			///@param in 发给数据路由包
			///@param f 订阅的方法
			void startup();

			///@brief 获取数据路由实例
			///@return 数据路由
			static CDataRoute* getInstance();

			///@brief CDataRoute析构
      ~CDataRoute(void);
	};
}
#endif //CDATAROUTE_H_
		</xsl:result-document>
	</xsl:template>
</xsl:stylesheet>
