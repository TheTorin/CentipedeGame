#include "AIManager.h"
#include "Player.h"

AIManager::AIManager()
{
	ship = 0;
	oldX = 0;
	oldY = 0;
}

void AIManager::checkInput()
{
	sf::Vector2f currPos = ship->getPos();

	if (oldX == currPos.x) horizontal *= -1;
	if (oldY == currPos.y) vertical *= -1;

	oldX = currPos.x;
	oldY = currPos.y;

	if (horizontal == 1) ship->moveRight();
	else ship->moveLeft();

	if (vertical == 1) ship->moveDown();
	else ship->moveUp();

	ship->Fire();
}

void AIManager::getPlayer(Player* p)
{
	ship = p;
}

AIManager::~AIManager()
{

}
