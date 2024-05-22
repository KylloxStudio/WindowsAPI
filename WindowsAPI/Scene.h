#pragma once

class Actor;
class UI;

class Scene
{
protected:
	vector<Actor*> _actors[static_cast<int>(LayerType::End)];
	Vector2 _cameraPosition = {};
	vector<UI*> _uis;

public:
	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

	void SpawnActor(Actor* actor);
	void DespawnActor(Actor* actor);

	void SetCameraPos(Vector2 pos) { _cameraPosition = pos; }
	Vector2 GetCameraPos() { return _cameraPosition; }
};
