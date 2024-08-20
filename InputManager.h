#ifndef _InputManager
#define _InputManager

#include "Game Components\TEAL\CommonElements.h"

class Player;

class InputManager
{
public:
	InputManager();
	InputManager(const InputManager&) = delete;
	InputManager& operator=(const InputManager&) = delete;
	~InputManager();

	virtual void getPlayer(Player* p) = 0;
	virtual void checkInput() = 0;

private:
};

#endif _InputManager