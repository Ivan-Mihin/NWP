#pragma once
#include <SFML/Graphics.hpp>

class Intro
{
	sf::Font font;
	sf::Text text1;
	sf::Text text2;
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