#pragma once

#include "framework.h"

#include "Defines.h"
#include "Types.h"
#include "CommonFunction.h"

#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")

#include <Windows.h>
#include <windowsx.h>

#include <iostream>
#include <algorithm>

#include <string>
#include <tchar.h>

#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _mousePos;
