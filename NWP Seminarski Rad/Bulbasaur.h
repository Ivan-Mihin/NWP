#pragma once
#include <SFML/Graphics.hpp>

class Bulbasaur
{
	int hit_points;
	int move1;
	int move2;
	int move3;
	int move4;

public:
	Bulbasaur();
	~Bulbasaur() {};

	sf::Texture texture;
	sf::Sprite sprite;
	int getHitPoints();
	int getMove(int move);
};