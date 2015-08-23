/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TPackage.cpp
///@brief ϵͳ����·�ɵĴ��������,����������Ԫ��ע�ᵽ����·�ɵĽӿ�ͳһ
///@author �ų�
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