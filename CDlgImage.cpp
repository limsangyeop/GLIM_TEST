// CDlgImage.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC_Draw.h"
#include "afxdialogex.h"
#include "CDlgImage.h"


// CDlgImage 대화 상자

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CDlgImage, pParent)
{
	m_pParent = pParent;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage 메시지 처리기


BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	DrawMainScreen();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgImage::DrawMainScreen()
{
	// SC_WIDTH = 640
	// SC_HEIGHT = 480
	// COLOR_BPP = 8
	// COLOR_KIND = 256
	m_MainScreen.Create(SC_WIDTH, -SC_HEIGHT, COLOR_BPP);
	if (COLOR_BPP == 8)
	{
		static RGBQUAD rgb[COLOR_KIND];
		for (int i = 0; i < COLOR_KIND; i++)
		{
			rgb[i].rgbRed = rgb[i].rgbBlue = rgb[i].rgbGreen = i;
		}
		m_MainScreen.SetColorTable(0, COLOR_KIND, rgb);
	}
	unsigned char* fm = (unsigned char*)m_MainScreen.GetBits();
	memset(fm, 0xff, SC_WIDTH * SC_HEIGHT);
}

void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	m_MainScreen.Draw(dc, 0, 0);
	DrawCircle(&dc);
}

void CDlgImage::DrawCircle(CDC* pDC)
{
	int nWidth = m_MainScreen.GetWidth();
	int nHeight = m_MainScreen.GetHeight();
	int nPitch = m_MainScreen.GetPitch();
	unsigned char* fm = (unsigned char*)m_MainScreen.GetBits();

	m_rect.SetRectEmpty();
	CPen nPen;
	nPen.CreatePen(PS_SOLID, PEN_BASIC, COLOR_RED);
	pDC->SelectObject(&nPen);
	if (m_Pos > (nHeight / 2) -1)
	{
		AfxMessageBox(_T("Too big size"));
		
		memset(fm, 0xff, nWidth * nHeight);
		return;
	}
	while (true)
	{
		if (m_Switch == 0) // 스위치가 0이면 랜덤돌림
		{
			m_ptData.x = rand() % nWidth;
			m_ptData.y = rand() % nHeight;
		}
		//생성된 원이 사각형 밖으로 나가는걸 막는다.
		if ((m_ptData.x + m_Pos) < nWidth && (m_ptData.x - m_Pos) > 0 && (m_ptData.y + m_Pos) < nHeight && (m_ptData.y - m_Pos) > 0)
		{
			m_rect.SetRect(m_ptData, m_ptData);
			m_rect.InflateRect(m_Pos, m_Pos);
			pDC->Ellipse(m_rect);

			if (m_Switch == 1)
			{
				DrawMidLine(pDC);
			}
			if (m_Switch == 2)
			{
				DrawCheckCircle(pDC);
			}
			if (m_Switch == 3)
			{
				DrawFullCircle(pDC);
			}
			return;
		}
	}
}

//기존 원의 가운데 라인을 그림
void CDlgImage::DrawMidLine(CDC* pDC)
{
	CPen nPen;
	nPen.CreatePen(PS_SOLID, PEN_BASIC, COLOR_BLACK);
	pDC->SelectObject(&nPen);

	int nCenterX = m_rect.left + (m_rect.Width() / 2);
	int nCenterY = m_rect.top + (m_rect.Height() / 2);

	// 수평 십자가
	pDC->MoveTo(m_rect.left, nCenterY);
	pDC->LineTo(m_rect.right, nCenterY);

	// 수직 십자가
	pDC->MoveTo(nCenterX, m_rect.top);
	pDC->LineTo(nCenterX, m_rect.bottom);
}

// 기존 원의 위치를 알려주는 외부 원을 그림
void CDlgImage::DrawCheckCircle(CDC* pDC)
{
	CPen nCheckedPen;
	nCheckedPen.CreatePen(PS_SOLID, PEN_CHECK, COLOR_GREEN);
	pDC->SelectObject(&nCheckedPen);
	int nAddRadius = 7;
	int nCenterX = m_rect.left + (m_rect.Width() / 2);
	int nCenterY = m_rect.top + (m_rect.Height() / 2);
	int nBoundingRadius = m_rect.Width() / 2 + nAddRadius; // 겉을 둘러싸는 원 크기 +7 고정값

	pDC->Ellipse(nCenterX - nBoundingRadius, nCenterY - nBoundingRadius,
		nCenterX + nBoundingRadius, nCenterY + nBoundingRadius);

	CPen nPen;
	nPen.CreatePen(PS_SOLID, PEN_BASIC, RGB(0xff, 0, 0));
	pDC->SelectObject(&nPen);
	m_rect.SetRect(m_ptData, m_ptData);
	m_rect.InflateRect(m_Pos, m_Pos);
	pDC->Ellipse(m_rect);
}

// 기존 원의 내부 전체를 그림
void CDlgImage::DrawFullCircle(CDC* pDC)
{
	CPen nPen;
	nPen.CreatePen(PS_SOLID, m_Pos + PEN_CHECK, COLOR_BLUE);
	pDC->SelectObject(&nPen);

	m_rect.SetRect(m_ptData, m_ptData);
	m_rect.InflateRect(m_Pos/2, m_Pos/2);
	pDC->Ellipse(m_rect);
}
