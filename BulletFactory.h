#ifndef _BulletFactory
#define _BulletFactory

#include "SFML/Graphics.hpp"
#include "BulletPool.h"

class GameObject;

class BulletFactory
{
private:
	static BulletFactory* ptrInstance;

	BulletFactory() = default;
	BulletFactory(const BulletFactory&) = delete;
	BulletFactory& operator=(const BulletFactory&) = delete;
	~BulletFactory() = default;

	static BulletFactory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new BulletFactory();
		return *ptrInstance;
	};

	BulletPool pool;

	void privCreateBullet(sf::Vector2f pos);
	void privRecycleBullet(GameObject* b);

public:

	static void createBullet(sf::Vector2f pos) { Instance().privCreateBullet(pos); };
	static void recycleBullet(GameObject* b) { Instance().privRecycleBullet(b); };
	static void Terminate();
};


#endif _BulletFactory