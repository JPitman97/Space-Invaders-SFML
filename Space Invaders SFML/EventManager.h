#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Player.h"
class EventManager
{
public:
	EventManager();
	~EventManager();

	void pollEvents(sf::RenderWindow &window, Player& player); //Handles the events for firing and window closure

private:
	sf::Event event; // event variable
};

