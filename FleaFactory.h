#ifndef _FleaFactory
#define _FleaFactory

#include "SFML/Graphics.hpp"
#include "FleaPool.h"

class GameObject;
class GameAlarm;

class FleaFactory
{
private:
	static FleaFactory* ptrInstance;

	FleaFactory() = default;
	FleaFactory(const FleaFactory&) = delete;
	FleaFactory& operator=(const FleaFactory&) = delete;
	~FleaFactory() = default;

	static FleaFactory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new FleaFactory();
		return *ptrInstance;
	};

	FleaPool pool;
	GameAlarm* ga = 0;

	bool active = false;
	bool spawned = false;
	int numShroomSpawn = 10;

	void privSetActive(bool activate) { active = activate; };
	void privSetSpawn(int num) { numShroomSpawn = num; };
	void privReceiveAlarm(GameAlarm* g) { ga = g; };

	void privCheckSpawn();
	void privSetup();
	void privCreateFlea();
	void privRecycleFlea(GameObject* b);

public:

	static void setActive(bool active) { Instance().privSetActive(active); };
	static void setSpawn(int num) { Instance().privSetSpawn(num); };
	static void receiveAlarm(GameAlarm* ga) { Instance().privReceiveAlarm(ga); };

	static void checkSpawn() { Instance().privCheckSpawn(); };
	static void setup() { Instance().privSetup(); };
	static void createFlea() { Instance().privCreateFlea(); };
	static void recycleFlea(GameObject* b) { Instance().privRecycleFlea(b); };
	static void Terminate();
};


#endif _FleaFactory