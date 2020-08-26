#pragma once

int const tile_size = 30;

class Map
{
	std::string map_name;	// Path to the .txt file
	int width;				// Map's width
	int height;				// Map's height

public:
	Map() {}
	~Map() {}

	//Variables
	sf::Vector2i** map;			// 2D array that stores information about tiles
	int** tile_information;		// 2D array that stores information about collision with terrain

	//Methods
	std::string returnMapName();					// Method that returns path to the .txt file
	int mapWidth();									// Method that returns map height
	int mapWidth(std::string mapName);				// Method that calculates and returns map's height
	int mapHeight();								// Method that returns map width
	int mapHeight(std::string mapName);				// Method that calculates and returns map's width
	sf::Vector2i** loadMap(std::string mapName);	// Method that loads tile information from a text file to a 2D array
};