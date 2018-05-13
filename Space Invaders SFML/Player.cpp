#include "Player.h"



Player::Player()
{
	std::cout << "Player Constructor Running" << std::endl; //Debug log to check if the constructor runs, not visible in actual gameplay
	/*Sets the initial values of the player, including the texture, position and scale, which are sent to the Entity Manager class which this inherits from*/
	init("Assets/Player.bmp");
	setPosition(250, 725);
	setScale(.5f, .5f);
}

/*Handles player events such as key presses to move the player or collisions such as against the screen border*/
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
	windowCollisions();
}

/*Handles whether the player has won, if so changes the current game state, debug text is hidden during gameplay*/
void Player::playerWin()
{
	std::cout << "WINNER!!!!!" << std::endl;
	stateManager::setState(2);
}

/*Handles whether the player has won, if so changes the current game state, debug text is hidden during gameplay*/
void Player::playerLose()
{
	std::cout << "LOSER!!!!!" << std::endl;
	stateManager::setState(3);
}

Player::~Player()
{
}
