#pragma once
#include "Scene.h"

class Dev2Scene : public Scene
{
	using base = Scene;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
};
