#include "pch.h"
#include "Dev1Scene.h"
#include "PlayerActor.h"
#include "BoxCollider.h"
#include "SpriteActor.h"
#include "FlipbookActor.h"
#include "Flipbook.h"
#include "CreatureActor.h"
#include "CameraComponent.h"
#include "Texture.h"
#include "Sprite.h"
#include "CircleCollider.h"
#include "TestPanel.h"

void Dev1Scene::Init()
{
	LoadResource();

	GET_SINGLE(SoundManager)->Play(L"BGM_Dev1Scene", true);


	SpriteActor* background = nullptr;
	{
		background = new SpriteActor();
		Sprite* sprite = Resource->GetSprite(L"S_Background");
		background->SetSprite(sprite);
		background->SetBody(Shape::MakeCenterRectLTWH(0, 0, sprite->GetSize().x, sprite->GetSize().y));
		background->Init();
		this->SpawnActor(background);
	}

	{
		CreatureActor* actor = new CreatureActor();

		actor->SetName("Player");
		actor->SetFlipbook(Resource->GetFlipbook(L"FB_PlayerDownIdle"));
		actor->SetPos(Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2));

		{
			CameraComponent* component = new CameraComponent();
			component->SetLTWH(background->GetSprite());
			component->Init();
			actor->AddComponent(component);
		}
		{
			CircleCollider* component = new CircleCollider();
			component->SetCollision(Vector2::Zero(), 50);
			component->Init();
			actor->AddComponent(component);
		}

		actor->Init();
		this->SpawnActor(actor);
	}

	{
		FlipbookActor* actor = new FlipbookActor();

		actor->SetName("Dummy");
		{
			BoxCollider* component = new BoxCollider();
			component->SetCollision(Shape::MakeCenterRect(0, 0, 50, 50));
			component->Init();
			actor->AddComponent(component);
		}
		actor->SetFlipbook(Resource->GetFlipbook(L"FB_PlayerRightIdle"));
		actor->SetPos(Vector2(WIN_SIZE_X / 2 + 100, WIN_SIZE_Y / 2));

		actor->Init();
		this->SpawnActor(actor);
	}

	//{
	//	TestPanel* testPanel = new TestPanel();
	//	_uis.push_back(testPanel);
	//}

	Super::Init();

}
void Dev1Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	wstring str = L"Dev1Scene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());

}
void Dev1Scene::Update()
{
	Super::Update();

	if (Input->GetKey(KeyCode::Control) && Input->GetKeyDown(KeyCode::RightMouse))
	{
		GET_SINGLE(SceneManager)->LoadScene(SceneType::Dev2Scene);
	}

	if (Input->GetKeyDown(KeyCode::P))
	{
		GET_SINGLE(SceneManager)->LoadScene(SceneType::PongGameScene);
	}

	if (Input->GetKeyDown(KeyCode::B))
	{
		GET_SINGLE(SceneManager)->LoadScene(SceneType::BrickGameScene);
	}

	if (Input->GetKeyDown(KeyCode::M))
	{
		GET_SINGLE(SceneManager)->LoadScene(SceneType::MoleGameScene);
	}
}

void Dev1Scene::Release()
{
	Super::Release();
}

void Dev1Scene::LoadResource()
{
	//----------------------------------
	//  ## Background
	//----------------------------------
	{
		Texture* texture = Resource->LoadTexture(L"T_Background" , L"CameraStudy/backround_supermario.bmp");
		Resource->CreateSprite(L"S_Background", texture);
	}


	//----------------------------------
	//  ## PlayerDown Texture
	//----------------------------------
	{
		Texture* texture = Resource->LoadTexture(L"T_PlayerDown" , L"FilpbookTest/PlayerDown.bmp" , RGB(128, 128, 128));

		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 0;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerDownIdle", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 1;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerDownMove", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 3;
			flipbookInfo.start = 0;
			flipbookInfo.end = 7;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerDownAttack", flipbookInfo);
		}
	}


	//----------------------------------
	//  ## PlayerUp Texture
	//----------------------------------
	{
		Texture* texture = Resource->LoadTexture(L"T_PlayerUp" , L"FilpbookTest/PlayerUp.bmp" , RGB(128, 128, 128));

		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 0;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerUpIdle", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 1;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerUpMove", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 3;
			flipbookInfo.start = 0;
			flipbookInfo.end = 7;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerUpAttack", flipbookInfo);
		}
	}


	//----------------------------------
	//  ## PlayerLeft Texture
	//----------------------------------
	{
		Texture* texture = Resource->LoadTexture(L"T_PlayerLeft" , L"FilpbookTest/PlayerLeft.bmp" , RGB(128, 128, 128));

		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 0;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerLeftIdle", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 1;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerLeftMove", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 3;
			flipbookInfo.start = 0;
			flipbookInfo.end = 7;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerLeftAttack", flipbookInfo);
		}
	}

	//----------------------------------
	//  ## PlayerRight Texture
	//----------------------------------
	{
		Texture* texture = Resource->LoadTexture(L"T_PlayerRight" , L"FilpbookTest/PlayerRight.bmp" , RGB(128, 128, 128));

		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 0;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerRightIdle", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 1;
			flipbookInfo.start = 0;
			flipbookInfo.end = 9;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerRightMove", flipbookInfo);
		}
		{
			FlipbookInfo flipbookInfo = {};
			flipbookInfo.duration = 1.0;
			flipbookInfo.loop = true;
			flipbookInfo.line = 3;
			flipbookInfo.start = 0;
			flipbookInfo.end = 7;
			flipbookInfo.size = { 200,200 };
			flipbookInfo.texture = texture;
			Resource->CreateFlipbook(L"FB_PlayerRightAttack", flipbookInfo);
		}
	}


	//----------------------------------
	//  ## Sound
	//----------------------------------
	Resource->LoadSound(L"BGM_Dev1Scene", L"Sounds/SoundStudy/BGM.wav");

	//----------------------------------
	//  ## UI
	//----------------------------------

}