#ifndef _BaseBlocker
#define _BaseBlocker

#include "Game Components\TEAL\CommonElements.h"

class BaseBlocker : public GameObject
{
public:
	BaseBlocker() = default;				// Private constructor 
	BaseBlocker& operator=(const BaseBlocker&);	// Prevent assignment
	~BaseBlocker() = default;

	virtual void regen() = 0;
	virtual bool isPoisoned() { return false; };
	virtual int getHealth() { return 3; };

private:

};

#endif _BaseBlocker