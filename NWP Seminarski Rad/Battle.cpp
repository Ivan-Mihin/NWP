#pragma once
#include <string>
#include "Battle.h"

Battle::Battle()
{
	texture.loadFromFile("Textures/Battle_Background.png");
	background.setTexture(texture);
	background.setPosition(0.0f, 0.0f);

	enemy_turn = false;
	chat_clear = false;
	battle_end = false;
}

void Battle::start(Pokemon pokemon)
{
	sf::RenderWindow battle_window(sf::VideoMode(640, 480), "Battle", sf::Style::Titlebar);

	pokemonSelect();
	
	sf::Font font;
	font.loadFromFile("Fonts/Pokemon_GB.ttf");

	textInitialization(&enemy_pokemon_name, &font, 16, this->pokemon.getName(), sf::Color::Red, 10.0f, 10.0f, false);
	textInitialization(&enemy_pokemon_health, &font, 16, "Health: " + std::to_string(this->pokemon.hit_points), sf::Color::White, 10.0f, 30.0f, false);

	textInitialization(&player_pokemon_name, &font, 16, pokemon.getName(), sf::Color::Blue, 475.0f, 320.0f, true);
	textInitialization(&player_pokemon_health, &font, 16, "Health: " + std::to_string(this->pokemon.hit_points), sf::Color::White, 475.0f, 340.0f, true);

	textInitialization(&chat_text, &font, 16, "", sf::Color::Black, 20.0f, 410.0f, false);
	textInitialization(&chat_text2, &font, 16, "", sf::Color::Black, 20.0f, 435.0f, false);

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

	sf::Clock clock;
	sf::Time elapsed = clock.getElapsedTime();

	while (battle_window.isOpen())
	{
		sf::Event battle_event;

		if (enemy_turn)
		{
			clock.restart();
			elapsed = clock.getElapsedTime();

			while (elapsed.asSeconds() < 2.0f)
			{
				elapsed = clock.getElapsedTime();
			}

			enemyTurn(&battle_window, &pokemon);

			enemy_turn = false;
			chat_clear = true;
		}

		while (battle_window.pollEvent(battle_event))
		{
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
						playerTurn(pokemon, move1_button, move2_button, move3_button, move4_button, mouse_position, &battle_window);

						enemy_turn = true;
					}

					if (run_button.isClicked(mouse_position))
					{
						chat_text.setString("YOU RAN FROM BATTLE.");
						chat_text2.setString("");

						drawOnScreen(&battle_window, pokemon, move1_button, move2_button, move3_button, move4_button, run_button);

						clock.restart();
						elapsed = clock.getElapsedTime();

						while (elapsed.asSeconds() < 2.0f)
						{
							elapsed = clock.getElapsedTime();
						}

						return;
					}
				}
			}
			}
		}

		drawOnScreen(&battle_window, pokemon, move1_button, move2_button, move3_button, move4_button, run_button);

		if (battle_end)
		{
			if (this->pokemon.hit_points <= 0)
			{
				clock.restart();
				elapsed = clock.getElapsedTime();

				while (elapsed.asSeconds() < 2.0f)
				{
					elapsed = clock.getElapsedTime();
				}

				chat_text.setString(this->pokemon.getName() + " FAINTED.");
				chat_text2.setString("YOU WON!");

				drawOnScreen(&battle_window, pokemon, move1_button, move2_button, move3_button, move4_button, run_button);

				clock.restart();
				elapsed = clock.getElapsedTime();

				while (elapsed.asSeconds() < 2.0f)
				{
					elapsed = clock.getElapsedTime();
				}

				battle_window.close();
			}
			else if (pokemon.hit_points <= 0)
			{
				clock.restart();
				elapsed = clock.getElapsedTime();

				while (elapsed.asSeconds() < 2.0f)
				{
					elapsed = clock.getElapsedTime();
				}

				chat_text.setString(pokemon.getName() + " FAINTED.");
				chat_text2.setString("YOU LOST!");

				drawOnScreen(&battle_window, pokemon, move1_button, move2_button, move3_button, move4_button, run_button);

				clock.restart();
				elapsed = clock.getElapsedTime();

				while (elapsed.asSeconds() < 2.0f)
				{
					elapsed = clock.getElapsedTime();
				}

				battle_window.close();
			}
		}

		if (chat_clear)
		{
			clock.restart();
			elapsed = clock.getElapsedTime();

			while (elapsed.asSeconds() < 2.0f)
			{
				elapsed = clock.getElapsedTime();
			}

			chat_text.setString("");
			chat_text2.setString("");

			chat_clear = false;
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

void Battle::playerTurn(Pokemon pokemon, Button move1_button, Button move2_button, Button move3_button, Button move4_button, sf::Vector2i mouse_position, sf::RenderWindow* battle_window)
{
	if (move1_button.isClicked(mouse_position))
	{
		float multiplier = damageMultiplier(pokemon.move1.type, this->pokemon.type);
		this->pokemon.hit_points -= pokemon.move1.value * multiplier;

		if (this->pokemon.hit_points <= 0)
		{
			this->pokemon.hit_points = 0;
			battle_end = true;
		}

		enemy_pokemon_health.setString("Health: " + std::to_string(this->pokemon.hit_points));

		chat(pokemon, pokemon.move1, multiplier);
	}

	if (move2_button.isClicked(mouse_position))
	{
		pokemon.hit_points += pokemon.move2.value;
		player_pokemon_health.setString("Health: " + std::to_string(pokemon.hit_points));

		chat_text.setString(pokemon.getName() + " USED " + pokemon.move2.name + ".");
		chat_text2.setString("");
	}

	if (move3_button.isClicked(mouse_position))
	{
		float multiplier = damageMultiplier(pokemon.move3.type, this->pokemon.type);
		this->pokemon.hit_points -= pokemon.move3.value * multiplier;

		if (this->pokemon.hit_points <= 0)
		{
			this->pokemon.hit_points = 0;
			battle_end = true;
		}

		enemy_pokemon_health.setString("Health: " + std::to_string(this->pokemon.hit_points));

		chat(pokemon, pokemon.move3, multiplier);
	}

	if (move4_button.isClicked(mouse_position))
	{
		float multiplier = damageMultiplier(pokemon.move4.type, this->pokemon.type);
		this->pokemon.hit_points -= pokemon.move4.value * multiplier;

		if (this->pokemon.hit_points <= 0)
		{
			this->pokemon.hit_points = 0;
			battle_end = true;
		}

		enemy_pokemon_health.setString("Health: " + std::to_string(this->pokemon.hit_points));

		chat(pokemon, pokemon.move4, multiplier);
	}
}

void Battle::enemyTurn(sf::RenderWindow* battle_window, Pokemon* pokemon)
{
	std::srand(std::time(nullptr));

	switch (rand() % 4 + 1)
	{
	case 1:
	{
		float multiplier = damageMultiplier(this->pokemon.move1.type, pokemon->type);
		pokemon->hit_points -= this->pokemon.move1.value * multiplier;

		if (pokemon->hit_points <= 0)
		{
			pokemon->hit_points = 0;
			battle_end = true;
		}

		player_pokemon_health.setString("Health: " + std::to_string(pokemon->hit_points));

		chat(this->pokemon, this->pokemon.move1, multiplier);
		break;
	}

	case 2:
	{
		this->pokemon.hit_points += this->pokemon.move2.value;
		enemy_pokemon_health.setString("Health: " + std::to_string(this->pokemon.hit_points));

		chat_text.setString(this->pokemon.getName() + " USED " + this->pokemon.move2.name + ".");
		chat_text2.setString("");
		break;
	}

	case 3:
	{
		float multiplier = damageMultiplier(this->pokemon.move3.type, pokemon->type);
		pokemon->hit_points -= this->pokemon.move3.value * multiplier;

		if (pokemon->hit_points <= 0)
		{
			pokemon->hit_points = 0;
			battle_end = true;
		}

		player_pokemon_health.setString("Health: " + std::to_string(pokemon->hit_points));

		chat(this->pokemon, this->pokemon.move3, multiplier);
		break;
	}

	case 4:
	{
		float multiplier = damageMultiplier(this->pokemon.move4.type, pokemon->type);
		pokemon->hit_points -= this->pokemon.move4.value * multiplier;

		if (pokemon->hit_points <= 0)
		{
			pokemon->hit_points = 0;
			battle_end = true;
		}

		player_pokemon_health.setString("Health: " + std::to_string(pokemon->hit_points));

		chat(this->pokemon, this->pokemon.move4, multiplier);
		break;
	}
	}
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

void Battle::chat(Pokemon pokemon, Move move, float multiplier)
{
	chat_text.setString(pokemon.getName() + " USED " + move.name + ".");

	if (multiplier == 0.5)
	{
		chat_text2.setString("IT'S NOT VERY EFFECTIVE.");
	}
	else if (multiplier == 2)
	{
		chat_text2.setString("IT'S SUPER EFFECTIVE!");
	}
	else
	{
		chat_text2.setString("");
	}
}

void Battle::drawOnScreen(sf::RenderWindow* battle_window, Pokemon pokemon, Button move1_button, Button move2_button, Button move3_button, Button move4_button, Button run_button)
{
	battle_window->clear();
	battle_window->draw(background);

	battle_window->draw(enemy_pokemon_name);
	battle_window->draw(enemy_pokemon_health);

	battle_window->draw(player_pokemon_name);
	battle_window->draw(player_pokemon_health);

	battle_window->draw(chat_text);
	battle_window->draw(chat_text2);

	battle_window->draw(move1_button.sprite);
	battle_window->draw(move1_button.text);

	battle_window->draw(move2_button.sprite);
	battle_window->draw(move2_button.text);

	battle_window->draw(move3_button.sprite);
	battle_window->draw(move3_button.text);

	battle_window->draw(move4_button.sprite);
	battle_window->draw(move4_button.text);

	battle_window->draw(run_button.sprite);
	battle_window->draw(run_button.text);

	battle_window->draw(this->pokemon.sprite);
	battle_window->draw(pokemon.sprite);

	battle_window->display();
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