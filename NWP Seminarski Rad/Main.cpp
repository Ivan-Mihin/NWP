#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "Audio.h"
#include "Intro.h"
#include "Map.h"
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Pokemon");
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(350.0f, 350.0f));

	// Playing music
	Audio audio;

	Player player;

	Intro intro;
	intro.introSequence(&window);
	
	player.pokemon.setPokemonStats(intro.choosePokemon(&window));

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

		int offset = 7;
		sf::Vector2i first_drawn_tile = sf::Vector2i(player.getX() / tile_size - offset, player.getY() / tile_size - offset);

		if (first_drawn_tile.x < 0) 
		{
			first_drawn_tile = sf::Vector2i(0, player.getY() / tile_size - offset);
		}

		if (first_drawn_tile.y < 0)
		{
			first_drawn_tile = sf::Vector2i(player.getX() / tile_size - offset, 0);
		}

		for (int w = first_drawn_tile.x; w < first_drawn_tile.x + offset * 2 + 1; ++w)
		{
			for (int h = first_drawn_tile.y; h < first_drawn_tile.y + offset * 2 + 1; ++h)
			{
				loaded_map.tile.setPosition(w * tile_size, h * tile_size);
				loaded_map.tile.setTextureRect(sf::IntRect(loaded_map.map[w][h].x * tile_size,
												loaded_map.map[w][h].y * tile_size, tile_size, tile_size));
				window.draw(loaded_map.tile);
			}
		}

		window.draw(player.sprite);
		window.display();
	}

	return 0;
}