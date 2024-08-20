#ifndef _MoveList
#define _MoveList

#include "LeftAndDown.h"
#include "LeftAndUp.h"
#include "RightAndDown.h"
#include "RightAndUp.h"
#include "UpAndLeft.h"
#include "UpAndRight.h"
#include "DownAndLeft.h"
#include "DownAndRight.h"
#include "Nothing.h"
#include "PoisonAndLeft.h"
#include "PoisonAndRight.h"

class MoveList
{
public:
	static const RightAndUp StateRightAndUp;
	static const RightAndDown StateRightAndDown;
	static const UpAndRight StateUpAndRight;
	static const DownAndRight StateDownAndRight;
	static const LeftAndUp StateLeftAndUp;
	static const LeftAndDown StateLeftAndDown;
	static const UpAndLeft StateUpAndLeft;
	static const DownAndLeft StateDownAndLeft;
	static const Nothing StateNothing;
	static const PoisonAndLeft StatePoisonLeft;
	static const PoisonAndRight StatePoisonRight;
};

#endif _MoveList
