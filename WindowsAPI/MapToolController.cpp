#include "pch.h"
#include "MapToolController.h"
#include "MapToolTilemapActor.h"
#include "Tilemap.h"

void MapToolController::Init(MapToolTilemapActor* mapToolActor)
{
	_mapToolActor = mapToolActor;
}

void MapToolController::Update()
{
	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		//타일이 클릭되었는지?
		// 타일이 클릭되었으면

		// 해당 타일의 Value + 1

		int x = 0;
		int y = 0;
		Tilemap* tileMap = _mapToolActor->GetTileMap();
		int tileSize = tileMap->GetTileSize();

		Vector2Int mousePos = Input->GetMousePos();

		Vector2 pos = _mapToolActor->GetBody().pos;
		x = (mousePos.x - static_cast<int>(pos.x)) / tileSize;
		y = (mousePos.y - static_cast<int>(pos.y)) / tileSize;

		Tile* tile = tileMap->GetTileAt({ x, y });
		if (tile)
		{
			tile->value++;
			tile->value %= _mapToolActor->GetTileSprites().size();
		}
	}

	if (Input->GetKeyDown(KeyCode::S))
	{
		_mapToolActor->Save();
	}

	if (Input->GetKeyDown(KeyCode::L))
	{
		_mapToolActor->Load();
	}
}
