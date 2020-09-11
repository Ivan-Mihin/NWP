#include "Bulbasaur.h"
#include "Pokemon.h"

Bulbasaur::Bulbasaur()
{
	hit_points = 40;
	type = GRASS;

	move1.type = NORMAL;
	move1.value = 10;
	move1.name = "TACKLE";

	move2.type = NORMAL;
	move2.value = 8;
	move2.name = "HEAL";

	move3.type = GRASS;
	move3.value = 8;
	move3.name = "RAZOR LEAF";

	move4.type = GRASS;
	move4.value = 15;
	move4.name = "VINE WHIP";

	texture.loadFromFile("Pokemon/Bulbasaur.png", sf::IntRect(128, 0, 128, 128));
	sprite.setTexture(texture);
}

int Bulbasaur::getHitPoints()
{
	return hit_points;
}

Move Bulbasaur::getMove(int move)
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

int Bulbasaur::getType()
{
	return type;
}