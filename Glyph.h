#ifndef _Glyph
#define _Glyph

#include "SFML\Graphics.hpp"
#include "BaseBlocker.h"

class SpriteSheet;

class Glyph
{
private:
	SpriteSheet* sprsheet;
	int cellIndex;
	sf::Vector2f position;

public:
	Glyph();
	Glyph& operator=(const Glyph&) = delete;
	~Glyph() = default;

	void Init(SpriteSheet* sheet, int cellInd, sf::Vector2f pos);
	sf::Vector2f getPos();
	void ReInit(int cellInd, sf::Vector2f pos);
	void ReInd(int cellInd);
	void RePos(sf::Vector2f pos);
	void Draw();
	bool isSpace();
};


#endif _Glyph