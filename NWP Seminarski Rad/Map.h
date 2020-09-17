#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

unsigned int const tile_size = 30;

class Map
{
	sf::Texture tile_texture;
	std::string map_name;		// Path to the .txt file
	unsigned int width;			// Map's width
	unsigned int height;		// Map's height

public:
	Map();
	~Map() {}

	//Variables
	sf::Sprite tile;
	std::vector<std::vector<sf::Vector2i>> map;
	std::vector<std::vector<unsigned int>> tile_information;
	enum maps 
	{
		MAP1 = 1, 
		MAP2 = 2, 
		MAP3 = 3
	};
	int current_map;

	//Methods
	std::string returnMapName();						// Method that returns path to the .txt file
	unsigned int mapWidth();							// Method that returns map height
	unsigned int mapWidth(std::string mapName);			// Method that calculates and returns map's height
	unsigned int mapHeight();							// Method that returns map width
	unsigned int mapHeight(std::string mapName);		// Method that calculates and returns map's width
	void loadMap(std::string mapName);					// Method that loads tile information from a text file to a 2D array
	void drawTiles(sf::RenderWindow* window, float player_x, float player_y);
};