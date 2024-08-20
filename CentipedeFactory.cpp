#include "CentipedeFactory.h"
#include "CentipedeBodyFactory.h"
#include "Centipede.h"
#include "SoundManager.h"
#include "SndPlay.h"

CentipedeFactory* CentipedeFactory::ptrInstance = nullptr;

CentipedeFactory::CentipedeFactory()
{
	sndBeat = SoundManager::GetSoundCommand(SoundManager::SoundEvents::CentipedeSnd);
}

void CentipedeFactory::privSpawnInitial()
{
	SoundManager::SendSoundPlay(sndBeat);

	Centipede* c = pool.getCentipede();
	numHeads++;

	c->SetExternalManagement(recycleCentipede);

	sf::Vector2f pos = sf::Vector2f(WindowManager::Window().getView().getSize().x / 2, 0);
	c->Initialize(pos);

	CentipedeBodyFactory::createCentipedeBody(pos, startLength, c);

	for (int i = 0; i < startHeads; i++) {
		privSpawnHead();
	}
}

void CentipedeFactory::privCreateCentipede(sf::Vector2f pos)
{
	Centipede* c = pool.getCentipede();
	numHeads++;

	c->SetExternalManagement(recycleCentipede);
	c->Initialize(pos);
}

void CentipedeFactory::privSpawnHead()
{
	MushroomManager* m = PlayerManager::getCurrentField();
	sf::Vector2f row, col;
	do {
		row = m->getRandTopRow(2);
		col = m->getRandCol();
	} while (m->testForMushroom(col.x, row.y));

	privCreateCentipede(sf::Vector2f(col.x, row.y));
}

void CentipedeFactory::privSpawnFromSide()
{
	MushroomManager* m = PlayerManager::getCurrentField();
	sf::Vector2f pos;
	do {
		pos = m->getRandBotRow(6);
		if (rand() % 2 == 0) pos.x = (float) WindowManager::Window().getSize().x;
	} while (m->testForMushroom(pos.x, pos.y));

	Centipede* c = pool.getCentipede();
	numHeads++;

	c->SetExternalManagement(recycleCentipede);
	c->InitializeSide(pos);
}

void CentipedeFactory::privUpgradeCentipede(sf::Vector2f pos, CentipedeBody* prev, const BaseMoveClass* bmc)
{
	Centipede* c = pool.getCentipede();
	numHeads++;

	c->SetExternalManagement(recycleCentipede);
	c->Upgraded(pos, prev, bmc);
}

void CentipedeFactory::privRecycleCentipede(GameObject* go)
{
	pool.returnCentipede(static_cast<Centipede*>(go));

	numHeads--;
	if (numHeads == 0) SoundManager::SendSoundPause(sndBeat);
}

void CentipedeFactory::Terminate()
{
	delete Instance().sndBeat;
	delete ptrInstance;
	ptrInstance = nullptr;
}