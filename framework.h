#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 일부 CString 생성자는 명시적으로 선언됩니다.

// MFC의 공통 부분과 무시 가능한 경고 메시지에 대한 숨기기를 해제합니다.
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 핵심 및 표준 구성 요소입니다.
#include <afxext.h>         // MFC 확장입니다.


#include <afxdisp.h>        // MFC 자동화 클래스입니다.


/////////////////////////////////////////////////////
#define MONITOR_WIDTH GetSystemMetrics(SM_CXSCREEN)
#define MONITOR_HEIGHT GetSystemMetrics(SM_CYSCREEN)

#define WD_WIDTH 1280
#define WD_HEIGHT 800
#define SC_WIDTH 640
#define SC_HEIGHT 480

#define COLOR_BPP 8
#define COLOR_KIND 256
#define COLOR_BLACK RGB(0, 0, 0)
#define COLOR_RED RGB(0xff, 0, 0)
#define COLOR_GREEN RGB(0, 0xff, 0)
#define COLOR_BLUE RGB(0, 0, 0xff)

#define PEN_BASIC 5
#define PEN_CHECK 10

//그림 로고 관련
#define DRAW_LOGO_PAGE_WIDTH 320
#define DRAW_LOGO_PAGE_HEIGHT 160
#define FIRST_RED_WIDTH 78
#define FIRST_RED_HEIGHT 10
#define SECEND_RED_WIDTH 10
#define SECEND_RED_HEIGHT 50
#define THIRD_RED_WIDTH 40
#define THIRD_RED_HEIGHT 50
/////////////////////////////////////////////////////



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Internet Explorer 4 공용 컨트롤에 대한 MFC 지원입니다.
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // Windows 공용 컨트롤에 대한 MFC 지원입니다.
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // MFC의 리본 및 컨트롤 막대 지원









#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


