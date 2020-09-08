#pragma once
#include "Pokemon.h"

class Battle 
{
	sf::Font font;
	sf::Text text1;
	sf::Text text2;
	sf::Texture texture;

public:
	Battle();
	~Battle() {}

	Pokemon pokemon;
	sf::Sprite background;

	void start(Pokemon pokemon);
	void pokemonSelect();
};