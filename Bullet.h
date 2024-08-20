#ifndef _Bullet
#define _Bullet

#include "Game Components\TEAL\CommonElements.h"
#include <SFML\Graphics\Sprite.hpp>
#include "SoundManager.h"

// Forward declarations
class Indestructible;
class Mushroom;
class Player;
class Spider;
class Scorpion;
class Centipede;
class CentipedeBody;

class Bullet : public GameObject
{
public:
	Bullet();
	Bullet(const Bullet&) = delete;
	Bullet& operator=(const Bullet&) = delete;
	~Bullet();

	void Initialize(sf::Vector2f shipPos);
	
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject* other) {};
	void Collision(Mushroom* other);
	void Collision(Indestructible* other);
	void Collision(Spider* other);
	void Collision(Scorpion* other);
	void Collision(Centipede* other);
	void Collision(CentipedeBody* other);

private:
	float SPEED;
	sf::Vector2f Pos;

	sf::Sprite MainSprite;
	CollisionTools::TextureBitmap bitmap;

	SndPlay* SndFire;
};

#endif _Bullet
