
// TestTask.h : main header file for the TestTask application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTestTaskApp:
// See TestTask.cpp for the implementation of this class
//

class CTestTaskApp : public CWinApp
{
public:
	CTestTaskApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTestTaskApp theApp;
