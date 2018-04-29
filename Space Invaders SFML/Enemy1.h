#pragma once
#include "EntityManager.h"
#include "Bullet.h"
#include "Player.h"
#include "AudioManager.h"
#include <ctime>    
#include <cstdlib>

class Enemy1 : public EntityManager
{
public:
	Enemy1();

	void pollEvents() override;
	

	void spawnEnemies();

	void setTexture();

	bool Objectcollisions(Bullet& bullet, AudioManager& Audio, Player& player);

	bool Objectcollisions(Player& player, AudioManager& Audio);

	~Enemy1();

	std::vector<Enemy1> EnemyVect;

	int enemiesRemaining;
	int enemypos = 1;
	float fallSpeed = 0.0f;

	bool hasFired = false;
};

