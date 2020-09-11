#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Pokemon.h"

class Battle 
{
	sf::Texture texture;
	bool enemy_turn;
	
public:
	Battle();
	~Battle() {}

	Pokemon pokemon;
	int chosen_pokemon;
	sf::Sprite background;
	sf::Text enemy_pokemon_name;
	sf::Text enemy_pokemon_health;
	sf::Text player_pokemon_name;
	sf::Text player_pokemon_health;

	void start(Pokemon pokemon);
	void pokemonSelect();
	void playerTurn(Button move1, Button move2, Button move3, Button move4, sf::Vector2i mouse_position);
	void enemyTurn(sf::RenderWindow* battle_window, Pokemon* pokemon, sf::Text* player_pokemon_health, sf::Text* enemy_pokemon_health);
	float damageMultiplier(int move_type, int pokemon_type);
	void textInitialization(sf::Text* text, sf::Font* font, int character_size, std::string string, sf::Color color, float position_x, float position_y, bool set_origin);
};