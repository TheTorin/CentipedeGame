#ifndef _BulletPool
#define _BulletPool

#include <stack>
class Bullet;

class BulletPool
{
private:
	std::stack<Bullet*> recycledItems;

public:
	BulletPool();
	BulletPool(const BulletPool&) = delete;
	BulletPool& operator=(const BulletPool&) = delete;
	~BulletPool();

	Bullet* getBullet();

	void returnBullet(Bullet* f);
};


#endif _BulletPool
