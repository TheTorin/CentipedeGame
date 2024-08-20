#include "AttractorUI.h"
#include "PlayerManager.h"
#include "Glyph.h"

AttractorUI::AttractorUI()
{
	SetDrawOrder(2000);

	MushroomManager* m = PlayerManager::getCurrentField();

	TopText.changeText("High Scores");
	TopText.drawString(TopPos);
	TopText.registerGlyphs(TopPos);

	for (int i = 0; i < 8; i++) {
		scorePos[i] = sf::Vector2f(176.0f, (float) (64 + (i * 16)));

		std::string num = std::to_string(PlayerManager::getTopScores(i));
		std::string format = std::string(5 - num.length(), '0') + num;

		std::string name = PlayerManager::getTopNames(i);
		scores[i].changeText(format + " " + name);
		scores[i].drawString(scorePos[i]);
		scores[i].registerGlyphs(scorePos[i]);
	}

	lifeInfo.changeText("Extra Life Every 12000 Points");
	lifeInfo.drawString(lifePos);
	lifeInfo.registerGlyphs(lifePos);

	copyright.changeText("[1980 Atari");
	copyright.drawString(copyPos);
	copyright.registerGlyphs(copyPos);
}

void AttractorUI::Update()
{

}

void AttractorUI::Draw()
{
	TopText.drawNoSpaces();
	for (int i = 0; i < 8; i++) {
		scores[i].drawNoSpaces();
	}
	lifeInfo.drawNoSpaces();
	copyright.drawNoSpaces();
}

AttractorUI::~AttractorUI()
{
	
}
