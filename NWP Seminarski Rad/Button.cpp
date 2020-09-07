#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

Button::Button(std::string path, int width, int height, float x, float y, bool button_state)
{
	texture.loadFromFile(path, sf::IntRect(0, 0, width, height));
	sprite.setTexture(texture);
	sprite.setPosition(x, y);

	box.left = sprite.getPosition().x;
	box.top = sprite.getPosition().y;
	box.width = sprite.getGlobalBounds().width;
	box.height = sprite.getGlobalBounds().height;

	isEnabled = button_state;
}

bool Button::isClicked(sf::Vector2i mouse_position)
{
	return box.contains(mouse_position.x, mouse_position.y);
}