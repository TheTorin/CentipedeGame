#include "LeftAndDown.h"
#include "MoveList.h"
#include "MovementList.h"
#include "Centipede.h"

const LeftAndDown MoveList::StateLeftAndDown;

LeftAndDown::LeftAndDown()
{
	offsets = MovementList::OffsetsStraightLeft;
}

const BaseMoveClass* LeftAndDown::GetNextState(Centipede* chead) const
{
	MushroomManager* m = PlayerManager::getCurrentField();
	int width = m->getGridWidth();
	sf::Vector2f cPos = chead->getPos();

	if (cPos.x - width < 0) {
		if (m->outOfPlayerDown(cPos.y)) {
			return &MoveList::StateUpAndRight;
		}
		else {
			return &MoveList::StateDownAndRight;
		}
	}
	else {
		if (m->testForMushroom(cPos.x - width, cPos.y)) {
			if (m->testForPoison(cPos.x - width, cPos.y)) {
				return &MoveList::StatePoisonLeft;
			}
			else {
				return &MoveList::StateDownAndRight;
			}
		}
		else {
			return &MoveList::StateLeftAndDown;
		}
	}
}

