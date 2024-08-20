#include "SpiderFactory.h"
#include "SpiderManager.h"

SpiderManager::SpiderManager()
{
	RegisterInput(InputFlags::KeyPressed);
}

void SpiderManager::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if (k == sf::Keyboard::P) {
		SpiderFactory::createSpider();
	}
}

SpiderManager::~SpiderManager()
{

}