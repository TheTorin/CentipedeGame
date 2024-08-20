#ifndef _Indestructible
#define _Indestructible

#include "Game Components\TEAL\CommonElements.h"
#include "BaseBlocker.h"

class Bullet;

class Indestructible : public BaseBlocker
{
public:
	Indestructible() = delete;				// Private constructor 
	Indestructible(const Indestructible&);				// Prevent copy-construction
	Indestructible& operator=(const Indestructible&);	// Prevent assignment
	~Indestructible() = default;

	Indestructible(sf::Vector2f pos);

	virtual void Destroy() { return; };
	virtual void regen() override { return; };

private:
	sf::Sprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
};

#endif _Indestructible
