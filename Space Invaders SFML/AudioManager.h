#pragma once
#include <SFML\Audio.hpp>
#include <iostream>

class AudioManager
{
public:
	AudioManager();
	~AudioManager();

	sf::SoundBuffer shotBuffer;
	sf::Sound shot;

	sf::SoundBuffer deathBuffer;
	sf::Sound death;

	sf::Music BGMusic;

	void playShotSound();
	void playDeathSound();
};

