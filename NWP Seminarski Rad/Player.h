#pragma once

class Player
{
	float movement_speed;
	bool walking;
	bool move[4];
	sf::Texture texture[4];
	sf::Vector2i current_tile;
	sf::Vector2i next_tile;
	enum MOVE { UP, LEFT, DOWN, RIGHT };

public:
	Player();
	~Player() {};

	sf::Sprite sprite;

	void keyboardInput(int** tile_information);
	void moving(Map* loaded_map, sf::Music* music);
	int getX();
	int getY();
};