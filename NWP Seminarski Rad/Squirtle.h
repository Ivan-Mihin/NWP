#pragma once
#include <SFML/Graphics.hpp>
#include "Move.h"

class Squirtle
{
	int hit_points;
	Move move1;
	Move move2;
	Move move3;
	Move move4;

public:
	Squirtle();
	~Squirtle() {};

	sf::Texture texture;
	sf::Sprite sprite;
	int getHitPoints();
	Move getMove(int move);
};