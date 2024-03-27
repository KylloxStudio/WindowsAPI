#include "framework.h"
#include "WindowsAPI.h"
#include <string>

using namespace std;

// 자료형 별칭: typedef A B
// - 자료형 A를 B로 사용 가능
typedef int dlsxm;

// 인스턴스 자료구조: HINSTANCE
HINSTANCE;

// ATOM: unsigned short
ATOM;

// BOOL: int
BOOL;

// LRESULT: __int64
LRESULT;

// HWND: 윈도우 핸들
HWND;

// UINT: unsigned int
UINT;

// WPARAM: unsigned __int64
WPARAM;

// LPARAM: __int64
LPARAM;

// LPWSTR: wchar_t*
LPWSTR;

// 유니코드
wchar_t;

// 멀티바이트 (아스키 코드)
char;

// C: 함수 하나 당 return값 1개만 받을 수 있음
// 함수의 매개변수로 리턴을 받을 수 있음
// return값을 함수의 성공유무로 많이 사용
_In_;       // 리턴값 사용 X
_Out_;      // 리턴값 사용 O
_In_opt_;   // Optional, In
_Out_opt_;  // Optional, Out

void Test()
{
    dlsxm a = 1;

    char c = 'a';

    string str = "hello world";
    wchar_t wChar[128] = L"asdf";

    // 멀티바이트, 유니코드 모두 지원
    TCHAR tChar[128];

    // _T: 속성이 멀티바이트면 멀티바이트 적용, 유니코드면 유니코드 적용
    wstring wstr = _T("qwer");
}
