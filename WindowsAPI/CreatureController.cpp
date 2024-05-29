#include "pch.h"
#include "CreatureController.h"
#include "CreatureActor.h"

void CreatureController::Init(CreatureActor* actor)
{
	_actor = actor;
	_newPos = _actor->GetPos();
}
void CreatureController::Update()
{
	_actor->SetIsAttackInput(false);
	Vector2 velocity = _actor->GetVelocity();

	if (_isMoveKeyInput)
	{
		velocity.x = _newVelocity.x * Time->GetDeltaTime();
		velocity.y = _newVelocity.y * Time->GetDeltaTime();
		_newPos = _actor->GetPos();
	}

	if (Input->GetKeyDown(KeyCode::Up))
	{
		_isMoveKeyInput = true;
		_actor->ChangeDirection(eCreatureDirection::UP);
		_curPos = _actor->GetPos();
		_newVelocity.x = 0;
		_newVelocity.y = -100.0f;
	}
	else if (Input->GetKeyDown(KeyCode::Left))
	{
		_isMoveKeyInput = true;
		_actor->ChangeDirection(eCreatureDirection::LEFT);
		_curPos = _actor->GetPos();
		_newVelocity.x = -100.0f;
		_newVelocity.y = 0;
	}
	else if (Input->GetKeyDown(KeyCode::Right))
	{
		_isMoveKeyInput = true;
		_actor->ChangeDirection(eCreatureDirection::RIGHT);
		_curPos = _actor->GetPos();
		_newVelocity.x = 100.0f;
		_newVelocity.y = 0;
	}
	else if (Input->GetKeyDown(KeyCode::Down))
	{
		_isMoveKeyInput = true;
		_actor->ChangeDirection(eCreatureDirection::DOWN);
		_curPos = _actor->GetPos();
		_newVelocity.y = 100.0f;
		_newVelocity.x = 0;
	}

	if (Input->GetKeyDown(KeyCode::Space))
	{
		_actor->SetIsAttackInput(true);
	}

	if ((_curPos - _newPos).Length() > 90)
	{
		_isMoveKeyInput = false;
		velocity = { 0,0 };
		_newVelocity = { 0, 0 };
	}

	_actor->SetVelocity(velocity);
}