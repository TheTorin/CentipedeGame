#include "LeftAndUp.h"
#include "MoveList.h"
#include "MovementList.h"
#include "Centipede.h"

const LeftAndUp MoveList::StateLeftAndUp;

LeftAndUp::LeftAndUp()
{
	offsets = MovementList::OffsetsStraightLeft;
}

const BaseMoveClass* LeftAndUp::GetNextState(Centipede* chead) const
{
	MushroomManager* m = PlayerManager::getCurrentField();
	int width = m->getGridWidth();
	sf::Vector2f cPos = chead->getPos();

	if (cPos.x - width < 0) {
		if (m->outOfPlayerUp(cPos.y)) {
			return &MoveList::StateDownAndRight;
		}
		else {
			return &MoveList::StateUpAndRight;
		}
	}
	else {
		if (m->testForMushroom(cPos.x - width, cPos.y)) {
			if (m->outOfPlayerUp(cPos.y)) {
				return &MoveList::StateDownAndRight;
			}
			else {
				return &MoveList::StateUpAndRight;
			}
		}
		else {
			return &MoveList::StateLeftAndUp;
		}
	}
}

