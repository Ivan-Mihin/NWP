#pragma once
#include <SFML/Audio.hpp>
#include <string>

class Audio
{
	std::string path;
	sf::Music music;

public:
	Audio();
	~Audio() {}

	void changeMusic(std::string path);
};