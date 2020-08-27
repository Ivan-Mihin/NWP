#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>
#include "Map.h"
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Pokemon");
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(350.0f, 350.0f));
	const int tile_width = 30;
	const int tile_height = 30;

	// Texture and Sprite for the tiles (map)
	sf::Texture tile_texture;
	sf::Sprite tile;
	tile_texture.loadFromFile("Textures/Tile_Set.png");
	tile.setTexture(tile_texture);

	// Creating a Map object and loading a map into it
	Map loaded_map;
	loaded_map.loadMap("Maps/Map1.txt");

	// Playing music
	sf::Music music;
	music.openFromFile("Audio/Map1Music.ogg");
	music.play();

	Player player;

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
		player.moving(&loaded_map, &music);
		player.sprite.setPosition(player.getX(), player.getY());

		int offset = 7;
		sf::Vector2i first_drawn_tile = sf::Vector2i(player.getX() / 30 - offset, player.getY() / 30 - offset);

		if (first_drawn_tile.x < 0) 
		{
			first_drawn_tile = sf::Vector2i(0, player.getY() / 30 - offset);
		}

		if (first_drawn_tile.y < 0)
		{
			first_drawn_tile = sf::Vector2i(player.getX() / 30 - offset, 0);
		}

		for (int w = first_drawn_tile.x; w < first_drawn_tile.x + offset * 2 + 1; ++w)
		{
			for (int h = first_drawn_tile.y; h < first_drawn_tile.y + offset * 2 + 1; ++h)
			{
				tile.setPosition(w * tile_width, h * tile_height);
				tile.setTextureRect(sf::IntRect(loaded_map.map[w][h].x * tile_width,
					loaded_map.map[w][h].y * tile_height, tile_width, tile_height));
				window.draw(tile);
			}
		}

		window.draw(player.sprite);
		window.display();
	}

	return 0;
}