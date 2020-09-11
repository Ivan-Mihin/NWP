#pragma once
#include <SFML/Graphics.hpp>

class Intro
{
	sf::Texture texture;	// Texture for the intro screen

public:
	Intro();
	~Intro() {};

	sf::Sprite sprite;		// Sprite for the intro screen

	void introSequence(sf::RenderWindow* window);		// Loads the intro screen and requires press of any button
	int choosePokemon(sf::RenderWindow* window);		// Returns a flag for the pokemon you chose
	void textInitialization(sf::Font* font, sf::Text* text, int character_size, std::string string, sf::Color color, float x, float y);		// Initialize text
	void textUpdate(sf::Text* text, std::string string, int x, float y);		// Update text
};