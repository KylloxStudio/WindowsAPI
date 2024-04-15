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

	float y = 125;
	for (int i = 0; i < 48; i++)
	{
		BrickActor* brick = new BrickActor();
		if (i % 12 == 0)
		{
			y += brick->GetHeight();
		}
		brick->SetPosition(Vector2(85 + (i % 12) * brick->GetWidth(), y));
		brick->Init();
		this->SpawnActor(brick);
		_bricks.push_back(brick);
	}

	_playerController = new PlayerController();
	_playerController->Init(_paddle, _ball);

	_score = 0;
	this->ChangeGameState(GameState::Wait);
}

void BrickGameScene::Update()
{
	base::Update();
	_playerController->Update();
}

void BrickGameScene::Render(HDC hdc)
{
	base::Render(hdc);

	wstring scoreStr = std::to_wstring(_score);
	::TextOut(hdc, WIN_SIZE_X / 2, 45, scoreStr.c_str(), scoreStr.length());

	wstring gameStateStr = format(L"GameState : {0}", (int)_gameState);
	::TextOut(hdc, 0, 60, gameStateStr.c_str(), gameStateStr.length());
}

void BrickGameScene::Release()
{
	base::Release();
}

void BrickGameScene::ChangeGameState(GameState state)
{
	if (_gameState == state)
	{
		return;
	}

	_gameState = state;

	switch (_gameState)
	{
	case GameState::None:
		break;

	case GameState::Wait:
	{
		_playerController->SetCanBallController(true);

		Vector2 paddlePos = _paddle->GetBody().pos;
		float paddleHeight = _paddle->GetBody().height;
		paddlePos.y -= _ball->GetBody().height / 2 + paddleHeight / 2;
		_ball->SetPosition(paddlePos);
		_ball->SetDirection(Vector2::Zero());
	}
	break;
	case GameState::Play:
		_playerController->SetCanBallController(false);
		break;
	}
}
