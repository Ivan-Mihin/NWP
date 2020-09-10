#pragma once
#include <SFML/Graphics.hpp>
#include "Move.h"

class Bulbasaur
{
	int hit_points;
	Move move1;
	Move move2;
	Move move3;
	Move move4;

public:
	Bulbasaur();
	~Bulbasaur() {};

	sf::Texture texture;
	sf::Sprite sprite;
	int getHitPoints();
	Move getMove(int move);
};