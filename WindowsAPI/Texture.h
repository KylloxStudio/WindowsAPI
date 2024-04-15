#pragma once
#include "ResourceBase.h"

class Texture : public ResourceBase
{
protected:
	HDC _hdc = {};
	HBITMAP _bitmap = {};
	Vector2Int _size = {};
	uint32 _transparent = RGB(255, 0, 255);

public:
	Texture();
	virtual ~Texture();

	HDC GetDC(HDC hdc) { return hdc; }

	Texture* LoadBmp(const wstring& path);

	Vector2Int GetSize() { return _size; }
	void SetSize(Vector2Int size) { _size = size; }

	uint32 GetTransparent() { return _transparent; }
	void SetTransparent(uint32 transparent) { _transparent = transparent; }
};
