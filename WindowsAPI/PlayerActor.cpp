#include "pch.h"
#include "PlayerActor.h"

void PlayerActor::Init()
{
	base::Init();
}

void PlayerActor::Update()
{
	base::Update();
}

void PlayerActor::Render(HDC hdc)
{
	base::Render(hdc);

	_body.Render(hdc);
}

void PlayerActor::Release()
{
	base::Release();
}
