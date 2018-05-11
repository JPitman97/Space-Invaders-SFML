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
	sf::Texture InstructionBackground;
	sf::Sprite InstructionBackgroundSpr;
	sf::Texture transparentBG;
	sf::Sprite transparentSpr;
	sf::Sprite transparentSpr2;
	sf::Sprite transparentSpr3;

	sf::Font font;
	sf::Font menuFont;
	sf::Text beginTxtBtn;
	sf::Text InstructionsTxtBtn;
	sf::Text EndTxtBtn;
	sf::Text enemiesUI;
	sf::Text fpsUI;
	std::stringstream tempString;
	std::string enemiesUiTxt;
	std::string FPSUiTxt;

	sf::Clock clock;
	sf::Time time;


	EventManager EM;
	Player player;
	Enemy1 enemy1;
	Bullet bullet;
	AudioManager Audio;
};

