#pragma once

class Component;
class Collider;
class Actor
{
protected:
	CenterRect _body = {};
	string _name;
	vector<Component*> _components;

	bool _isEnable = true;
	LayerType _layer = LayerType::Object;

public:
	Actor() {}
	virtual ~Actor() {}

	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

	virtual void OnCollisionEnter(Collider* collider, Collider* other);
	virtual void OnCollisionStay(Collider* collider, Collider* other);
	virtual void OnCollisionExit(Collider* collider, Collider* other);

	void AddComponent(Component* component);
	void RemoveComponent(Component* component);
	template<typename T>
	T* GetComponent()
	{
		for (Component* component : _components)
		{
			if (typeid(*component) == typeid(T))
			{
				T* result = dynamic_cast<T*>(component);
				if (result != nullptr)
				{
					return result;
				}
			}
		}

		return nullptr;
	}

	CenterRect GetBody() { return _body; }
	void SetBody(CenterRect body) { _body = body; }

	void SetPos(Vector2 pos) { _body.pos = pos; }
	Vector2 GetPos() { return _body.pos; }

	void SetWidth(float width) { _body.width = width; }
	float GetWidth() { return _body.width; }

	void SetHeight(float height) { _body.height = height; }
	float GetHeight() { return _body.height; }

	string GetName() { return _name; }
	void SetName(string name) { _name = name; }

	bool GetEnable() { return _isEnable; }
	void SetEnable(bool enable) { _isEnable = enable; }

	LayerType GetLayer() { return _layer; }
	void SetLayer(LayerType layer) { _layer = layer; }
	int GetLayerInt() { return static_cast<int>(_layer); }
};
