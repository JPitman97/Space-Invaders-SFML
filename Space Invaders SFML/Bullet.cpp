#include "Bullet.h"


/*This method initialises the bullet with a texture, position and scale*/
Bullet::Bullet()
{
	init("Assets/Bullet.bmp");
	setPosition(250, 700);
	setScale(1.5f, 1.5f);
	
}

/*This method sets the texture whenever it needs to be reset*/
void Bullet::setTexture()
{
	if (!Texture.loadFromFile("Assets/Bullet.bmp"))
	{
		std::cout << "Error loading texture!" << std::endl; //Debug log, not visible in game
	}

	Sprite.setTexture(Texture); //Sets the texture to the object
}

/*Handles the movement of the bullet up the screen*/
void Bullet::pollEvents()
{
	Sprite.move(0.f, -moveSpeed);
}


Bullet::~Bullet()
{
}
