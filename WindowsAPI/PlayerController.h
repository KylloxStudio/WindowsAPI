#pragma once

class PaddleActor;
class BallActor;
class PlayerController
{
public:
	void Init(PaddleActor* paddle, BallActor* ball);
	void Update();

	void SetCanBallController(bool canBallControl) { _canBallControl = canBallControl; }

private:
	PaddleActor* _paddle;
	BallActor* _ball;

	bool _canBallControl = false;
	float _paddleMoveSpeed = 500.0f;
};
