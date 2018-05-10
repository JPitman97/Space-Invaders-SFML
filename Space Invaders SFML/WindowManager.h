#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "EventManager.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy1.h"
#include "AudioManager.h"
#include "stateManager.h"
#include <ctime>    
#include <cstdlib>
#include <sstream>

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
	sf::Texture MenuBackground;
	sf::Sprite MenuBackgroundSpr;
	sf::Texture WinBackground;
	sf::Sprite WinBackgroundSpr;
	sf::Texture LossBackground;
	sf::Sprite LossBackgroundSpr;

	sf::Font font;
	sf::Text text;
	std::stringstream tempString;
	std::string enemiesUiTxt;

	sf::Clock clock;
	sf::Time time;


	EventManager EM;
	Player player;
	Enemy1 enemy1;
	Bullet bullet;
	AudioManager Audio;
};

