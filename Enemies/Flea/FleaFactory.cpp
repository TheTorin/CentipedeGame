#include "FleaFactory.h"
#include "Flea.h"
#include "GameAlarm.h"
#include "PlayerManager.h"

FleaFactory* FleaFactory::ptrInstance = nullptr;

void FleaFactory::privSetup()
{
	if (active) ga->fleaBegin();
}

void FleaFactory::privCheckSpawn()
{
	if (PlayerManager::getCurrentField()->getPlayerMushroom() < numShroomSpawn && !spawned) privCreateFlea();
}

void FleaFactory::privCreateFlea()
{
	if (active && !spawned) {
		sf::Vector2f pos = PlayerManager::getCurrentField()->getRandCol();

		Flea* c = pool.getFlea();

		c->SetExternalManagement(recycleFlea);
		c->Initialize(pos);

		spawned = true;
	}
}

void FleaFactory::privRecycleFlea(GameObject* go)
{
	pool.returnFlea(static_cast<Flea*>(go));
}

void FleaFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
