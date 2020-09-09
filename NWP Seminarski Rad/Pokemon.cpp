#pragma once
#include "Pokemon.h"
#include "Bulbasaur.h"
#include "Charmander.h"
#include "Squirtle.h"
#include "Pikachu.h"

void Pokemon::setPokemon(int choice)
{
	switch (choice)
	{
	case BULBASAUR:
	{
		Bulbasaur bulbasaur;
		name = "BULBASAUR";
		hit_points = bulbasaur.getHitPoints();
		move1 = bulbasaur.getMove(1);
		move2 = bulbasaur.getMove(2);
		move3 = bulbasaur.getMove(3);
		move4 = bulbasaur.getMove(4);
		texture = bulbasaur.texture;
		sprite.setTexture(texture);
		break;
	}

	case CHARMANDER:
	{
		Charmander charmander;
		name = "CHARMANDER";
		hit_points = charmander.getHitPoints();
		move1 = charmander.getMove(1);
		move2 = charmander.getMove(2);
		move3 = charmander.getMove(3);
		move4 = charmander.getMove(4);
		texture = charmander.texture;
		sprite.setTexture(texture);
		break;
	}

	case SQUIRTLE:
	{
		Squirtle squirtle;
		name = "SQUIRTLE";
		hit_points = squirtle.getHitPoints();
		move1 = squirtle.getMove(1);
		move2 = squirtle.getMove(2);
		move3 = squirtle.getMove(3);
		move4 = squirtle.getMove(4);
		texture = squirtle.texture;
		sprite.setTexture(texture);
		break;
	}

	case PIKACHU:
	{
		Pikachu pikachu;
		name = "PIKACHU";
		hit_points = pikachu.getHitPoints();
		move1 = pikachu.getMove(1);
		move2 = pikachu.getMove(2);
		move3 = pikachu.getMove(3);
		move4 = pikachu.getMove(4);
		texture = pikachu.texture;
		sprite.setTexture(texture);
		break;
	}
	}
}

std::string Pokemon::getName()
{
	return name;
}