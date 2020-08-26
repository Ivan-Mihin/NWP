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

		player.keyboardInput(&loaded_map);
		player.moving(&loaded_map);
		player.sprite.setPosition(player.getX(), player.getY());

		for (int w = 0; w < loaded_map.mapWidth(); ++w)
		{
			for (int h = 0; h < loaded_map.mapHeight(); ++h)
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