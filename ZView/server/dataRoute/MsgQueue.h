#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file MsgQueue.h
///@brief ��Ϣ���У�ר��Ϊ����·�ɶ��Ƶ���������ʽ����
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////
#include "../generate/gen.h"
#include "TPackage.h"

#ifndef CMSGQUEQUE_H_
#define CMSGQUEQUE_H_

namespace ZYSystem {

	class CMsgQueue
	{
	public:

		///@brief CMsgQueue��Ϣ���й��캯��
		///@param max_size_in ������󳤶�
		CMsgQueue(TVolume max_size_in = 500);

		///@brief ��ȡ���ݰ���������
		~CMsgQueue();

		///@brief �����ݰ��������
		///@param msg ����ָ��(����Ϊ��)
		void push(CTPackage* msg);

		///@brief ��ȡ���ݰ���������
		///@param msg ����ָ��(����Ϊ��)
		void pop(CTPackage* msg);

		///@brief �رն���
		void close();

		///@brief ��ȡ���е���󳤶�
		///@return ��󳤶�
		TVolume getMaxSize();

		///@brief ��ȡ���еĳ���
		///@return   ���еĵ�ǰ����
		TVolume getSize();

	private:
		///@brief ���в�����
		boost::mutex mtx;

		///@brief ����������������
		boost::condition_variable_any full_cond;

		///@brief �������������п�
		boost::condition_variable_any empty_cond;

		///@brief ����
		std::queue<CTPackage> msgs; 

		///@brief ���е���󳤶�
		std::size_t max_size;

		///@brief ��ȡ���ݰ���������
		bool close_flag;
	};
}
#endif //CMSGQUEQUE_H_