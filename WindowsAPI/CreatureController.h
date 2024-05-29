#pragma once
class CreatureActor;

class CreatureController
{
private:
	CreatureActor* _actor;
	Vector2 _curPos;
	Vector2 _newPos;
	Vector2 _newVelocity;
	bool _isMoveKeyInput;

public:
	void Init(CreatureActor* actor);
	void Update();
};

