#include "pch.h"
#include "Dev1Scene.h"

void Dev1Scene::Init()
{
	base::Init();

	_player = { Vector2(250, 250), 50, 50 };
	_wall = Shape::MakeCenterRectLTRB(500, 200, 600, 300);
}

void Dev1Scene::Update()
{
	base::Update();

	if (Input->GetKey(KeyCode::Control) && Input->GetKeyDown(KeyCode::RightMouse))
	{
		GET_SINGLE(SceneManager)->LoadScene(SceneType::Dev2Scene);
	}

	if (Input->GetKeyDown(KeyCode::P))
	{
		GET_SINGLE(SceneManager)->LoadScene(SceneType::PongGameScene);
	}

	if (Input->GetKey(KeyCode::Left))
	{
		_playerDirc = Vector2(-1, 0);
		_player.pos += _playerDirc * (Time->GetDeltaTime() * 500);
	}

	if (Input->GetKey(KeyCode::Right))
	{
		_playerDirc = Vector2(1, 0);
		_player.pos += _playerDirc * (Time->GetDeltaTime() * 500);
	}

	if (Input->GetKey(KeyCode::Up))
	{
		_playerDirc = Vector2(0, -1);
		_player.pos += _playerDirc * (Time->GetDeltaTime() * 500);
	}

	if (Input->GetKey(KeyCode::Down))
	{
		_playerDirc = Vector2(0, 1);
		_player.pos += _playerDirc * (Time->GetDeltaTime() * 500);
	}

	if (Input->GetKeyDown(KeyCode::RightMouse))
	{
		POINT mousePos = Input->GetMousePos();
		_targetPos = Vector2(mousePos.x, mousePos.y);
		_playerDirc = (_targetPos - _player.pos).Normalize();
	}

	if ((_targetPos - _player.pos).Length() > 10)
	{
		_player.pos += _playerDirc * (Time->GetDeltaTime() * 500);
	}

	RECT collision = {};
	RECT playerCollision = _player.ToRect();
	RECT wallCollision = _wall.ToRect();
	if (::IntersectRect(&collision, &playerCollision, &wallCollision))
	{
		int collisionWidth = collision.right - collision.left;
		int collisionHeight = collision.bottom - collision.top;
		if (collisionHeight < collisionWidth)
		{
			if (collision.top == playerCollision.top)
			{
				cout << "아래 -> 위" << endl;
				_player.pos.y += collisionHeight;
				_wall.pos.y -= collisionHeight;
			}

			if (collision.bottom == playerCollision.bottom)
			{
				cout << "위 -> 아래" << endl;
				_player.pos.y -= collisionHeight;
				_wall.pos.y += collisionHeight;
			}
		}
		else
		{
			if (collision.left == playerCollision.left)
			{
				cout << "오른쪽 -> 왼쪽" << endl;
				_player.pos.x += collisionWidth;
				_wall.pos.x -= collisionWidth;
			}

			if (collision.right == playerCollision.right)
			{
				cout << "왼쪽 -> 오른쪽" << endl;
				_player.pos.x -= collisionWidth;
				_wall.pos.x += collisionWidth;
			}
		}
	}
}

void Dev1Scene::Render(HDC hdc)
{
	base::Render(hdc);

	wstring str = _T("Dev1Scene");
	::TextOut(hdc, 0, 45, str.c_str(), str.length());

	_wall.Render(hdc);
	_player.Render(hdc);
}

void Dev1Scene::Release()
{
	base::Release();
}
