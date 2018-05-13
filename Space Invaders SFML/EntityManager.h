#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class EntityManager
{
public:
	EntityManager();
	virtual ~EntityManager() = 0; // Makes this class pure virtual (Abstract), meaning it cannot be instantiated on it's own

	/*Method prototypes used for objects that inherit from this class, they are all virtual so that they can be overridden*/
	virtual void init(std::string texLoc);
	virtual void setPosition(float x, float y);
	virtual sf::Vector2f getPosition();
	virtual void setScale(float x, float y);
	virtual void pollEvents() = 0; // Override this function!
	virtual bool windowCollisions();
	virtual void draw(sf::RenderWindow &window);
	virtual sf::Sprite getSprite() { return this->Sprite; };
	virtual void setSpeed(float speed) { moveSpeed = speed; };

protected:
	/*Protected variables for classes that inherit to use*/
	sf::Sprite Sprite;
	sf::Texture Texture;

	float posX = 0;
	float posY = 0;

	float moveSpeed = 5;
	float deltaTime;
};

