#pragma once
#include <SFML\Graphics.hpp>
#include "EntityManager.h"
#include <iostream>
#include "Bullet.h"
#include "stateManager.h"

class Player : public EntityManager
{
public:
	Player();
	~Player();

	void playerWin();
	void playerLose();

	bool fire = false;
	void pollEvents() override;

private:
	
};

