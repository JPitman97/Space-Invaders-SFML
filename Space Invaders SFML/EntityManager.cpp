#include "EntityManager.h"



EntityManager::EntityManager()
{
}

void EntityManager::init(std::string texLoc)
{
	if (!Texture.loadFromFile(texLoc))
	{
		std::cout << "Error loading texture!" << std::endl;
	}

	Sprite.setTexture(Texture);
}

void EntityManager::setPosition(float x, float y)
{
	Sprite.setPosition(x, y);
}

sf::Vector2f EntityManager::getPosition()
{
	return Sprite.getPosition();
}

void EntityManager::setScale(float x, float y)
{
	Sprite.setScale(x, y);
}

void EntityManager::draw(sf::RenderWindow& window)
{
	window.draw(Sprite);
}

bool EntityManager::windowCollisions()
{
	if (Sprite.getPosition().x <= 0) // Left side collision?
	{
		std::cout << "Hitting the left edge!" << std::endl;
		Sprite.move(+5.0, 0.0);
		return true;
	}
	
	if (Sprite.getPosition().x + Sprite.getLocalBounds().width >= 727) //Right side collision?
	{
		std::cout << "Hitting the right edge!" << std::endl;
		Sprite.move(-5.0, 0.0);
		return true;
	} 

	if (Sprite.getPosition().y <= -10) //Top Collision?
	{
		std::cout << "Hitting the top!" << std::endl;
		return true;
	}

	if (Sprite.getPosition().y >= 750) //Bottom Collision?
	{
		std::cout << "Hitting the bottom!" << std::endl;
		return true;
	}

	return false;

}


EntityManager::~EntityManager()
{
}
