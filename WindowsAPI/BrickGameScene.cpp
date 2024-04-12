#include "pch.h"
#include "BrickGameScene.h"
#include "BoxCollider.h"
#include "PaddleActor.h"
#include "BallActor.h"
#include "BrickActor.h"
#include "PlayerController.h"

void BrickGameScene::Init()
{
	base::Init();

	_paddle = new PaddleActor();
	_paddle->Init();
	this->SpawnActor(_paddle);

	_ball = new BallActor();
	_ball->Init();
	this->SpawnActor(_ball);

	_playerController = new PlayerController();
	_playerController->Init(_paddle, _ball);

	_score = 0;
}

void BrickGameScene::Update()
{
	base::Update();

	if (!_isGameStarted && Input->GetKeyDown(KeyCode::LeftMouse))
	{
		POINT mousePos = Input->GetMousePos();
		Vector2 _targetPos = Vector2(mousePos.x, mousePos.y);
		_ball->SetDirection((_targetPos - _ball->GetBody().pos).Normalize());
		_isGameStarted = true;
	}

	if (!_isGameStarted)
	{
		return;
	}

	_playerController->Update();
}

void BrickGameScene::Render(HDC hdc)
{
	base::Render(hdc);

	wstring scoreStr = std::to_wstring(_score);
	::TextOut(hdc, WIN_SIZE_X / 2, 45, scoreStr.c_str(), scoreStr.length());

	wstring gameStateStr = std::to_wstring(_score);
	::TextOut(hdc, 5, 45, gameStateStr.c_str(), gameStateStr.length());
}

void BrickGameScene::Release()
{
	base::Release();
}
