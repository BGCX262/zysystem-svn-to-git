/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file ZYSystemServerLoader.cpp
///@brief ZY Syetem 的启动函数所在类
///@author 张弛
///@date 20101105
/////////////////////////////////////////////////////////////////////////

#include "ZYSystemMain.h"

using namespace ZYSystem;

int main(void)
{	
	
	
	//设置配置文件的位置
	const ZYSystem::TFile configFile = "config.xml";
	ZYSystem::CConfigXml* configXML = new ZYSystem::CConfigXml(configFile);
	
	//设置日志文件

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

	//实例化 ZYSystemMain 
	ZYSystem::ZYSystemMain* server = new ZYSystem::ZYSystemMain(configXML);	
	return 0;
}