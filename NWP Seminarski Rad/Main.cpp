#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Pokemon");


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
		window.display();
	}

	return 0;
}