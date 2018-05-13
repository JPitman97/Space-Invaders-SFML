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

	/*Method prototypes*/
	void playerWin();
	void playerLose();
	void pollEvents() override; //This method is overridden from Entity Manager

	/*Variable used to determin whether the player has fired*/
	bool fire = false;

private:
	
};

