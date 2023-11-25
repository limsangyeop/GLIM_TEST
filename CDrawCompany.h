#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include "afxdialogex.h"


// CDrawCompany 대화 상자

class CDrawCompany : public CDialogEx
{
	DECLARE_DYNAMIC(CDrawCompany)

public:
	CDrawCompany(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDrawCompany();

private:
	CImage m_DrawCompany;
	CImage m_DrawRedOne;
	CImage m_DrawRedTwo;
	CImage m_DrawRedThr;
	int m_Switch = 0;
	std::thread m_UpThread;
	std::thread m_DownThread;

private:
	void DrawMainScreen();

	void DrawCompanyLogo();
	void Up_StartScreen();
	void Down_StartScreen();

	void SetDrawRedOne();
	void DrawRedOne();
	void SetDrawRedTwo();
	void DrawRedTwo();
	void SetDrawRedThr();
	void DrawRedThr();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CDrawCompany };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	
	void DrawCompany();
};
