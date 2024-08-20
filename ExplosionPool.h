#ifndef _ExplosionPool
#define _ExplosionPool

#include <stack>
class Explosion;

class ExplosionPool
{
private:
	std::stack<Explosion*> recycledItems;

public:
	ExplosionPool();
	ExplosionPool(const ExplosionPool&) = delete;
	ExplosionPool& operator=(const ExplosionPool&) = delete;
	~ExplosionPool();

	Explosion* getExplosion();

	void returnExplosion(Explosion* f);
};


#endif _ExplosionPool