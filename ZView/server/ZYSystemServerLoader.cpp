/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ZYSystemServerLoader.cpp
///@brief ZY Syetem ����������������
///@author �ų�
///@date 20101105
/////////////////////////////////////////////////////////////////////////

#include "ZYSystemMain.h"

using namespace ZYSystem;

int main(void)
{	
	
	
	//���������ļ���λ��
	const ZYSystem::TFile configFile = "config.xml";
	ZYSystem::CConfigXml* configXML = new ZYSystem::CConfigXml(configFile);
	
	//������־�ļ�

	SLogConfig* logConfig_in = new SLogConfig();
	configXML->getLogConfig(logConfig_in);
	ZYSystem::CStdLogger::setLogConfig(logConfig_in);
	delete logConfig_in;

	//LOGO
	Debug_Log("*************************************************************");
	Debug_Log("**********                                           ********");
	Debug_Log("**********                 ZYSystem                  ********");
	Debug_Log("**********                                           ********");
	Debug_Log("**********        Copyright 2010-2012 Ziumsoft       ********");
	Debug_Log("**********             Imagined Everything           ********");
	Debug_Log("*************************************************************");

	//ʵ���� ZYSystemMain 
	ZYSystem::ZYSystemMain* server = new ZYSystem::ZYSystemMain(configXML);	
	return 0;
}