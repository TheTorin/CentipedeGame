#include "UpAndRight.h"
#include "MoveList.h"
#include "MovementList.h"
#include "Centipede.h"

const UpAndRight MoveList::StateUpAndRight;

UpAndRight::UpAndRight()
{
	offsets = MovementList::OffsetsTurnUpEndRight;
}

const BaseMoveClass* UpAndRight::GetNextState(Centipede* chead) const
{
	MushroomManager* m = PlayerManager::getCurrentField();
	int width = m->getGridWidth();
	sf::Vector2f cPos = chead->getPos();

	if (cPos.x + width > WindowManager::Window().getSize().x) {
		if (m->outOfPlayerUp(cPos.y)) {
			chead->hitTop();
			return &MoveList::StateDownAndLeft;
		}
		else {
			return &MoveList::StateUpAndLeft;
		}
	}
	else {
		if (m->testForMushroom(cPos.x + width, cPos.y)) {
			if (m->outOfPlayerUp(cPos.y)) {
				return &MoveList::StateDownAndLeft;
			}
			else {
				return &MoveList::StateUpAndLeft;
			}
		}
		else {
			return &MoveList::StateRightAndUp;
		}
	}
}

