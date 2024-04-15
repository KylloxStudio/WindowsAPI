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

	float GetWidth() { return _width; }
	void SetWidth(float width) { _width = width; }

	float GetHeight() { return _height; }
	void SetHeight(float height) { _height = height; }

	Vector2 GetPosition() { return _position; }
	void SetPosition(Vector2 pos) { _position = pos; }

private:
	Vector2 _position = Vector2::Zero();
	float _width = 100;
	float _height = 25;
};
