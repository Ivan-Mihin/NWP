#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "Audio.h"
#include "Intro.h"
#include "Map.h"
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Pokemon", sf::Style::Titlebar | sf::Style::Close);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(350.0f, 350.0f));

	std::srand(std::time(nullptr));

	// Playing music
	Audio audio;

	Player player;

	Intro intro;
	intro.introSequence(&window);
	
	player.pokemon.setPokemon(intro.choosePokemon(&window));

	// Creating a Map object and loading a map into it
	Map loaded_map;

	audio.changeMusic("Audio/Map1Music.ogg", 25);

	while (window.isOpen())
	{
		sf::Event game_event;

		while (window.pollEvent(game_event))
		{
			switch (game_event.type)
			{
			case game_event.Closed:
			{
				window.close();
				break;
			}		
			}
		}

		window.clear();

		view.setCenter(player.sprite.getPosition().x + player.sprite.getGlobalBounds().width / 2,
					   player.sprite.getPosition().y + player.sprite.getGlobalBounds().height / 2);
		window.setView(view);

		player.keyboardInput(loaded_map.tile_information);
		player.movement(&loaded_map, &audio);
		player.sprite.setPosition(player.getX(), player.getY());

		loaded_map.drawTiles(&window, player.getX(), player.getY());

		window.draw(player.sprite);
		window.display();
	}

	return 0;
}