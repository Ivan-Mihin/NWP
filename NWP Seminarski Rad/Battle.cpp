#include <SFML/Graphics.hpp>
#include "Battle.h"
#include "Pokemon.h"
#include "Bulbasaur.h"
#include "Charmander.h"
#include "Squirtle.h"
#include "Pikachu.h"
#include "Player.h"

Battle::Battle()
{
	font.loadFromFile("Fonts/Pokemon_GB.ttf");

	texture.loadFromFile("Textures/Battle_Background.png");
	background.setTexture(texture);
	background.setPosition(0.0f, 0.0f);
}

void Battle::start(Pokemon pokemon)
{
	sf::RenderWindow battleWindow(sf::VideoMode(640, 480), "Battle");

	pokemonSelect();

	text1.setFont(font);
	text1.setString(this->pokemon.getName());
	text1.setCharacterSize(16);
	text1.setFillColor(sf::Color::White);
	text1.setStyle(sf::Text::Bold);
	text1.setPosition(5.0f, 5.0f);

	text2.setFont(font);
	text2.setString(pokemon.getName());
	text2.setCharacterSize(16);
	text2.setFillColor(sf::Color::White);
	text2.setStyle(sf::Text::Bold);

	text2.setOrigin(text2.getLocalBounds().left + text2.getLocalBounds().width,
		text2.getLocalBounds().top + text2.getLocalBounds().height);
	text2.setPosition(280.0f, 250.0f);


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
		}

		battleWindow.clear();
		battleWindow.draw(background);
		battleWindow.draw(text1);
		battleWindow.draw(text2);
		battleWindow.display();
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
		break;
	}
	case 1:
	{
		pokemon.setPokemon(pokemon.CHARMANDER);
		break;
	}
	case 2:
	{
		pokemon.setPokemon(pokemon.SQUIRTLE);
		break;
	}
	case 3:
	{
		pokemon.setPokemon(pokemon.PIKACHU);
		break;
	}
	}
}