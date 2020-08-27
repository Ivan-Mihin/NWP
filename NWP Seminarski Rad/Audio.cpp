#include <SFML/Audio.hpp>
#include "Audio.h"

Audio::Audio()
{
	music.openFromFile("Audio/Map1Music.ogg");
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