#pragma once
#include <SFML/Graphics.hpp>
#include "Move.h"

class Pikachu
{
	int hit_points;
	Move move1;
	Move move2;
	Move move3;
	Move move4;

public:
	Pikachu();
	~Pikachu() {};

	sf::Texture texture;
	sf::Sprite sprite;
	int getHitPoints();
	Move getMove(int move);
};