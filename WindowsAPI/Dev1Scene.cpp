#include "pch.h"
#include "Dev1Scene.h"

void Dev1Scene::Init()
{
	base::Init();

	_player1 = { Vector2(75, 250), 20, 150 };
	_player2 = { Vector2(1000, 250), 20, 150 };
	_player1Wall = { Vector2(0, 0), 1, 10000 };
	_player2Wall = { Vector2(1065, 0), 1, 10000 };
	_ball = { Vector2(125, 250), 20, 20 };
	_topWall = { Vector2(0, 0), 10000, 1 };
	_bottomWall = { Vector2(0, 585), 10000, 1 };
	_ballSpeed = 500.0f;
	_player1Score = 0;
	_player2Score = 0;
}

void Dev1Scene::Update()
{
	base::Update();

	if (Input->GetKey(KeyCode::Control) && Input->GetKeyDown(KeyCode::RightMouse))
	{
		GET_SINGLE(SceneManager)->LoadScene(SceneType::Dev2Scene);
	}

	if (!_isGameStarted && Input->GetKeyDown(KeyCode::LeftMouse))
	{
		POINT mousePos = Input->GetMousePos();
		Vector2 _targetPos = Vector2(mousePos.x, mousePos.y);
		_ballDirc = (_targetPos - _ball.pos).Normalize();
		_isGameStarted = true;
	}

	if (!_isGameStarted)
	{
		return;
	}

	if (Input->GetKey(KeyCode::W))
	{
		_player1Dirc = Vector2(0, -1);
		_player1.pos += _player1Dirc * (Time->GetDeltaTime() * 500);
	}
	else
	{
		_player1Dirc = Vector2(0, 0);
	}

	if (Input->GetKey(KeyCode::S))
	{
		_player1Dirc = Vector2(0, 1);
		_player1.pos += _player1Dirc * (Time->GetDeltaTime() * 500);
	}
	else
	{
		_player1Dirc = Vector2(0, 0);
	}

	if (Input->GetKey(KeyCode::Up))
	{
		_player2Dirc = Vector2(0, -1);
		_player2.pos += _player2Dirc * (Time->GetDeltaTime() * 500);
	}
	else
	{
		_player2Dirc = Vector2(0, 0);
	}

	if (Input->GetKey(KeyCode::Down))
	{
		_player2Dirc = Vector2(0, 1);
		_player2.pos += _player2Dirc * (Time->GetDeltaTime() * 500);
	}
	else
	{
		_player2Dirc = Vector2(0, 0);
	}

	RECT ballRect = _ball.ToRect();
	RECT player1Rect = _player1.ToRect();
	RECT player2Rect = _player2.ToRect();
	RECT topWallRect = _topWall.ToRect();
	RECT bottomWallRect = _bottomWall.ToRect();
	if (Collision::RectInRect(ballRect, player1Rect))
	{
		_ballDirc.x = _ballDirc.x * -1;
		_ballDirc.y = _player1Dirc.y >= 1 ? _ballDirc.y * -1 : _ballDirc.y;
		_ballSpeed *= 1.1f;
	}

	if (Collision::RectInRect(ballRect, player2Rect))
	{
		_ballDirc.x = _ballDirc.x * -1;
		_ballDirc.y = _player2Dirc.y >= 1 ? _ballDirc.y * -1 : _ballDirc.y;
		_ballSpeed *= 1.1f;
	}

	if (Collision::RectInRect(ballRect, topWallRect) || Collision::RectInRect(ballRect, bottomWallRect))
	{
		_ballDirc.y = _ballDirc.y * -1;
	}

	_ball.pos += _ballDirc * (Time->GetDeltaTime() * _ballSpeed);

	RECT player1Wall = _player1Wall.ToRect();
	RECT player2Wall = _player2Wall.ToRect();
	if (Collision::RectInRect(ballRect, player1Wall))
	{
		_player1.pos = Vector2(75, 250);
		_player2.pos = Vector2(1000, 250);
		_ball.pos = Vector2(125, 250);
		_player2Score++;
		_isGameStarted = false;
	}
	else if (Collision::RectInRect(ballRect, player2Wall))
	{
		_player1.pos = Vector2(75, 250);
		_player2.pos = Vector2(1000, 250);
		_ball.pos = Vector2(900, 250);
		_player1Score++;
		_isGameStarted = false;
	}
}

void Dev1Scene::Render(HDC hdc)
{
	base::Render(hdc);

	wstring str = std::to_wstring(_player1Score) + _T(" : ") + std::to_wstring(_player2Score);
	::TextOut(hdc, 500, 45, str.c_str(), str.length());

	_player1.Render(hdc);
	_player2.Render(hdc);
	_player1Wall.Render(hdc);
	_player2Wall.Render(hdc);
	_ball.Render(hdc);
	_topWall.Render(hdc);
	_bottomWall.Render(hdc);
}

void Dev1Scene::Release()
{
	base::Release();
}
