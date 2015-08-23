/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CXML.h
///@brief ZY System的xml读取基类
///@author 张弛
///@date 20110329
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "../generate/Gen.h"

#ifndef CXML_H_
#define CXML_H_

using namespace TinyXPath;

namespace ZYSystem {
	class CXML {
		protected:
			///@brief XMLdom
			TiXmlDocument dom;

			///@brief 访问element节点,执行一个xpath,返回double
			///@param xpathString	xpath表达式
			///@param nodeIn		需要访问的节点
			///@return 结果值
			double elementDoubleValue(const TXPath xpathString,
									  TiXmlNode* nodeIn = NULL);
			

			///@brief 访问element节点,执行一个xpath,返回char*
			///@param xpathString	xpath表达式
			///@param value         返回的结果值
			///@param nodeIn		需要访问的节点
			///@return 结果值
			char* elementCharValue(const TXPath xpathString,
								   TXPathValue value,
								   TiXmlNode* nodeIn = NULL);
			
			///@brief 访问element节点,执行一个xpath,返回int
			///@param xpathString	xpath表达式
			///@param nodeIn		需要访问的节点
			///@return 结果值
			int elementIntValue(const TXPath xpathString, 
								TiXmlNode* nodeIn = NULL);

		public:
			///@brief CXML构造函数
			///@param configFile	需要装载的xml文件
			CXML(const TFile configFile);
			
			///@brief CXML析构函数
			~CXML(void);
	};
}

#endif // CXML_H_

