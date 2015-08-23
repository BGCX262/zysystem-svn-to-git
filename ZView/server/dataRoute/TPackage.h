#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file TPackage.h
///@brief ϵͳ����·�ɵĴ��������,����������Ԫ��ע�ᵽ����·�ɵĽӿ�ͳһ
///@author �ų�
///@date 20120303
/////////////////////////////////////////////////////////////////////////
#include "../generate/gen.h"

#ifndef CTPACKAGE_H_
#define CTPACKAGE_H_

namespace ZYSystem {
	class CTPackage
	{
	private:
		///@brief ���ݰ�����������
		TPID packageType;

		///@brief ���ݰ�����
		char* content;

		///@brief ���ݰ�����
		TPLength length;
	public:
		///@brief �������ݰ���������
		///@param type ����
		void setPackageType(TPID type);

		///@brief ��ȡ���ݰ���������
		///@return	����
		TPID getPackageType();

		///@brief �������ݰ����ݵ���Ϣ����
		///@param in ����ָ��
		///@param length ���ݳ���
		TID setContent(void* content_in,TPLength length_in);

		///@brief ��ȡ���ݰ�������
		///@param in ��ȡ��Ϣ��ָ�룬�ǿ�
		///@param length ���ݳ���
		TID getContent(void* content_in);

		///@brief ������������еĿ���\���\���\����
		CTPackage(void);

		///@brief TPackage����������
		~CTPackage(void);
	};
}
#endif //CTPACKAGE_H_