// CDrawCompany.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_Draw.h"
#include "afxdialogex.h"
#include "CDrawCompany.h"


// CDrawCompany 대화 상자

IMPLEMENT_DYNAMIC(CDrawCompany, CDialogEx)

CDrawCompany::CDrawCompany(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CDrawCompany, pParent)
{

}

CDrawCompany::~CDrawCompany()
{
}

void CDrawCompany::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDrawCompany, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDrawCompany 메시지 처리기


BOOL CDrawCompany::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	DrawMainScreen();
	SetDrawRedOne();
	SetDrawRedTwo();
	SetDrawRedThr();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDrawCompany::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	m_DrawCompany.Draw(dc, 0, 0);

	if (m_Switch == 1)
	{
		m_DrawRedOne.Draw(dc, 30, 42);
		m_DrawRedTwo.Draw(dc, 98, 42);
		m_DrawRedThr.Draw(dc, 228, 52);
	}
}

void CDrawCompany::DrawMainScreen()
{
	// DRAW_LOGO_PAGE_WIDTH = 320;
	// DRAW_LOGO_PAGE_HEIGHT = 160;
	// COLOR_BPP = 8
	// COLOR_KIND = 256
	m_DrawCompany.Create(DRAW_LOGO_PAGE_WIDTH, - DRAW_LOGO_PAGE_HEIGHT, COLOR_BPP);
	if (COLOR_BPP == 8)
	{
		static RGBQUAD rgb[COLOR_KIND];
		for (int i = 0; i < COLOR_KIND; i++)
		{
			rgb[i].rgbRed = rgb[i].rgbBlue = rgb[i].rgbGreen = i;
		}
		m_DrawCompany.SetColorTable(0, COLOR_KIND, rgb);
	}
	unsigned char* fm = (unsigned char*)m_DrawCompany.GetBits();
	memset(fm, 0xff, DRAW_LOGO_PAGE_WIDTH * DRAW_LOGO_PAGE_HEIGHT);
}


void CDrawCompany::DrawCompany()
{
	DrawCompanyLogo();

	m_Switch = 1;
	Invalidate();
	UpdateWindow();

	DrawRedOne();
	DrawRedTwo();
	DrawRedThr();
}

void CDrawCompany::DrawCompanyLogo()
{
	int nWidth = m_DrawCompany.GetWidth();
	int nHeight = m_DrawCompany.GetHeight();
	int nPitch = m_DrawCompany.GetPitch();
	unsigned char* fm = (unsigned char*)m_DrawCompany.GetBits();

	int nPosX = 60;
	int nPosY = 10;

	memset(fm, 0, nWidth * nHeight);

	//first Draw
	m_UpThread = std::thread(&CDrawCompany::Up_StartScreen, this);
	m_DownThread = std::thread(&CDrawCompany::Down_StartScreen, this);
	m_UpThread.join();
	m_DownThread.join();


	//그림 Draw
	//ㄱ
	for (int i = nPosX / 2; i < nPosX + 48; i++)
	{
		for (int j = nPosY + 32; j < nPosY + 32 + 10; j++)
		{
			fm[j * nPitch + i] = 0;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		Invalidate();
		UpdateWindow();
	}

	for (int j = nPosY + 32 + 10; j < nPosY + 72 + 10; j++)
	{
		for (int i = nPosX + 38; i < nPosX + 38 + 10; i++)
		{
			fm[j * nPitch + i] = 0;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		Invalidate();
		UpdateWindow();
	}

	//ㅡ
	for (int i = nPosX / 2; i < nPosX + 48; i++)
	{
		for (int j = nPosY + 92; j < nPosY + 92 + 10; j++)
		{
			fm[j * nPitch + i] = 0;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		Invalidate();
		UpdateWindow();
	}

	//ㄹ
	for (int j = nPosY + 102; j >= nPosY + 32; j--)
	{
		for (int i = nPosX + 58; i < nPosX + 58 + 10; i++)
		{
			fm[j * nPitch + i] = 0;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		Invalidate();
		UpdateWindow();
	}

	for (int i = nPosX + 68; i < nPosX + 88; i++)
	{
		for (int j = nPosY + 32; j < nPosY + 32 + 10; j++)
		{
			fm[j * nPitch + i] = 0;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		Invalidate();
		UpdateWindow();
	}

	for (int j = nPosY + 32; j < nPosY + 102; j++)
	{
		for (int i = nPosX + 88; i < nPosX + 88 + 10; i++)
		{
			fm[j * nPitch + i] = 0;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		Invalidate();
		UpdateWindow();
	}

	for (int i = nPosX + 98; i < nPosX + 118; i++)
	{
		for (int j = nPosY + 92; j < nPosY + 92 + 10; j++)
		{
			fm[j * nPitch + i] = 0;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		Invalidate();
		UpdateWindow();
	}

	for (int j = nPosY + 102 - 1; j >= nPosY + 32; j--)
	{
		for (int i = nPosX + 118; i < nPosX + 118 + 10; i++)
		{
			fm[j * nPitch + i] = 0;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		Invalidate();
		UpdateWindow();
	}

	//ㅣ
	for (int j = nPosY + 32; j < nPosY + 102; j++)
	{
		for (int i = nPosX + 138; i < nPosX + 138 + 10; i++)
		{
			fm[j * nPitch + i] = 0;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		Invalidate();
		UpdateWindow();
	}

	//ㅁ
	for (int j = nPosY + 32; j < nPosY + 102; j++)
	{
		for (int i = nPosX + 158; i < nPosX + 158 + 60; i++)
		{
			fm[j * nPitch + i] = 0;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		Invalidate();
		UpdateWindow();
	}
}


void CDrawCompany::Up_StartScreen()
{
	int nWidth = m_DrawCompany.GetWidth();
	int nHeight = m_DrawCompany.GetHeight();
	int nPitch = m_DrawCompany.GetPitch();
	unsigned char* fm = (unsigned char*)m_DrawCompany.GetBits();

	//up
	for (int j = nHeight /2; j >= 0; j--)
	{
		for (int i = 0; i < nWidth; i++)
		{
			fm[j * nPitch + i] = 255;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		Invalidate();
		UpdateWindow();
	}
}
void CDrawCompany::Down_StartScreen()
{
	int nWidth = m_DrawCompany.GetWidth();
	int nHeight = m_DrawCompany.GetHeight();
	int nPitch = m_DrawCompany.GetPitch();
	unsigned char* fm = (unsigned char*)m_DrawCompany.GetBits();

	//down
	for (int j = nHeight / 2; j < nHeight; j++)
	{
		for (int i = 0; i < nWidth; i++)
		{
			fm[j * nPitch + i] = 255;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		Invalidate();
		UpdateWindow();
	}
}


void CDrawCompany::SetDrawRedOne()
{
	// FIRST_RED_WIDTH = 78;
	// FIRST_RED_HEIGHT = 10;
	// COLOR_BPP = 8
	// COLOR_KIND = 256
	m_DrawRedOne.Create(FIRST_RED_WIDTH, -FIRST_RED_HEIGHT, COLOR_BPP);
	if (COLOR_BPP == 8)
	{
		static RGBQUAD rgb[COLOR_KIND];
		for (int i = 0; i < COLOR_KIND; i++)
		{
			rgb[i].rgbRed = i;
			rgb[i].rgbBlue = rgb[i].rgbGreen = 0;
		}
		m_DrawRedOne.SetColorTable(0, COLOR_KIND, rgb);
	}
	unsigned char* fm = (unsigned char*)m_DrawRedOne.GetBits();
	int nPitch = m_DrawRedOne.GetPitch();

	memset(fm, 0, FIRST_RED_WIDTH * FIRST_RED_HEIGHT);
}
void CDrawCompany::DrawRedOne()
{
	unsigned char* fm = (unsigned char*)m_DrawRedOne.GetBits();
	int nPitch = m_DrawRedOne.GetPitch();

	for (int i = 0; i < FIRST_RED_WIDTH; i++)
	{
		for (int j = 0; j < FIRST_RED_HEIGHT; j++)
		{
			fm[j * nPitch + i] = 255;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		Invalidate();
		UpdateWindow();
	}
}


void CDrawCompany::SetDrawRedTwo()
{
	// SECEND_RED_WIDTH = 10;
	// SECEND_RED_HEIGHT = 50;
	// COLOR_BPP = 8
	// COLOR_KIND = 256
	m_DrawRedTwo.Create(SECEND_RED_WIDTH, -SECEND_RED_HEIGHT, COLOR_BPP);
	if (COLOR_BPP == 8)
	{
		static RGBQUAD rgb[COLOR_KIND];
		for (int i = 0; i < COLOR_KIND; i++)
		{
			rgb[i].rgbRed = i;
			rgb[i].rgbBlue = rgb[i].rgbGreen = 0;
		}
		m_DrawRedTwo.SetColorTable(0, COLOR_KIND, rgb);
	}
	unsigned char* fm = (unsigned char*)m_DrawRedTwo.GetBits();
	int nPitch = m_DrawRedTwo.GetPitch();

	memset(fm, 0, SECEND_RED_WIDTH * SECEND_RED_HEIGHT);
}
void CDrawCompany::DrawRedTwo()
{
	unsigned char* fm = (unsigned char*)m_DrawRedTwo.GetBits();
	int nPitch = m_DrawRedTwo.GetPitch();

	for (int j = 0; j < SECEND_RED_HEIGHT; j++)
	{
		for (int i = 0; i < SECEND_RED_WIDTH; i++)
		{
			fm[j * nPitch + i] = 255;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		Invalidate();
		UpdateWindow();
	}
}


void CDrawCompany::SetDrawRedThr()
{
	// THIRD_RED_WIDTH = 40;
	// THIRD_RED_HEIGHT = 50;
	// COLOR_BPP = 8
	// COLOR_KIND = 256
	m_DrawRedThr.Create(THIRD_RED_WIDTH, -THIRD_RED_HEIGHT, COLOR_BPP);
	if (COLOR_BPP == 8)
	{
		static RGBQUAD rgb[COLOR_KIND];
		for (int i = 0; i < COLOR_KIND; i++)
		{
			rgb[i].rgbRed = i;
			rgb[i].rgbBlue = rgb[i].rgbGreen = 0;
		}
		m_DrawRedThr.SetColorTable(0, COLOR_KIND, rgb);
	}
	unsigned char* fm = (unsigned char*)m_DrawRedThr.GetBits();
	int nPitch = m_DrawRedThr.GetPitch();

	memset(fm, 0, THIRD_RED_WIDTH * THIRD_RED_HEIGHT);
}
void CDrawCompany::DrawRedThr()
{
	unsigned char* fm = (unsigned char*)m_DrawRedThr.GetBits();
	int nPitch = m_DrawRedThr.GetPitch();

	for (int j = 0; j < THIRD_RED_HEIGHT; j++)
	{
		for (int i = 0; i < THIRD_RED_WIDTH; i++)
		{
			fm[j * nPitch + i] = 255;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		Invalidate();
		UpdateWindow();
	}
}