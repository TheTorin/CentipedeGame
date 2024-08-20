#include "CmdDistance.h"
#include "ScoreManager.h"
#include "PlayerManager.h"
#include "Player.h"

CmdDistance::CmdDistance(int rn, int rm, int rf,
	int sn, int sm, int sf)
	: rNear(rn), rMid(rm), rFar(rf), sNear(sn), sMid(sm), sFar(sf)
{

}

void CmdDistance::TakePos(sf::Vector2f oPos)
{
	otherPos = oPos;
}

void CmdDistance::Execute()
{
	sf::Vector2f shipPos = PlayerManager::getCurrentPlayer()->getPos();
	float sX = shipPos.x - otherPos.x;
	float sY = shipPos.y - otherPos.y;
	float distance = sqrt(sX*sX + sY*sY);

	if (distance <= rNear) ScoreManager::AddScore(sNear);
	else if (distance <= rMid) ScoreManager::AddScore(sMid);
	else ScoreManager::AddScore(sFar);
}