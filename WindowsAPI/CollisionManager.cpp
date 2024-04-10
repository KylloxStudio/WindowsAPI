#include "pch.h"
#include "CollisionManager.h"
#include "Actor.h"
#include "Collider.h"

void CollisionManager::Init()
{

}

void CollisionManager::Update()
{
	for (int i = 0; i < _colliders.size(); i++)
	{
		Collider* c1 = _colliders[i];
		for (int j = i + 1; j < _colliders.size(); j++)
		{
			Collider* c2 = _colliders[j];
			if (c1->CheckCollision(c2))
			{
				if (!c1->_collisionMap.contains(c2))
				{
					c1->_collisionMap.insert(c2);
					c2->_collisionMap.insert(c1);
					c1->GetOwner()->OnCollisionEnter(c1, c2);
					c2->GetOwner()->OnCollisionEnter(c2, c1);
				}

				c1->GetOwner()->OnCollisionStay(c1, c2);
				c2->GetOwner()->OnCollisionStay(c2, c1);
			}
			else
			{
				if (c1->_collisionMap.contains(c2))
				{
					c1->_collisionMap.erase(c2);
					c2->_collisionMap.erase(c1);
					c1->GetOwner()->OnCollisionExit(c1, c2);
					c2->GetOwner()->OnCollisionExit(c2, c1);
				}
			}
		}
	}
}

void CollisionManager::AddCollider(Collider* collider)
{
	_colliders.push_back(collider);
}

void CollisionManager::RemoveCollider(Collider* collider)
{
	auto findIt = find(_colliders.begin(), _colliders.end(), collider);
	if (findIt != _colliders.end())
	{
		_colliders.erase(findIt);
	}
}

void CollisionManager::ClearCollider()
{
	_colliders.clear();
}
