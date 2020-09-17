#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <vector>
#include "Map.h"
#include "Player.h"

Map::Map()
{
	tile_texture.loadFromFile("Textures/Tile_Set.png");
	tile.setTexture(tile_texture);

	loadMap("Maps/Map1.txt");
	current_map = MAP1;
}

std::string Map::returnMapName()
{
	return this->map_name;
}

unsigned int Map::mapWidth()
{
	return this->width;
}

unsigned int Map::mapWidth(std::string mapName)
{
	std::ifstream file(mapName);
	std::string str;

	std::getline(file, str);
	file.close();

	return str.length() / 6 + 1;
}

unsigned int Map::mapHeight()
{
	return this->height;
}

unsigned int Map::mapHeight(std::string mapName)
{
	std::ifstream file(mapName);
	std::string str;

	int counter = 0;

	while (std::getline(file, str))
	{
		++counter;
	}

	file.close();

	return counter;
}

void Map::loadMap(std::string mapName)
{
	this->map_name = mapName;

	std::ifstream file(mapName);
	if (!file.is_open())
	{
		return;
	}

	height = mapHeight(mapName);	// number of rows
	width = mapWidth(mapName);		// number of columns

	map.clear();
	tile_information.clear();

	for (int i = 0; i < width; ++i)
	{
		std::vector<sf::Vector2i> vector;
		map.push_back(vector);
	}

	for (int i = 0; i < width; ++i)
	{
		std::vector<unsigned int> vector;
		tile_information.push_back(vector);
	}

	sf::Vector2i load_counter = sf::Vector2i(0, 0);		// Variable for iterating through a .txt file

	while (!file.eof())
	{
		std::string str;
		file >> str;

		int x = std::stoi(str.substr(0, 2));
		int y = std::stoi(str.substr(3, 5));
		int c = std::stoi(str.substr(6, 8));

		map[load_counter.x].push_back(sf::Vector2i(x, y));
		tile_information[load_counter.x].push_back(c);

		if (file.peek() == '\n')
		{
			load_counter.x = 0;
			load_counter.y++;
		}
		else
		{
			load_counter.x++;
		}
	}

	file.close();
}

void Map::drawTiles(sf::RenderWindow* window, float player_x, float player_y)
{
	int offset = 7;
	sf::Vector2i first_drawn_tile = sf::Vector2i(player_x / tile_size - offset, player_y / tile_size - offset);

	if (first_drawn_tile.x < 0)
	{
		first_drawn_tile = sf::Vector2i(0, player_y / tile_size - offset);
	}

	if (first_drawn_tile.y < 0)
	{
		first_drawn_tile = sf::Vector2i(player_x / tile_size - offset, 0);
	}

	for (int w = first_drawn_tile.x; w < first_drawn_tile.x + offset * 2 + 1; ++w)
	{
		for (int h = first_drawn_tile.y; h < first_drawn_tile.y + offset * 2 + 1; ++h)
		{
			tile.setPosition(w * tile_size, h * tile_size);
			tile.setTextureRect(sf::IntRect(map[w][h].x * tile_size,
				map[w][h].y * tile_size, tile_size, tile_size));
			window->draw(tile);
		}
	}
}