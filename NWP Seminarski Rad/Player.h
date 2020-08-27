#pragma once
#include "Audio.h"

class Player
{
	float movement_speed;
	bool is_moving;
	bool move[4];
	unsigned int animation_counter;
	unsigned int loops_per_tile_change;
	sf::Texture texture[12];
	sf::Vector2f current_tile;
	sf::Vector2i next_tile;
	enum MOVE { UP, LEFT, DOWN, RIGHT};

public:
	Player();
	~Player() {};

	sf::Sprite sprite;

	void keyboardInput(unsigned int** tile_information);
	void movement(Map* loaded_map, Audio* audio);
	void animation(int index);
	float getX();
	float getY();
};