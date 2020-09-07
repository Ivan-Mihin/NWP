#pragma once
#include <SFML/Audio.hpp>

class Audio
{
	std::string path;
	sf::Music music;

public:
	Audio();
	~Audio() {}

	void changeMusic(std::string path);
	void changeMusic(std::string path, int volume);
};