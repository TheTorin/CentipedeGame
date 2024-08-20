#ifndef _UI
#define _UI

#include "Game Components\TEAL\CommonElements.h"
#include "GlyphString.h"

class UI : public GameObject
{
public:
	UI();
	UI(const UI&) = delete;
	UI& operator=(const UI&) = delete;
	~UI();

	virtual void Update();
	virtual void Draw();

private:
	GlyphString P1Points;
	GlyphString P2Points;
	GlyphString HighScore;

	sf::Vector2f P1Pos = sf::Vector2f(32, 0);
	sf::Vector2f P2Pos = sf::Vector2f(400, 0);
	sf::Vector2f HSPos = sf::Vector2f(216, 0);
};

#endif _UI
