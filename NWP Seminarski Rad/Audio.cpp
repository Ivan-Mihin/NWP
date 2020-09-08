#include <SFML/Audio.hpp>
#include "Audio.h"

Audio::Audio()
{
	music.openFromFile("Audio/Intro.ogg");
	music.setVolume(50);
	music.play();
	music.setLoop(true);
}

void Audio::changeMusic(std::string path)
{
	music.stop();
	music.openFromFile(path);
	music.play();
	music.setLoop(true);
}

void Audio::changeMusic(std::string path, int volume)
{
	music.stop();
	music.openFromFile(path);
	music.setVolume(volume);
	music.play();
	music.setLoop(true);
}