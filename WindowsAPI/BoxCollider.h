#pragma once
#include "Collider.h"

class BoxCollider : public Collider
{
private:
	CenterRect _collision;

public:
	using base = Collider;

	BoxCollider();
	virtual ~BoxCollider();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	CenterRect GetCollision();
	void SetCollision(CenterRect collision) { _collision = collision; }

	virtual bool CheckCollision(Collider* other);
};
