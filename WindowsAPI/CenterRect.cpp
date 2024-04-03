#include "pch.h"
#include "CenterRect.h"
#include "Vector2.h"

RECT CenterRect::ToRect()
{
	RECT rect;
	rect.left = static_cast<LONG>(pos.x - width / 2);
	rect.right = static_cast<LONG>(pos.x + width / 2);
	rect.top = static_cast<LONG>(pos.y - height / 2);
	rect.bottom = static_cast<LONG>(pos.y + height / 2);

	return rect;
}

void CenterRect::Render(HDC hdc)
{
	RECT rect = this->ToRect();
	::Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
}
