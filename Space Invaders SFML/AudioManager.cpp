#include "AudioManager.h"


/*This method loads in all thw audio required for the game and sets their volume and loop, it plays the background audio immeditately*/
AudioManager::AudioManager()
{
	if (!BGMusic.openFromFile("Assets/Background-Music.wav"))
	{
		std::cout << "Failed to load Background Music!" << std::endl;
	}
	BGMusic.setVolume(20);
	BGMusic.setLoop(true);
	BGMusic.play();

	
	if (!shotBuffer.loadFromFile("Assets/Gun-Shot.wav"))
	{
		std::cout << "Failed to load Gunshot Audio!" << std::endl;
	}
	shot.setBuffer(shotBuffer);
	shot.setVolume(60);

	if (!deathBuffer.loadFromFile("Assets/Enemy-Death-Sound.wav"))
	{
		std::cout << "Failed to load Death Audio!" << std::endl;
	}
	death.setBuffer(deathBuffer);
	death.setVolume(30);
}


AudioManager::~AudioManager()
{
}

/*This method plays the gun shot sound when the bullet is fired*/
void AudioManager::playShotSound()
{
	shot.play();
}

/*This method plays the death sound when an enemy dies or the game is over*/
void AudioManager::playDeathSound()
{
	death.play();
}
