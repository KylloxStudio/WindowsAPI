#pragma once

class Actor;
class Scene
{
protected:
	vector<Actor*> _actors;

public:
	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

	void SpawnActor(Actor* actor);
	void DespawnActor(Actor* actor);
};
