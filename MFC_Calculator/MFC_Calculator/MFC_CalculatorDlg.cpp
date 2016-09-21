
// MFC_CalculatorDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MFC_Calculator.h"
#include "MFC_CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC_CalculatorDlg 대화 상자



CMFC_CalculatorDlg::CMFC_CalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_CALCULATOR_DIALOG, pParent)
	, m_inputStaticV(_T(""))
	, m_outputStaticV(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_CalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC2, m_inputStaticC);
	DDX_Text(pDX, IDC_STATIC2, m_inputStaticV);
	DDX_Text(pDX, IDC_STATIC1, m_outputStaticV);
}

BEGIN_MESSAGE_MAP(CMFC_CalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON18, &CMFC_CalculatorDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFC_CalculatorDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFC_CalculatorDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFC_CalculatorDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFC_CalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFC_CalculatorDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFC_CalculatorDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFC_CalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFC_CalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFC_CalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_CalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_CalculatorDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMFC_CalculatorDlg 메시지 처리기

BOOL CMFC_CalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_inputStaticV = TEXT("0");

	UpdateData(FALSE);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFC_CalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFC_CalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFC_CalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_CalculatorDlg::OnBnClickedButton18()
{
	// TODO: Add your control notification handler code here
	if (m_inputStaticV == TEXT("0"))
		m_inputStaticV = TEXT("0");
	else
		m_inputStaticV += TEXT("0");

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton13()
{
	// TODO: Add your control notification handler code here
	if (m_inputStaticV == TEXT("0"))
		m_inputStaticV = TEXT("1");
	else
		m_inputStaticV += TEXT("1");

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton14()
{
	// TODO: Add your control notification handler code here
	if (m_inputStaticV == TEXT("0"))
		m_inputStaticV = TEXT("2");
	else
		m_inputStaticV += TEXT("2");

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton15()
{
	// TODO: Add your control notification handler code here
	if (m_inputStaticV == TEXT("0"))
		m_inputStaticV = TEXT("3");
	else
		m_inputStaticV += TEXT("3");

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	if (m_inputStaticV == TEXT("0"))
		m_inputStaticV = TEXT("4");
	else
		m_inputStaticV += TEXT("4");

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton10()
{
	// TODO: Add your control notification handler code here
	if (m_inputStaticV == TEXT("0"))
		m_inputStaticV = TEXT("5");
	else
		m_inputStaticV += TEXT("5");

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton11()
{
	// TODO: Add your control notification handler code here
	if (m_inputStaticV == TEXT("0"))
		m_inputStaticV = TEXT("6");
	else
		m_inputStaticV += TEXT("6");

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	if (m_inputStaticV == TEXT("0"))
		m_inputStaticV = TEXT("7");
	else
		m_inputStaticV += TEXT("7");

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here.
	if (m_inputStaticV == TEXT("0"))
		m_inputStaticV = TEXT("8");
	else
		m_inputStaticV += TEXT("8");

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	if (m_inputStaticV == TEXT("0"))
		m_inputStaticV = TEXT("9");
	else
		m_inputStaticV += TEXT("9");

	UpdateData(FALSE);
}


void CMFC_CalculatorDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	m_inputStaticV = TEXT("0");

	UpdateData(FALSE);
}


void CMFC_CalculatorDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	m_inputStaticV = TEXT("0");
	m_outputStaticV = TEXT("");

	UpdateData(FALSE);
}
