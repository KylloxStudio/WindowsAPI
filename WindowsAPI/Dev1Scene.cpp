#include "pch.h"
#include "Dev1Scene.h"

void Dev1Scene::Init()
{
	base::Init();

	_player = { Vector2(250, 250), 20, 150 };
}

void Dev1Scene::Update()
{
	base::Update();

	if (Input->GetKey(KeyCode::Control) && Input->GetKeyDown(KeyCode::RightMouse))
	{
		GET_SINGLE(SceneManager)->LoadScene(SceneType::Dev2Scene);
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
}

void Dev1Scene::Render(HDC hdc)
{
	base::Render(hdc);

	wstring str = _T("Dev1Scene");
	::TextOut(hdc, 0, 45, str.c_str(), str.length());

	_player.Render(hdc);
}

void Dev1Scene::Release()
{
	base::Release();
}
