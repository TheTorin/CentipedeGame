#include "CmdValue.h"
#include "ScoreManager.h"

CmdValue::CmdValue(int val)
	: points(val)
{

}

void CmdValue::Execute()
{
	ScoreManager::AddScore(points);
}
