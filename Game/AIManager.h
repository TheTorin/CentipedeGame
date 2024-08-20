#ifndef _AIManager
#define _AIManager

#include "Game Components\TEAL\CommonElements.h"
#include "InputManager.h"

class Player;

class AIManager : public InputManager
{
public:
	AIManager();
	AIManager(const AIManager&) = delete;
	AIManager& operator=(const AIManager&) = delete;
	~AIManager();

	void checkInput() override;
	void getPlayer(Player* p) override;

private:
	Player* ship;
	float oldX;
	float oldY;
	int horizontal = -1;
	int vertical = -1;
};

#endif _AIManager
