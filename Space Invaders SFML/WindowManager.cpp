#include "WindowManager.h"

WindowManager::WindowManager()
{

	std::cout << "Window Manager Constructor Running" << std::endl;

	window.create(sf::VideoMode(winWidth, winHeight), winTitle, sf::Style::Close);
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	if (!Background.loadFromFile("Assets/Background.jpg"))
	{
		std::cout << "Error loading Background" << std::endl;
	}
	BackgroundSpr.setTexture(Background);
	if (!MenuBackground.loadFromFile("Assets/Menu/StartScreen.jpg"))
	{
		std::cout << "Error loading Background" << std::endl;
	}
	MenuBackgroundSpr.setTexture(MenuBackground);
	if (!WinBackground.loadFromFile("Assets/Menu/WinScreen.jpg"))
	{
		std::cout << "Error loading Background" << std::endl;
	}
	WinBackgroundSpr.setTexture(WinBackground);
	if (!LossBackground.loadFromFile("Assets/Menu/LossScreen.jpg"))
	{
		std::cout << "Error loading Background" << std::endl;
	}
	LossBackgroundSpr.setTexture(LossBackground);

	if (!font.loadFromFile("Assets/arial.ttf"))
	{
		std::cout << "Could not load UI font!" << std::endl;
	}
	else
	{
		text.setFont(font);
	}

	enemy1.spawnEnemies();

	while (window.isOpen())
	{
		if (stateManager::getState() == "Menu")
		{
			EM.pollEvents(window, player);
			window.clear();
			window.draw(MenuBackgroundSpr);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				stateManager::setState(1);
			}
		}

		if (stateManager::getState() == "Game")
		{
			window.clear(sf::Color::Magenta);
			window.draw(BackgroundSpr);
			EM.pollEvents(window, player);
			player.pollEvents();
			player.draw(window);

			enemy1.Objectcollisions(player, Audio);

			for (size_t i = 0; i < enemy1.EnemyVect.size(); i++)
			{
				enemy1.EnemyVect[i].draw(window);
				enemy1.EnemyVect[i].pollEvents();
				if (enemy1.EnemyVect[i].windowCollisions())
				{
					enemy1.EnemyVect.erase(enemy1.EnemyVect.begin() + i);
					enemy1.enemiesRemaining--;
					if (enemy1.enemiesRemaining == 0)
					{
						player.playerLose();
					}
				}
			}

			if (player.fire)
			{
					Bullet newBullet;
					newBullet.setPosition((player.getPosition().x) + 40, 700);
					bullet.bulletVect.push_back(newBullet);
					Audio.playShotSound();
					player.fire = false;
			}

			for (size_t i = 0; i < bullet.bulletVect.size(); i++)
			{
				bullet.bulletVect[i].setTexture();
				bullet.bulletVect[i].draw(window);
				bullet.bulletVect[i].pollEvents();

				if (enemy1.Objectcollisions(bullet.bulletVect[i], Audio, player) || bullet.bulletVect[i].windowCollisions())
				{
					bullet.bulletVect.erase(bullet.bulletVect.begin() + i);
				}
			}

			tempString << "Enemies remaining: " << enemy1.enemiesRemaining;
			enemiesUiTxt = tempString.str();

			text.setString(enemiesUiTxt);
			window.draw(text);
			tempString.str("");
		}

		if (stateManager::getState() == "Win")
		{
			EM.pollEvents(window, player);
			window.clear();
			window.draw(WinBackgroundSpr);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				stateManager::setState(1);
				enemy1.spawnEnemies();
			}
		}

		if (stateManager::getState() == "Loss")
		{
			EM.pollEvents(window, player);
			window.clear();
			window.draw(LossBackgroundSpr);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				stateManager::setState(1);
				enemy1.spawnEnemies();
			}
		}

		window.display();

		time = clock.getElapsedTime();
		std::cout << 1.0f / time.asSeconds() << std::endl;

		clock.restart().asSeconds();
	}
}

WindowManager::~WindowManager()
{
}
