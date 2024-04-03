#pragma once

class Game
{
public:
	Game();
	~Game();

	void Init(HWND hwnd);
	void Update();
	void Render();

private:
	HWND _hwnd;
	HDC _hdc;

	// �������۸� ����
	RECT _rect = {};
	HDC _hdcBack = {};
	HBITMAP _bmpBack = {};
};