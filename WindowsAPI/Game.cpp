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

	// 더블버퍼링
	::GetClientRect(_hwnd, &_rect);											//윈도우핸들의 크기를 반환
	_hdcBack = ::CreateCompatibleDC(_hdc);									//_hdc와 호환되는 화면 생성
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom);	//_hdc와 호환되는 비트맵 생성
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack);				//_hdcBack에 _bmp 연결
	::DeleteObject(prev);

	Time->Init();
	Input->Init(_hwnd);
	GET_SINGLE(SceneManager)->Init();
	GET_SINGLE(CollisionManager)->Init();

	GET_SINGLE(SceneManager)->LoadScene(SceneType::BrickGameScene);
}

void Game::Update()
{
	Time->Update();
	Input->Update();
	GET_SINGLE(SceneManager)->Update();
	GET_SINGLE(CollisionManager)->Update();
}

void Game::Render()
{
	// FPS 출력
	uint32 fps = Time->GetFps();
	float deltaTime = Time->GetDeltaTime();
	wstring timeStr = format(_T("FPS: {0}, DeltaTime: {1} ms"), fps, static_cast<int32>(deltaTime * 1000));
	::TextOut(_hdcBack, 5, 5, timeStr.c_str(), timeStr.length());

	// 마우스좌표 출력
	POINT mousePos = Input->GetMousePos();
	wstring str = format(_T("MousePos: {0}, {1}"), mousePos.x, mousePos.y);
	::TextOut(_hdcBack, 5, 25, str.c_str(), str.length());

	GET_SINGLE(SceneManager)->Render(_hdcBack);

	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
}