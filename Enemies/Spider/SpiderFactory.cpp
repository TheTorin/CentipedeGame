#include "SpiderFactory.h"
#include "Spider.h"
#include "GameAlarm.h"
#include "SoundManager.h"
#include "SndPlay.h"

SpiderFactory* SpiderFactory::ptrInstance = nullptr;

SpiderFactory::SpiderFactory()
{
	sndSpider = SoundManager::GetSoundCommand(SoundManager::SoundEvents::SpiderSnd);
}

void SpiderFactory::privSetup()
{
	float time = (float) (rand() % spawnRate);
	ga->spiderRespawn(time);
}

void SpiderFactory::privCreateSpider()
{
	if (active && !spawned) {
		Spider* c = pool.getSpider();

		c->SetExternalManagement(recycleSpider);
		c->Initialize(spiderSpeed);

		spawned = true;
		SoundManager::SendSoundPlay(sndSpider);
	}
}

void SpiderFactory::privRecycleSpider(GameObject* go)
{
	pool.returnSpider(static_cast<Spider*>(go));

	SoundManager::SendSoundPause(sndSpider);
	spawned = false;
	float time = (float) (rand() % spawnRate);
	ga->spiderRespawn(time);
}

void SpiderFactory::Terminate()
{
	delete Instance().sndSpider;
	delete ptrInstance;
	ptrInstance = nullptr;
}
