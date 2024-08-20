#include "Bullet.h"
#include "Player.h"
#include "PlayerManager.h"
#include "SndPlay.h"

Bullet::Bullet()
{
	SPEED = 900;

	MainSprite = sf::Sprite(ResourceManager::GetTexture("Bullet"));

	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(1, 1);
	MainSprite.setPosition(Pos);

	bitmap = ResourceManager::GetTextureBitmap("Bullet");
	SetCollider(MainSprite, bitmap, true);

	SetDrawOrder(1000);

	SndFire = SoundManager::GetSoundCommand(SoundManager::SoundEvents::BulletFire);
}

void Bullet::Initialize(sf::Vector2f shipPos)
{
	Pos = shipPos;
	RegisterCollision<Bullet>(*this);
	SoundManager::SendSoundPlay(SndFire);
}

void Bullet::Update() 
{
	Pos.y -= SPEED * Game::FrameTime();
	MainSprite.setPosition(Pos);

	if (Pos.y < MainSprite.getTextureRect().height) 
	{
		MarkForDestroy();
	}
}

void Bullet::Collision(Mushroom* other)
{
	MarkForDestroy();
}

void Bullet::Collision(Indestructible* other)
{
	MarkForDestroy();
}

void Bullet::Collision(Spider* other)
{
	MarkForDestroy();
}

void Bullet::Collision(Scorpion* other)
{
	MarkForDestroy();
}

void Bullet::Collision(Centipede* other)
{
	MarkForDestroy();
}

void Bullet::Collision(CentipedeBody* other)
{
	MarkForDestroy();
}


void Bullet::Destroy()
{
	Player* p = PlayerManager::getCurrentPlayer();
	if (p != NULL) p->bulletDestroyed();
	DeregisterCollision<Bullet>(*this);
}

void Bullet::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

Bullet::~Bullet()
{
	delete SndFire;
}
