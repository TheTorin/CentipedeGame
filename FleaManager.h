#ifndef _FleaManager
#define _FleaManager

#include "Game Components\TEAL\CommonElements.h"
#include "Flea.h"

class FleaFactory;
class MushroomManager;

class FleaManager : public GameObject
{
public:
	FleaManager();
	FleaManager(const FleaManager&) = delete;
	FleaManager& operator=(const FleaManager&) = delete;
	~FleaManager();

	//virtual void Alarm0();
	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);

private:

};

#endif _FleaManager