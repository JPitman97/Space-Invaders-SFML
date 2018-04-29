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

	enemy1.spawnEnemies();


	while (window.isOpen())
	{
		EM.pollEvents(window, player);

		window.clear(sf::Color::Magenta);
		window.draw(BackgroundSpr);
		player.pollEvents();
		player.draw(window);

		enemy1.Objectcollisions(player, Audio);

		for (size_t i = 0; i < enemy1.EnemyVect.size(); i++)
		{
			enemy1.EnemyVect[i].draw(window);
			enemy1.EnemyVect[i].pollEvents();
			if (enemy1.EnemyVect[i].collisions())
			{
				enemy1.EnemyVect.erase(enemy1.EnemyVect.begin() + i);
				if (enemy1.EnemyVect.empty())
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

			if (enemy1.Objectcollisions(bullet.bulletVect[i], Audio, player) || bullet.bulletVect[i].collisions())
			{
				bullet.bulletVect.erase(bullet.bulletVect.begin() + i);
			}
		}

		window.display();

		time = clock.getElapsedTime();
		//std::cout << 1.0f / time.asSeconds() << std::endl;

		clock.restart().asSeconds();
	}
}

WindowManager::~WindowManager()
{
}
