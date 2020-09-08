#include "Bulbasaur.h"

Bulbasaur::Bulbasaur()
{
	name = "BULBASAUR";
	hit_points = 40;
	move1 = 2;
	move2 = 5;
	move3 = 10;
	move4 = 20;
	texture.loadFromFile("Pokemon/Bulbasaur.png", sf::IntRect(128, 0, 128, 128));
	sprite.setTexture(texture);
}

int Bulbasaur::getHitPoints()
{
	return hit_points;
}

int Bulbasaur::getMove(int move)
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

std::string Bulbasaur::getName()
{
	return name;
}