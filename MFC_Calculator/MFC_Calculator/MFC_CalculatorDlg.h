
// MFC_CalculatorDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"


// CMFC_CalculatorDlg 대화 상자
class CMFC_CalculatorDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFC_CalculatorDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	bool isFirst, isMathSignClicked;
	int resultSign, beforeResult;

public:
	inline void InitCString(CString &str) { str = TEXT(""); }
	void InterimCalculate(CString &, CString &);
	void MathematicSignCalculate(CString, int &add, CString num);

public:
	CStatic m_inputStaticC;
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	CString m_inputStaticV;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CString m_outputStaticV;
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton1();
	CString m_listBoxV;
	afx_msg void OnBnClickedButton17();
	CListBox m_listBoxC;
};
