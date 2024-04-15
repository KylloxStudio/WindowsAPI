#include "pch.h"
#include "PlayerController.h"
#include "PaddleActor.h"
#include "BallActor.h"
#include "BrickGameScene.h"

void PlayerController::Init(PaddleActor* paddle, BallActor* ball)
{
	_paddle = paddle;
	_ball = ball;
}

void PlayerController::Update()
{
	if (_canBallControl)
	{
		if (::Input->GetKey(KeyCode::LeftMouse))
		{
			POINT mousePos = Input->GetMousePos();
			Vector2 _targetPos = Vector2(mousePos.x, mousePos.y);
			_ball->SetDirection((_targetPos - _ball->GetBody().pos).Normalize());

			BrickGameScene* currentScene = dynamic_cast<BrickGameScene*>(GET_SINGLE(SceneManager)->GetCurrentScene());
			if (currentScene != nullptr)
			{
				currentScene->ChangeGameState(GameState::Play);
			}

		}
	}
	else
	{
		if (Input->GetKey(KeyCode::Right) && _paddle->GetBody().pos.x < WIN_SIZE_X - _paddle->GetBody().width / 2)
		{
			_paddle->CalcMovement(Vector2::Right(), _paddleMoveSpeed);
		}
		else
		{
			_paddle->CalcMovement(Vector2::Zero(), _paddleMoveSpeed);
		}

		if (Input->GetKey(KeyCode::Left) && _paddle->GetBody().pos.x > _paddle->GetBody().width / 2)
		{
			_paddle->CalcMovement(Vector2::Left(), _paddleMoveSpeed);
		}
		else
		{
			_paddle->CalcMovement(Vector2::Zero(), _paddleMoveSpeed);
		}
	}
}
