#include "FleaManager.h"
#include "FleaFactory.h"
#include "MushroomManager.h"
#include "GameManager.h"

FleaManager::FleaManager()
{
	RegisterInput(InputFlags::KeyPressed);
}

void FleaManager::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if (k == sf::Keyboard::F) {
		FleaFactory::createFlea();
	}
}

FleaManager::~FleaManager()
{

}