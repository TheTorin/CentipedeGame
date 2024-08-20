#include "BulletPool.h"
#include "Bullet.h"
#include "Game Components\TEAL\CommonElements.h"

BulletPool::BulletPool()
{

}

BulletPool::~BulletPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Bullet* BulletPool::getBullet()
{
	Bullet* s;

	if (recycledItems.empty())
	{
		s = new Bullet();
	}
	else
	{
		s = recycledItems.top();
		recycledItems.pop();

		s->RegisterToCurrentScene();
	}

	return s;
}

void BulletPool::returnBullet(Bullet* s)
{
	recycledItems.push(static_cast<Bullet*>(s));

}