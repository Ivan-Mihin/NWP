#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Pokemon");
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(350.0f, 350.0f));

	sf::Texture playerTexture;
	sf::Sprite player;
	playerTexture.loadFromFile("Ash_Sprites.png", sf::IntRect(0, 0, 30, 30));
	player.setTexture(playerTexture);

	sf::Texture tileTexture;
	sf::Sprite tile;
	tileTexture.loadFromFile("Tile_Set.png");
	tile.setTexture(tileTexture);

	std::ifstream file("testMap.txt");
	if (!file.is_open())
	{
		return NULL;
	}

	sf::Vector2i map[100][100];
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

	while (window.isOpen())
	{
		sf::Event gameEvent;

		while (window.pollEvent(gameEvent))
		{
			switch (gameEvent.type)
			{
			case gameEvent.Closed:
			{
				window.close();
				break;
			}

			case sf::Event::KeyPressed:
			{
				switch (gameEvent.key.code)
				{
				case sf::Keyboard::W:
				case sf::Keyboard::Up:
				{
					player.setPosition(player.getPosition().x, player.getPosition().y - 30);
					break;
				}

				case sf::Keyboard::A:
				case sf::Keyboard::Left:
				{
					player.setPosition(player.getPosition().x - 30, player.getPosition().y);
					break;
				}

				case sf::Keyboard::S:
				case sf::Keyboard::Down:
				{
					player.setPosition(player.getPosition().x, player.getPosition().y + 30);
					break;
				}

				case sf::Keyboard::D:
				case sf::Keyboard::Right:
				{
					player.setPosition(player.getPosition().x + 30, player.getPosition().y);
					break;
				}

				break;
				}
			}
			}
		}

		view.setCenter(player.getPosition().x + player.getGlobalBounds().width / 2, player.getPosition().y + player.getGlobalBounds().height / 2);
		window.setView(view);

		window.clear();

		for (int h = 0; h < 10; ++h)
		{
			for (int w = 0; w < 10; ++w)
			{
				tile.setPosition(h * 30, w * 30);
				tile.setTextureRect(sf::IntRect(map[h][w].x * 30, map[h][w].y * 30, 30, 30));
				window.draw(tile);
			}
		}

		window.draw(player);
		window.display();
	}

	return 0;
}