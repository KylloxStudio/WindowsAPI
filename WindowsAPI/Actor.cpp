#include "pch.h"
#include "Actor.h"
#include "Scene.h"
#include "Component.h"
#include "Collider.h"

void Actor::Init()
{

}

void Actor::Update()
{
	for (Component* component : _components)
	{
		component->Update();
	}

	if (!_isEnable)
	{
		Scene* curScene = GET_SINGLE(SceneManager)->GetCurrentScene();
		curScene->DespawnActor(this);
	}
}

void Actor::Render(HDC hdc)
{
	for (Component* component : _components)
	{
		component->Render(hdc);
	}
}

void Actor::Release()
{
	for (Component* component : _components)
	{
		component->Release();
		SAFE_DELETE(component);
	}

	_components.clear();
}

void Actor::OnCollisionEnter(Collider* collider, Collider* other)
{
	cout << "충돌 시작: " << collider->GetOwner()->GetName() << " -> " << other->GetOwner()->GetName() << endl;
}

void Actor::OnCollisionStay(Collider* collider, Collider* other)
{
	cout << "충돌 중: " << collider->GetOwner()->GetName() << " -> " << other->GetOwner()->GetName() << endl;
}

void Actor::OnCollisionExit(Collider* collider, Collider* other)
{
	cout << "충돌 끝: " << collider->GetOwner()->GetName() << " -> " << other->GetOwner()->GetName() << endl;
}

void Actor::AddComponent(Component* component)
{
	if (component == nullptr) return;

	component->SetOwner(this);
	component->Init();
	_components.push_back(component);
}

void Actor::RemoveComponent(Component* component)
{
	auto findIt = find(_components.begin(), _components.end(), component);
	if (findIt != _components.end())
	{
		Component* deleteComponent = *findIt;
		deleteComponent->Release();
		SAFE_DELETE(deleteComponent);
		_components.erase(findIt);
	}
}
