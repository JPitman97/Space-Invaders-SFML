#include "Enemy1.h"

Enemy1::Enemy1()
{
	/*Initialises the Enemy with a texture and scale and position, sent to the Entity Manager*/
	init("Assets/Enemy1.bmp");
	setScale(0.3f, 0.3f);
	setPosition(0, 0);
}

/*This method spanws a wave of 10 enemies at the top of the screen during the game, and adds them to a vector, it also resets their texture if it is lost*/
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

/*This method resets the texture if it is lost when adding it to the vector*/
void Enemy1::setTexture()
{
	if (!Texture.loadFromFile("Assets/Enemy1.bmp"))
	{
		std::cout << "Error loading texture!" << std::endl;
	}

	Sprite.setTexture(Texture);
}

/*This method allows the player to move slowely down the screen when shot*/
void Enemy1::pollEvents()
{
	Sprite.move(0.f, fallSpeed);
}

/*This method is used to detect collision between the enemy and the bullet, this is a override method that can take either a bullet object or a player object*/
bool Enemy1::Objectcollisions(Bullet& bullet, AudioManager& Audio, Player& player)
{
	for (size_t i = 0; i < EnemyVect.size(); i++) //Loop through all the enemies on the screen
	{
		sf::FloatRect rect = bullet.getSprite().getGlobalBounds(); //Get the position of the bullet
		if (EnemyVect[i].Sprite.getGlobalBounds().intersects(rect)) //Does it collide with the enemy
		{
			std::cout << "BULLET HIT!!!" << std::endl; //Debug, not seen during gameplay

			Audio.playDeathSound(); //Plays the death audio

			EnemyVect.erase(EnemyVect.begin() + i); //Erases the enemy from the vector
			for (size_t i = 0; i < EnemyVect.size(); i++) //Loops through the remaining enemies and increases their fallspeed as well as resetting the texture
			{
				EnemyVect[i].setTexture();
				EnemyVect[i].fallSpeed += 0.2f;
			}
			--enemiesRemaining; //lowers the amount of enemies left

			std::cout << enemiesRemaining << std::endl; // debug


			if (enemiesRemaining == 0) //Check to see if the player has won and if so call the playerWin method
			{
				player.playerWin();
			}
			return true;
		}
	}
	return false;
}

/*This method is similar to the one above but checks collision against the player instead of against the bullet, the only difference is commented*/
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

			player.playerLose(); // If collision does occur the player is dead and so the game is lost
			return true;
		}
	}
	return false;
}

Enemy1::~Enemy1()
{
}
