#include "CentipedeBodyFactory.h"
#include "CentipedeBody.h"

CentipedeBodyFactory* CentipedeBodyFactory::ptrInstance = nullptr;

void CentipedeBodyFactory::privCreateCentipedeBody(sf::Vector2f pos, int numSegments, Centipede* head)
{
	for (int i = 0; i < numSegments; i++) {
		CentipedeBody* c = pool.getCentipedeBody();

		c->SetExternalManagement(recycleCentipedeBody);
		c->Initialize(pos, head);
	}
}

void CentipedeBodyFactory::privRecycleCentipedeBody(GameObject* go)
{
	pool.returnCentipedeBody(static_cast<CentipedeBody*>(go));
}

void CentipedeBodyFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
