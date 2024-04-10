#pragma once
#include "Component.h"

class Collider : public Component
{
protected:
	ColliderType _colliderType;

public:
	using base = Component;
	unordered_set<Collider*> _collisionMap;

	Collider(ColliderType colliderType) { _colliderType = colliderType; }
	virtual ~Collider() {}

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual bool CheckCollision(Collider* other);
	ColliderType GetColliderType() { return _colliderType; }
};
