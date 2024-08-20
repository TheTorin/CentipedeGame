#ifndef _CentipedeFactory
#define _CentipedeFactory

#include "SFML/Graphics.hpp"
#include "CentipedePool.h"

class GameObject;
class MushroomManager;
class CentipedeBody;
class BaseMoveClass;
class SndPlay;

class CentipedeFactory
{
private:
	static CentipedeFactory* ptrInstance;

	CentipedeFactory();
	CentipedeFactory(const CentipedeFactory&) = delete;
	CentipedeFactory& operator=(const CentipedeFactory&) = delete;
	~CentipedeFactory() = default;

	static CentipedeFactory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new CentipedeFactory();
		return *ptrInstance;
	};

	CentipedePool pool;

	SndPlay* sndBeat = 0;

	int startLength = 10;
	int startHeads = 0;

	int centiSpeed = 2;
	int headSpeed = 4;

	int numHeads = 0;

	void privSetLength(int length) { startLength = length; };
	void privSetHeads(int num) { startHeads = num; };
	void privSetCentiSpeed(int num) { centiSpeed = num; };
	void privSetHeadSpeed(int num) { headSpeed = num; };

	int privGetCentiSpeed() { return centiSpeed; };
	int privGetHeadSpeed() { return headSpeed; };

	void privSpawnHead();
	void privSpawnFromSide();
	void privUpgradeCentipede(sf::Vector2f pos, CentipedeBody* prev, const BaseMoveClass* bmc);
	void privCreateCentipede(sf::Vector2f pos);
	void privRecycleCentipede(GameObject* b);
	void privSpawnInitial();

public:
	static void setLength(int length) { Instance().privSetLength(length); };
	static void setHeads(int num) { Instance().privSetHeads(num); };
	static void setCentiSpeed(int num) { Instance().privSetCentiSpeed(num); };
	static void setHeadSpeed(int num) { Instance().privSetHeadSpeed(num); };

	static int getCentiSpeed() { return Instance().privGetCentiSpeed(); };
	static int getHeadSpeed() { return Instance().privGetHeadSpeed(); };

	static void upgradeCentipede(sf::Vector2f pos, CentipedeBody* prev, const BaseMoveClass* bmc) { Instance().privUpgradeCentipede(pos, prev, bmc); };
	static void createCentipede(sf::Vector2f pos) { Instance().privCreateCentipede(pos); };
	static void recycleCentipede(GameObject* b) { Instance().privRecycleCentipede(b); };
	static void spawnInitial() { Instance().privSpawnInitial(); };
	static void spawnFromSide() { Instance().privSpawnFromSide(); };
	static void Terminate();
};


#endif _CentipedeFactory