#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class EntityManager
{
public:
	EntityManager();
	virtual ~EntityManager() = 0;

	virtual void init(std::string texLoc);
	virtual void setPosition(float x, float y);
	virtual sf::Vector2f getPosition();
	virtual void setScale(float x, float y);
	virtual void pollEvents() = 0; // Override this function!
	virtual bool collisions();
	virtual void draw(sf::RenderWindow &window);
	virtual sf::Sprite getSprite() { return this->Sprite; };
	virtual void setSpeed(int speed) { moveSpeed = speed; };

protected:
	sf::Sprite Sprite;
	sf::Texture Texture;

	float posX = 0;
	float posY = 0;

	float moveSpeed = 5;
	float deltaTime;
};

