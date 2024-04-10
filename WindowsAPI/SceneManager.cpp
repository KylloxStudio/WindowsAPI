#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Dev1Scene.h"
#include "Dev2Scene.h"
#include "PongGameScene.h"
#include "BrickGameScene.h"

void SceneManager::Init()
{

}

void SceneManager::Update()
{
	if (_scene)
	{
		_scene->Update();
	}

	if (_nextSceneType == SceneType::None)
	{
		return;
	}

	Scene* newScene = nullptr;
	switch (_nextSceneType)
	{
	case SceneType::None:
		break;
	case SceneType::Dev1Scene:
		newScene = new Dev1Scene();
		break;
	case SceneType::Dev2Scene:
		newScene = new Dev2Scene();
		break;
	case SceneType::PongGameScene:
		newScene = new PongGameScene();
		break;
	case SceneType::BrickGameScene:
		newScene = new BrickGameScene();
		break;
	default:
		break;
	}

	SAFE_DELETE(_scene);
	_scene = newScene;
	_sceneType = _nextSceneType;
	_nextSceneType = SceneType::None;
	newScene->Init();
}

void SceneManager::Render(HDC hdc)
{
	if (_scene)
	{
		_scene->Render(hdc);
	}
}

void SceneManager::Release()
{
	if (_scene)
	{
		_scene->Release();
	}
}

void SceneManager::LoadScene(SceneType sceneType)
{
	if (_sceneType == sceneType)
	{
		return;
	}

	_nextSceneType = sceneType;
}
