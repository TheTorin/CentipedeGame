#ifndef _CentipedePool
#define _CentipedePool

#include <stack>
class Centipede;

class CentipedePool
{
private:
	std::stack<Centipede*> recycledItems;

public:
	CentipedePool();
	CentipedePool(const CentipedePool&) = delete;
	CentipedePool& operator=(const CentipedePool&) = delete;
	~CentipedePool();

	Centipede* getCentipede();

	void returnCentipede(Centipede* c);
};


#endif _CentipedePool