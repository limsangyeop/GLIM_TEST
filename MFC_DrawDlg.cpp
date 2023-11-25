
// MFC_DrawDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC_Draw.h"
#include "MFC_DrawDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

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


// CMFCDrawDlg 대화 상자



CMFCDrawDlg::CMFCDrawDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_DRAW_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCDrawDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCDrawDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ShowScreen, &CMFCDrawDlg::OnBnClickedShowscreen)
	ON_BN_CLICKED(IDC_DRAWCIRCLE_BT, &CMFCDrawDlg::OnBnClickedDrawcircleBt)
	ON_BN_CLICKED(IDC_WHEREPOS_BT, &CMFCDrawDlg::OnBnClickedWhereposBt)
	ON_BN_CLICKED(IDC_DRAWLINE_BT, &CMFCDrawDlg::OnBnClickedDrawlineBt)
	ON_BN_CLICKED(IDC_CHECK_BT, &CMFCDrawDlg::OnBnClickedCheckBt)
	ON_BN_CLICKED(IDC_DRAWFULLCIRCLE, &CMFCDrawDlg::OnBnClickedDrawfullcircle)
//	ON_EN_KILLFOCUS(IDC_INPUT, &CMFCDrawDlg::OnEnKillfocusInput)
	ON_EN_SETFOCUS(IDC_INPUT, &CMFCDrawDlg::OnEnSetfocusInput)
	ON_WM_DESTROY()
	ON_EN_KILLFOCUS(IDC_INPUT, &CMFCDrawDlg::OnEnKillfocusInput)
END_MESSAGE_MAP()


// CMFCDrawDlg 메시지 처리기

BOOL CMFCDrawDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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
	// MONITOR_WIDTH 모니터 가로크기
	// MONITOR_HEIGHT 모니터 세로크기
	// WD_WIDTH = 1280
	// WD_HEIGHT = 800
	int nPosX = (MONITOR_WIDTH - WD_WIDTH) / 2;
	int nPosY = (MONITOR_HEIGHT - WD_HEIGHT) / 2;

	MoveWindow(nPosX, nPosY, WD_WIDTH, WD_HEIGHT);

	m_MainScreen = new CDlgImage;
	m_MainScreen->Create(IDD_CDlgImage, this);

	//회사 그림
	m_ServeScreen = new CDrawCompany;
	m_ServeScreen->Create(IDD_CDlgImage, this);
	m_ServeScreen->MoveWindow(WD_WIDTH - (SC_WIDTH / 2), 0, nPosX, nPosX / 2);
	m_ServeScreen->ShowWindow(SW_SHOW);
	
	//Edit control text set
	CString str = _T("1~239까지");
	SetDlgItemText(IDC_INPUT, str);

	m_ThreadRunning = true;

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCDrawDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCDrawDlg::OnPaint()
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
HCURSOR CMFCDrawDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// 첫 메인화면을 보여주는 버튼
void CMFCDrawDlg::OnBnClickedShowscreen()
{
	//SC_WIDTH = 640
	//SC_HEIGHT = 480
	int nPosX = (WD_WIDTH - SC_WIDTH) / 2;
	int nPosY = (WD_HEIGHT - SC_HEIGHT) / 2;

	if (m_ThreadRunning)
	{
		m_Thread = std::thread(&CMFCDrawDlg::CompanyDraw, this);
	}
	
	if (m_MainScreen->IsWindowVisible())
	{
		m_MainScreen->ShowWindow(SW_HIDE);
	}
	else
	{
		m_MainScreen->m_Pos = 0;
		m_MainScreen->ShowWindow(SW_SHOW);
		m_MainScreen->MoveWindow(nPosX, nPosY, SC_WIDTH, SC_HEIGHT);
	}
}


// 원을 그리는 버튼
void CMFCDrawDlg::OnBnClickedDrawcircleBt()
{
	CEdit* nInput = (CEdit*)GetDlgItem(IDC_INPUT);
	CString nText;
	nInput->GetWindowText(nText);
	int nRadius = 0;
	m_MainScreen->m_Pos = nRadius;
	m_MainScreen->m_Switch = nRadius;
	
	if (!nText.IsEmpty())
	{
		int nLength = nText.GetLength();
		if (nLength > 0)
		{
			bool nIndata = true;
			for (int i = 0; i < nLength; i++)
			{
				if (!_istdigit(nText[i]))
				{
					nIndata = false;
					break;
				}
			}

			if (nIndata)
			{
				nRadius = _ttoi(nText);

				if (nRadius == 0) // 입력값이 0일시
				{
					AfxMessageBox(_T("don't Zero please!"));
					return;
				}
				m_MainScreen->m_Pos = nRadius;
				m_MainScreen->Invalidate();
			}
			else {
				AfxMessageBox(_T("please don't str!")); // 글자 입력했을시
			}
		}
	}
	else {
		AfxMessageBox(_T("please input a radius!")); // 입력을 안했을시
	}
}

// 좌표를 나타내는 버튼
void CMFCDrawDlg::OnBnClickedWhereposBt()
{
	CString nPosX;
	CString nPosY;
	nPosX.Format(_T("%d"), m_MainScreen->m_ptData.x);
	nPosY.Format(_T("%d"), m_MainScreen->m_ptData.y);
	CString nPosText = _T("X좌표 ") + nPosX + _T("\n") + _T("Y좌표 ") + nPosY;
	AfxMessageBox(nPosText);

	std::cout << "X좌표는: " << m_MainScreen->m_ptData.x << " Y좌표는: " << m_MainScreen->m_ptData.y << std::endl;
}

// 가운데 라인을 그리는 버튼
void CMFCDrawDlg::OnBnClickedDrawlineBt()
{
	m_MainScreen->m_Switch = 1;
	m_MainScreen->Invalidate();
}

// 원 위치를 나타내는 버튼
void CMFCDrawDlg::OnBnClickedCheckBt()
{
	m_MainScreen->m_Switch = 2;
	m_MainScreen->Invalidate();
}

// 원을 전부 칠하는 버튼
void CMFCDrawDlg::OnBnClickedDrawfullcircle()
{
	m_MainScreen->m_Switch = 3;
	m_MainScreen->Invalidate();
}

// TEXT 비우는 Signal
void CMFCDrawDlg::OnEnSetfocusInput()
{
	SetDlgItemText(IDC_INPUT, NULL);
}

// TEXT Set Signal
void CMFCDrawDlg::OnEnKillfocusInput()
{
	CEdit* nInput = (CEdit*)GetDlgItem(IDC_INPUT);
	CString nText;
	nInput->GetWindowText(nText);

	if (nText == _T(""))
	{
		nText = _T("1~239까지");
		nInput->SetWindowText(nText);
	}
}

// 그림을 그림
void CMFCDrawDlg::CompanyDraw()
{
	m_ThreadRunning = false;
	m_ServeScreen->DrawCompany();
}


void CMFCDrawDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if (m_Thread.joinable())
	{
		m_Thread.join();
	}

	if (m_MainScreen)
	{
		delete m_MainScreen;
		m_MainScreen = nullptr;
	}
	if (m_ServeScreen)
	{
		delete m_ServeScreen;
		m_ServeScreen = nullptr;
	}
}



