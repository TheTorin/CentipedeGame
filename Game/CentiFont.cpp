#include "CentiFont.h"
#include "Game Components\TEAL\ResourceManager.h"
#include "GameManager.h"

CentiFont::CentiFont()
	: SpriteSheet(ResourceManager::GetTexture("Font"), 16, 3)
{}

int CentiFont::CharToIndex(char& c)
{
	int cellIndex = 0;

	if (c >= 'a' && c <= 'z')
		c -= 32;

	if (c >= '0' && c <= '9')
		cellIndex = (int)c - (int) '0';
	else if (c >= 'A' && c <= 'Z')
		cellIndex = (int)c - (int) 'A' + 17;
	else
		switch (c)
		{
		case ' ':	// Space
			cellIndex = 16;
			break;
		case ':':	// Colon
			cellIndex = 10;
			break;
		case '/':	// Half
			cellIndex = 11;
			break;
		case '[':	// Copyright
			cellIndex = 12;
			break;
		case ']':	// Publisher
			cellIndex = 14;
			break;
		case '~':	// Player
			cellIndex = 43;
			break;
		default:
			cellIndex = 16;
		}

	return cellIndex;
}
