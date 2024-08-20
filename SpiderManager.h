#ifndef _SpiderManager
#define _SpiderManager

#include "Game Components\TEAL\CommonElements.h"

class SpiderManager : GameObject
{
public:
	SpiderManager();
	SpiderManager(const SpiderManager&) = delete;
	SpiderManager& operator=(const SpiderManager&) = delete;
	~SpiderManager();

	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);

private:
};

#endif _SpiderManager