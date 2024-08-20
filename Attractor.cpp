#include "Attractor.h"

#include "WaveClass.h"
#include "GameManager.h"
#include "GameAlarm.h"
#include "AttractorInput.h"

#include "Level1.h"

#include "UI.h"
#include "AttractorUI.h"

#include "CritterList.h"
#include "PlayerManager.h"
#include "PlayerFactory.h"
#include "Player.h"

#include "Indestructible.h"
#include "MushroomFactory.h"

#include "BulletFactory.h"
#include "Bullet.h"

#include "ScorpionFactory.h"
#include "ScorpionManager.h"

#include "FleaFactory.h"
#include "FleaManager.h"

#include "SpiderFactory.h"
#include "Spider.h"

#include "CentipedeBodyFactory.h"
#include "CentipedeFactory.h"
#include "Centipede.h"

#include "ExplosionFactory.h"
#include "RegenFactory.h"
#include "ScoreManager.h"

void Attractor::Initialize()
{
	WindowManager::SetBackgroundColor(sf::Color(0, 0, 0, 255));

	WaveClass::initData();
	WaveClass::setupWaveNum(1);
	SoundManager::Mute();

	new UI;
	new GameAlarm;
	new AttractorInput;

	GameManager::Init();
	PlayerManager::Init();
	SpiderFactory::setup();
	ScorpionFactory::setup();
	FleaFactory::setup();
	CentipedeFactory::spawnInitial();

	new AttractorUI;

	CollisionTestPair<Player, Mushroom>();
	CollisionTestPair<Bullet, Mushroom>();
	CollisionTestPair<Bullet, Indestructible>();
	CollisionTestPair<Bullet, Spider>();
	CollisionTestPair<Player, Spider>();
	CollisionTestPair<Mushroom, Spider>();
	CollisionTestPair<Bullet, Flea>();
	CollisionTestPair<Player, Flea>();
	CollisionTestPair<Scorpion, Mushroom>();
	CollisionTestPair<Scorpion, Bullet>();
	CollisionTestPair<Centipede, Bullet>();
	CollisionTestPair<Centipede, Player>();
	CollisionTestPair<CentipedeBody, Player>();
	CollisionTestPair<CentipedeBody, Bullet>();
}

void Attractor::Terminate()
{

}