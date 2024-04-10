#pragma once
#include "Scene.h"

class BrickGameScene : public Scene
{
	using base = Scene;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	CenterRect _player;
	CenterRect _ball;
	CenterRect _bricks[20];

	CenterRect _topWall;
	CenterRect _bottomWall;
	CenterRect _leftWall;
	CenterRect _rightWall;

	Vector2 _playerDirc;
	Vector2 _ballDirc;

	float brickWidth;
	float brickHeight;

	float _ballSpeed;

	int _score;
	bool _isGameStarted;
};
