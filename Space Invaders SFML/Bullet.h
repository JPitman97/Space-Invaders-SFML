#pragma once
#include "EntityManager.h"
class Bullet : public EntityManager
{
public:
	Bullet();
	~Bullet();

	void pollEvents() override;

	void setTexture();

private:
	float moveSpeed = 10;
	
};

