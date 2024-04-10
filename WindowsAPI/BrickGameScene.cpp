#include "pch.h"
#include "BrickGameScene.h"

void BrickGameScene::Init()
{
	base::Init();

	_player = { Vector2(500, 500), 150, 20 };
	_ball = { Vector2(500, 400), 20, 20 };

	brickWidth = 100;
	brickHeight = 25;

	_topWall = { Vector2(0, -50), 10000, 100 };
	_bottomWall = { Vector2(0, 640), 10000, 100 };
	_leftWall = { Vector2(-50, 0), 100, 10000 };
	_rightWall = { Vector2(1120, 0), 100, 10000 };

	_ballSpeed = 350.0f;
	_score = 0;
}

void BrickGameScene::Update()
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

	if (Input->GetKey(KeyCode::Right))
	{
		_playerDirc = Vector2(1, 0);
		_player.pos += _playerDirc * (Time->GetDeltaTime() * 500);
	}
	else
	{
		_playerDirc = Vector2(0, 0);
	}

	if (Input->GetKey(KeyCode::Left))
	{
		_playerDirc = Vector2(-1, 0);
		_player.pos += _playerDirc * (Time->GetDeltaTime() * 500);
	}
	else
	{
		_playerDirc = Vector2(0, 0);
	}

	RECT collision = {};

	RECT topWallCollision = _topWall.ToRect();
	RECT bottomWallCollision = _bottomWall.ToRect();
	RECT leftWallCollision = _leftWall.ToRect();
	RECT rightWallCollision = _rightWall.ToRect();

	RECT playerCollision = _player.ToRect();
	RECT ballCollision = _ball.ToRect();

	if (::IntersectRect(&collision, &playerCollision, &ballCollision))
	{
		int collisionWidth = collision.right - collision.left;
		int collisionHeight = collision.bottom - collision.top;
		if (collisionHeight < collisionWidth)
		{
			if (collision.top == playerCollision.top)
			{
				cout << "아래 -> 위" << endl;
				_ballDirc.y = -1;
			}

			if (collision.bottom == playerCollision.bottom)
			{
				cout << "위 -> 아래" << endl;
				_ballDirc.y = 1;
			}
		}
		else
		{
			if (collision.left == playerCollision.left)
			{
				cout << "오른쪽 -> 왼쪽" << endl;
				_ballDirc.x = 1;
			}

			if (collision.right == playerCollision.right)
			{
				cout << "왼쪽 -> 오른쪽" << endl;
				_ballDirc.x = -1;
			}
		}
	}

	if (Collision::RectInRect(ballCollision, topWallCollision))
	{
		_ballDirc.y = 1;
	}

	if (Collision::RectInRect(ballCollision, bottomWallCollision))
	{
		_ballDirc.y = -1;
	}

	if (Collision::RectInRect(ballCollision, leftWallCollision))
	{
		_ballDirc.x = 1;
	}

	if (Collision::RectInRect(ballCollision, rightWallCollision))
	{
		_ballDirc.x = -1;
	}

	_ball.pos += _ballDirc * (Time->GetDeltaTime() * _ballSpeed);
}

void BrickGameScene::Render(HDC hdc)
{
	base::Render(hdc);

	wstring str = std::to_wstring(_score);
	::TextOut(hdc, 500, 45, str.c_str(), str.length());

	_topWall.Render(hdc);
	_bottomWall.Render(hdc);
	_leftWall.Render(hdc);
	_rightWall.Render(hdc);

	_player.Render(hdc);
	_ball.Render(hdc);
}

void BrickGameScene::Release()
{
	base::Release();
}
