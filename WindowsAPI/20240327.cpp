#include "framework.h"
#include "WindowsAPI.h"
#include <string>

using namespace std;

// �ڷ��� ��Ī: typedef A B
// - �ڷ��� A�� B�� ��� ����
typedef int dlsxm;

// �ν��Ͻ� �ڷᱸ��: HINSTANCE
HINSTANCE;

// ATOM: unsigned short
ATOM;

// BOOL: int
BOOL;

// LRESULT: __int64
LRESULT;

// HWND: ������ �ڵ�
HWND;

// UINT: unsigned int
UINT;

// WPARAM: unsigned __int64
WPARAM;

// LPARAM: __int64
LPARAM;

// LPWSTR: wchar_t*
LPWSTR;

// �����ڵ�
wchar_t;

// ��Ƽ����Ʈ (�ƽ�Ű �ڵ�)
char;

// C: �Լ� �ϳ� �� return�� 1���� ���� �� ����
// �Լ��� �Ű������� ������ ���� �� ����
// return���� �Լ��� ���������� ���� ���
_In_;       // ���ϰ� ��� X
_Out_;      // ���ϰ� ��� O
_In_opt_;   // Optional, In
_Out_opt_;  // Optional, Out

void Test()
{
    dlsxm a = 1;

    char c = 'a';

    string str = "hello world";
    wchar_t wChar[128] = L"asdf";

    // ��Ƽ����Ʈ, �����ڵ� ��� ����
    TCHAR tChar[128];

    // _T: �Ӽ��� ��Ƽ����Ʈ�� ��Ƽ����Ʈ ����, �����ڵ�� �����ڵ� ����
    wstring wstr = _T("qwer");
}
