#ifndef _AttractorInput
#define _AttractorInput

#include "Game Components\TEAL\CommonElements.h"

class AttractorInput : public GameObject
{
public:
	AttractorInput();
	AttractorInput(const AttractorInput&) = delete;
	AttractorInput& operator=(const AttractorInput&) = delete;
	~AttractorInput();

	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);

private:
};

#endif _AttractorInput
