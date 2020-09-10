#pragma once
#include <SFML/Graphics.hpp>
#include "Pokemon.h"

class Battle 
{
	sf::Texture texture;

public:
	Battle();
	~Battle() {}

	Pokemon pokemon;
	int chosen_pokemon;
	sf::Sprite background;

	void start(Pokemon pokemon);
	void pokemonSelect();
	void enemyAttack(sf::RenderWindow* battle_window, Pokemon* pokemon, sf::Text* player_pokemon_health, sf::Text* enemy_pokemon_health);
};