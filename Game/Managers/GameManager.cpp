#include "GameManager.h"
#include "PlayerManager.h"
#include "CritterList.h"

GameManager* GameManager::ptrInstance = nullptr;

void GameManager::privInit()
{
	cFont;
}

CentiFont* GameManager::privGetCentiFont()
{
	return &cFont;
}

void GameManager::privCheckCentiDead()
{
	if (CritterList::centiAlive() || PlayerManager::playerDead()) return;
	PlayerManager::waveEnd();
	CentipedeFactory::spawnInitial();
}

void GameManager::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
