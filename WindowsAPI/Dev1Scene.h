#pragma once
#include "Scene.h"

class Dev1Scene : public Scene
{
	using base = Scene;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	CenterRect _player1;
	CenterRect _player2;
	CenterRect _player1Wall;
	CenterRect _player2Wall;
	CenterRect _ball;

	CenterRect _topWall;
	CenterRect _bottomWall;

	Vector2 _player1Dirc;
	Vector2 _player2Dirc;
	Vector2 _ballDirc;

	float _ballSpeed;

	int _player1Score;
	int _player2Score;

	bool _isGameStarted;
};
