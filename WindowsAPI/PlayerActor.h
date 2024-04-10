#pragma once
#include "Actor.h"

class PlayerActor : public Actor
{
public:
	using base = Actor;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	CenterRect _player;
	CenterRect _ball;
	vector<CenterRect> _bricks = vector<CenterRect>(50);

	CenterRect _topWall;
	CenterRect _bottomWall;
	CenterRect _leftWall;
	CenterRect _rightWall;

	Vector2 _playerDirc;
	Vector2 _ballDirc;

	float _brickWidth;
	float _brickHeight;

	float _ballSpeed;
};
