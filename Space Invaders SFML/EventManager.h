#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Player.h"
class EventManager
{
public:
	EventManager();
	~EventManager();

	void pollEvents(sf::RenderWindow &window, Player& player);
private:
	sf::Event event;
};

