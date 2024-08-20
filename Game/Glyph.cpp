#include "Glyph.h"
#include "SpriteSheet.h"
#include "Game Components\TEAL\ResourceManager.h"
#include <assert.h>

Glyph::Glyph()
{
	sprsheet = nullptr;
	cellIndex = 0;
	position = sf::Vector2f(0, 0);
}

void Glyph::Init(SpriteSheet* sheet, int cellInd, sf::Vector2f pos)
{
	sprsheet = sheet;
	position = pos;
	cellIndex = cellInd;
}

void Glyph::ReInit(int cellInd, sf::Vector2f pos)
{
	position = pos;
	cellIndex = cellInd;
}

void Glyph::RePos(sf::Vector2f pos)
{
	position = pos;
}

void Glyph::ReInd(int cellInd)
{
	cellIndex = cellInd;
}

sf::Vector2f Glyph::getPos()
{
	return position;
}

bool Glyph::isSpace()
{
	return (cellIndex == 16);
}

void Glyph::Draw()
{
	assert(sprsheet != nullptr);

	sprsheet->Draw(cellIndex, position);
}
