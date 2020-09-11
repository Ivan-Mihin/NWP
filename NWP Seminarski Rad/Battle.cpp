#pragma once
#include <string>
#include "Battle.h"

Battle::Battle()
{
	texture.loadFromFile("Textures/Battle_Background.png");
	background.setTexture(texture);
	background.setPosition(0.0f, 0.0f);

	enemy_turn = false;
}

void Battle::start(Pokemon pokemon)
{
	sf::RenderWindow battle_window(sf::VideoMode(640, 480), "Battle", sf::Style::Titlebar);

	pokemonSelect();

	sf::Font font;
	font.loadFromFile("Fonts/Pokemon_GB.ttf");

	textInitialization(&enemy_pokemon_name, &font, 16, this->pokemon.getName(), sf::Color::White, 10.0f, 10.0f, false);
	textInitialization(&enemy_pokemon_health, &font, 16, "Health: " + std::to_string(this->pokemon.hit_points), sf::Color::White, 10.0f, 30.0f, false);

	textInitialization(&player_pokemon_name, &font, 16, pokemon.getName(), sf::Color::White, 475.0f, 320.0f, true);
	textInitialization(&player_pokemon_health, &font, 16, "Health: " + std::to_string(this->pokemon.hit_points), sf::Color::White, 475.0f, 340.0f, true);

	Button move1_button("Textures/Battle_Button.png", 135, 50, 495, 107);
	Button move2_button("Textures/Battle_Button.png", 135, 50, 495, 162);
	Button move3_button("Textures/Battle_Button.png", 135, 50, 495, 217);
	Button move4_button("Textures/Battle_Button.png", 135, 50, 495, 272);
	Button run_button("Textures/Battle_Button.png", 135, 50, 495, 420);

	sf::Font font2;
	font2.loadFromFile("Fonts/arial.ttf");

	move1_button.textInitialization(&font2, 15, pokemon.move1.name, sf::Color::Black);
	move2_button.textInitialization(&font2, 15, pokemon.move2.name, sf::Color::Black);
	move3_button.textInitialization(&font2, 15, pokemon.move3.name, sf::Color::Black);
	move4_button.textInitialization(&font2, 15, pokemon.move4.name, sf::Color::Black);
	run_button.textInitialization(&font2, 15, "RUN", sf::Color::Black);

	pokemon.sprite.setScale(2.0f, 2.0f);
	pokemon.sprite.setOrigin(0, pokemon.sprite.getLocalBounds().top + pokemon.sprite.getLocalBounds().height);
	pokemon.sprite.setPosition(20, 400);

	battle_window.clear();

	while (battle_window.isOpen())
	{
		sf::Event battle_event;

		while (battle_window.pollEvent(battle_event))
		{
			if (enemy_turn)
			{
				enemyTurn(&battle_window, &pokemon, &player_pokemon_health, &enemy_pokemon_health);

				enemy_turn = false;
			}

			switch (battle_event.type)
			{
			case battle_event.Closed:
			{
				battle_window.close();
				break;
			}

			case battle_event.MouseButtonPressed:
			{
				sf::Vector2i mouse_position = sf::Mouse::getPosition(battle_window);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (move1_button.isClicked(mouse_position) || move2_button.isClicked(mouse_position) || move3_button.isClicked(mouse_position) || move4_button.isClicked(mouse_position))
					{
						playerTurn(move1_button, move2_button, move3_button, move4_button, mouse_position);

						enemy_turn = true;
					}

					if (run_button.isClicked(mouse_position))
					{
						battle_window.close();
					}
				}
			}
			}

			battle_window.draw(background);

			battle_window.draw(enemy_pokemon_name);
			battle_window.draw(enemy_pokemon_health);

			battle_window.draw(player_pokemon_name);
			battle_window.draw(player_pokemon_health);

			battle_window.draw(move1_button.sprite);
			battle_window.draw(move1_button.text);

			battle_window.draw(move2_button.sprite);
			battle_window.draw(move2_button.text);

			battle_window.draw(move3_button.sprite);
			battle_window.draw(move3_button.text);

			battle_window.draw(move4_button.sprite);
			battle_window.draw(move4_button.text);

			battle_window.draw(run_button.sprite);
			battle_window.draw(run_button.text);

			battle_window.draw(this->pokemon.sprite);
			battle_window.draw(pokemon.sprite);
			battle_window.display();
		}
	}
}

void Battle::pokemonSelect()
{
	switch (rand() % 4)
	{
	case BULBASAUR:
	{
		pokemon.setPokemon(BULBASAUR);
		pokemon.texture.loadFromFile("Pokemon/Bulbasaur.png", sf::IntRect(0, 0, 128, 128));
		pokemon.sprite.setTexture(this->pokemon.texture);
		break;
	}

	case CHARMANDER:
	{
		pokemon.setPokemon(CHARMANDER);
		pokemon.texture.loadFromFile("Pokemon/Charmander.png", sf::IntRect(0, 0, 128, 128));
		pokemon.sprite.setTexture(this->pokemon.texture);
		break;
	}

	case SQUIRTLE:
	{
		pokemon.setPokemon(SQUIRTLE);
		pokemon.texture.loadFromFile("Pokemon/Squirtle.png", sf::IntRect(0, 0, 128, 128));
		pokemon.sprite.setTexture(this->pokemon.texture);
		break;
	}

	case PIKACHU:
	{
		pokemon.setPokemon(PIKACHU);
		pokemon.texture.loadFromFile("Pokemon/Pikachu.png", sf::IntRect(0, 0, 128, 128));
		pokemon.sprite.setTexture(this->pokemon.texture);
		break;
	}
	}

	pokemon.sprite.setPosition(300, 80);
}

void Battle::textInitialization(sf::Text* text, sf::Font* font, int character_size, std::string string, sf::Color color, float position_x, float position_y, bool set_origin)
{
	text->setFont(*font);
	text->setCharacterSize(character_size);
	text->setString(string);
	text->setFillColor(color);

	if (set_origin)
	{
		text->setOrigin(text->getLocalBounds().left + text->getLocalBounds().width, text->getLocalBounds().top + text->getLocalBounds().height);
	}

	text->setPosition(position_x, position_y);
}

void Battle::playerTurn(Button move1_button, Button move2_button, Button move3_button, Button move4_button, sf::Vector2i mouse_position)
{
	if (move1_button.isClicked(mouse_position))
	{
		//sf::Text battle_text;
		//battle_text.setFont(font);
		//battle_text.setCharacterSize(20);
		//battle_text.setString(pokemon.getName() + " used " + pokemon.move1.name + ".");
		//battle_text.setFillColor(sf::Color::Black);
		//battle_text.setPosition(10.0f, 30.0f);

		/*if (multiplier == 0.5)
		{
			battle_text.setString("It's not very effective.");
		}
		else if (multiplier == 2)
		{
			battle_text.setString("It's super effective!");
		}*/

		float multiplier = damageMultiplier(pokemon.move1.type, this->pokemon.type);
		this->pokemon.hit_points -= pokemon.move1.value * multiplier;
		enemy_pokemon_health.setString("Health: " + std::to_string(this->pokemon.hit_points));

		if (this->pokemon.hit_points <= 0)
		{
			return;
		}
	}

	if (move2_button.isClicked(mouse_position))
	{
		pokemon.hit_points += pokemon.move2.value;
		player_pokemon_health.setString("Health: " + std::to_string(pokemon.hit_points));
	}

	if (move3_button.isClicked(mouse_position))
	{
		this->pokemon.hit_points -= pokemon.move3.value * damageMultiplier(pokemon.move3.type, this->pokemon.type);
		enemy_pokemon_health.setString("Health: " + std::to_string(this->pokemon.hit_points));

		if (this->pokemon.hit_points <= 0)
		{
			return;
		}
	}

	if (move4_button.isClicked(mouse_position))
	{
		this->pokemon.hit_points -= pokemon.move4.value * damageMultiplier(pokemon.move4.type, this->pokemon.type);
		enemy_pokemon_health.setString("Health: " + std::to_string(this->pokemon.hit_points));

		if (this->pokemon.hit_points <= 0)
		{
			return;
		}
	}
}

void Battle::enemyTurn(sf::RenderWindow* battle_window, Pokemon* pokemon, sf::Text* player_pokemon_health, sf::Text* enemy_pokemon_health)
{
	std::srand(std::time(nullptr));

	switch (rand() % 4 + 1)
	{
	case 1:
	{
		pokemon->hit_points -= this->pokemon.move1.value * damageMultiplier(this->pokemon.move1.type, pokemon->type);
		player_pokemon_health->setString("Health: " + std::to_string(pokemon->hit_points));

		if (pokemon->hit_points <= 0)
		{
			battle_window->close();
		}
	}

	case 2:
	{
		this->pokemon.hit_points += this->pokemon.move2.value;
		enemy_pokemon_health->setString("Health: " + std::to_string(this->pokemon.hit_points));
		break;
	}

	case 3:
	{
		pokemon->hit_points -= this->pokemon.move3.value * damageMultiplier(this->pokemon.move3.type, pokemon->type);
		player_pokemon_health->setString("Health: " + std::to_string(pokemon->hit_points));

		if (pokemon->hit_points <= 0)
		{
			battle_window->close();
		}
		break;
	}

	case 4:
	{
		pokemon->hit_points -= this->pokemon.move4.value * damageMultiplier(this->pokemon.move4.type, pokemon->type);
		player_pokemon_health->setString("Health: " + std::to_string(pokemon->hit_points));

		if (pokemon->hit_points <= 0)
		{
			battle_window->close();
		}
		break;
	}
	}
}

float Battle::damageMultiplier(int move_type, int pokemon_type)
{
	switch (move_type)
	{
	case NORMAL:
	{
		switch (pokemon_type)
		{
		case NORMAL:
		{
			return 1;
		}

		case GRASS:
		{
			return 1;
		}

		case FIRE:
		{
			return 1;
		}

		case WATER:
		{
			return 1;
		}

		case ELECTRIC:
		{
			return 1;
		}
		}

		break;
	}

	case GRASS:
	{
		switch (pokemon_type)
		{
		case NORMAL:
		{
			return 1;
		}

		case GRASS:
		{
			return 0.5;
		}

		case FIRE:
		{
			return 0.5;
		}

		case WATER:
		{
			return 2;
		}

		case ELECTRIC:
		{
			return 1;
		}
		}

		break;
	}

	case FIRE:
	{
		switch (pokemon_type)
		{
		case NORMAL:
		{
			return 1;
		}

		case GRASS:
		{
			return 2;
		}

		case FIRE:
		{
			return 0.5;
		}

		case WATER:
		{
			return 0.5;
		}

		case ELECTRIC:
		{
			return 1;
		}
		}

		break;
	}

	case WATER:
	{
		switch (pokemon_type)
		{
		case NORMAL:
		{
			return 1;
		}

		case GRASS:
		{
			return 0.5;
		}

		case FIRE:
		{
			return 2;
		}

		case WATER:
		{
			return 0.5;
		}

		case ELECTRIC:
		{
			return 1;
		}
		}

		break;
	}

	case ELECTRIC:
	{
		switch (pokemon_type)
		{
		case NORMAL:
		{
			return 1;
		}

		case GRASS:
		{
			return 0.5;
		}

		case FIRE:
		{
			return 1;
		}

		case WATER:
		{
			return 2;
		}

		case ELECTRIC:
		{
			return 0.5;
		}
		}

		break;
	}
	}
}