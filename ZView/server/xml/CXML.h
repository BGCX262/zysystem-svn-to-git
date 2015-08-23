/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CXML.h
///@brief ZY System��xml��ȡ����
///@author �ų�
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

			///@brief ����element�ڵ�,ִ��һ��xpath,����double
			///@param xpathString	xpath���ʽ
			///@param nodeIn		��Ҫ���ʵĽڵ�
			///@return ���ֵ
			double elementDoubleValue(const TXPath xpathString,
									  TiXmlNode* nodeIn = NULL);
			

			///@brief ����element�ڵ�,ִ��һ��xpath,����char*
			///@param xpathString	xpath���ʽ
			///@param value         ���صĽ��ֵ
			///@param nodeIn		��Ҫ���ʵĽڵ�
			///@return ���ֵ
			char* elementCharValue(const TXPath xpathString,
								   TXPathValue value,
								   TiXmlNode* nodeIn = NULL);
			
			///@brief ����element�ڵ�,ִ��һ��xpath,����int
			///@param xpathString	xpath���ʽ
			///@param nodeIn		��Ҫ���ʵĽڵ�
			///@return ���ֵ
			int elementIntValue(const TXPath xpathString, 
								TiXmlNode* nodeIn = NULL);

		public:
			///@brief CXML���캯��
			///@param configFile	��Ҫװ�ص�xml�ļ�
			CXML(const TFile configFile);
			
			///@brief CXML��������
			~CXML(void);
	};
}

#endif // CXML_H_

