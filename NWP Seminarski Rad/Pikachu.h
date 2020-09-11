#pragma once
#include <SFML/Graphics.hpp>
#include "Move.h"

class Pikachu
{
	int hit_points;		// Pokemon's hit points
	int type;			// Pokemon's type
	Move move1;			// Pokemon's first move
	Move move2;			// Pokemon's second move
	Move move3;			// Pokemon's third move
	Move move4;			// Pokemon's fourth move

public:
	Pikachu();
	~Pikachu() {};

	sf::Texture texture;		// Texture for pokemon
	sf::Sprite sprite;			// Sprite for pokemon

	int getHitPoints();			// Returns pokemon's hit points
	int getType();				// Returns pokemon's type
	Move getMove(int move);		// Returns pokemon's move		
};