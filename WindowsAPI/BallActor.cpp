#include "pch.h"
#include "BallActor.h"
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
	RECT temp = {};
	RECT ballRect = static_cast<BoxCollider*>(collider)->GetCollision().ToRect();
	ballRect.left -= 1;
	ballRect.top -= 1;
	ballRect.right += 1;
	ballRect.bottom += 1;
	RECT paddleRect = static_cast<BoxCollider*>(other)->GetCollision().ToRect();
	if (::IntersectRect(&temp, &ballRect, &paddleRect))
	{
		int collisionWidth = temp.right - temp.left;
		int collisionHeight = temp.bottom - temp.top;
		if (collisionHeight < collisionWidth)
		{
			if (temp.top == ballRect.top)
			{
				_moveDirc.y = -_moveDirc.y;
				_body.pos.y += temp.bottom - temp.top;
			}

			if (temp.bottom == ballRect.bottom)
			{
				_moveDirc.y = -_moveDirc.y;
				_body.pos.y += temp.top - temp.bottom;
			}
		}
		else
		{
			if (temp.left == ballRect.left)
			{
				_moveDirc.x = -_moveDirc.y;
				_body.pos.x += temp.right - temp.left;
			}

			if (temp.right == ballRect.right)
			{
				_moveDirc.x = -_moveDirc.y;
				_body.pos.x += temp.left - temp.right;
			}
		}
	}
}
