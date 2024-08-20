#include "DownAndRight.h"
#include "MoveList.h"
#include "MovementList.h"
#include "Centipede.h"

const DownAndRight MoveList::StateDownAndRight;

DownAndRight::DownAndRight()
{
	offsets = MovementList::OffsetsTurnDownEndRight;
}

const BaseMoveClass* DownAndRight::GetNextState(Centipede* chead) const
{
	MushroomManager* m = PlayerManager::getCurrentField();
	int width = m->getGridWidth();
	sf::Vector2f cPos = chead->getPos();

	if (cPos.x + width > WindowManager::Window().getSize().x) {
		if (m->outOfPlayerDown(cPos.y)) {
			return &MoveList::StateUpAndLeft;
		}
		else {
			return &MoveList::StateDownAndLeft;
		}
	}
	else {
		if (m->testForMushroom(cPos.x + width, cPos.y)) {
			if (m->testForPoison(cPos.x + width, cPos.y)) {
				return &MoveList::StatePoisonRight;
			}
			else {
				return &MoveList::StateDownAndLeft;
			}
		}
		else {
			return &MoveList::StateRightAndDown;
		}
	}
}

