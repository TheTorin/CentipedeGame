#ifndef _DownAndLeft
#define _DownAndLeft

#include "BaseMoveClass.h"

class DownAndLeft : public BaseMoveClass
{
public:
	DownAndLeft();
	virtual const BaseMoveClass* GetNextState(Centipede* chead) const override;
};

#endif _DownAndLeft
