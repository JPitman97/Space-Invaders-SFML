#pragma once
#include "EntityManager.h"
class Bullet : public EntityManager
{
public:
	Bullet();
	~Bullet();

	/*Handle overriding of the pollevents method to make the bullet sly upwards, as well as setting the texture*/
	void pollEvents() override;
	void setTexture();

	std::vector<Bullet> bulletVect; //A vector of instances of this class


private:
	//The movement speed of the bullet
	float moveSpeed = 10;
	
};

