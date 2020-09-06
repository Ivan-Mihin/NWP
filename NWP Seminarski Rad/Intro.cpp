#pragma once
#include <SFML/Graphics.hpp>
#include "Intro.h"
#include "Pokemon.h"

Intro::Intro()
{
	texture.loadFromFile("Textures/Intro.jpg");
	sprite.setTexture(texture);
	sprite.setPosition(0.0f, 0.0f);

	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setString("PRESS ANY BUTTON TO CONTINUE");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	text.setPosition(105.0f, 350.0f);

	rgb_value = 255;
	towards_white = true;
	towards_gray = false;
}

void Intro::introSequence(sf::RenderWindow* window)
{
	while (window->isOpen())
	{
		sf::Event game_event;

		while (window->pollEvent(game_event))
		{
			switch (game_event.type)
			{
			case game_event.Closed:
			{
				window->close();
				break;
			}
			case game_event.KeyPressed:
			{
				return;
			}
			}
		}

		if (towards_white)
		{
			--rgb_value;

			if (rgb_value == 100)
			{
				towards_white = false;
				towards_gray = true;
			}
		}
		
		if (towards_gray)
		{
			++rgb_value;

			if (rgb_value == 255)
			{
				towards_white = true;
				towards_gray = false;
			}
		}
		
		text.setFillColor(sf::Color(rgb_value, rgb_value, rgb_value));

		window->clear();
		window->draw(sprite);
		window->draw(text);
		window->display();
	}
}

int Intro::choosePokemon(sf::RenderWindow* window)
{
	Pokemon pokemon;

	while (window->isOpen())
	{
		sf::Event game_event;

		while (window->pollEvent(game_event))
		{
			switch (game_event.type)
			{
			case game_event.Closed:
			{
				window->close();
				break;
			}
			}
		}

		//return pokemon.BULBASAUR;

		window->clear();
		window->draw(sprite);
		window->draw(text);
		window->display();
	}
}