#pragma once
#include "Scene.h"
class Panel;
class Dev1Scene : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;


private:
	void LoadResource();

protected:
};

