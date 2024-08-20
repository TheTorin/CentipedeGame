#ifndef _CentipedeBody
#define _CentipedeBody

#include "Game Components\TEAL\CommonElements.h"
#include "CentipedeBase.h"

class Bullet;
class BaseMoveClass;
class Centipede;

class CentipedeBody : public CentipedeBase
{
public:
	CentipedeBody();
	CentipedeBody(const CentipedeBody&) = delete;
	CentipedeBody& operator=(const CentipedeBody&) = delete;
	~CentipedeBody();

	void Initialize(sf::Vector2f pos, Centipede* head);

	void moveUpdate();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject* other) {};
	void Collision(Bullet* other);

	virtual CentipedeBody* getPrev() override { return prev; };
	virtual CentipedeBase* getNext() override { return next; };
	virtual Centipede* getHead() override  { return head; };

	virtual void setHead(Centipede* c) override;
	virtual void setPrev(CentipedeBody* b) override { prev = b; };
	virtual void setNext(CentipedeBase* b) override { next = b; };

	const void setMoveState (const BaseMoveClass* bmc);
	const void emergencySet(const BaseMoveClass* bmc);
	void upgradeToHead();
	void Split();
	void finalMove();

private:
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
	sf::Vector2f Pos;

	CmdScore* cmdDeath;
	SndPlay* sndDeath;

	Centipede* head;
	CentipedeBase* next;
	CentipedeBody* prev;

	const BaseMoveClass* currMoveState;
	const BaseMoveClass* nextMoveState;

	OffsetArray prevCell = OffsetArray(0, 0, 0);
	int movementIndex = -1;
	int maxIndex = 15;
	int pixelsPerFrame = 2;
};

#endif _CentipedeBody