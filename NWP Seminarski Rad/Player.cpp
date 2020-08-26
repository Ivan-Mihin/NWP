#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Player.h"

Player::Player()
{
	sprite.setPosition(210.0f, 210.0f);
	current_tile = (sf::Vector2i) sprite.getPosition();
	movement_speed = 1;

	move[UP] = false;
	move[LEFT] = false;
	move[DOWN] = false;
	move[RIGHT] = false;

	texture[UP].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(30, 30, 30, 30));
	texture[LEFT].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(30, 0, 30, 30));
	texture[DOWN].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(0, 0, 30, 30));
	texture[RIGHT].loadFromFile("Textures/Ash_Sprites.png", sf::IntRect(0, 30, 30, 30));

	sprite.setTexture(texture[DOWN]);

	walking = false;
}

void Player::keyboardInput(Map* loaded_map)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (walking == false)
		{
			sprite.setTexture(texture[UP]);
			next_tile = sf::Vector2i(current_tile.x, current_tile.y - tile_size);

			if (loaded_map->tile_information[next_tile.x / 30][next_tile.y / 30] > 0)
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

			if (loaded_map->tile_information[next_tile.x / 30][next_tile.y / 30] > 0)
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

			if (loaded_map->tile_information[next_tile.x / 30][next_tile.y / 30] > 0)
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

			if (loaded_map->tile_information[next_tile.x / 30][next_tile.y / 30] > 0)
			{
				move[RIGHT] = true;
				walking = true;
			}
		}
	}
}

void Player::moving(Map* loaded_map)
{
	if (walking == true)
	{
		if (move[UP] == true)
		{
			current_tile.y -= movement_speed;

			if (current_tile.y == next_tile.y)
			{
				if (loaded_map->tile_information[next_tile.x / 30][next_tile.y / 30] == 1)
				{
					loaded_map->loadMap("Maps/Map1.txt");
					current_tile = sf::Vector2i(sprite.getPosition().x, 28 * tile_size);
					/*music.stop();
					music.openFromFile("Audio/Map1Music.ogg");
					music.play();*/
				}

				if (loaded_map->tile_information[next_tile.x / 30][next_tile.y / 30] == 2)
				{
					loaded_map->loadMap("Maps/Map2.txt");
					current_tile = sf::Vector2i(sprite.getPosition().x - 25 * tile_size, 28 * tile_size);
					/*music.stop();
					music.openFromFile("Audio/Map2Music.ogg");
					music.play();*/
				}

				walking = false;
				move[UP] = false;
			}
		}

		if (move[LEFT] == true)
		{
			current_tile.x -= movement_speed;

			if (current_tile.x == next_tile.x)
			{
				if (loaded_map->tile_information[next_tile.x / 30][next_tile.y / 30] == 1)
				{
					loaded_map->loadMap("Maps/Map1.txt");
					current_tile = sf::Vector2i(28 * tile_size, sprite.getPosition().y);
					/*music.stop();
					music.openFromFile("Audio/Map1Music.ogg");
					music.play();*/
				}

				walking = false;
				move[LEFT] = false;
			}
		}

		if (move[DOWN] == true)
		{
			current_tile.y += movement_speed;

			if (current_tile.y == next_tile.y)
			{
				if (loaded_map->tile_information[next_tile.x / 30][next_tile.y / 30] == 3)
				{
					if (loaded_map->returnMapName().compare("Maps/Map1.txt") == 0)
					{
						loaded_map->loadMap("Maps/Map3.txt");
						current_tile = sf::Vector2i(sprite.getPosition().x, 6 * tile_size);
						/*music.stop();
						music.openFromFile("Audio/Map3Music.ogg");
						music.play();*/
					}
					else
					{
						loaded_map->loadMap("Maps/Map3.txt");
						current_tile = sf::Vector2i(sprite.getPosition().x + 25 * tile_size, 6 * tile_size);
						/*music.stop();
						music.openFromFile("Audio/Map3Music.ogg");
						music.play();*/
					}
				}

				walking = false;
				move[DOWN] = false;
			}
		}

		if (move[RIGHT] == true)
		{
			current_tile.x += movement_speed;

			if (current_tile.x == next_tile.x)
			{
				if (loaded_map->tile_information[next_tile.x / 30][next_tile.y / 30] == 2)
				{
					loaded_map->loadMap("Maps/Map2.txt");
					current_tile = sf::Vector2i(6 * tile_size, sprite.getPosition().y);
					/*music.stop();
					music.openFromFile("Audio/Map3Music.ogg");
					music.play();*/
				}

				walking = false;
				move[RIGHT] = false;
			}
		}
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