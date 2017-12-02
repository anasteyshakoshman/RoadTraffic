#include "FunctionForMain.h"

void main()
{
	if (checkSpeed())
	{
		sf::RenderWindow window(sf::VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), "Model of ROAD TRAFFIC", sf::Style::Fullscreen); 
		Map map(MIDDLE_MAP);   
		View view(map);   

		sf::Texture texture;
		texture.loadFromFile(TEXTURE_CAR);

		sf::Clock clock;   
		sf::Vector3i currentClock(0, 0, 0);         
		float time = 0.;
		bool crash = false;

		createTrLightAndRSign(window, map); 

		while (window.isOpen())
		{
			sf::Event event;
			time = clock.getElapsedTime().asMicroseconds();
			clock.restart();   
			time = time / 800;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) window.close();
			}
			window.clear();
			Work(window, map, view, texture, currentClock, time, crash);  
			window.display();              
		}
	}
}


