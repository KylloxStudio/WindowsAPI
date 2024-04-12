#pragma once
#include "Actor.h"

class PaddleActor : public Actor
{
public:
	using base = Actor;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void CalcMovement(Vector2 dirc, float speed);
};
