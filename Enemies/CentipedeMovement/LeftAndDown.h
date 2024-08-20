#ifndef _LeftAndDown
#define _LeftAndDown

#include "BaseMoveClass.h"

class LeftAndDown : public BaseMoveClass
{
public:
	LeftAndDown();
	virtual const BaseMoveClass* GetNextState(Centipede* chead) const override;
};

#endif _LeftAndDown
