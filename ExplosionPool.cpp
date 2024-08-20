#include "ExplosionPool.h"
#include "Explosion.h"
#include "Game Components\TEAL\CommonElements.h"

ExplosionPool::ExplosionPool()
{

}

ExplosionPool::~ExplosionPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Explosion* ExplosionPool::getExplosion()
{
	Explosion* s;

	if (recycledItems.empty())
	{
		s = new Explosion();
	}
	else
	{
		s = recycledItems.top();
		recycledItems.pop();

		s->RegisterToCurrentScene();
	}

	return s;
}

void ExplosionPool::returnExplosion(Explosion* s)
{
	recycledItems.push(static_cast<Explosion*>(s));

}