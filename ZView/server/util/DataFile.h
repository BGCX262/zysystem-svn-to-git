#pragma once
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file DataFile.h
///@brief �����ļ����ʻ���
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////

#include "../generate/TypeDefine.h"

#ifndef CDATAFILE_H_
#define CDATAFILE_H_

namespace ZYSystem {

	class CDataFile
	{
	public:
        ///@brief ȫ�ֹ��������ļ��洢·��
		static TPath dataPath;
		
        ///@brief ���캯��
        CDataFile(void);
		
        ///@brief ��������
        ~CDataFile(void);
	};
}
#endif //CDATAFILE_H_
