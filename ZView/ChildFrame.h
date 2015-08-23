#pragma once


class ChildFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(ChildFrame)
public:
	ChildFrame();

// Overrides
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~ChildFrame();

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};