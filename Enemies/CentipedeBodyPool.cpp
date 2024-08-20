#include "CentipedeBodyPool.h"
#include "CentipedeBody.h"
#include "Game Components\TEAL\CommonElements.h"

CentipedeBodyPool::CentipedeBodyPool()
{

}

CentipedeBodyPool::~CentipedeBodyPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

CentipedeBody* CentipedeBodyPool::getCentipedeBody()
{
	CentipedeBody* c;

	if (recycledItems.empty())
	{
		c = new CentipedeBody();
	}
	else
	{
		c = recycledItems.top();
		recycledItems.pop();

		c->RegisterToCurrentScene();
	}

	return c;
}

void CentipedeBodyPool::returnCentipedeBody(CentipedeBody* c)
{
	recycledItems.push(static_cast<CentipedeBody*>(c));
}
