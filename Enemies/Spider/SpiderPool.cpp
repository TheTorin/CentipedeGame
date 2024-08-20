#include "SpiderPool.h"
#include "Spider.h"
#include "Game Components\TEAL\CommonElements.h"

SpiderPool::SpiderPool()
{

}

SpiderPool::~SpiderPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Spider* SpiderPool::getSpider()
{
	Spider* c;

	if (recycledItems.empty())
	{
		c = new Spider();
	}
	else
	{
		c = recycledItems.top();
		recycledItems.pop();

		c->RegisterToCurrentScene();
	}

	return c;
}

void SpiderPool::returnSpider(Spider* c)
{
	recycledItems.push(static_cast<Spider*>(c));
}
