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
	collisions();
}

void Player::playerWin()
{
	std::cout << "WINNER!!!!!" << std::endl;
	setSpeed(0);
	gameOver = true;
}

void Player::playerLose()
{
	std::cout << "LOSER!!!!!" << std::endl;
	setSpeed(0);
	gameOver = true;
}

Player::~Player()
{
}
