#pragma once
#include "Actor.h"

class WallActor : public Actor
{
public:
	using base = Actor;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	CenterRect _topWall;
	CenterRect _bottomWall;
	CenterRect _leftWall;
	CenterRect _rightWall;
};
