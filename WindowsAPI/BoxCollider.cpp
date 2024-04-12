#include "pch.h"
#include "BoxCollider.h"
#include "Actor.h"

BoxCollider::BoxCollider() : Collider(ColliderType::Box)
{
	_collision = {};
}

BoxCollider::~BoxCollider()
{
}

void BoxCollider::Init()
{
	base::Init();
}

void BoxCollider::Update()
{
	base::Update();
}

void BoxCollider::Render(HDC hdc)
{
	base::Render(hdc);
}

void BoxCollider::Release()
{
	base::Release();
}

CenterRect BoxCollider::GetCollision()
{
	CenterRect rect;
	rect.pos.x = this->_collision.pos.x + this->_owner->GetBody().pos.x;
	rect.pos.y = this->_collision.pos.y + this->_owner->GetBody().pos.y;
	rect.width = this->_collision.width;
	rect.height = this->_collision.height;

	return rect;
}

bool BoxCollider::CheckCollision(Collider* other)
{
	switch (other->GetColliderType())
	{
	case ColliderType::Box:
	{
		BoxCollider* otherCollider = static_cast<BoxCollider*>(other);
		CenterRect otherCollision = otherCollider->GetCollision();
		return Collision::RectInRect(this->GetCollision().ToRect(), otherCollider->GetCollision().ToRect());
		break;
	}
	case ColliderType::Circle:
		return false;
		break;
	default:
		return false;
		break;
	}

	return false;
}
