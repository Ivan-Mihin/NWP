#pragma once
#include <SFML/Graphics.hpp>

class Intro
{
	sf::Font font;
	sf::Text text;
	int rgb_value;
	bool towards_white;
	bool towards_gray;

public:
	Intro();
	~Intro() {};

	sf::Texture texture;
	sf::Sprite sprite;

	void introSequence(sf::RenderWindow* window);
	int choosePokemon(sf::RenderWindow* window);
};