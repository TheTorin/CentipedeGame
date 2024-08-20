#include "FleaPool.h"
#include "Flea.h"
#include "Game Components\TEAL\CommonElements.h"

FleaPool::FleaPool()
{

}

FleaPool::~FleaPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Flea* FleaPool::getFlea()
{
	Flea* f;

	if (recycledItems.empty())
	{
		f = new Flea();
	}
	else
	{
		f = recycledItems.top();
		recycledItems.pop();

		f->RegisterToCurrentScene();
	}

	return f;
}

void FleaPool::returnFlea(Flea* f)
{
	recycledItems.push(static_cast<Flea*>(f));

}
