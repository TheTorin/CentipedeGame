#include "Centipede.h"
#include "MushroomManager.h"
#include "BaseMoveClass.h"
#include "MoveList.h"
#include "CritterList.h"
#include "GameManager.h"
#include "CmdScore.h"
#include "SndPlay.h"

Centipede::Centipede()
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Centipede"), 8, 2);
	MainSprite.SetAnimation(0, 7);

	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(2, 2);

	bitmap = ResourceManager::GetTextureBitmap("Centipede");
	SetCollider(MainSprite, bitmap, true);

	SetDrawOrder(1500);

	SetUpdateOrder(1);

	cmdDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::CentipedeHeadKilled);
	sndDeath = SoundManager::GetSoundCommand(SoundManager::SoundEvents::CritterDeath);
}

void Centipede::Initialize(sf::Vector2f pos)
{
	CritterList::insertNode(this);

	prev = 0;
	toDie = false;

	Pos = pos;
	Pos.y += MainSprite.getTextureRect().height;
	Pos.x += MainSprite.getTextureRect().width;
	prevCell.Xoffset = Pos.x;
	prevCell.Yoffset = Pos.y;
	prevCell.Zoffset = 0;
	MainSprite.setPosition(Pos);

	movementIndex = -1;
	if (rand() % 2 == 0) {
		currMoveState = &MoveList::StateLeftAndDown;
	}
	else {
		currMoveState = &MoveList::StateRightAndDown;
	}

	pixelsPerFrame = CentipedeFactory::getHeadSpeed();
	nextPix = pixelsPerFrame;
	
	RegisterCollision<Centipede>(*this);
}

void Centipede::InitializeSide(sf::Vector2f pos)
{
	CritterList::insertNode(this);

	prev = 0;
	toDie = false;

	Pos = pos;
	Pos.y += MainSprite.getTextureRect().height;
	prevCell.Yoffset = Pos.y;
	prevCell.Zoffset = 0;

	movementIndex = -1;

	if (Pos.x == 0) {
		Pos.x += MainSprite.getTextureRect().width;
		prevCell.Xoffset = Pos.x;
		MainSprite.setPosition(Pos);
		currMoveState = &MoveList::StateRightAndDown;
	}
	else {
		Pos.x -= MainSprite.getTextureRect().width;
		prevCell.Xoffset = Pos.x;
		MainSprite.setPosition(Pos);
		currMoveState = &MoveList::StateLeftAndDown;
	}
	pixelsPerFrame = CentipedeFactory::getHeadSpeed();
	nextPix = pixelsPerFrame;
	
	RegisterCollision<Centipede>(*this);
}

void Centipede::Upgraded(sf::Vector2f pos, CentipedeBody* Cprev, const BaseMoveClass* bmc)
{
	CritterList::insertNode(this);

	toDie = false;
	Pos = pos;
	MainSprite.setPosition(Pos);
	prevCell = OffsetArray(Pos.x, Pos.y, 0);

	RegisterCollision<Centipede>(*this);

	prev = Cprev;

	if (prev != 0) {
		prev->setNext(this);
		prev->setHead(this);
		pixelsPerFrame = CentipedeFactory::getCentiSpeed();
	}
	else pixelsPerFrame = CentipedeFactory::getHeadSpeed();

	nextPix = pixelsPerFrame;
	movementIndex = -1;

	currMoveState = bmc->GetNextState(this);
}

void Centipede::Update()
{
	movementIndex += pixelsPerFrame;

	OffsetArray currOffset = currMoveState->GetMoveOffsets()[movementIndex];
	Pos.x = prevCell.Xoffset + currOffset.Xoffset;
	Pos.y = prevCell.Yoffset + currOffset.Yoffset;
	MainSprite.setRotation(currOffset.Zoffset);

	if (movementIndex == maxIndex) {
		if (toDie) Die();
		else {
			if (prev != 0) prev->setMoveState(currMoveState);
			currMoveState = currMoveState->GetNextState(this);
			movementIndex = -1;
			prevCell.Xoffset = Pos.x;
			prevCell.Yoffset = Pos.y;
			pixelsPerFrame = nextPix;
		}
	}

	MainSprite.setPosition(Pos);
	MainSprite.Update();

	if (prev != 0) prev->moveUpdate();
}

void Centipede::setPrev(CentipedeBody* c)
{
	prev = c;
	pixelsPerFrame = CentipedeFactory::getCentiSpeed();
	nextPix = pixelsPerFrame;
}

void Centipede::Die()
{
	ExplosionFactory::createExplosion(Pos);
	PlayerManager::getCurrentField()->spawnMushroom(Pos.x, Pos.y);
	ScoreManager::SendScoreCmd(cmdDeath);
	SoundManager::SendSoundPlay(sndDeath);
	if (prev != 0) prev->upgradeToHead();
	MarkForDestroy();
}

void Centipede::hitTop()
{
	CentipedeFactory::spawnFromSide();
}

void Centipede::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Centipede::Destroy()
{
	CritterList::removeNode(this);
	GameManager::checkCentiDead();
	DeregisterCollision<Centipede>(*this);
}

void Centipede::Collision(Bullet* other)
{
	toDie = true;
}

Centipede::~Centipede()
{
	delete cmdDeath;
	delete sndDeath;
}