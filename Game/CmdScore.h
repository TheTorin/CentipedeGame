#ifndef _CmdScore
#define _CmdScore

#include "Game Components\TEAL\CommonElements.h"

class CmdScore
{
public:
	CmdScore() = default;
	CmdScore(const CmdScore&) = delete;
	CmdScore& operator=(const CmdScore&) = delete;
	~CmdScore() = default;

	virtual void Execute() = 0;
	virtual void TakePos(sf::Vector2f Pos) = 0;

private:
};

#endif _CmdScore
