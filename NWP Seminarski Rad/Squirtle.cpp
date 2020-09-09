#include "Squirtle.h"

Squirtle::Squirtle()
{
	hit_points = 40;
	move1 = 3;
	move2 = 6;
	move3 = 12;
	move4 = 24;
	texture.loadFromFile("Pokemon/Squirtle.png", sf::IntRect(128, 0, 128, 128));
	sprite.setTexture(texture);
}

int Squirtle::getHitPoints()
{
	return hit_points;
}

int Squirtle::getMove(int move)
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