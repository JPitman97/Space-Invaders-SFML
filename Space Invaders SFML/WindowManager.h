#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "EventManager.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy1.h"

class WindowManager
{
public:
	WindowManager();
	~WindowManager();

protected:
	sf::RenderWindow window;

private:
	const uint16_t winWidth = 600;
	const uint16_t winHeight = 800;
	const std::string winTitle = "Space Invaders Clone!";

	sf::Texture Background;
	sf::Sprite BackgroundSpr;	

	sf::Clock clock;
	sf::Time time;


	EventManager EM;
	Player player;
	Enemy1 enemy1;
	Bullet bullet;
};

