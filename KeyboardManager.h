#ifndef _KeyboardManager
#define _KeyboardManager

#include "Game Components\TEAL\CommonElements.h"
#include "InputManager.h"

class Player;

class KeyboardManager : public InputManager
{
public:
	KeyboardManager();
	KeyboardManager(const KeyboardManager&) = delete;
	KeyboardManager& operator=(const KeyboardManager&) = delete;
	~KeyboardManager();

	void checkInput() override;
	void getPlayer(Player* p) override;

private:
	Player* ship;
};

#endif _KeyboardManager