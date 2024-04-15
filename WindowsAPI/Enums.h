#pragma once

enum class SceneType
{
	None,
	Dev1Scene,
	Dev2Scene,
	PongGameScene,
	BrickGameScene
};

enum class GameState
{
	None,
	Wait,
	Play
};

enum class ColliderType
{
	None,
	Box,
	Circle
};

enum CollisionLayerType : uint8
{
	CLT_OBJECT
};
