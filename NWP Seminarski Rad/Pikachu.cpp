#include "Pikachu.h"

Pikachu::Pikachu()
{
	hit_points = 40;
	move1 = 4;
	move2 = 10;
	move3 = 13;
	move4 = 21;
	texture.loadFromFile("Pokemon/Pikachu.png", sf::IntRect(128, 0, 128, 128));
	sprite.setTexture(texture);
}

int Pikachu::getHitPoints()
{
	return hit_points;
}

int Pikachu::getMove(int move)
{
	switch (move)
	{
	case 1:
	{
		return move1;
	}
	case 2:
	{
		return move2;
	}
	case 3:
	{
		return move3;
	}
	case 4:
	{
		return move4;
	}
	}
}