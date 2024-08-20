#ifndef _GameManagerFactory
#define _GameManagerFactory

#include "SFML/Graphics.hpp"
#include "MushroomManager.h"
#include "centiFont.h"
#include "WaveClass.h"
#include "CentipedeFactory.h"

class GameObject;

class GameManager
{
private:
	static GameManager* ptrInstance;

	GameManager() = default;
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;
	~GameManager() = default;

	static GameManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new GameManager();
		return *ptrInstance;
	};

	CentiFont cFont;

	void privInit();
	CentiFont* privGetCentiFont();
	void privCheckCentiDead();

public:

	static void Init() { Instance().privInit(); };
	static CentiFont* getCentiFont() { return Instance().privGetCentiFont(); };
	static void checkCentiDead() { Instance().privCheckCentiDead(); };
	static void Terminate();
};


#endif _GameManagerFactory