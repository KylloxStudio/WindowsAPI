#include "pch.h"
#include "BrickActor.h"
#include "BoxCollider.h"

void BrickActor::Init()
{
	base::Init();

	this->SetName("Brick");
	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, _width, _height));
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(_position.x, _position.y, _width, _height));
}

void BrickActor::Update()
{
	base::Update();
}

void BrickActor::Render(HDC hdc)
{
	base::Render(hdc);
	_body.Render(hdc);
}

void BrickActor::Release()
{
	base::Release();
}
