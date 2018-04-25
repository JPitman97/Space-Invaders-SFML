#include "Bullet.h"



Bullet::Bullet()
{

	init("Assets/Bullet.png");
	setPosition(250, 700);
	setScale(1.5f, 1.5f);
	
}

void Bullet::setTexture()
{
	if (!Texture.loadFromFile("Assets/Bullet.png"))
	{
		std::cout << "Error loading texture!" << std::endl;
	}

	Sprite.setTexture(Texture);
}

void Bullet::pollEvents()
{
	Sprite.move(0.f, -moveSpeed);
}

Bullet::~Bullet()
{
}
