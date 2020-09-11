#pragma once
#include <SFML/Audio.hpp>

class Audio
{
	std::string path;		// Path to the .ogg file for music
	sf::Music music;

public:
	Audio();
	~Audio() {}

	// Change music
	void changeMusic(std::string path);					// Change music
	void changeMusic(std::string path, int volume);		// Change music with ability to set volume
};