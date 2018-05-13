#include "EntityManager.h"



EntityManager::EntityManager()
{
}

/*Virtual init method allows Player, Enemy and bullet to initialise themselves with a texture*/
void EntityManager::init(std::string texLoc)
{
	if (!Texture.loadFromFile(texLoc))
	{
		std::cout << "Error loading texture!" << std::endl;
	}

	Sprite.setTexture(Texture);
}

/*Virtual setPosition method allows Player, Enemy and bullet to initialise themselves with a position*/
void EntityManager::setPosition(float x, float y)
{
	Sprite.setPosition(x, y);
}

/*Virtual getPosition method allows classes to get the position of an inherited object*/
sf::Vector2f EntityManager::getPosition()
{
	return Sprite.getPosition();
}

/*Virtual setScale method allows Player, Enemy and bullet to initialise themselves with a scale*/
void EntityManager::setScale(float x, float y)
{
	Sprite.setScale(x, y);
}

/*Virtual draw method allows Player, Enemy and bullet to draw themselves to the screen*/
void EntityManager::draw(sf::RenderWindow& window)
{
	window.draw(Sprite);
}

/*Virtual method to check whether objects are colliding with the borders of the screen, contains debug logs that are not visible in game*/
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
