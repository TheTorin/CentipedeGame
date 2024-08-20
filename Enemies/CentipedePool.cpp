#include "CentipedePool.h"
#include "Centipede.h"
#include "Game Components\TEAL\CommonElements.h"

CentipedePool::CentipedePool()
{

}

CentipedePool::~CentipedePool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Centipede* CentipedePool::getCentipede()
{
	Centipede* c;

	if (recycledItems.empty())
	{
		c = new Centipede();
	}
	else
	{
		c = recycledItems.top();
		recycledItems.pop();

		c->RegisterToCurrentScene();
	}

	return c;
}

void CentipedePool::returnCentipede(Centipede* c)
{
	recycledItems.push(static_cast<Centipede*>(c));
}
