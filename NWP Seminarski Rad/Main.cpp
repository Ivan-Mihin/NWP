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

			}
		}

		window.clear();
		window.draw(player);
		window.display();
	}

	return 0;
}