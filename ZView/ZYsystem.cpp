/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CtpMDSpi.cpp
///@brief 实现 用于上期技术综合交易平台的行情服务接口类
///@author 张弛
///@date 20130818
/////////////////////////////////////////////////////////////////////////
#include "ZYsystem.h"

using namespace ZYSystem;

BEGIN_MESSAGE_MAP(ZYsystemApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &ZYsystemApp::OnAppAbout)
END_MESSAGE_MAP()

ZYsystemApp::ZYsystemApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

ZYsystemApp theApp;

BOOL ZYsystemApp::InitInstance()
{
	CWinApp::InitInstance();

	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_ZYsystemTYPE,
		RUNTIME_CLASS(ZYsystemDoc),
		RUNTIME_CLASS(ChildFrame), // custom MDI child frame
		RUNTIME_CLASS(ZYsystemView));
	AddDocTemplate(pDocTemplate);

	// create main MDI Frame window
	MainFrame* pMainFrame = new MainFrame();
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;

	pMainFrame->ShowWindow(SW_SHOWMAXIMIZED);
	pMainFrame->UpdateWindow();

	return TRUE;
}


class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

void ZYsystemApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}