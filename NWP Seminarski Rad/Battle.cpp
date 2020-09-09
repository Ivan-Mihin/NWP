#pragma once
#include "Battle.h"
#include "Pokemon.h"

Battle::Battle()
{
	font.loadFromFile("Fonts/Pokemon_GB.ttf");

	texture.loadFromFile("Textures/Battle_Background.png");
	background.setTexture(texture);
	background.setPosition(0.0f, 0.0f);
}
	
void Battle::start(Pokemon pokemon)
{
	sf::RenderWindow battle_window(sf::VideoMode(640, 480), "Battle", sf::Style::Titlebar);

	pokemonSelect();

	text1.setFont(font);
	text1.setString(this->pokemon.getName());
	text1.setCharacterSize(16);
	text1.setFillColor(sf::Color::White);
	text1.setStyle(sf::Text::Bold);
	text1.setPosition(10.0f, 10.0f);

	text2.setFont(font);
	text2.setString(pokemon.getName());
	text2.setCharacterSize(16);
	text2.setFillColor(sf::Color::White);
	text2.setStyle(sf::Text::Bold);

	text2.setOrigin(text2.getLocalBounds().left + text2.getLocalBounds().width,
		text2.getLocalBounds().top + text2.getLocalBounds().height);
	text2.setPosition(475.0f, 400.0f);

	pokemon.sprite.setScale(2.0f, 2.0f);
	pokemon.sprite.setOrigin(0, pokemon.sprite.getLocalBounds().top + pokemon.sprite.getLocalBounds().height);
	pokemon.sprite.setPosition(20, battle_window.getSize().y);

	while (battle_window.isOpen())
	{
		sf::Event battleEvent;

		while (battle_window.pollEvent(battleEvent))
		{
			switch (battleEvent.type)
			{
			case battleEvent.Closed:
			{
				battle_window.close();
				break;
			}
			}

		battle_window.clear();
		battle_window.draw(background);
		battle_window.draw(text1);
		battle_window.draw(text2);
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
		break;
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