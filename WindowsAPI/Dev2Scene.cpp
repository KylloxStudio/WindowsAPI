#include "pch.h"
#include "Dev2Scene.h"

void Dev2Scene::Init()
{
	base::Init();
}

void Dev2Scene::Update()
{
	base::Update();

	if (Input->GetKey(KeyCode::Control) && Input->GetKeyDown(KeyCode::RightMouse))
	{
		GET_SINGLE(SceneManager)->LoadScene(SceneType::Dev1Scene);
	}
}

void Dev2Scene::Render(HDC hdc)
{
	base::Render(hdc);

	wstring str = _T("Dev2Scene");
	::TextOut(hdc, 0, 45, str.c_str(), str.length());
}

void Dev2Scene::Release()
{
	base::Release();
}
