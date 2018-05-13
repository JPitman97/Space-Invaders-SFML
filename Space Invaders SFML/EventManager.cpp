#include "EventManager.h"



EventManager::EventManager()
{
	std::cout << "Event Manager Constructor Running" << std::endl; //Debug text to check whether the constructor runs, not seen during gameplay
}

/*Handle the events of the game, this method takes in the window object and the player object*/
void EventManager::pollEvents(sf::RenderWindow &window, Player& player)
{
	/*Loops through all the events*/
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
				std::cout << "Closing!" << std::endl;
				window.close();
			}
			/*If the space key is pressed, the player has fired so set fire to true*/
			if (event.key.code == sf::Keyboard::Space) 
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
