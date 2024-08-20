#ifndef _CentipedeBodyPool
#define _CentipedeBodyPool

#include <stack>
class CentipedeBody;

class CentipedeBodyPool
{
private:
	std::stack<CentipedeBody*> recycledItems;

public:
	CentipedeBodyPool();
	CentipedeBodyPool(const CentipedeBodyPool&) = delete;
	CentipedeBodyPool& operator=(const CentipedeBodyPool&) = delete;
	~CentipedeBodyPool();

	CentipedeBody* getCentipedeBody();

	void returnCentipedeBody(CentipedeBody* c);
};


#endif _CentipedeBodyPool