#include "pch.h"
#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::Init(HWND hwnd)
{
	this->_hwnd = hwnd;
	this->_hdc = ::GetDC(this->_hwnd);

	::GetClientRect(_hwnd, &_rect);
	_hdcBack = ::CreateCompatibleDC(_hdc);
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom);
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack);
	::DeleteObject(prev);

	GET_SINGLE(TimeManager)->Init();
}

void Game::Update()
{
	GET_SINGLE(TimeManager)->Update();

	_x++;
}

void Game::Render()
{
	uint32 fps = GET_SINGLE(TimeManager)->GetFps();
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	wstring timeStr = format(_T("FPS: ({0}), DeltaTime: ({1}) ms"), fps, static_cast<int32>(deltaTime * 1000));
	::TextOut(_hdcBack, 0, 0, timeStr.c_str(), timeStr.length());

	wstring str = _T("동해물과 백두산이 마르고 닳도록 하느님이 보우하사 우리나라 만세");
	::TextOut(_hdcBack, _x % 700, 50, str.c_str(), str.length());

	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
}
