#ifndef _BaseMoveClass
#define _BaseMoveClass

#include "Game Components\TEAL\CommonElements.h"
#include "MushroomManager.h"

struct OffsetArray;
class Centipede;

class BaseMoveClass
{
public:
	BaseMoveClass() {};
	const OffsetArray* GetMoveOffsets() const { return offsets; }
	virtual const BaseMoveClass* GetNextState(Centipede* chead) const = 0;

protected:
	const OffsetArray* offsets = 0;
};

#endif _BaseMoveClass
