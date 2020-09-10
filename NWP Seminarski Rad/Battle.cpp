#pragma once
#include <string>
#include "Battle.h"
#include "Button.h"
#include "Pokemon.h"

Battle::Battle()
{
	texture.loadFromFile("Textures/Battle_Background.png");
	background.setTexture(texture);
	background.setPosition(0.0f, 0.0f);
}
	
void Battle::start(Pokemon pokemon)
{
	sf::RenderWindow battle_window(sf::VideoMode(640, 480), "Battle", sf::Style::Titlebar);

	pokemonSelect();

	sf::Font font;
	font.loadFromFile("Fonts/Pokemon_GB.ttf");

	sf::Text enemy_pokemon_name;
	enemy_pokemon_name.setFont(font);
	enemy_pokemon_name.setString(this->pokemon.getName());
	enemy_pokemon_name.setCharacterSize(16);
	enemy_pokemon_name.setFillColor(sf::Color::White);
	enemy_pokemon_name.setStyle(sf::Text::Bold);
	enemy_pokemon_name.setPosition(10.0f, 10.0f);

	sf::Text enemy_pokemon_health;
	enemy_pokemon_health.setFont(font);
	enemy_pokemon_health.setString("Health: " + std::to_string(this->pokemon.hit_points));
	enemy_pokemon_health.setCharacterSize(16);
	enemy_pokemon_health.setFillColor(sf::Color::White);
	enemy_pokemon_health.setPosition(10.0f, 30.0f);

	sf::Text player_pokemon_name;
	player_pokemon_name.setFont(font);
	player_pokemon_name.setString(pokemon.getName());
	player_pokemon_name.setCharacterSize(16);
	player_pokemon_name.setFillColor(sf::Color::White);
	player_pokemon_name.setStyle(sf::Text::Bold);
	player_pokemon_name.setOrigin(player_pokemon_name.getLocalBounds().left + player_pokemon_name.getLocalBounds().width,
		player_pokemon_name.getLocalBounds().top + player_pokemon_name.getLocalBounds().height);
	player_pokemon_name.setPosition(475.0f, 400.0f);

	sf::Text player_pokemon_health;
	player_pokemon_health.setFont(font);
	player_pokemon_health.setString("Health: " + std::to_string(this->pokemon.hit_points));
	player_pokemon_health.setCharacterSize(16);
	player_pokemon_health.setFillColor(sf::Color::White);
	player_pokemon_health.setOrigin(player_pokemon_health.getLocalBounds().left + player_pokemon_health.getLocalBounds().width,
		player_pokemon_health.getLocalBounds().top + player_pokemon_health.getLocalBounds().height);
	player_pokemon_health.setPosition(475.0f, 420.0f);

	Button move1("Textures/Battle_Button.png", 135, 50, 495, 107);
	Button move2("Textures/Battle_Button.png", 135, 50, 495, 162);
	Button move3("Textures/Battle_Button.png", 135, 50, 495, 217);
	Button move4("Textures/Battle_Button.png", 135, 50, 495, 272);
	Button run("Textures/Battle_Button.png", 135, 50, 495, 420);

	sf::Font font2;
	font2.loadFromFile("Fonts/arial.ttf");

	move1.textInitialize(&font2, pokemon.move1.name, 15, sf::Color::Black);
	move2.textInitialize(&font2, pokemon.move2.name, 15, sf::Color::Black);
	move3.textInitialize(&font2, pokemon.move3.name, 15, sf::Color::Black);
	move4.textInitialize(&font2, pokemon.move4.name, 15, sf::Color::Black);
	run.textInitialize(&font2, "RUN", 15, sf::Color::Black);

	pokemon.sprite.setScale(2.0f, 2.0f);
	pokemon.sprite.setOrigin(0, pokemon.sprite.getLocalBounds().top + pokemon.sprite.getLocalBounds().height);
	pokemon.sprite.setPosition(20, battle_window.getSize().y);

	while (battle_window.isOpen())
	{
		sf::Event battle_event;

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
					if (move1.isClicked(mouse_position))
					{
						this->pokemon.hit_points -= pokemon.move1.value;
						enemy_pokemon_health.setString("Health: " + std::to_string(this->pokemon.hit_points));

						if (this->pokemon.hit_points <= 0)
						{
							return;
						}

						enemyAttack(&battle_window, &pokemon, &player_pokemon_health, &enemy_pokemon_health);
					}

					if (move2.isClicked(mouse_position))
					{
						pokemon.hit_points += pokemon.move2.value;
						player_pokemon_health.setString("Health: " + std::to_string(pokemon.hit_points));

						enemyAttack(&battle_window, &pokemon, &player_pokemon_health, &enemy_pokemon_health);
					}

					if (move3.isClicked(mouse_position))
					{
						this->pokemon.hit_points -= pokemon.move3.value;
						enemy_pokemon_health.setString("Health: " + std::to_string(this->pokemon.hit_points));

						if (this->pokemon.hit_points <= 0)
						{
							return;
						}

						enemyAttack(&battle_window, &pokemon, &player_pokemon_health, &enemy_pokemon_health);
					}

					if (move4.isClicked(mouse_position))
					{
						this->pokemon.hit_points -= pokemon.move4.value;
						enemy_pokemon_health.setString("Health: " + std::to_string(this->pokemon.hit_points));

						if (this->pokemon.hit_points <= 0)
						{
							return;
						}

						enemyAttack(&battle_window, &pokemon, &player_pokemon_health, &enemy_pokemon_health);
					}

					if (run.isClicked(mouse_position))
					{
						return;
					}
				}
			}
			}

		battle_window.clear();
		battle_window.draw(background);

		battle_window.draw(enemy_pokemon_name);
		battle_window.draw(enemy_pokemon_health);

		battle_window.draw(player_pokemon_name);
		battle_window.draw(player_pokemon_health);

		battle_window.draw(move1.sprite);
		battle_window.draw(move1.text);

		battle_window.draw(move2.sprite);
		battle_window.draw(move2.text);

		battle_window.draw(move3.sprite);
		battle_window.draw(move3.text);

		battle_window.draw(move4.sprite);
		battle_window.draw(move4.text);

		battle_window.draw(run.sprite);
		battle_window.draw(run.text);

		battle_window.draw(this->pokemon.sprite);
		battle_window.draw(pokemon.sprite);
		battle_window.display();
		}
	}
}

void Battle::pokemonSelect()
{
	std::srand(std::time(nullptr));

	switch (rand() % 4)
	{
	case 0:
	{
		pokemon.setPokemon(pokemon.BULBASAUR);
		pokemon.texture.loadFromFile("Pokemon/Bulbasaur.png", sf::IntRect(0, 0, 128, 128));
		pokemon.sprite.setTexture(this->pokemon.texture);
	}
	case 1:
	{
		pokemon.setPokemon(pokemon.CHARMANDER);
		pokemon.texture.loadFromFile("Pokemon/Charmander.png", sf::IntRect(0, 0, 128, 128));
		pokemon.sprite.setTexture(this->pokemon.texture);
		break;
	}
	case 2:
	{
		pokemon.setPokemon(pokemon.SQUIRTLE);
		pokemon.texture.loadFromFile("Pokemon/Squirtle.png", sf::IntRect(0, 0, 128, 128));
		pokemon.sprite.setTexture(this->pokemon.texture);

		break;
	}
	case 3:
	{
		pokemon.setPokemon(pokemon.PIKACHU);
		pokemon.texture.loadFromFile("Pokemon/Pikachu.png", sf::IntRect(0, 0, 128, 128));
		pokemon.sprite.setTexture(this->pokemon.texture);
		break;
	}
	}

	pokemon.sprite.setPosition(325, 100);
}

void Battle::enemyAttack(sf::RenderWindow* battle_window, Pokemon* pokemon, sf::Text* player_pokemon_health, sf::Text* enemy_pokemon_health)
{
	std::srand(std::time(nullptr));

	switch (rand() % 4 + 1)
	{
	case 1:
	{
		pokemon->hit_points -= this->pokemon.move1.value;
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
		pokemon->hit_points -= this->pokemon.move3.value;
		player_pokemon_health->setString("Health: " + std::to_string(pokemon->hit_points));

		if (pokemon->hit_points <= 0)
		{
			battle_window->close();
		}
		break;
	}

	case 4:
	{
		pokemon->hit_points -= this->pokemon.move4.value;
		player_pokemon_health->setString("Health: " + std::to_string(pokemon->hit_points));

		if (pokemon->hit_points <= 0)
		{
			battle_window->close();
		}
		break;
	}
	}
}