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
	CenterRect _player;
	Vector2 _playerDirc;
	Vector2 _targetPos = { -1, -1 };
	CenterRect _wall;
};