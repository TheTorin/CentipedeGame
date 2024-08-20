#include "UI.h"
#include "PlayerManager.h"
#include "Glyph.h"

UI::UI()
{
	SetDrawOrder(2000);

	P1Points.changeText("0000~~");
	P2Points.changeText("0000");
	HighScore.changeText("0000");

	P1Points.drawString(P1Pos);
	P2Points.drawString(P2Pos);
	HighScore.drawString(HSPos);
}

void UI::Update()
{
	std::string s = std::to_string(PlayerManager::getCurrentPoints());
	if (PlayerManager::getCurrentLives() > 0) s.append(PlayerManager::getCurrentLives() - 1, '~');
	P1Points.changeText(s);

	s = std::to_string(PlayerManager::getOtherPoints());
	P2Points.changeText(s);

	s = std::to_string(PlayerManager::getHighScore());
	HighScore.changeText(s);
}

void UI::Draw()
{
	P1Points.drawString(P1Pos);
	P2Points.drawString(P2Pos);
	HighScore.drawString(HSPos);
}

UI::~UI()
{

}