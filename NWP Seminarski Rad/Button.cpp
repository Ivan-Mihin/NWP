#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

Button::Button(std::string path, int width, int height, float x, float y)
{
	texture.loadFromFile(path, sf::IntRect(0, 0, width, height));
	sprite.setTexture(texture);
	sprite.setPosition(x, y);

	box.left = sprite.getPosition().x;
	box.top = sprite.getPosition().y;
	box.width = sprite.getGlobalBounds().width;
	box.height = sprite.getGlobalBounds().height;
}

bool Button::isClicked(sf::Vector2i mouse_position)
{
	return box.contains(mouse_position.x, mouse_position.y);
}

void Button::textInitialization(sf::Font* font, int character_size, std::string string, sf::Color color)
{
	text.setFont(*font);
	text.setCharacterSize(character_size);
	text.setString(string);
	text.setFillColor(color);

	text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width / 2.0f,
				   text.getLocalBounds().top + text.getLocalBounds().height / 2.0f);

	text.setPosition(sprite.getGlobalBounds().left + sprite.getGlobalBounds().width / 2.0f,
					 sprite.getGlobalBounds().top + sprite.getGlobalBounds().height / 2.0f);
}