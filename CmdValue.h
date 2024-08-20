#ifndef _CmdValue
#define _CmdValue

#include "Game Components\TEAL\CommonElements.h"
#include "CmdScore.h"

class CmdValue : public CmdScore
{
public:
	CmdValue() = delete;
	CmdValue(int points);
	CmdValue(const CmdValue&) = delete;
	CmdValue& operator=(const CmdValue&) = delete;
	~CmdValue() = default;

	virtual void Execute() override;
	virtual void TakePos(sf::Vector2f oPos) override { };

private:
	int points;
};

#endif _CmdValue