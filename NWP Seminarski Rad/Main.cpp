#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Pokemon");

	sf::Texture playerTexture;
	sf::Sprite player;
	playerTexture.loadFromFile("Ash_Sprites.png", sf::IntRect(0, 0, 30, 30));
	player.setTexture(playerTexture);

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

		window.clear();
		window.draw(player);
		window.display();
	}

	return 0;
}