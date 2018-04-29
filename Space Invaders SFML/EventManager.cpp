#include "EventManager.h"



EventManager::EventManager()
{
	std::cout << "Event Manager Constructor Running" << std::endl;
}

void EventManager::pollEvents(sf::RenderWindow &window, Player& player)
{
	while (window.pollEvent(event))
	{
		// What happened?
		switch (event.type)
		{
			// window closed
		case sf::Event::Closed:
			window.close();
			break;

			// key pressed
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
			{
				std::cout << "Escape!" << std::endl;
			}
			if (event.key.code == sf::Keyboard::Space && player.gameOver != true)
			{
				player.fire = true;
			}
			break;

			// Ignore anything else
		default:
			break;
		}
	}
}


EventManager::~EventManager()
{
}
