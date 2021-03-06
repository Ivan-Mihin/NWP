#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Pokemon.h"

class Battle 
{
	sf::Texture texture;
	bool enemy_turn;
	bool chat_clear;
	bool battle_end;
	
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
	sf::Text chat_text;
	sf::Text chat_text2;

	void start(Pokemon pokemon);
	void pokemonSelect();
	void playerTurn(Pokemon pokemon, Button move1, Button move2, Button move3, Button move4, sf::Vector2i mouse_position, sf::RenderWindow* battle_window);
	void enemyTurn(sf::RenderWindow* battle_window, Pokemon* pokemon);
	void textInitialization(sf::Text* text, sf::Font* font, int character_size, std::string string, sf::Color color, float position_x, float position_y, bool set_origin);
	void chat(Pokemon pokemon, Move move, float multiplier);
	void drawOnScreen(sf::RenderWindow* battle_window, Pokemon pokemon, Button move1_button, Button move2_button, Button move3_button, Button move4_button, Button run_button);
	float damageMultiplier(int move_type, int pokemon_type);
};