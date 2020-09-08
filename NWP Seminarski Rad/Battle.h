#pragma once
#include <SFML/Graphics.hpp>
#include "Pokemon.h"

class Battle 
{
	sf::Font font;
	sf::Text text1;
	sf::Text text2;

public:
	Battle();
	~Battle() {}

	Pokemon pokemon;
	int chosen_pokemon;

	void start();
	void pokemonSelect();
};