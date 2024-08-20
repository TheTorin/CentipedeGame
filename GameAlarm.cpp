#include "GameAlarm.h"
#include "ScoreManager.h"
#include "SoundManager.h"
#include "PlayerManager.h"
#include "SpiderFactory.h"
#include "ScorpionFactory.h"
#include "FleaFactory.h"

GameAlarm::GameAlarm()
{
	PlayerManager::receiveAlarm(this);
	SpiderFactory::receiveAlarm(this);
	ScorpionFactory::receiveAlarm(this);
	FleaFactory::receiveAlarm(this);
}

void GameAlarm::Init()
{

}

void GameAlarm::Update()
{
	ScoreManager::ProcessScores();
	SoundManager::ProcessSounds();
}

void GameAlarm::playerRespawn()
{
	SetAlarm(0, 1);
}

void GameAlarm::spiderRespawn(float time)
{
	SetAlarm(1, time);
}

void GameAlarm::scorpionRespawn(float time)
{
	SetAlarm(2, time);
}

void GameAlarm::fleaBegin()
{
	SetAlarm(3, (float) (rand() % 2));
}

void GameAlarm::Alarm0()
{
	PlayerManager::respawnPlayer();
}

void GameAlarm::Alarm1()
{
	SpiderFactory::createSpider();
}

void GameAlarm::Alarm2()
{
	ScorpionFactory::createScorpion();
}

void GameAlarm::Alarm3()
{
	FleaFactory::checkSpawn();
	SetAlarm(3, (float) (rand() % 2));
}

GameAlarm::~GameAlarm()
{

}