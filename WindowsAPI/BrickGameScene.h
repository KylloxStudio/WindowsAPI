#pragma once
#include "Scene.h"

class PaddleActor;
class BallActor;
class BrickActor;
class PlayerController;

class BrickGameScene : public Scene
{
	using base = Scene;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void ChangeGameState(GameState state);
	GameState GetGameState() { return _gameState; }

private:
	PaddleActor* _paddle = nullptr;
	BallActor* _ball = nullptr;
	PlayerController* _playerController = nullptr;
	vector<BrickActor*> _bricks = vector<BrickActor*>();

	int _score;
	GameState _gameState = GameState::None;
};
