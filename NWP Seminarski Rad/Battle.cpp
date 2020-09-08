#pragma once
#include "Battle.h"
#include "Pokemon.h"

Battle::Battle()
{
	font.loadFromFile("arial.ttf");

	text1.setFont(font);
	text1.setString("Hello world");
	text1.setCharacterSize(24);
	text1.setFillColor(sf::Color::Red);
	text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text1.setPosition(50.0f, 50.0f);

	text2.setFont(font);
	text2.setString("Hello world");
	text2.setCharacterSize(24);
	text2.setFillColor(sf::Color::Red);
	text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text2.setPosition(250.0f, 250.0f);
}

void Battle::start()
{
	sf::RenderWindow battleWindow(sf::VideoMode(800, 600), "Battle");

	pokemonSelect();

	while (battleWindow.isOpen())
	{
		sf::Event battleEvent;

		while (battleWindow.pollEvent(battleEvent))
		{
			switch (battleEvent.type)
			{
			case battleEvent.Closed:
			{
				battleWindow.close();
				break;
			}
			}

			battleWindow.clear();
			battleWindow.draw(text1);
			battleWindow.draw(text2);
			battleWindow.display();
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
		chosen_pokemon = pokemon.BULBASAUR;
		pokemon.texture.loadFromFile("Bulbasaur.png", sf::IntRect(0, 0, 128, 128));
		pokemon.sprite.setTexture(pokemon.texture);
		break;
	}
	case 1:
	{
		chosen_pokemon = pokemon.CHARMANDER;
		pokemon.texture.loadFromFile("Charmander.png", sf::IntRect(0, 0, 128, 128));
		pokemon.sprite.setTexture(pokemon.texture);
		break;
	}
	case 2:
	{
		chosen_pokemon = pokemon.SQUIRTLE;
		pokemon.texture.loadFromFile("Squirtle.png", sf::IntRect(0, 0, 128, 128));
		pokemon.sprite.setTexture(pokemon.texture);
		break;
	}
	case 3:
	{
		chosen_pokemon = pokemon.PIKACHU;
		pokemon.texture.loadFromFile("Pikachu.png", sf::IntRect(0, 0, 128, 128));
		pokemon.sprite.setTexture(pokemon.texture);
		break;
	}
	}
}