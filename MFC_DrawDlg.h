
// MFC_DrawDlg.h: 헤더 파일
//

#pragma once

#include "CDlgImage.h"
#include "CDrawCompany.h"


// CMFCDrawDlg 대화 상자
class CMFCDrawDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCDrawDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

private:
	CDlgImage* m_MainScreen;
	CDrawCompany* m_ServeScreen;

	std::thread m_Thread;
	std::atomic<bool> m_ThreadRunning;

private:
	void CompanyDraw();


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_DRAW_DIALOG };
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
	afx_msg void OnBnClickedShowscreen();
	afx_msg void OnBnClickedDrawcircleBt();
	afx_msg void OnBnClickedWhereposBt();
	afx_msg void OnBnClickedDrawlineBt();
	afx_msg void OnBnClickedCheckBt();
	afx_msg void OnBnClickedDrawfullcircle();
	afx_msg void OnEnSetfocusInput();
	afx_msg void OnDestroy();
	afx_msg void OnEnKillfocusInput();
};
