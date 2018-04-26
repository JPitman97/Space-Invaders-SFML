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

	std::vector<Bullet> bulletVect;

	while (window.isOpen())
	{
		EM.pollEvents(window, player);

		window.clear(sf::Color::Magenta);
		window.draw(BackgroundSpr);
		player.pollEvents();
		player.draw(window);
		if (player.fire)
		{
			Bullet newBullet;
			newBullet.setPosition((player.getPosition().x) + 40, 700);
			bulletVect.push_back(newBullet);
			player.fire = false;
		}

		for (size_t i = 0; i < bulletVect.size(); i++)
		{
			bulletVect[i].setTexture();
			bulletVect[i].draw(window);
			bulletVect[i].pollEvents();
			if (bulletVect[i].collisions())
			{
				bulletVect.erase(bulletVect.begin() + i);
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
