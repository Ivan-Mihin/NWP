#pragma once
#include <SFML/Graphics.hpp>

class Pokemon
{	
	int move1;
	int move2;
	int move3;
	int move4;
	std::string name;

public:
	Pokemon() {};
	~Pokemon() {}

	int hit_points;
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