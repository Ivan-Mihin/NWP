#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Battle.h"
#include "Map.h"
#include "Player.h"

Player::Player()
{
	sprite.setPosition(570.0f, 360.0f);
	current_tile = sprite.getPosition();
	movement_speed = 0.5f;
	animation_counter = 0;
	loops_per_tile_change = tile_size / movement_speed;

	for (int i = 0, k = 0; i < 4; ++i)
	{
		move[i] = false;

		for (int j = 0; j < 3; ++j, ++k)
		{
			texture[k].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(j * tile_size, i * tile_size, tile_size, tile_size));
		}
	}

	sprite.setTexture(texture[6]);
	is_moving = false;
}

void Player::keyboardInput(unsigned int** tile_information)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (is_moving == false)
		{
			sprite.setTexture(texture[UP * 3]);
			next_tile = sf::Vector2i(current_tile.x, current_tile.y - tile_size);

			if (tile_information[next_tile.x / tile_size][next_tile.y / tile_size] > 0)
			{
				move[UP] = true;
				is_moving = true;
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (is_moving == false)
		{
			sprite.setTexture(texture[LEFT * 3]);
			next_tile = sf::Vector2i(current_tile.x - tile_size, current_tile.y);

			if (tile_information[next_tile.x / tile_size][next_tile.y / tile_size] > 0)
			{
				move[LEFT] = true;
				is_moving = true;
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (is_moving == false)
		{
			sprite.setTexture(texture[DOWN * 3]);
			next_tile = sf::Vector2i(current_tile.x, current_tile.y + tile_size);

			if (tile_information[next_tile.x / tile_size][next_tile.y / tile_size] > 0)
			{
				move[DOWN] = true;
				is_moving = true;
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (is_moving == false)
		{
			sprite.setTexture(texture[RIGHT * 3]);
			next_tile = sf::Vector2i(current_tile.x + tile_size, current_tile.y);

			if (tile_information[next_tile.x / tile_size][next_tile.y / tile_size] > 0)
			{
				move[RIGHT] = true;
				is_moving = true;
			}
		}
	}
}

void Player::movement(Map* loaded_map, Audio* audio)
{
	if (is_moving == true)
	{
		if (move[UP] == true)
		{
			current_tile.y -= movement_speed;
			animation(UP * 3);

			if (current_tile.y <= next_tile.y)
			{
				current_tile.y = next_tile.y;
				animation_counter = 0;
				sprite.setTexture(texture[UP * 3]);

				switch (loaded_map->current_map)
				{
				case loaded_map->MAP1:
				{
					break;
				}

				case loaded_map->MAP2:
				{
					break;
				}

				case loaded_map->MAP3:
				{
					if (loaded_map->tile_information[next_tile.x / tile_size][next_tile.y / tile_size] == 1)
					{
						loaded_map->loadMap("Maps/Map1.txt");
						loaded_map->current_map = loaded_map->MAP1;
						current_tile = sf::Vector2f(sprite.getPosition().x, 29 * tile_size);
						audio->changeMusic("Audio/Map1Music.ogg");
					}

					if (loaded_map->tile_information[next_tile.x / 30][next_tile.y / 30] == 2)
					{
						loaded_map->loadMap("Maps/Map2.txt");
						loaded_map->current_map = loaded_map->MAP2;
						current_tile = sf::Vector2f(sprite.getPosition().x - 25 * tile_size, 29 * tile_size);
						audio->changeMusic("Audio/Map2Music.ogg");
					}

					break;
				}
				}

				if (loaded_map->tile_information[next_tile.x / tile_size][next_tile.y / tile_size] == 5)
				{
					Battle battle;
					battle.start();
				}

				is_moving = false;
				move[UP] = false;
			}
		}

		if (move[LEFT] == true)
		{
			current_tile.x -= movement_speed;
			animation(LEFT * 3);
			
			if (current_tile.x <= next_tile.x)
			{
				current_tile.x = next_tile.x;
				animation_counter = 0;
				sprite.setTexture(texture[LEFT * 3]);

				switch (loaded_map->current_map)
				{
				case loaded_map->MAP1:
				{
					break;
				}

				case loaded_map->MAP2:
				{
					if (loaded_map->tile_information[next_tile.x / tile_size][next_tile.y / tile_size] == 1)
					{
						loaded_map->loadMap("Maps/Map1.txt");
						loaded_map->current_map = loaded_map->MAP1;
						current_tile = sf::Vector2f(29 * tile_size, sprite.getPosition().y);
						audio->changeMusic("Audio/Map1Music.ogg");
					}

					break;
				}

				case loaded_map->MAP3:
				{
					break;
				}
				}

				is_moving = false;
				move[LEFT] = false;
			}
		}

		if (move[DOWN] == true)
		{
			current_tile.y += movement_speed;
			animation(DOWN * 3);

			if (current_tile.y >= next_tile.y)
			{
				current_tile.y = next_tile.y;
				animation_counter = 0;
				sprite.setTexture(texture[DOWN * 3]);

				switch (loaded_map->current_map)
				{
				case loaded_map->MAP1:
				{
					if (loaded_map->tile_information[next_tile.x / tile_size][next_tile.y / tile_size] == 3)
					{
						loaded_map->loadMap("Maps/Map3.txt");
						loaded_map->current_map = loaded_map->MAP3;
						current_tile = sf::Vector2f(sprite.getPosition().x, 7 * tile_size);
						audio->changeMusic("Audio/Map3Music.ogg");
					}

					break;
				}

				case loaded_map->MAP2:
				{
					if (loaded_map->tile_information[next_tile.x / tile_size][next_tile.y / tile_size] == 3)
					{
						loaded_map->loadMap("Maps/Map3.txt");
						loaded_map->current_map = loaded_map->MAP3;
						current_tile = sf::Vector2f(sprite.getPosition().x + 25 * tile_size, 7 * tile_size);
						audio->changeMusic("Audio/Map3Music.ogg");
					}

					break;
				}

				case loaded_map->MAP3:
				{
					break;
				}
				}

				is_moving = false;
				move[DOWN] = false;
			}
		}

		if (move[RIGHT] == true)
		{
			current_tile.x += movement_speed;
			animation(RIGHT * 3);

			if (current_tile.x >= next_tile.x)
			{
				current_tile.x = next_tile.x;
				animation_counter = 0;
				sprite.setTexture(texture[RIGHT * 3]);

				switch (loaded_map->current_map)
				{
				case loaded_map->MAP1:
				{
					if (loaded_map->tile_information[next_tile.x / tile_size][next_tile.y / tile_size] == 2)
					{
						loaded_map->loadMap("Maps/Map2.txt");
						loaded_map->current_map = loaded_map->MAP2;
						current_tile = sf::Vector2f(7 * tile_size, sprite.getPosition().y);
						audio->changeMusic("Audio/Map2Music.ogg");
					}

					break;
				}

				case loaded_map->MAP2:
				{
					break;
				}

				case loaded_map->MAP3:
				{
					break;
				}
				}

				is_moving = false;
				move[RIGHT] = false;
			}
		}
	}
}

void Player::animation(int index)
{
	++animation_counter;

	if (animation_counter > 0 && animation_counter <=  loops_per_tile_change / 2)
	{
		sprite.setTexture(texture[index + 1]);
	}
	else
	{
		sprite.setTexture(texture[index + 2]);
	}
}

float Player::getX()
{
	return current_tile.x;
}

float Player::getY()
{
	return current_tile.y;
}