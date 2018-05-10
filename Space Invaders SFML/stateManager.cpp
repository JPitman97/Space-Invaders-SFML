#include "stateManager.h"


static enum GAMESTATE { Menu, Game, Win, Loss };
static GAMESTATE STATE;

stateManager::stateManager()
{
	STATE = Menu;
}

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
	default:
		break;
	}
}

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
	default:
		std::cout << "Error setting state!" << std::endl;
		break;
	}
}


stateManager::~stateManager()
{
}
