#pragma once

class Scene;

class SceneManager
{
	DECLARE_SINGLE(SceneManager);

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void LoadScene(SceneType sceneType);
	Scene* GetCurrentScene() { return _scene; }

private:
	SceneType _sceneType = SceneType::None;
	SceneType _nextSceneType = SceneType::None;

	Scene* _scene = nullptr;
};

