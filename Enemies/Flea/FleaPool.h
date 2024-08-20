#ifndef _FleaPool
#define _FleaPool

#include <stack>
class Flea;

class FleaPool
{
private:
	std::stack<Flea*> recycledItems;

public:
	FleaPool();
	FleaPool(const FleaPool&) = delete;
	FleaPool& operator=(const FleaPool&) = delete;
	~FleaPool();

	Flea* getFlea();

	void returnFlea(Flea* f);
};


#endif _FleaPool
