#include "Enemy1.h"

Enemy1::Enemy1()
{
	init("Assets/Enemy1.png");
	setScale(0.3f, 0.3f);
	setPosition(0, 0);
}

void Enemy1::spawnEnemies()
{
	for (int i = 0; i < 5; i++)
	{
		Enemy1 enemy;
		enemy.setPosition(85.f * enemypos, 0.f);
		EnemyVect.push_back(enemy);
		++enemypos;
		++enemiesRemaining;
	}

	enemypos = 1;

	for (int i = 0; i < 5; i++)
	{
		Enemy1 enemy;
		enemy.setPosition(85.f * enemypos, 100.f);
		EnemyVect.push_back(enemy);
		++enemypos;
		++enemiesRemaining;
	}

	for (size_t i = 0; i < EnemyVect.size(); i++)
	{
		EnemyVect[i].setTexture();
	}

	enemypos = 1;
}

void Enemy1::setTexture()
{
	if (!Texture.loadFromFile("Assets/Enemy1.png"))
	{
		std::cout << "Error loading texture!" << std::endl;
	}

	Sprite.setTexture(Texture);
}

void Enemy1::pollEvents()
{
	Sprite.move(0.f, fallSpeed);
}

bool Enemy1::Objectcollisions(Bullet& bullet, AudioManager& Audio, Player& player)
{
	for (size_t i = 0; i < EnemyVect.size(); i++)
	{
		sf::FloatRect rect = bullet.getSprite().getGlobalBounds();
		if (EnemyVect[i].Sprite.getGlobalBounds().intersects(rect))
		{
			std::cout << "BULLET HIT!!!" << std::endl;

			Audio.playDeathSound();

			EnemyVect.erase(EnemyVect.begin() + i);
			for (size_t i = 0; i < EnemyVect.size(); i++)
			{
				EnemyVect[i].setTexture();
				EnemyVect[i].fallSpeed += 0.2f;
			}
			--enemiesRemaining;

			std::cout << enemiesRemaining << std::endl;


			if (enemiesRemaining == 0)
			{
				player.playerWin();
			}
			return true;
		}
	}
	return false;
}

bool Enemy1::Objectcollisions(Player& player, AudioManager& Audio)
{
	for (size_t i = 0; i < EnemyVect.size(); i++)
	{
		sf::FloatRect rect = player.getSprite().getGlobalBounds();
		if (EnemyVect[i].Sprite.getGlobalBounds().intersects(rect))
		{
			EnemyVect.erase(EnemyVect.begin() + i);
			for (size_t i = 0; i < EnemyVect.size(); i++)
			{
				EnemyVect[i].setTexture();
			}
			--enemiesRemaining;

			std::cout << enemiesRemaining << std::endl;

			player.playerLose();
			return true;
		}
	}
	return false;
}

Enemy1::~Enemy1()
{
}
