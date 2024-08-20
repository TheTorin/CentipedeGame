#ifndef _CmdDistance
#define _CmdDistance

#include "Game Components\TEAL\CommonElements.h"
#include "CmdScore.h"

class CmdDistance : public CmdScore
{
public:
	CmdDistance() = delete;
	CmdDistance(int rNear, int rMid, int rFar, int sNear, int sMid, int sFar);
	CmdDistance(const CmdDistance&) = delete;
	CmdDistance& operator=(const CmdDistance&) = delete;
	~CmdDistance() = default;

	virtual void Execute() override;
	virtual void TakePos(sf::Vector2f Pos) override;

private:
	sf::Vector2f otherPos;
	int rNear;
	int rMid;
	int rFar;
	int sNear;
	int sMid;
	int sFar;
};

#endif _CmdDistance
