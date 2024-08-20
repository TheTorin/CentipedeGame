#ifndef _CentipedeBodyFactory
#define _CentipedeBodyFactory

#include "SFML/Graphics.hpp"
#include "CentipedeBodyPool.h"
class GameObject;
class Centipede;

class CentipedeBodyFactory
{
private:
	static CentipedeBodyFactory* ptrInstance;

	CentipedeBodyFactory() = default;
	CentipedeBodyFactory(const CentipedeBodyFactory&) = delete;
	CentipedeBodyFactory& operator=(const CentipedeBodyFactory&) = delete;
	~CentipedeBodyFactory() = default;

	static CentipedeBodyFactory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new CentipedeBodyFactory();
		return *ptrInstance;
	};

	CentipedeBodyPool pool;

	void privCreateCentipedeBody(sf::Vector2f pos, int numSegments, Centipede* c);
	void privRecycleCentipedeBody(GameObject* b);

public:

	static void createCentipedeBody(sf::Vector2f pos, int numSegments, Centipede* c) { Instance().privCreateCentipedeBody(pos, numSegments, c); };
	static void recycleCentipedeBody(GameObject* b) { Instance().privRecycleCentipedeBody(b); };
	static void Terminate();
};


#endif _CentipedeBodyFactory
