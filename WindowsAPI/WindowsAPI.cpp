﻿// WindowsAPI.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "pch.h"
#include "WindowsAPI.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE _hInstance;   // 현재 인스턴스
HWND _hWnd;             // 윈도우 객체
POINT _mousePos;        // 마우스 좌표

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    // TODO: 여기에 코드를 입력합니다.

    // 1. 클래스 등록
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    MSG msg;
    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSAPI));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr;
    wcex.lpszClassName  = _T("Game Client");
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   _hInstance = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(_T("Game Client"), _T("Game Client"), WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   _hWnd = hWnd;

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(_hWnd, nCmdShow);
   UpdateWindow(_hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
int gugudan = 1;
bool isChasing = false;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_MOUSEMOVE:
        _mousePos.x = GET_X_LPARAM(lParam);
        _mousePos.y = GET_Y_LPARAM(lParam);

        ::InvalidateRect(_hWnd, NULL, true);
        break;
    case WM_KEYDOWN:
        if (wParam == 'A')
        {
            isChasing = !isChasing;
            printf("A 누름: %d\n", isChasing);
        }

        if (wParam == VK_RIGHT)
        {
            if (gugudan < 9)
            {
                gugudan++;
                //LOG
            }
            printf("현재 단: %d\n", gugudan);
        }
        else if (wParam == VK_LEFT)
        {
            if (1 < gugudan)
            {
                gugudan--;
            }
            printf("현재 단: %d\n", gugudan);
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            // ::Rectangle(hdc, 350, 350, 450, 450);
            // ::Ellipse(hdc, 350, 350, 450, 450);

            wchar_t mouseStr[128];
            wsprintf(mouseStr, L"%d, %d", _mousePos.x, _mousePos.y);
            ::TextOut(hdc, _mousePos.x, _mousePos.y, mouseStr, _tcsclen(mouseStr));

            if (isChasing)
            {
                for (int i = 1; i <= 9; i++)
                {
                    wchar_t str[128];
                    wsprintf(str, _T("%d * %d = %d"), gugudan, i, gugudan * i);
                    ::TextOut(hdc, _mousePos.x, _mousePos.y + (i * 20), str, _tcsclen(str));
                }
            }
            else
            {
                int x = 0;
                int y = 0;
                for (int i = 1; i <= 9; i++)
                {
                    for (int j = 1; j <= 9; j++)
                    {
                        if (i > 3)
                        {
                            x = -300;
                            y = 200;
                        }
                        
                        if (i > 6)
                        {
                            x = -600;
                            y = 400;
                        }

                        wchar_t str[128];
                        wsprintf(str, _T("%d * %d = %d"), i, j, i * j);
                        ::TextOut(hdc, x + (i * 100), y + (j * 20), str, _tcsclen(str));
                    }
                }
            }
            
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
