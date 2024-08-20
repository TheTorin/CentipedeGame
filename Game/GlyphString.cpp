#include "GlyphString.h"
#include "GameManager.h"
#include "PlayerManager.h"
#include "MushroomManager.h"

GlyphString::GlyphString(std::string s)
{
	CentiFont* cFont = GameManager::getCentiFont();

	for (int i = 0; i < (int) s.length(); i++) {
		glyphs.push_back(cFont->GetGlyph(s.at(i), sf::Vector2f(0, 0)));
	}
}

void GlyphString::changeText(std::string s)
{
	CentiFont* cFont = GameManager::getCentiFont();
	if (s.length() == glyphs.size()) {
		for (int i = 0; i < (int) glyphs.size(); i++) {
			glyphs.at(i).ReInd(cFont->CharToIndex(s.at(i)));
		}
	}
	else {
		glyphs.clear();
		for (int i = 0; i < (int) s.length(); i++) {
			glyphs.push_back(cFont->GetGlyph(s.at(i), sf::Vector2f(0, 0)));
		}
	}
}

void GlyphString::deleteLast()
{
	glyphs.pop_back();
}

void GlyphString::drawString(sf::Vector2f pos)
{
	int width = GameManager::getCentiFont()->CellWidth();

	for (int i = 0; i < (int) glyphs.size(); i++) {
		glyphs.at(i).RePos(pos);
		glyphs.at(i).Draw();
		pos.x += width;
	}
}

void GlyphString::drawString()
{
	for (int i = 0; i < (int) glyphs.size(); i++) {
		glyphs.at(i).Draw();
	}
}

void GlyphString::drawNoSpaces()
{
	for (int i = 0; i < (int) glyphs.size(); i++) {
		if (!glyphs.at(i).isSpace()) glyphs.at(i).Draw();
	}
}

void GlyphString::registerGlyphs(sf::Vector2f pos)
{
	int width = GameManager::getCentiFont()->CellWidth();
	MushroomManager* m = PlayerManager::getCurrentField();

	for (int i = 0; i < (int) glyphs.size(); i++) {
		glyphs.at(i).RePos(pos);
		glyphs.at(i).Draw();
		if (!glyphs.at(i).isSpace()) m->spawnBlocker(pos.x, pos.y);
		pos.x += width;
	}
}

GlyphString::~GlyphString()
{
	glyphs.clear();
}
