#pragma once

class Component;
class Collider;
class Actor
{
protected:
	CenterRect _body = {};
	string _name;
	vector<Component*> _components;

public:
	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

	virtual void OnCollisionEnter(Collider* collider, Collider* other);
	virtual void OnCollisionStay(Collider* collider, Collider* other);
	virtual void OnCollisionExit(Collider* collider, Collider* other);

	void AddComponent(Component* component);
	void RemoveComponent(Component* component);

	CenterRect GetBody() { return _body; }
	void SetBody(CenterRect body) { _body = body; }

	string GetName() { return _name; }
	void SetName(string name) { _name = name; }
};
