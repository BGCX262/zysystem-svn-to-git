/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CXML.cpp
///@brief 实现xml抽象类的功能函数
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "CXML.h"

#ifndef CXML_CPP_
#define CXML_CPP_

using namespace ZYSystem;

CXML::CXML(const TFile configFile){
	dom.LoadFile(configFile);
}

CXML::~CXML(){
}


double CXML::elementDoubleValue(const TXPath xpathString, TiXmlNode* nodeIn){

	if(xpathString == NULL) {
		return 0;
	}	
	
	if(nodeIn == NULL) {
		nodeIn =  dom.RootElement();
	}
	
	double result = 0;
    TinyXPath::o_xpath_double(nodeIn,xpathString,result);
	if (result==0) {
		TiXmlNode* node = TinyXPath::XNp_xpath_node(nodeIn, xpathString);
		if (node != NULL) {
			result = boost::lexical_cast<double> (node->ToElement()->GetText());
		}
	}

	return result;
}

char* CXML::elementCharValue(const TXPath xpathString,TXPathValue value,TiXmlNode* nodeIn){
	if(xpathString == NULL) {
		return 0;
	}
	if(nodeIn == NULL) {
		nodeIn = dom.RootElement();
	}
	TiXmlNode* node = TinyXPath::XNp_xpath_node(nodeIn, xpathString);
	if (node != NULL) {
		strcpy(value, node->ToElement()->GetText());
	}
	return value;
}

int CXML::elementIntValue(const TXPath xpathString, TiXmlNode* nodeIn){
	if(xpathString == NULL) {
		return 0;
	}	
	if(nodeIn == NULL) {
		nodeIn = dom.RootElement();
	}
	int result = 0;
	TinyXPath::o_xpath_int(nodeIn,xpathString,result);
	if (result==0) {
		TiXmlNode* node = TinyXPath::XNp_xpath_node(nodeIn, xpathString);
		if (node != NULL) {
			result = boost::lexical_cast<int> (node->ToElement()->GetText());
		}
	}
	return result;
}
#endif // CXML_CPP_