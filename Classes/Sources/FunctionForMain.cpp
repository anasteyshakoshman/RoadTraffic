#include "FunctionForMain.h"
#include "FUnction.h"


void CheckSpeed()
{
	if (PIXEL % INT(MIN_SPEED1) == 0 && PIXEL % INT(MIN_SPEED2) == 0 && PIXEL % INT(MAX_SPEED1) == 0 && PIXEL % INT(MAX_SPEED2) == 0) 1;
	else  throw std::logic_error("Uncorrect value of speed, your speed must : '120 % SPEED == 0' (check 'Include.h' line 15 - 25 ) ");
}

void CreateTrLightAndRSign(const Map & map)
{
	for (size_t i = 0; i < map.getHeight(); ++i)
	{
		for (size_t j = 0; j < map.getWidth(); ++j)
		{
			if (map.getTM()[i][j] == 's') TrafficLight(map, FLOAT(j), FLOAT(i));
			else if (IsRoadSign(map.getTM()[i][j])) RoadSign(map, FLOAT(j), FLOAT(i));
		}
	}
}

sf::Color & chooseColor()
{
	int random = rand() % 6;
	sf::Color color;
	if (!random) color = sf::Color::Green;
	else if (random == 1) color = sf::Color::Yellow;
	else if (random == 2 || random == 8) color = sf::Color::Red;
	else if (random == 4) color = sf::Color::Magenta;
	else if (random == 5) color = sf::Color::Cyan;
	else color = sf::Color::Blue;
	return color;
}

void AddCar(const sf::Texture & texture, const Map & map, sf::Vector3i & currentClock)
{
	int maxNum = MAX_NUM_CAR;
	if (map.getScale() == BIG_MAP) maxNum *= 15;
	if (currentClock.x - currentClock.y >= LIMIT_ADD_CAR && Car::Vec().size() <= maxNum && (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || Car::Vec().size() < LARGE_NUM_CAR))
	{
		currentClock.y = currentClock.x;
		Car newCar(map, texture, chooseColor());
		if (newCar.getDirection() == X_PLUS || newCar.getDirection() == Y_PLUS)
		{
			for (int i = Car::Vec().size() - 2; i >= 0; --i)
			{
				if (newCar.getX() == Car::Vec()[i].getX() && newCar.getY() == Car::Vec()[i].getY())
				{
					Car::Vec().pop_back();
					break;
				}
			}
		}
	}
}

bool IsCrash(sf::Vector3i & currentClock, const Map & map)
{
	int bigNumCar = BIG_NUM_CAR, largeNumCar = LARGE_NUM_CAR;
	if (map.getScale() == BIG_MAP)
	{
		bigNumCar *= 10;
		largeNumCar *= 10;
	}
	if ((Car::Vec().size() > bigNumCar && Car::Vec().size() < largeNumCar && currentClock.x - currentClock.z >= LIMIT_CRASH1)\
		|| (Car::Vec().size() > largeNumCar && currentClock.x - currentClock.z >= LIMIT_CRASH2))
	{
		int random = rand() % 4;
		if (random > 1)
		{
			currentClock.z = currentClock.x;
			return true;
		}
	}
	return false;
}

void Work(sf::RenderWindow & window, Map & map, View & view, const sf::Texture & texture1, const sf::Texture & texture2, sf::Vector3i & currentClock, float time, bool & crash, bool & pause)
{
	view.work(window, time);
	map.work(window);
	for (auto it = TrafficLight::Vec().begin(); it != TrafficLight::Vec().end(); ++it)
	{
		it->work(currentClock.x, window);
	}
	for (size_t i = 0; i < Car::Vec().size(); ++i)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || IsCrash(currentClock, map)) crash = true;
		Car::Vec()[i].go(window, map, crash, pause);
		if (!Car::Vec()[i].getLife()) Car::Vec().erase(Car::Vec().begin() + i);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) pause = true;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) pause = false;
	if (pause == false)
	{
		++currentClock.x;
		if (rand() % 2) AddCar(texture1, map, currentClock);
		else AddCar(texture2, map, currentClock);
		for (size_t i = 0; i < Crash::Vec().size(); ++i)
		{
			if (Crash::Vec()[i].work(window) == CRASH_END)
				Crash::Vec().erase(Crash::Vec().begin() + i);
		}
	}
}

