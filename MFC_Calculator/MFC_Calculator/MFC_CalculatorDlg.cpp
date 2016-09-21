
// MFC_CalculatorDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MFC_Calculator.h"
#include "MFC_CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CMFC_CalculatorDlg ��ȭ ����



CMFC_CalculatorDlg::CMFC_CalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_CALCULATOR_DIALOG, pParent)
	, m_inputStaticV(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_CalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC2, m_inputStaticC);
	DDX_Text(pDX, IDC_STATIC2, m_inputStaticV);
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
END_MESSAGE_MAP()


// CMFC_CalculatorDlg �޽��� ó����

BOOL CMFC_CalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMFC_CalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMFC_CalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_CalculatorDlg::OnBnClickedButton18()
{
	// TODO: Add your control notification handler code here
	m_inputStaticV += TEXT("0");

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton13()
{
	// TODO: Add your control notification handler code here
	m_inputStaticV += TEXT("1");

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton14()
{
	// TODO: Add your control notification handler code here
	m_inputStaticV += TEXT("2");

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton15()
{
	// TODO: Add your control notification handler code here
	m_inputStaticV += TEXT("3");

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	m_inputStaticV += TEXT("4");

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton10()
{
	// TODO: Add your control notification handler code here
	m_inputStaticV += TEXT("5");

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton11()
{
	// TODO: Add your control notification handler code here
	m_inputStaticV += TEXT("6");

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	m_inputStaticV += TEXT("7");

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here.
	m_inputStaticV += TEXT("8");

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	m_inputStaticV += TEXT("9");

	UpdateData(FALSE);
}
