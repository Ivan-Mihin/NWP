#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>

class Map
{
	std::string mapName;

public:
	Map() {}
	~Map() {}

	sf::Vector2i** map;
	sf::Vector2i** loadMap(std::string mapName);
};

sf::Vector2i** Map::loadMap(std::string mapName)
{
	this->mapName = mapName;
	std::ifstream file(mapName);
	if (!file.is_open())
	{
		return NULL;
	}

	int height = 30;
	int width = 30;

	map = new sf::Vector2i*[width];
	for (int w = 0; w < width; ++w)
	{
		map[w] = new sf::Vector2i[height];

		for (int h = 0; h < height; ++h)
		{
			map[w][h] = sf::Vector2i(0, 0);
		}
	}

	sf::Vector2i loadCounter = sf::Vector2i(0, 0);

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