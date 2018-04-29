#include "AudioManager.h"



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

void AudioManager::playShotSound()
{
	shot.play();
}

void AudioManager::playDeathSound()
{
	death.play();
}
