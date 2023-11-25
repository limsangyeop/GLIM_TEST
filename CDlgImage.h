#pragma once
#include <iostream>
#include "afxdialogex.h"


// CDlgImage 대화 상자

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgImage();

	CWnd* m_pParent;
	CImage m_MainScreen;
	CPoint m_ptData;
	int m_Pos =0;
	CRect m_rect;
	int m_Switch = 0;

private:
	void DrawMainScreen();
	void DrawCircle(CDC* pDC);
	void DrawMidLine(CDC* pDC);
	void DrawCheckCircle(CDC* pDC);
	void DrawFullCircle(CDC* pDC);


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CDlgImage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	
};
