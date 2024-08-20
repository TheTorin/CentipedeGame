#ifndef _ExplosionFactory
#define _ExplosionFactory

#include "SFML/Graphics.hpp"
#include "ExplosionPool.h"

class GameObject;

class ExplosionFactory
{
private:
	static ExplosionFactory* ptrInstance;

	ExplosionFactory() = default;
	ExplosionFactory(const ExplosionFactory&) = delete;
	ExplosionFactory& operator=(const ExplosionFactory&) = delete;
	~ExplosionFactory() = default;

	static ExplosionFactory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new ExplosionFactory();
		return *ptrInstance;
	};

	ExplosionPool pool;

	void privCreateExplosion(sf::Vector2f pos);
	void privRecycleExplosion(GameObject* b);

public:

	static void createExplosion(sf::Vector2f pos) { Instance().privCreateExplosion(pos); };
	static void recycleExplosion(GameObject* b) { Instance().privRecycleExplosion(b); };
	static void Terminate();
};


#endif _ExplosionFactory
