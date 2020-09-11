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
}

void Intro::introSequence(sf::RenderWindow* window)
{
	sf::Font font;
	font.loadFromFile("Fonts/Pokemon_GB.ttf");

	sf::Text text1;
	textInitialization(&font, &text1, 24, "PRESS ANY BUTTON", sf::Color::White, (float)(window->getSize().x / 2), 350.0f);

	sf::Text text2;
	textInitialization(&font, &text2, 24, "TO CONTINUE", sf::Color::White, (float)(window->getSize().x / 2), 380.0f);

	int rgb_value = 0;				// RGB value used for coloring text 
	bool towards_white = true;		// Flag used for increasing RGB value towards 255
	bool towards_gray = false;		// Flag used for decreasing RGB value towards 

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

		// Color of text going from gray to white
		if (towards_white)
		{
			++rgb_value;

			if (rgb_value == 255)
			{
				towards_white = false;
				towards_gray = true;
			}
		}

		// Color of text going from white to gray
		if (towards_gray)
		{
			--rgb_value;

			if (rgb_value == 100)
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
	sf::Font font;
	font.loadFromFile("Fonts/Pokemon_GB.ttf");

	Button bulbasaur_button("Textures/Bulbasaur_Button.png", 128, 128, 25.0f, 150.0f);
	Button charmander_button("Textures/Charmander_Button.png", 128, 128, 178.0f, 150.0f);
	Button squirtle_button("Textures/Squirtle_Button.png", 128, 128, 331.0f, 150.0f);
	Button pikachu_button("Textures/Pikachu_Button.png", 128, 128, 484.0f, 150.0f);
	Button confirm_button("Textures/Button.png", 250, 150, 210.0f, 325.0f);

	sf::Text text;
	textInitialization(&font, &text, 36, "CHOOSE A POKEMON", sf::Color::White, (float)(window->getSize().x / 2), 75.0f);

	int choice;									// Flag for the chosen pokemon
	bool confirm_button_is_enabled = false;		// Flag that hides confirm button until a choice is made

	while (window->isOpen())
	{
		sf::Event game_event;

		if (confirm_button_is_enabled)
		{
			confirm_button.textInitialization(&font, 24, "CONFIRM", sf::Color::White);
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
						textUpdate(&text, "BULBASAUR", (float)(window->getSize().x / 2), 75.0f);
						choice = BULBASAUR;
						confirm_button_is_enabled = true;
					}

					if (charmander_button.isClicked(mouse_position))
					{
						textUpdate(&text, "CHARMANDER", (float)(window->getSize().x / 2), 75.0f);
						choice = CHARMANDER;
						confirm_button_is_enabled = true;
					}

					if (squirtle_button.isClicked(mouse_position))
					{
						textUpdate(&text, "SQUIRTLE", (float)(window->getSize().x / 2), 75.0f);
						choice = SQUIRTLE;
						confirm_button_is_enabled = true;
					}

					if (pikachu_button.isClicked(mouse_position))
					{
						textUpdate(&text, "PIKACHU", (float)(window->getSize().x / 2), 75.0f);
						choice = PIKACHU;
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

		window->draw(text);
		window->display();
	}
}

void Intro::textInitialization(sf::Font* font, sf::Text* text, int character_size, std::string string, sf::Color color, float x, float y)
{
	text->setFont(*font);
	text->setCharacterSize(character_size);
	text->setString(string);
	text->setFillColor(color);

	text->setOrigin(text->getLocalBounds().left + text->getLocalBounds().width / 2.0f,
		text->getLocalBounds().top + text->getLocalBounds().height / 2.0f);

	text->setPosition(x, y);
}

void Intro::textUpdate(sf::Text* text, std::string string, int x, float y)
{
	text->setString(string);

	text->setOrigin(text->getLocalBounds().left + text->getLocalBounds().width / 2.0f,
		text->getLocalBounds().top + text->getLocalBounds().height / 2.0f);

	text->setPosition(x, y);
}