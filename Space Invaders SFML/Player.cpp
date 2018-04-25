#include "Player.h"



Player::Player()
{
	std::cout << "Player Constructor Running" << std::endl;

	init("Assets/Player.png");
	setPosition(250, 725);
	setScale(.5f, .5f);
}

void Player::pollEvents()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Sprite.move(moveSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Sprite.move(-moveSpeed, 0.f);
	}

	/*else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		fire = true;
	}*/

	collisions();
}

Player::~Player()
{
}
