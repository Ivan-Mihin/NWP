#pragma once

class Button
{
	sf::IntRect box;
	sf::Texture texture;

public:
	Button() {};
	Button(std::string path, int width, int height, float x, float y, bool button_state);
	~Button() {}

	bool isEnabled;
	sf::Text text;
	sf::Sprite sprite;

	bool isClicked(sf::Vector2i mouse_position);
};