#include "SpriteSheet.h"
#include "Game Components\TEAL\WindowManager.h" 

SpriteSheet::SpriteSheet(sf::Texture& tex, int CellCountHor, int CellCountVert)
{
	MainSprite = sf::Sprite(tex);

	// Rectangle dimension corresponding to a single cell of the sprite sheet
	cellWidth = tex.getSize().x / CellCountHor;
	cellHeight = tex.getSize().y / CellCountVert;

	cells.resize(CellCountHor * CellCountVert);

	// Determine the rectangle for each cell
	int left;
	int top;
	for (int j = 0; j < CellCountVert; j++)
	{
		top = j * cellHeight;
		for (int i = 0; i < CellCountHor; i++)
		{
			left = i * cellWidth;
			cells[j * CellCountHor + i] = sf::IntRect(left, top, cellWidth, cellHeight);
		}
	}
}

int SpriteSheet::CellWidth() {
	return cellWidth;
}

int SpriteSheet::CellHeight() {
	return cellHeight;
}

Glyph SpriteSheet::GetGlyph(char c, sf::Vector2f pos)
{
	Glyph g;
	g.Init(this, CharToIndex(c), pos);
	return g;
}

void SpriteSheet::Draw(int i, sf::Vector2f pos)
{
	MainSprite.setTextureRect(cells[i]);	
	MainSprite.setPosition(pos);
	WindowManager::Window().draw(MainSprite);
}
