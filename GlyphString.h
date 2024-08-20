#ifndef _GlyphString
#define _GlyphString

#include <vector>
#include "Game Components\TEAL\CommonElements.h"
class Glyph;

class GlyphString
{
public:
	GlyphString() = default;
	GlyphString(const GlyphString&) = delete;
	GlyphString& operator=(const GlyphString&) = delete;
	~GlyphString();

	GlyphString(std::string s);

	void changeText(std::string s);
	void deleteLast();
	void drawString(sf::Vector2f pos);
	void drawString();
	void drawNoSpaces();

	void registerGlyphs(sf::Vector2f pos);

private:
	std::vector<Glyph> glyphs;
};


#endif _GlyphString
