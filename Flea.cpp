#include "Flea.h"
#include "MushroomManager.h"
#include "PlayerManager.h"
#include "ExplosionFactory.h"
#include "ScoreManager.h"
#include "SoundManager.h"
#include "CritterList.h"
#include "SndPlay.h"
#include "CmdScore.h"

Flea::Flea()
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Flea"), 2, 2);
	MainSprite.SetAnimation(0, 3);

	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(1, 1);

	bitmap = ResourceManager::GetTextureBitmap("Flea");
	SetCollider(MainSprite, bitmap, true);

	SetDrawOrder(1500);

	cellsPerSecond = 8;
	cellHeight = PlayerManager::getCurrentField()->getGridHeight();

	cmdDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::FleaKilled);
	sndStart = SoundManager::GetSoundCommand(SoundManager::SoundEvents::FleaSpawn);
	sndDeath = SoundManager::GetSoundCommand(SoundManager::SoundEvents::CritterDeath);
}

void Flea::Initialize(sf::Vector2f position)
{
	CritterList::insertNode(this);
	SoundManager::SendSoundPlay(sndStart);

	health = 2;
	speed = cellsPerSecond * cellHeight;
	SetAlarm(0, 1.0f / cellsPerSecond);

	Pos = position;
	Pos.y -= (MainSprite.getTextureRect().height / 2);
	Pos.x += (MainSprite.getTextureRect().width / 2);
	MainSprite.setPosition(Pos);
	
	RegisterCollision<Flea>(*this);
}

void Flea::Update()
{
	MainSprite.Update();

	Pos.y += speed * Game::FrameTime();

	if (Pos.y > WindowManager::Window().getSize().y) MarkForDestroy();

	MainSprite.setPosition(Pos);
}

void Flea::Alarm0()
{
	if (health == 2) {
		int chance = 3;
		if (rand() % chance == 0) PlayerManager::getCurrentField()->spawnMushroom(Pos.x - (MainSprite.getTextureRect().width / 2), Pos.y);
		SetAlarm(0, 1.0f / cellsPerSecond);
	}
}

void Flea::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Flea::Destroy()
{
	DeregisterCollision<Flea>(*this);
	CritterList::removeNode(this);
}

void Flea::Collision(Bullet* other)
{
	health--;
	if (health == 0) {
		ScoreManager::SendScoreCmd(cmdDeath);
		SoundManager::SendSoundPlay(sndDeath);
		ExplosionFactory::createExplosion(Pos);
		MarkForDestroy();
	}
	speed = 300;
}

Flea::~Flea()
{
	delete cmdDeath;
	delete sndDeath;
	delete sndStart;
}