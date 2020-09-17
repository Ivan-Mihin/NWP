#pragma once
#include <SFML/Graphics.hpp>
#include "Move.h"

enum pokemon_enum
{
	BULBASAUR = 0,
	CHARMANDER = 1,
	SQUIRTLE = 2,
	PIKACHU = 3
};

enum pokemon_type
{
	NORMAL = 0,
	GRASS = 1,
	FIRE = 2,
	WATER = 3,
	ELECTRIC = 4
};

class Pokemon
{	
	std::string name;

public:
	Pokemon() {};
	~Pokemon() {}

	int hit_points;			// Pokemon's hit points
	int type;				// Pokemon's type
	Move move1;				// Pokemon's first move
	Move move2;				// Pokemon's second move
	Move move3;				// Pokemon's third move
	Move move4;				// Pokemon's fourth move
	sf::Texture texture;	// Texture for pokemon
	sf::Sprite sprite;		// Sprite for pokemon

	void setPokemon(int choice);	// Sets pokemon stats
	std::string getName();			// Returns pokemon name
};