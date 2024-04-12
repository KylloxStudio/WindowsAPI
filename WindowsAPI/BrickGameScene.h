#pragma once
#include "Scene.h"

class PaddleActor;
class BallActor;
class BrickActor;
class PlayerController;

class BrickGameScene : public Scene
{
	using base = Scene;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	PaddleActor* _paddle = nullptr;
	BallActor* _ball = nullptr;
	PlayerController* _playerController = nullptr;

	int _score;
	bool _isGameStarted;
};
