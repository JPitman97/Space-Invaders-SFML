#include "stateManager.h"

/*Creates the enum for the possible gamestates, then creates a variable of the same type*/
static enum GAMESTATE { Menu, Game, Win, Loss , Instructions};
static GAMESTATE STATE;

stateManager::stateManager()
{
	//Sets the default state
	STATE = Menu;
}

/*Handles getting the current game state to allow for switching views*/
std::string stateManager::getState()
{
	switch (STATE)
	{
	case Menu:
		return "Menu";
		break;
	case Game:
		return "Game";
		break;
	case Win:
		return "Win";
		break;
	case Loss:
		return "Loss";
		break;
	case Instructions:
		return "Instructions";
		break;
	default:
		return NULL;
		break;
	}
	return NULL;
}

/*Allows for setting the state to be used for setting the views*/
void stateManager::setState(int state)
{
	switch (state)
	{
	case 0:
		STATE = Menu;
		break;
	case 1:
		STATE = Game;
		break;
	case 2:
		STATE = Win;
		break;
	case 3:
		STATE = Loss;
		break;
	case 4:
		STATE = Instructions;
		break;
	default:
		std::cout << "Error setting state!" << std::endl;
		break;
	}
}


stateManager::~stateManager()
{
}
