
// MFC_Calculator.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMFC_CalculatorApp:
// �� Ŭ������ ������ ���ؼ��� MFC_Calculator.cpp�� �����Ͻʽÿ�.
//

class CMFC_CalculatorApp : public CWinApp
{
public:
	CMFC_CalculatorApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMFC_CalculatorApp theApp;