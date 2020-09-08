#pragma once
#include <SFML/Graphics.hpp>

class Charmander
{
	std::string name;
	int hit_points;
	int move1;
	int move2;
	int move3;
	int move4;
	sf::Texture texture;

public:
	Charmander();
	~Charmander() {};

	sf::Sprite sprite;
	int getHitPoints();
	int getMove(int move);
	std::string getName();
};