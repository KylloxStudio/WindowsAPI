#pragma once

class PaddleActor;
class BallActor;
class PlayerController
{
public:
	void Init(PaddleActor* paddle, BallActor* ball);
	void Update();

private:
	PaddleActor* _paddle;
	BallActor* _ball;

	float _paddleMoveSpeed;
	float _ballMoveSpeed;
};
