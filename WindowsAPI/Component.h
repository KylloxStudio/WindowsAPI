#pragma once

class Actor;
class Component
{
protected:
	Actor* _owner = nullptr;

public:
	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

	Actor* GetOwner() { return _owner; }
	void SetOwner(Actor* owner) { _owner = owner; }
};
