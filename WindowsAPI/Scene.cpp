#include "pch.h"
#include "Scene.h"
#include "Actor.h"

void Scene::Init()
{

}

void Scene::Update()
{
	/*for (int i = 0; i < _actors.size(); i++)
	{
		_actors[i]->Update();
	}*/

	for (Actor* actor : _actors)
	{
		actor->Update();
	}
}

void Scene::Render(HDC hdc)
{
	for (Actor* actor : _actors)
	{
		actor->Render(hdc);
	}
}

void Scene::Release()
{
	for (Actor* actor : _actors)
	{
		actor->Release();
		SAFE_DELETE(actor);
	}

	_actors.clear();
}

void Scene::SpawnActor(Actor* actor)
{
	if (actor == nullptr) return;

	actor->Init();
	_actors.push_back(actor);
}

void Scene::DespawnActor(Actor* actor)
{
	if (actor == nullptr) return;

	auto findIt = find(_actors.begin(), _actors.end(), actor);
	if (findIt != _actors.end())
	{
		(*findIt)->Release();
		Actor* deleteActor = (*findIt);
		SAFE_DELETE(deleteActor);
		_actors.erase(findIt);
	}
}
