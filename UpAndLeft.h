#ifndef _UpAndLeft
#define _UpAndLeft

#include "BaseMoveClass.h"

class UpAndLeft : public BaseMoveClass
{
public:
	UpAndLeft();
	virtual const BaseMoveClass* GetNextState(Centipede* chead) const override;
};

#endif _UpAndLeft