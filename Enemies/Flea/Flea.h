#ifndef _Flea
#define _Flea

#include "Critter.h"

class Bullet;
class CmdScore;
class SndPlay;

class Flea : public Critter
{
public:
	Flea();
	Flea(const Flea&) = delete;
	Flea& operator=(const Flea&) = delete;
	~Flea();

	void Initialize(sf::Vector2f pos);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Alarm0();
	virtual void Collision(GameObject* other) {};
	void Collision(Bullet* other);

	Types getType() override { return Types::Flea; };

private:
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
	sf::Vector2f Pos;

	CmdScore* cmdDeath;
	SndPlay* sndStart;
	SndPlay* sndDeath;
	
	int health;
	int cellsPerSecond;
	int speed;
	int cellHeight;
};

#endif _Flea
