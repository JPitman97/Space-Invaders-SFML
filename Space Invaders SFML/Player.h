#pragma once
#include <SFML\Graphics.hpp>
#include "EntityManager.h"
#include <iostream>
#include "Bullet.h"

class Player : public EntityManager
{
public:
	Player();
	~Player();

	bool fire = false;
	void pollEvents() override;

private:
	
};

