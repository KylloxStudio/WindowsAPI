#pragma once

class Scene
{
public:
	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();
};
