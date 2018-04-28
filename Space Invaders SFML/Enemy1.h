#pragma once
#include "EntityManager.h"
#include "Bullet.h"
#include "Player.h"

class Enemy1 : public EntityManager
{
public:
	Enemy1();

	void pollEvents() override;

	void spawnEnemies();

	void setTexture();

	bool collisions(Bullet& bullet);

	bool collisions(Player& player);

	~Enemy1();

	std::vector<Enemy1> EnemyVect;

	int enemiesRemaining;
	int enemypos = 1;
	float fallSpeed = 0.3f;
};

