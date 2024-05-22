#pragma once
#include "ResourceBase.h"

struct Tile
{
	int value = 0;

};

class Tilemap : public ResourceBase
{
	DECLARE_CHILD(Tilemap, ResourceBase)

public:
	virtual void LoadFile(const wstring& path);
	virtual void SaveFile(const wstring& path);

	Vector2Int GetMapSize() { return _mapSize; }
	int GetTileSize() { return _tileSize; }
	vector<vector<Tile>>& GetTiles() { return _tiles; }
	Tile* GetTileAt(Vector2Int pos);

	void SetMapSize(Vector2Int mapSize) { _mapSize = mapSize; }
	void SetTileSize(int tileSize) { _tileSize = tileSize; }

protected:
	Vector2Int _mapSize = {};
	int _tileSize = 0;
	vector<vector<Tile>> _tiles;
};
