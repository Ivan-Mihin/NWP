#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>
#include "Map.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Pokemon");
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(350.0f, 350.0f));
	const int tile_width = 30;
	const int tile_height = 30;

	// Texture and Sprite for the player
	sf::Texture player_texture[4];
	sf::Sprite player;
	player_texture[0].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(0, 0, 30, 30));
	player_texture[1].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(30, 0, 30, 30));
	player_texture[2].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(0, 30, 30, 30));
	player_texture[3].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(30, 30, 30, 30));
	player.setTexture(player_texture[0]);
	player.setPosition(210, 210);

	// Texture and Sprite for the tiles (map)
	sf::Texture tile_texture;
	sf::Sprite tile;
	tile_texture.loadFromFile("Textures/Tile_Set.png");
	tile.setTexture(tile_texture);

	// Creating a Map object and loading a map into it
	Map loaded_map;
	loaded_map.loadMap("Maps/Map1.txt");

	// Variable for storing position for a current tile
	sf::Vector2i currentTile;

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

			case sf::Event::KeyPressed:
			{
				switch (game_event.key.code)
				{
				case sf::Keyboard::W:
				case sf::Keyboard::Up:
				{
					player.setTexture(player_texture[3]);

					switch (loaded_map.tile_information[currentTile.x][currentTile.y - 1])
					{
					case 4:
					{
						player.move(0, -tile_height);
						break;
					}
					}

					break;
				}

				case sf::Keyboard::A:
				case sf::Keyboard::Left:
				{
					player.setTexture(player_texture[1]);

					switch (loaded_map.tile_information[currentTile.x - 1][currentTile.y])
					{
					case 1:
					{
						loaded_map.map = loaded_map.loadMap("Maps/Map1.txt");
						player.setPosition(28 * tile_width, player.getPosition().y);
						break;
					}

					case 4:
					{
						player.move(-tile_width, 0);
						break;
					}
					}

					break;
				}

				case sf::Keyboard::S:
				case sf::Keyboard::Down:
				{
					player.setTexture(player_texture[0]);

					switch (loaded_map.tile_information[currentTile.x][currentTile.y + 1])
					{
					case 4:
					{
						player.move(0, tile_height);
						break;
					}
					}

					break;
				}

				case sf::Keyboard::D:
				case sf::Keyboard::Right:
				{
					player.setTexture(player_texture[2]);

					switch (loaded_map.tile_information[currentTile.x + 1][currentTile.y])
					{
					case 2:
					{
						loaded_map.map = loaded_map.loadMap("Maps/Map2.txt");
						player.setPosition(tile_width, player.getPosition().y);
						break;
					}

					case 4:
					{
						player.move(tile_width, 0);
						break;
					}
					}

					break;
				}
				}
			}
			}
		}

		view.setCenter(player.getPosition().x + player.getGlobalBounds().width / 2,
					   player.getPosition().y + player.getGlobalBounds().height / 2);
		window.setView(view);

		currentTile = sf::Vector2i(player.getPosition().x / tile_width, player.getPosition().y / tile_height);

		window.clear();

		for (int h = 0; h < loaded_map.mapHeight(); ++h)
		{
			for (int w = 0; w < loaded_map.mapWidth(); ++w)
			{
				tile.setPosition(h * tile_height, w * tile_width);
				tile.setTextureRect(sf::IntRect(loaded_map.map[h][w].x * tile_width,
												loaded_map.map[h][w].y * tile_height, tile_width, tile_height));
				window.draw(tile);
			}
		}

		window.draw(player);
		window.display();
	}

	return 0;
}