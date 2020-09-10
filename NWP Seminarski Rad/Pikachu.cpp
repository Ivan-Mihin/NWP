#include "Pikachu.h"

Pikachu::Pikachu()
{
	hit_points = 40;

	move1.value = 10;
	move1.name = "TACKLE";

	move2.value = 10;
	move2.name = "HEAL";

	move3.value = 8;
	move3.name = "VOLT TACKLE";

	move4.value = 15;
	move4.name = "THUNDERSHOCK";

	texture.loadFromFile("Pokemon/Pikachu.png", sf::IntRect(128, 0, 128, 128));
	sprite.setTexture(texture);
}

int Pikachu::getHitPoints()
{
	return hit_points;
}

Move Pikachu::getMove(int move)
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