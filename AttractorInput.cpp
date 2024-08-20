#include "AttractorInput.h"
#include "PlayerManager.h"
#include "Level1.h"
#include "Game Components/TEAL/SceneManager.h"

AttractorInput::AttractorInput()
{
	RegisterInput(InputFlags::KeyPressed);
}

void AttractorInput::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if (k == sf::Keyboard::Num1) {
		PlayerManager::sceneEnd();
		PlayerManager::setMulti(false);
		SceneManager::ChangeScene(new Level1);
	}
	else if (k == sf::Keyboard::Num2) {
		PlayerManager::sceneEnd();
		PlayerManager::setMulti(true);
		SceneManager::ChangeScene(new Level1);
	}
}

AttractorInput::~AttractorInput()
{

}