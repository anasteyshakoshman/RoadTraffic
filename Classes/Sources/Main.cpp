#include "FunctionForMain.h"

void main()
{
	try
	{
		CheckSpeed();

		sf::RenderWindow window(sf::VideoMode(size_t(WIDTH_WINDOW), size_t(HEIGHT_WINDOW)), "Model of ROAD TRAFFIC", sf::Style::Fullscreen);
		//srand(size_t(time(0)));

		Map map(MIDDLE_MAP);
		View view(map);

		sf::Texture textureCar1, textureCar2;
		if (!textureCar1.loadFromFile(TEXTURE_CAR1) || !textureCar2.loadFromFile(TEXTURE_CAR2))
			throw std::logic_error("Texture wasn't loading");

		sf::Clock clock;
		sf::Vector3i currentClock(0, 0, 0);
		float time = 0.;
		bool crash = false;
		bool pause = false;

		std::vector<bool> unitTestCar;   // для unit-тестов
		unitTestCar.assign(11, false);

		std::vector<bool> unitTestClasses;
		unitTestClasses.assign(4, false);

		CreateTrLightAndRSign(map);

		while (window.isOpen())
		{
			sf::Event event;
			time = FLOAT(clock.getElapsedTime().asMicroseconds());
			clock.restart();
			time /= 800.;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) window.close();
			}
			window.clear();
			Work(window, map, view, textureCar1, textureCar2, currentClock, time, crash, pause);
			window.display();
		}
	}
	catch (const std::logic_error & e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
}
