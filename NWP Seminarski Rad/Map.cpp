#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include "Map.h"

Map::Map()
{
	loadMap("Maps/Map1.txt");
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

	map = new sf::Vector2i*[width];
	for (int w = 0; w < width; ++w)
	{
		map[w] = new sf::Vector2i[height];

		for (int h = 0; h < height; ++h)
		{
			map[w][h] = sf::Vector2i(0, 0);
		}
	}

	tile_information = new unsigned int*[width];
	for (int w = 0; w < width; ++w)
	{
		tile_information[w] = new unsigned int[height];

		for (int h = 0; h < height; ++h)
		{
			tile_information[w][h] = 0;
		}
	}

	sf::Vector2i load_counter = sf::Vector2i(0, 0);		// Variable for iterating through a .txt file

	while (!file.eof())
	{
		std::string str;
		file >> str;

		char x = str[0];
		char y = str[2];
		char c = str[4];

		map[load_counter.x][load_counter.y] = sf::Vector2i(x - '0', y - '0');
		tile_information[load_counter.x][load_counter.y] = c - '0';

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