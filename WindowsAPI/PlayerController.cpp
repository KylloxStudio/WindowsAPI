#include "pch.h"
#include "PaddleActor.h"
#include "BallActor.h"
#include "PlayerController.h"

void PlayerController::Init(PaddleActor* paddle, BallActor* ball)
{
	_paddle = paddle;
	_ball = ball;

	_paddleMoveSpeed = 500.0f;
}

void PlayerController::Update()
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
