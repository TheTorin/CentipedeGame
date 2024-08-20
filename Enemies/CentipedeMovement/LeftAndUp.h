#ifndef _LeftAndUp
#define _LeftAndUp

#include "BaseMoveClass.h"

class LeftAndUp : public BaseMoveClass
{
public:
	LeftAndUp();
	virtual const BaseMoveClass* GetNextState(Centipede* chead) const override;
};

#endif _LeftAndUp
