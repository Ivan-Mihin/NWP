#pragma once
#include <SFML/Graphics.hpp>

class Button
{
	sf::IntRect box;
	sf::Texture texture;

public:
	Button() {};
	Button(std::string path, int width, int height, float x, float y);
	~Button() {}

	sf::Text text;
	sf::Sprite sprite;

	bool isClicked(sf::Vector2i mouse_position);
	void textInitialization(sf::Font* font, int character_size, std::string string, sf::Color color);
};