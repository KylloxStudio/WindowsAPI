#pragma once
#include "Enums.h";

class BrickGameState
{
public:
	void SetGameState(GameState state) { _state = state; }
	GameState GetGameState() { return _state; }

private:
	GameState _state = GameState::None;
};
