#include "ExplosionFactory.h"
#include "Explosion.h"

ExplosionFactory* ExplosionFactory::ptrInstance = nullptr;

void ExplosionFactory::privCreateExplosion(sf::Vector2f pos)
{
	Explosion* c = pool.getExplosion();

	c->SetExternalManagement(recycleExplosion);
	c->Initialize(pos);
}

void ExplosionFactory::privRecycleExplosion(GameObject* go)
{
	pool.returnExplosion(static_cast<Explosion*>(go));
}

void ExplosionFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
