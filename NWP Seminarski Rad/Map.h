#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>

class Map
{
	std::string mapName;	// Path to the .txt file
	int width;				// Map's width
	int height;				// Map's height

public:
	Map() {}
	~Map() {}

	//Variables
	sf::Vector2i** map;		// 2D array that stores information about tiles

	//Methods
	std::string returnMapName();					// Method that returns path to the .txt file
	int mapWidth();									// Method that returns map height
	int mapWidth(std::string mapName);				// Method that calculates and returns map's height
	int mapHeight();								// Method that returns map width
	int mapHeight(std::string mapName);				// Method that calculates and returns map's width
	sf::Vector2i** loadMap(std::string mapName);	// Method that loads tile information from a text file to a 2D array
};

std::string Map::returnMapName()
{
	return this->mapName;
}

int Map::mapWidth()
{
	return this->width;
}

int Map::mapWidth(std::string mapName)
{
	std::ifstream file(mapName);
	std::string str;

	std::getline(file, str);
	file.close();

	return str.length() / 6 + 1;
}

int Map::mapHeight()
{
	return this->height;
}

int Map::mapHeight(std::string mapName)
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

sf::Vector2i** Map::loadMap(std::string mapName)
{
	this->mapName = mapName;
	std::ifstream file(mapName);
	if (!file.is_open())
	{
		return NULL;
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

	sf::Vector2i loadCounter = sf::Vector2i(0, 0);		// Variable for iterating through a .txt file

	while (!file.eof())
	{
		std::string str;
		file >> str;

		char x = str[0];
		char y = str[2];

		map[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0', y - '0');

		if (file.peek() == '\n')
		{
			loadCounter.x = 0;
			loadCounter.y++;
		}
		else
		{
			loadCounter.x++;
		}
	}

	file.close();

	return map;
}