#include "Charmander.h"

Charmander::Charmander()
{
	hit_points = 35;
	move1 = 4;
	move2 = 7;
	move3 = 12;
	move4 = 18;
	texture.loadFromFile("Pokemon/Charmander.png", sf::IntRect(128, 0, 128, 128));
	sprite.setTexture(texture);
}

int Charmander::getHitPoints()
{
	return hit_points;
}

int Charmander::getMove(int move)
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