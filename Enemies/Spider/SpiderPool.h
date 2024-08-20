#ifndef _SpiderPool
#define _SpiderPool

#include <stack>
class Spider;

class SpiderPool
{
private:
	std::stack<Spider*> recycledItems;

public:
	SpiderPool();
	SpiderPool(const SpiderPool&) = delete;
	SpiderPool& operator=(const SpiderPool&) = delete;
	~SpiderPool();

	Spider* getSpider();

	void returnSpider(Spider* c);
};


#endif _SpiderPool
