#ifndef _AttractorUI
#define _AttractorUI

#include "Game Components\TEAL\CommonElements.h"
#include "GlyphString.h"

class AttractorUI : public GameObject
{
public:
	AttractorUI();
	AttractorUI(const AttractorUI&) = delete;
	AttractorUI& operator=(const AttractorUI&) = delete;
	~AttractorUI();

	virtual void Update();
	virtual void Draw();

private:
	GlyphString TopText;
	GlyphString scores[8];
	GlyphString lifeInfo;
	GlyphString copyright;

	sf::Vector2f TopPos = sf::Vector2f(160, 48);
	sf::Vector2f scorePos[8];
	sf::Vector2f lifePos = sf::Vector2f(16, 208);
	sf::Vector2f copyPos = sf::Vector2f(160, 496);
};

#endif _AttractorUI