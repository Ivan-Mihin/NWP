#pragma once
#include "Pokemon.h"
#include "Bulbasaur.h"
#include "Charmander.h"
#include "Squirtle.h"
#include "Pikachu.h"

Pokemon::Pokemon()
{
}

void Pokemon::setPokemon(int choice) 
{
	switch (choice)
	{
	case BULBASAUR:
	{
		Bulbasaur bulbasaur;
		hit_points = bulbasaur.getHitPoints();
		move1 = bulbasaur.getMove(1);
		move2 = bulbasaur.getMove(2);
		move3 = bulbasaur.getMove(3);
		move4 = bulbasaur.getMove(4);
		sprite = bulbasaur.sprite;
		break;
	}

	case CHARMANDER:
	{
		Charmander charmander;
		hit_points = charmander.getHitPoints();
		move1 = charmander.getMove(1);
		move2 = charmander.getMove(2);
		move3 = charmander.getMove(3);
		move4 = charmander.getMove(4);
		sprite = charmander.sprite;
	}

	case SQUIRTLE:
	{
		Squirtle squirtle;
		hit_points = squirtle.getHitPoints();
		move1 = squirtle.getMove(1);
		move2 = squirtle.getMove(2);
		move3 = squirtle.getMove(3);
		move4 = squirtle.getMove(4);
		sprite = squirtle.sprite;
	}

	case PIKACHU:
	{
		Pikachu pikachu;
		hit_points = pikachu.getHitPoints();
		move1 = pikachu.getMove(1);
		move2 = pikachu.getMove(2);
		move3 = pikachu.getMove(3);
		move4 = pikachu.getMove(4);
		sprite = pikachu.sprite;
	}
	}
}