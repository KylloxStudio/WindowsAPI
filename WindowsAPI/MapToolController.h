#pragma once

class MapToolTilemapActor;

class MapToolController
{
public:
	void Init(MapToolTilemapActor* mapToolActor);
	void Update();

private:
	MapToolTilemapActor* _mapToolActor = nullptr;
};

