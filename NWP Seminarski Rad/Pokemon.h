#pragma once
#include <SFML/Graphics.hpp>

class Pokemon
{
	int hit_points;
	
public:
	Pokemon();
	~Pokemon() {}

	sf::Texture texture;
	sf::Sprite sprite;
	enum pokemon_enum
	{
		BULBASAUR = 0,
		CHARMANDER = 1,
		SQUIRTLE = 2,
		PIKACHU = 3
	};
};