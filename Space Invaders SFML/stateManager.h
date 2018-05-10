#pragma once
#include <iostream>
class stateManager
{
public:
	stateManager();
	~stateManager();

	static std::string getState();
	static void setState(int state);

private:
	
};

