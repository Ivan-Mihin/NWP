#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Map.h"
#include "Player.h"

Player::Player()
{
	sprite.setPosition(210.0f, 210.0f);
	current_tile = sprite.getPosition();
	movement_speed = 0.4f;
	animation_counter = 0;

	move[UP] = false;
	move[LEFT] = false;
	move[DOWN] = false;
	move[RIGHT] = false;

	texture[0].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(0, 0, 30, 30));
	texture[1].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(30, 0, 30, 30));
	texture[2].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(60, 0, 30, 30));

	texture[3].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(0, 30, 30, 30));
	texture[4].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(30, 30, 30, 30));
	texture[5].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(60, 30, 30, 30));

	texture[6].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(0, 60, 30, 30));
	texture[7].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(30, 60, 30, 30));
	texture[8].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(60, 60, 30, 30));

	texture[9].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(0, 90, 30, 30));
	texture[10].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(30, 90, 30, 30));
	texture[11].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(60, 90, 30, 30));

	sprite.setTexture(texture[6]);

	walking = false;
}

void Player::keyboardInput(int** tile_information)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (walking == false)
		{
			sprite.setTexture(texture[UP]);
			next_tile = sf::Vector2i(current_tile.x, current_tile.y - tile_size);

			if (tile_information[next_tile.x / 30][next_tile.y / 30] > 0)
			{
				move[UP] = true;
				walking = true;
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (walking == false)
		{
			sprite.setTexture(texture[LEFT]);
			next_tile = sf::Vector2i(current_tile.x - tile_size, current_tile.y);

			if (tile_information[next_tile.x / 30][next_tile.y / 30] > 0)
			{
				move[LEFT] = true;
				walking = true;
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (walking == false)
		{
			sprite.setTexture(texture[DOWN]);
			next_tile = sf::Vector2i(current_tile.x, current_tile.y + tile_size);

			if (tile_information[next_tile.x / 30][next_tile.y / 30] > 0)
			{
				move[DOWN] = true;
				walking = true;
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (walking == false)
		{
			sprite.setTexture(texture[RIGHT]);
			next_tile = sf::Vector2i(current_tile.x + tile_size, current_tile.y);

			if (tile_information[next_tile.x / 30][next_tile.y / 30] > 0)
			{
				move[RIGHT] = true;
				walking = true;
			}
		}
	}
}

void Player::moving(Map* loaded_map, sf::Music* music)
{
	if (walking == true)
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

				if (loaded_map->tile_information[next_tile.x / 30][next_tile.y / 30] == 1)
				{
					loaded_map->loadMap("Maps/Map1.txt");
					current_tile = sf::Vector2f(sprite.getPosition().x, 29 * tile_size);
					music->stop();
					music->openFromFile("Audio/Map1Music.ogg");
					music->play();
				}

				if (loaded_map->tile_information[next_tile.x / 30][next_tile.y / 30] == 2)
				{
					loaded_map->loadMap("Maps/Map2.txt");
					current_tile = sf::Vector2f(sprite.getPosition().x - 25 * tile_size, 29 * tile_size);
					music->stop();
					music->openFromFile("Audio/Map2Music.ogg");
					music->play();
				}

				walking = false;
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

				if (loaded_map->tile_information[next_tile.x / 30][next_tile.y / 30] == 1)
				{
					loaded_map->loadMap("Maps/Map1.txt");
					current_tile = sf::Vector2f(28 * tile_size, sprite.getPosition().y);
					music->stop();
					music->openFromFile("Audio/Map1Music.ogg");
					music->play();
				}

				walking = false;
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

				if (loaded_map->tile_information[next_tile.x / 30][next_tile.y / 30] == 3)
				{
					if (loaded_map->returnMapName().compare("Maps/Map1.txt") == 0)
					{
						loaded_map->loadMap("Maps/Map3.txt");
						current_tile = sf::Vector2f(sprite.getPosition().x, 7 * tile_size);
						music->stop();
						music->openFromFile("Audio/Map3Music.ogg");
						music->play();
					}
					else
					{
						loaded_map->loadMap("Maps/Map3.txt");
						current_tile = sf::Vector2f(sprite.getPosition().x + 25 * tile_size, 7 * tile_size);
						music->stop();
						music->openFromFile("Audio/Map3Music.ogg");
						music->play();
					}
				}

				walking = false;
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

				if (loaded_map->tile_information[next_tile.x / 30][next_tile.y / 30] == 2)
				{
					loaded_map->loadMap("Maps/Map2.txt");
					current_tile = sf::Vector2f(7 * tile_size, sprite.getPosition().y);
					music->stop();
					music->openFromFile("Audio/Map2Music.ogg");
					music->play();
				}

				walking = false;
				move[RIGHT] = false;
			}
		}
	}
}

void Player::animation(int index)
{
	++animation_counter;

	if (animation_counter > 0 && animation_counter <= 25)
	{
		sprite.setTexture(texture[index + 1]);
	}
	else if (animation_counter > 25 && animation_counter <= 50)
	{
		sprite.setTexture(texture[index + 2]);
	}
	else
	{
		sprite.setTexture(texture[index + 1]);
	}
}

int Player::getX()
{
	return current_tile.x;
}

int Player::getY()
{
	return current_tile.y;
}