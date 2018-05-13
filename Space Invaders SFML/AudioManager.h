#pragma once
#include <SFML\Audio.hpp>
#include <iostream>

class AudioManager
{
public:
	AudioManager();
	~AudioManager();

	/*Variables related to sound objects used for the game*/
	sf::SoundBuffer shotBuffer;
	sf::Sound shot;
	sf::SoundBuffer deathBuffer;
	sf::Sound death;
	sf::Music BGMusic;

	/*Methods used to play the sounds used for the game*/
	void playShotSound();
	void playDeathSound();
};

