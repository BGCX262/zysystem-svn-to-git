/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TPackage.cpp
///@brief 系统数据路由的传输包声明,将各个处理单元的注册到数据路由的接口统一
///@author 张弛
///@date 20120303
/////////////////////////////////////////////////////////////////////////
#include "TPackage.h"

#ifndef CTPACKAGE_CPP_
#define CTPACKAGE_CPP_

using namespace ZYSystem;

CTPackage::CTPackage(void){
	content =new char[TPACKAGE_LEN];
}

CTPackage::~CTPackage(void){
}

TID CTPackage::setContent(void* content_in,TPLength length_in) {
	this->length = length_in;
	std::memcpy(content,content_in,length_in);
	return SUCCESS;
}

TID CTPackage::getContent(void* content_in) {
	std::memcpy(content_in,content,length);
	return SUCCESS;
}

void CTPackage::setPackageType(TPID type){
	this->packageType = type;
}

TPID CTPackage::getPackageType(){
	return packageType;
}

#endif //CTPACKAGE_CPP_