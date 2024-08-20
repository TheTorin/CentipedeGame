#ifndef _Centipede
#define _Centipede

#include "Game Components\TEAL\CommonElements.h"
#include "CentipedeBase.h"
#include "CentipedeBody.h"
#include "CentipedeFactory.h"

class Bullet;
class BaseMoveClass;
class MushroomManager;

class Centipede : public CentipedeBase
{
public:
	Centipede();
	Centipede(const Centipede&) = delete;
	Centipede& operator=(const Centipede&) = delete;
	~Centipede();

	void Initialize(sf::Vector2f pos);
	void InitializeSide(sf::Vector2f pos);
	void Upgraded(sf::Vector2f pos, CentipedeBody* prev, const BaseMoveClass* bmc);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	void Die();

	virtual void Collision(GameObject* other) {};
	void Collision(Bullet* other);

	sf::Vector2f getPos() { return Pos; };
	float getRotation() { return MainSprite.getRotation(); };

	void hitTop();

	virtual CentipedeBody* getPrev() override { return prev; };
	virtual void setPrev(CentipedeBody* c) override;
	virtual void checkPrev() override { nextPix = CentipedeFactory::getHeadSpeed(); };

private:
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
	sf::Vector2f Pos;

	CmdScore* cmdDeath;
	SndPlay* sndDeath;

	OffsetArray prevCell = OffsetArray(0.0f, 0.0f, 0.0f);
	int pixelsPerFrame = 2;
	int nextPix = 2;

	const BaseMoveClass* currMoveState;

	CentipedeBody* prev;
	
	int movementIndex;
	int maxIndex = 15;

	bool toDie;
};

#endif _Centipede
