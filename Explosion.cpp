#include "Explosion.h"

Explosion::Explosion()
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Explosion"), 4, 2);
	MainSprite.SetAnimation(0, 7);

	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(1, 1);

	SetDrawOrder(1600);
}

void Explosion::Initialize(sf::Vector2f position)
{
	MainSprite.setPosition(position);
}

void Explosion::Update()
{
	MainSprite.Update();
	if (MainSprite.GetFrame() >= MainSprite.GetFrameCount() - 1) MarkForDestroy();
}

void Explosion::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Explosion::Destroy()
{

}

Explosion::~Explosion()
{

}