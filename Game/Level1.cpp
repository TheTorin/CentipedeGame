#include "Game Components\TEAL\CommonElements.h"

#include "WaveClass.h"
#include "GameManager.h"
#include "GameAlarm.h"

#include "Level1.h"

#include "UI.h"

#include "CritterList.h"
#include "PlayerManager.h"
#include "PlayerFactory.h"
#include "Player.h"

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

void Level1::Initialize()
{
	WindowManager::SetBackgroundColor(sf::Color(0, 0, 0, 255));

	WaveClass::setupWaveNum(1);
	SoundManager::Unmute();

	new UI;
	new GameAlarm;

	PlayerManager::gameStart();
	SpiderFactory::setup();
	ScorpionFactory::setup();
	FleaFactory::setup();
	CentipedeFactory::spawnInitial();

	CollisionTestPair<Player, Mushroom>();
	CollisionTestPair<Bullet, Mushroom>();
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
};

void Level1::Terminate()
{

}
