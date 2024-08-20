#include "CentipedeBody.h"
#include "Centipede.h"
#include "BaseMoveClass.h"
#include "MoveList.h"
#include "MovementList.h"
#include "CentipedeFactory.h"
#include "ScoreManager.h"
#include "CritterList.h"
#include "CmdScore.h"
#include "SndPlay.h"

CentipedeBody::CentipedeBody()
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("CentipedeBody"), 8, 2);
	MainSprite.SetAnimation(0, 7);

	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(2, 2);

	bitmap = ResourceManager::GetTextureBitmap("CentipedeBody");
	SetCollider(MainSprite, bitmap, true);

	SetDrawOrder(1500);

	SetUpdateOrder(2);

	cmdDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::CentipedeBodyKilled);
	sndDeath = SoundManager::GetSoundCommand(SoundManager::SoundEvents::CritterDeath);
}

void CentipedeBody::Initialize(sf::Vector2f pos, Centipede* h)
{
	CritterList::insertNode(this);

	Pos = pos;
	Pos.y += MainSprite.getTextureRect().height;
	Pos.x += MainSprite.getTextureRect().width;
	prevCell.Xoffset = Pos.x;
	prevCell.Yoffset = Pos.y;
	prevCell.Zoffset = 0;
	MainSprite.setPosition(Pos);

	movementIndex = -1;
	pixelsPerFrame = CentipedeFactory::getCentiSpeed();

	head = h;
	CentipedeBase* last = h;
	while (last->getPrev() != 0) last = last->getPrev();
	next = last;
	last->setPrev(this);
	prev = 0;

	MainSprite.setRotation(head->getRotation());
	
	currMoveState = &MoveList::StateNothing;
	nextMoveState = &MoveList::StateNothing;

	RegisterCollision<CentipedeBody>(*this);
}

void CentipedeBody::moveUpdate()
{
	movementIndex += pixelsPerFrame;

	OffsetArray currOffset = currMoveState->GetMoveOffsets()[movementIndex];
	Pos.x = prevCell.Xoffset + currOffset.Xoffset;
	Pos.y = prevCell.Yoffset + currOffset.Yoffset;
	MainSprite.setRotation(currOffset.Zoffset);

	if (movementIndex == maxIndex) {
		if (prev != 0) prev->setMoveState(currMoveState);
		currMoveState = nextMoveState;
		movementIndex = -1;
		prevCell.Xoffset = Pos.x;
		prevCell.Yoffset = Pos.y;
	}

	MainSprite.setPosition(Pos);
	MainSprite.Update();

	if (prev != 0) prev->moveUpdate();
}

void CentipedeBody::finalMove()
{
	movementIndex = -1;
	OffsetArray finOffset = currMoveState->GetMoveOffsets()[maxIndex];
	Pos.x = prevCell.Xoffset + finOffset.Xoffset;
	Pos.y = prevCell.Yoffset + finOffset.Yoffset;
	MainSprite.setRotation(finOffset.Zoffset);

	prevCell.Xoffset = Pos.x;
	prevCell.Yoffset = Pos.y;

	MainSprite.setPosition(Pos);
	if (prev != 0) prev->finalMove();
}

const void CentipedeBody::setMoveState(const BaseMoveClass* bmc)
{
	nextMoveState = bmc;
}

void CentipedeBody::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void CentipedeBody::Destroy()
{
	CritterList::removeNode(this);
	DeregisterCollision<CentipedeBody>(*this);
}

void CentipedeBody::Split()
{
	finalMove();
	float x = currMoveState->GetMoveOffsets()[maxIndex].Xoffset + prevCell.Xoffset;
	PlayerManager::getCurrentField()->spawnMushroom(x, Pos.y);
	if (prev != 0)
	{
		prev->setNext(0);
		prev->upgradeToHead();
	}
	if (next != 0) {
		next->setPrev(0);
		next->checkPrev();
	}

	ScoreManager::SendScoreCmd(cmdDeath);
	SoundManager::SendSoundPlay(sndDeath);
	ExplosionFactory::createExplosion(Pos);
	MarkForDestroy();
}

void CentipedeBody::upgradeToHead()
{
	if (prev != 0) {
		prev->setNext(0);
		prev->emergencySet(currMoveState);
	}
	CentipedeFactory::upgradeCentipede(Pos, prev, currMoveState);
	MarkForDestroy();
}

const void CentipedeBody::emergencySet(const BaseMoveClass* bmc)
{
	if (prev != 0) prev->emergencySet(currMoveState);
	currMoveState = bmc;
}

void CentipedeBody::setHead(Centipede* h)
{
	head = h;
	if (prev != 0) prev->setHead(h);
}

void CentipedeBody::Collision(Bullet* other)
{
	Split();
}

CentipedeBody::~CentipedeBody()
{
	delete cmdDeath;
	delete sndDeath;
}
