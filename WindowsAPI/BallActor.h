#pragma once
#include "Actor.h"

class BallActor : public Actor
{
public:
	using base = Actor;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
	virtual void OnCollisionEnter(Collider* collider, Collider* other) override;

	void CalcMovement(Vector2 dirc, float speed);

	void SetPosition(Vector2 pos);
	Vector2 GetPosition() { return _body.pos; };

	void SetDirection(Vector2 dirc);
	Vector2 GetDirection() { return _moveDirc; };

	float GetBallSpeed() { return _speed; }

	void Bounce(RECT myRect, RECT otherRect);

private:
	Vector2 _moveDirc;
	float _speed;
};
