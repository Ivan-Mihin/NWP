#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Pokemon");
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(350.0f, 350.0f));

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

		view.setCenter(player.getPosition().x + player.getGlobalBounds().width / 2, player.getPosition().y + player.getGlobalBounds().height / 2);
		window.setView(view);

		window.clear();
		window.draw(player);
		window.display();
	}

	return 0;
}