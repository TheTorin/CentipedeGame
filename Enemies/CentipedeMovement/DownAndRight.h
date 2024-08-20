#ifndef _DownAndRight
#define _DownAndRight

#include "BaseMoveClass.h"

class DownAndRight : public BaseMoveClass
{
public:
	DownAndRight();
	virtual const BaseMoveClass* GetNextState(Centipede* chead) const override;
};

#endif _DownAndRight
