#pragma once
#include "EntityManager.h"
class Bullet : public EntityManager
{
public:
	Bullet();
	~Bullet();

	void pollEvents() override;

	void setTexture();

	std::vector<Bullet> bulletVect;


private:
	float moveSpeed = 10;
	
};

