#include "Squirtle.h"
#include "Pokemon.h"

Squirtle::Squirtle()
{
	hit_points = 40;
	type = WATER;

	move1.type = NORMAL;
	move1.value = 10;
	move1.name = "TACKLE";

	move2.type = NORMAL;
	move2.value = 8;
	move2.name = "HEAL";

	move3.type = WATER;
	move3.value = 8;
	move3.name = "WATER PULSE";

	move4.type = WATER;
	move4.value = 15;
	move4.name = "SURF";

	texture.loadFromFile("Pokemon/Squirtle.png", sf::IntRect(128, 0, 128, 128));
	sprite.setTexture(texture);
}

int Squirtle::getHitPoints()
{
	return hit_points;
}

Move Squirtle::getMove(int move)
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

int Squirtle::getType()
{
	return type;
}