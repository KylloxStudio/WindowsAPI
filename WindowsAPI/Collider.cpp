#include "pch.h"
#include "Collider.h"

void Collider::Init()
{
	base::Init();

	GET_SINGLE(CollisionManager)->AddCollider(this);
}

void Collider::Update()
{
	base::Update();
}

void Collider::Render(HDC hdc)
{
	base::Render(hdc);
}

void Collider::Release()
{
	base::Release();

	GET_SINGLE(CollisionManager)->RemoveCollider(this);
}

bool Collider::CheckCollision(Collider* other)
{
	return false;
}
