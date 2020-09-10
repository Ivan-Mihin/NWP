#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Intro.h"
#include "Pokemon.h"

Intro::Intro()
{
	texture.loadFromFile("Textures/Intro.jpg");
	sprite.setTexture(texture);
	sprite.setPosition(0.0f, 0.0f);

	font.loadFromFile("Fonts/Pokemon_GB.ttf");
}

void Intro::introSequence(sf::RenderWindow* window)
{
	text1.setFont(font);
	text1.setString("PRESS ANY BUTTON");
	text1.setCharacterSize(24);
	text1.setFillColor(sf::Color::White);
	text1.setStyle(sf::Text::Bold);
	text1.setOrigin(text1.getLocalBounds().left + text1.getLocalBounds().width / 2.0f,
		text1.getLocalBounds().top + text1.getLocalBounds().height / 2.0f);
	text1.setPosition((float)(window->getSize().x / 2), 350.0f);

	text2.setFont(font);
	text2.setString("TO CONTINUE");
	text2.setCharacterSize(24);
	text2.setFillColor(sf::Color::White);
	text2.setStyle(sf::Text::Bold);
	text2.setOrigin(text2.getLocalBounds().left + text2.getLocalBounds().width / 2.0f,
		text2.getLocalBounds().top + text2.getLocalBounds().height / 2.0f);
	text2.setPosition((float)(window->getSize().x / 2), 380.0f);

	rgb_value = 255;
	towards_white = true;
	towards_gray = false;

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

			case game_event.MouseButtonPressed:
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

		text1.setFillColor(sf::Color(rgb_value, rgb_value, rgb_value));
		text2.setFillColor(sf::Color(rgb_value, rgb_value, rgb_value));

		window->clear();
		window->draw(sprite);
		window->draw(text1);
		window->draw(text2);
		window->display();
	}
}

int Intro::choosePokemon(sf::RenderWindow* window)
{
	Pokemon pokemon;

	Button bulbasaur_button("Textures/Bulbasaur_Button.png", 128, 128, 25.0f, 150.0f);
	Button charmander_button("Textures/Charmander_Button.png", 128, 128, 178.0f, 150.0f);
	Button squirtle_button("Textures/Squirtle_Button.png", 128, 128, 331.0f, 150.0f);
	Button pikachu_button("Textures/Pikachu_Button.png", 128, 128, 484.0f, 150.0f);
	Button confirm_button("Textures/Button.png", 250, 150, 210.0f, 325.0f);

	text1.setFillColor(sf::Color::White);
	text1.setCharacterSize(36);
	text1.setString("CHOOSE A POKEMON");
	text1.setOrigin(text1.getLocalBounds().left + text1.getLocalBounds().width / 2.0f,
		text1.getLocalBounds().top + text1.getLocalBounds().height / 2.0f);
	text1.setPosition((float)(window->getSize().x / 2), 75.0f);

	text2.setFillColor(sf::Color::White);
	text2.setString("");

	int choice;
	bool confirm_button_is_enabled = false;

	while (window->isOpen())
	{
		sf::Event game_event;

		if (confirm_button_is_enabled)
		{
			confirm_button.textInitialize(&font, "CONFIRM", 24, sf::Color::White);
		}

		while (window->pollEvent(game_event))
		{
			switch (game_event.type)
			{
			case game_event.Closed:
			{
				window->close();
				break;
			}

			case game_event.MouseButtonPressed:
			{
				sf::Vector2i mouse_position = sf::Mouse::getPosition(*window);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (bulbasaur_button.isClicked(mouse_position))
					{
						text1.setString("BULBASAUR");
						text1.setOrigin(text1.getLocalBounds().left + text1.getLocalBounds().width / 2.0f,
							text1.getLocalBounds().top + text1.getLocalBounds().height / 2.0f);
						text1.setPosition((float)(window->getSize().x / 2), 75.0f);
						choice = pokemon.BULBASAUR;
						confirm_button_is_enabled = true;
					}

					if (charmander_button.isClicked(mouse_position))
					{
						text1.setString("CHARMANDER");
						text1.setOrigin(text1.getLocalBounds().left + text1.getLocalBounds().width / 2.0f,
							text1.getLocalBounds().top + text1.getLocalBounds().height / 2.0f);
						text1.setPosition((float)(window->getSize().x / 2), 75.0f);
						choice = pokemon.CHARMANDER;
						confirm_button_is_enabled = true;
					}

					if (squirtle_button.isClicked(mouse_position))
					{
						text1.setString("SQUIRTLE");
						text1.setOrigin(text1.getLocalBounds().left + text1.getLocalBounds().width / 2.0f,
							text1.getLocalBounds().top + text1.getLocalBounds().height / 2.0f);
						text1.setPosition((float)(window->getSize().x / 2), 75.0f);
						choice = pokemon.SQUIRTLE;
						confirm_button_is_enabled = true;
					}

					if (pikachu_button.isClicked(mouse_position))
					{
						text1.setString("PIKACHU");
						text1.setOrigin(text1.getLocalBounds().left + text1.getLocalBounds().width / 2.0f,
							text1.getLocalBounds().top + text1.getLocalBounds().height / 2.0f);
						text1.setPosition((float)(window->getSize().x / 2), 75.0f);
						choice = pokemon.PIKACHU;
						confirm_button_is_enabled = true;
					}

					if (confirm_button_is_enabled)
					{
						if (confirm_button.isClicked(mouse_position))
						{
							return choice;
						}
					}
				}
			}
			}
		}

		window->clear();
		window->draw(bulbasaur_button.sprite);
		window->draw(charmander_button.sprite);
		window->draw(squirtle_button.sprite);
		window->draw(pikachu_button.sprite);

		if (confirm_button_is_enabled)
		{
			window->draw(confirm_button.sprite);
			window->draw(confirm_button.text);
		}

		window->draw(text1);
		window->draw(text2);
		window->display();
	}
}