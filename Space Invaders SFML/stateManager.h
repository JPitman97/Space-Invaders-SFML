#pragma once
#include <iostream>
class stateManager
{
public:
	stateManager();
	~stateManager();

	/*Method Prototypes*/
	static std::string getState();
	static void setState(int state);

private:
	
};

