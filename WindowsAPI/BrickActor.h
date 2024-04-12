#pragma once
#include "Actor.h"

class BrickActor : public Actor
{
public:
	using base = Actor;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	vector<CenterRect> _bricks = vector<CenterRect>(50);
	float _width;
	float _height;
};
