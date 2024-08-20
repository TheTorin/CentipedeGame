#include "Indestructible.h"

Indestructible::Indestructible(sf::Vector2f pos)
{
	MainSprite = sf::Sprite(ResourceManager::GetTexture("Blaster"));

	MainSprite.setOrigin(0, 0);
	MainSprite.setScale(1, 1);
	MainSprite.setPosition(pos);

	bitmap = ResourceManager::GetTextureBitmap("Blaster");
	SetCollider(MainSprite, bitmap, true);

	RegisterCollision<Indestructible>(*this);
}