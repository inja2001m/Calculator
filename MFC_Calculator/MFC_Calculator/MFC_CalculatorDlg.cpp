
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
	, m_outputStaticV(_T(""))
	, m_listBoxV(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_CalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC2, m_inputStaticC);
	DDX_Text(pDX, IDC_STATIC2, m_inputStaticV);
	DDX_Text(pDX, IDC_STATIC1, m_outputStaticV);
	DDX_LBString(pDX, IDC_LIST1, m_listBoxV);
	DDX_Control(pDX, IDC_LIST1, m_listBoxC);
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
	ON_BN_CLICKED(IDC_BUTTON16, &CMFC_CalculatorDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFC_CalculatorDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFC_CalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC_CalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_CalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFC_CalculatorDlg::OnBnClickedButton17)
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
	m_inputStaticV = TEXT("0");
	isFirst = true;
	isMathSignClicked = false;
	resultSign = 0;
	beforeResult = 0;

	UpdateData(FALSE);

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


// Num Button
void CMFC_CalculatorDlg::OnBnClickedButton18()
{
	// TODO: Add your control notification handler code here
	if (isMathSignClicked)
		InitCString(m_inputStaticV);

	if (m_inputStaticV == TEXT("0"))
		m_inputStaticV = TEXT("0");
	else
		m_inputStaticV += TEXT("0");

	isMathSignClicked = false;

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton13()
{
	// TODO: Add your control notification handler code here
	if (isMathSignClicked)
		InitCString(m_inputStaticV);

	if (m_inputStaticV == TEXT("0"))
		m_inputStaticV = TEXT("1");
	else
		m_inputStaticV += TEXT("1");

	isMathSignClicked = false;

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton14()
{
	// TODO: Add your control notification handler code here
	if (isMathSignClicked)
		InitCString(m_inputStaticV);

	if (m_inputStaticV == TEXT("0"))
		m_inputStaticV = TEXT("2");
	else
		m_inputStaticV += TEXT("2");

	isMathSignClicked = false;

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton15()
{
	// TODO: Add your control notification handler code here
	if (isMathSignClicked)
		InitCString(m_inputStaticV);

	if (m_inputStaticV == TEXT("0"))
		m_inputStaticV = TEXT("3");
	else
		m_inputStaticV += TEXT("3");

	isMathSignClicked = false;

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	if (isMathSignClicked)
		InitCString(m_inputStaticV);

	if (m_inputStaticV == TEXT("0"))
		m_inputStaticV = TEXT("4");
	else
		m_inputStaticV += TEXT("4");

	isMathSignClicked = false;

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton10()
{
	// TODO: Add your control notification handler code here
	if (isMathSignClicked)
		InitCString(m_inputStaticV);

	if (m_inputStaticV == TEXT("0"))
		m_inputStaticV = TEXT("5");
	else
		m_inputStaticV += TEXT("5");

	isMathSignClicked = false;

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton11()
{
	// TODO: Add your control notification handler code here
	if (isMathSignClicked)
		InitCString(m_inputStaticV);

	if (m_inputStaticV == TEXT("0"))
		m_inputStaticV = TEXT("6");
	else
		m_inputStaticV += TEXT("6");

	isMathSignClicked = false;

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	if (isMathSignClicked)
		InitCString(m_inputStaticV);

	if (m_inputStaticV == TEXT("0"))
		m_inputStaticV = TEXT("7");
	else
		m_inputStaticV += TEXT("7");

	isMathSignClicked = false;

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here.
	if (isMathSignClicked)
		InitCString(m_inputStaticV);

	if (m_inputStaticV == TEXT("0"))
		m_inputStaticV = TEXT("8");
	else
		m_inputStaticV += TEXT("8");

	isMathSignClicked = false;

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	if (isMathSignClicked)
		InitCString(m_inputStaticV);

	if (m_inputStaticV == TEXT("0"))
		m_inputStaticV = TEXT("9");
	else
		m_inputStaticV += TEXT("9");

	isMathSignClicked = false;

	UpdateData(FALSE);
}

// CE, C Button
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
	InitCString(m_outputStaticV);

	UpdateData(FALSE);
}

// Mathematical Sign Button
void CMFC_CalculatorDlg::MathematicSignCalculate(CString sign, int &add, CString num)
{
	switch (sign[0])
	{
	case '+':  add += _ttoi(num); break;
	case '-':  add -= _ttoi(num); break;
	case '*':  add *= _ttoi(num); break;
	case '/':  add /= _ttoi(num); break;
	default: break;
	}
}
void CMFC_CalculatorDlg::InterimCalculate(CString &inputStr, CString &outputStr)
{
	UpdateData(TRUE);

	bool isAdd = false;
	int add;
	CString num, sign;

	outputStr += inputStr;
	outputStr += TEXT(" ");

	int i = 0;
	for (; i < outputStr.GetLength(); ++i)
	{
		if (outputStr[i] == ' ')
			break;
		
		num += outputStr[i];
	}
	add = _ttoi(num);

	InitCString(num);
	int check = 0;
	for (i += 1; i < outputStr.GetLength(); ++i)
	{
		if ('0' <= outputStr[i] && outputStr[i] <= '9')
			num += outputStr[i];
		else if(outputStr[i] == '+')
		{
			InitCString(num);
			sign = TEXT("+");
		}
		else if (outputStr[i] == '-')
		{
			InitCString(num);
			sign = TEXT("-");
		}
		else if (outputStr[i] == '*')
		{
			InitCString(num);
			sign = TEXT("*");
		}
		else if (outputStr[i] == '/')
		{
			InitCString(num);
			sign = TEXT("/");
		}
		else if (outputStr[i] == ' ')
		{
			if (++check == 2)
			{
				MathematicSignCalculate(sign, add, num);
				check = 0;
			}
		}
	}

	beforeResult = add;
	inputStr.Format(_T("%d"), add);
	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton16()
{
	// TODO: Add your control notification handler code here
	if (m_inputStaticV == TEXT("0"))
		return;
	if (isFirst)
	{
		m_outputStaticV = m_inputStaticV + TEXT(" + ");
		isFirst = false;
		isMathSignClicked = true;
		resultSign = 1;
		beforeResult = _ttoi(m_inputStaticV);

		UpdateData(FALSE);

		return;
	}
	
	InterimCalculate(m_inputStaticV, m_outputStaticV);
	m_outputStaticV += TEXT("+ ");

	isFirst = false;
	isMathSignClicked = true;

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton12()
{
	// TODO: Add your control notification handler code here
	if (m_inputStaticV == TEXT("0"))
		return;
	if (isFirst)
	{
		m_outputStaticV = m_inputStaticV + TEXT(" - ");
		isFirst = false;
		isMathSignClicked = true;
		resultSign = 2;
		beforeResult = _ttoi(m_inputStaticV);

		UpdateData(FALSE);

		return;
	}

	InterimCalculate(m_inputStaticV, m_outputStaticV);
	m_outputStaticV += TEXT("- ");

	isFirst = false;
	isMathSignClicked = true;

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	if (m_inputStaticV == TEXT("0"))
		return;
	if (isFirst)
	{
		m_outputStaticV = m_inputStaticV + TEXT(" * ");
		isFirst = false;
		isMathSignClicked = true;
		resultSign = 3;
		beforeResult = _ttoi(m_inputStaticV);

		UpdateData(FALSE);

		return;
	}

	InterimCalculate(m_inputStaticV, m_outputStaticV);
	m_outputStaticV += TEXT("* ");

	isFirst = false;
	isMathSignClicked = true;

	UpdateData(FALSE);
}
void CMFC_CalculatorDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	if (m_inputStaticV == TEXT("0"))
		return;
	if (isFirst)
	{
		m_outputStaticV = m_inputStaticV + TEXT(" / ");
		isFirst = false;
		isMathSignClicked = true;
		resultSign = 4;
		beforeResult = _ttoi(m_inputStaticV);

		UpdateData(FALSE);

		return;
	}

	InterimCalculate(m_inputStaticV, m_outputStaticV);
	m_outputStaticV += TEXT("/ ");

	isFirst = false;
	isMathSignClicked = true;

	UpdateData(FALSE);
}


void CMFC_CalculatorDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	if (m_inputStaticV != '0')
	{
		m_inputStaticV.Delete(0, 1);
		if (m_inputStaticV == "")
			m_inputStaticV = TEXT("0");
	}

	UpdateData(FALSE);
}


void CMFC_CalculatorDlg::OnBnClickedButton17()
{
	// TODO: Add your control notification handler code here
	if (m_outputStaticV.IsEmpty())
		return;

	CString str, strTemp;

	str = m_outputStaticV;
	
	int result;
	switch (resultSign)
	{
	case 1:
		result = beforeResult + _ttoi(m_inputStaticV);
		break;
	case 2:
		result = beforeResult - _ttoi(m_inputStaticV);
		break;
	case 3:
		result = beforeResult * _ttoi(m_inputStaticV);
		break;
	case 4:
		if (m_inputStaticV == '0')
			result = 0;
		else
			result = beforeResult / _ttoi(m_inputStaticV);
		break;
	default:
		break;
	}

	strTemp.Format(_T("%d"), result);
	str += m_inputStaticV + TEXT(" = ") + strTemp;

	m_listBoxC.AddString(str);

	InitCString(m_outputStaticV);

	m_inputStaticV = strTemp;

	UpdateData(FALSE);
}
