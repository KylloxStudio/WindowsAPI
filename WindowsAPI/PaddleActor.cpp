#include "pch.h"
#include "PaddleActor.h"
#include "BoxCollider.h"

void PaddleActor::Init()
{
	base::Init();

	this->SetName("Paddle");
	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 150, 20));
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y - 200, 150, 20));
}

void PaddleActor::Update()
{
	base::Update();
}

void PaddleActor::Render(HDC hdc)
{
	base::Render(hdc);
	_body.Render(hdc);
}

void PaddleActor::Release()
{
	base::Release();
}

void PaddleActor::CalcMovement(Vector2 dirc, float speed)
{
	_body.pos += dirc * (Time->GetDeltaTime() * speed);
}
