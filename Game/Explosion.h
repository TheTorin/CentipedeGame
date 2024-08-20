#ifndef _Explosion
#define _Explosion

#include "Game Components\TEAL\CommonElements.h"

class Bullet;

class Explosion : public GameObject
{
public:
	Explosion();
	Explosion(const Explosion&) = delete;
	Explosion& operator=(const Explosion&) = delete;
	~Explosion();

	void Initialize(sf::Vector2f pos);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

private:
	AnimatedSprite MainSprite;
};

#endif _Explosion
