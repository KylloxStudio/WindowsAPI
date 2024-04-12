#include "pch.h"
#include "WallActor.h"

void WallActor::Init()
{
	base::Init();
}

void WallActor::Update()
{
	base::Update();
}

void WallActor::Render(HDC hdc)
{
	base::Render(hdc);

	_body.Render(hdc);
}

void WallActor::Release()
{
	base::Release();
}
