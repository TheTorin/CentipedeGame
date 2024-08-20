#ifndef _SpiderFactory
#define _SpiderFactory

#include "SFML/Graphics.hpp"
#include "SpiderPool.h"
#include "SpiderManager.h"

class GameObject;
class GameAlarm;
class SndPlay;

class SpiderFactory
{
private:
	static SpiderFactory* ptrInstance;

	SpiderFactory();
	SpiderFactory(const SpiderFactory&) = delete;
	SpiderFactory& operator=(const SpiderFactory&) = delete;
	~SpiderFactory() = default;

	static SpiderFactory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new SpiderFactory();
		return *ptrInstance;
	};

	SpiderPool pool;
	GameAlarm* ga = 0;
	SndPlay* sndSpider = 0;

	bool active = false;
	bool spawned = false;
	int spiderSpeed = 100;
	int spawnRate = 10;


	void privActivateSpawner(bool activate) { active = activate; };
	void privSetSpeed(int speed) { spiderSpeed = speed; };
	void privSetSpawnRate(int rate) { spawnRate = rate; };
	void privReceiveAlarm(GameAlarm* g) { ga = g; };

	void privSetup();
	void privCreateSpider();
	void privRecycleSpider(GameObject* b);

public:

	static void setActive(bool active) { Instance().privActivateSpawner(active); };
	static void setSpeed(int speed) { Instance().privSetSpeed(speed); };
	static void setSpawnRate(int rate) { Instance().privSetSpawnRate(rate); };
	static void receiveAlarm(GameAlarm* ga) { Instance().privReceiveAlarm(ga); };

	static void setup() { Instance().privSetup(); };
	static void createSpider() { Instance().privCreateSpider(); };
	static void recycleSpider(GameObject* b) { Instance().privRecycleSpider(b); };
	static void Terminate();
};


#endif _SpiderFactory
