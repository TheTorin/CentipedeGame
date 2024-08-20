#ifndef _UpAndRight
#define _UpAndRight

#include "BaseMoveClass.h"

class UpAndRight : public BaseMoveClass
{
public:
	UpAndRight();
	virtual const BaseMoveClass* GetNextState(Centipede* chead) const override;
};

#endif _UpAndRight