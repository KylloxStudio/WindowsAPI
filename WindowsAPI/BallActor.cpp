#include "pch.h"
#include "Scene.h"
#include "BallActor.h"
#include "BrickActor.h"
#include "BoxCollider.h"

void BallActor::Init()
{
	base::Init();

	this->SetName("Ball");
	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 20, 20));
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y - 221, 20, 20));
	_speed = 750.0f;
}

void BallActor::Update()
{
	base::Update();

	Vector2 prevPos = _body.pos;
	CalcMovement(_moveDirc, _speed);
	if (_body.pos.x >= WIN_SIZE_X - 10)
	{
		_moveDirc.x = -_moveDirc.x;
		_body.pos = prevPos;
	}

	if (_body.pos.x <= 10)
	{
		_moveDirc.x = -_moveDirc.x;
		_body.pos = prevPos;
	}

	if (_body.pos.y >= WIN_SIZE_Y - 10)
	{
		_moveDirc.y = -_moveDirc.y;
		_body.pos = prevPos;
	}

	if (_body.pos.y <= 10)
	{
		_moveDirc.y = -_moveDirc.y;
		_body.pos = prevPos;
	}
}

void BallActor::Render(HDC hdc)
{
	base::Render(hdc);
	_body.Render(hdc);
}

void BallActor::Release()
{
	base::Release();
}

void BallActor::CalcMovement(Vector2 dirc, float speed)
{
	_body.pos += dirc * (Time->GetDeltaTime() * speed);
}

void BallActor::SetPosition(Vector2 pos)
{
	_body.pos = pos;
}

void BallActor::SetDirection(Vector2 dirc)
{
	_moveDirc = dirc;
}

void BallActor::OnCollisionEnter(Collider* collider, Collider* other)
{
	base::OnCollisionEnter(collider, other);

	RECT myRect = static_cast<BoxCollider*>(collider)->GetCollision().ToRect();
	RECT otherRect = static_cast<BoxCollider*>(other)->GetCollision().ToRect();

	string otherName = other->GetOwner()->GetName();
	if (otherName == "Paddle")
	{
		Bounce(myRect, otherRect);
	}

	if (otherName == "Brick")
	{
		BrickActor* brickActor = dynamic_cast<BrickActor*>(other->GetOwner());
		if (brickActor == nullptr)
		{
			return;
		}

		Bounce(myRect, otherRect);
		brickActor->SetEnable(false);
	}
}

void BallActor::Bounce(RECT myRect, RECT otherRect)
{
	RECT temp = {};
	myRect.left -= 1;
	myRect.top -= 1;
	myRect.right += 1;
	myRect.bottom += 1;
	if (::IntersectRect(&temp, &myRect, &otherRect))
	{
		int collisionWidth = temp.right - temp.left;
		int collisionHeight = temp.bottom - temp.top;
		if (collisionHeight < collisionWidth)
		{
			if (temp.top == myRect.top)
			{
				_moveDirc.y = -_moveDirc.y;
				_body.pos.y += temp.bottom - temp.top;
			}

			if (temp.bottom == myRect.bottom)
			{
				_moveDirc.y = -_moveDirc.y;
				_body.pos.y += temp.top - temp.bottom;
			}
		}
		else
		{
			if (temp.left == myRect.left)
			{
				_moveDirc.x = -_moveDirc.x;
				_body.pos.x += temp.right - temp.left;
			}

			if (temp.right == myRect.right)
			{
				_moveDirc.x = -_moveDirc.x;
				_body.pos.x += temp.left - temp.right;
			}
		}
	}
}
