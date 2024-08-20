#ifndef _CentipedeBase
#define _CentipedeBase

#include "Critter.h"
#include "PlayerManager.h"
#include "ExplosionFactory.h"
#include "ScoreManager.h"
#include "SoundManager.h"
#include "MovementList.h"

class Bullet;
class BaseMoveClass;
class MushroomManager;
class Centipede;
class CentipedeBody;
class CmdScore;

class CentipedeBase : public Critter
{
public:
	virtual Centipede* getHead() { return 0; };
	virtual CentipedeBase* getNext() { return 0; };
	virtual CentipedeBody* getPrev() { return 0; };

	virtual void setHead(Centipede*) { return; };
	virtual void setNext(CentipedeBase*) { return; };
	virtual void setPrev(CentipedeBody*) { return; };

	virtual void checkPrev() { return; };

	Types getType() override { return Types::Centipede; };
};

#endif _CentipedeBase