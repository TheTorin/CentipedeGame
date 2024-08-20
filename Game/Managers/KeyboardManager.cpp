#include "KeyboardManager.h"
#include "SoundManager.h"
#include "Player.h"

KeyboardManager::KeyboardManager()
{
	ship = 0;
}

void KeyboardManager::checkInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		ship->moveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		ship->moveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		ship->moveDown();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		ship->moveRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		ship->Fire();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
		SoundManager::Mute();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
		SoundManager::Unmute();
	}
}

void KeyboardManager::getPlayer(Player* p)
{
	ship = p;
}

KeyboardManager::~KeyboardManager()
{

}
