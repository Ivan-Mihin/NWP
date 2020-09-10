#pragma once
#include <SFML/Graphics.hpp>
#include "Move.h"

class Pokemon
{	
	std::string name;

public:
	Pokemon() {};
	~Pokemon() {}

	int hit_points;
	Move move1;
	Move move2;
	Move move3;
	Move move4;
	sf::Texture texture;
	sf::Sprite sprite;
	enum pokemon_enum
	{
		BULBASAUR = 0,
		CHARMANDER = 1,
		SQUIRTLE = 2,
		PIKACHU = 3
	};

	void setPokemon(int choice);
	std::string getName();
};