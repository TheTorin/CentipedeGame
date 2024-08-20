#include "BulletFactory.h"
#include "Bullet.h"

BulletFactory* BulletFactory::ptrInstance = nullptr;

void BulletFactory::privCreateBullet(sf::Vector2f pos)
{
	Bullet* c = pool.getBullet();

	c->SetExternalManagement(recycleBullet);
	c->Initialize(pos);
}

void BulletFactory::privRecycleBullet(GameObject* go)
{
	pool.returnBullet(static_cast<Bullet*>(go));
}

void BulletFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
