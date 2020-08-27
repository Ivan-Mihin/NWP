#pragma once

class Player
{
	float movement_speed;
	bool walking;
	bool move[4];
	int animation_counter;
	sf::Texture texture[12];
	sf::Vector2f current_tile;
	sf::Vector2i next_tile;
	enum MOVE { UP, LEFT, DOWN, RIGHT};

public:
	Player();
	~Player() {};

	sf::Sprite sprite;

	void keyboardInput(int** tile_information);
	void moving(Map* loaded_map, sf::Music* music);
	void animation(int index);
	int getX();
	int getY();
};