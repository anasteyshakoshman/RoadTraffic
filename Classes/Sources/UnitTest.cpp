#include "TrafficLight.h"
#include "RoadSign.h"
#include "UnitTest.h"
#include "Crash.h"
#include "Car.h"
#include "Map.h"

template <typename T>
void Assert(const T true_value, const T check_value, const std::string functionName)
{
	std::cerr << " - " << functionName;
	if (true_value == check_value) std::cerr << " is successfully" << std::endl;
	else std::cerr << " is falling" << std::endl;
}

bool UTest_Car(const Map & map, sf::RenderWindow & window, std::vector<bool> & was)
{
	if (map.getScale() == MIDDLE_MAP)
	{
		if (!was[0])
		{
			std::cerr << "Unit Tests for class Car : " << std::endl;
			was[0] = true;
		}
		for (auto it = Car::Vec().begin(); it != Car::Vec().end(); ++it)
		{
			if (it->mX() == 9. && it->mY() == 21. && !was[1])
			{
				Assert(MIN_SPEED1, it->getSpeed(), "signAround");
				was[1] = true;
			}
			if (it->mX() == 13. && it->mY() == 7. && !was[2])
			{
				if (TrafficLight::Vec()[0].getColor() == sf::Color::Green)
					Assert(true, it->lightAround(map), "lightAround");
				else Assert(false, it->lightAround(map), "lightAround");
				was[2] = true;
			}
			if (it->mX() == 4. && it->mY() == 9. && it->getDirection() == Y_PLUS && !it->getChangeDir() && !was[3])
			{
				was[3] = true;
				Assert(std::vector<int> { Y_PLUS, X_PLUS }, it->freeDirections(map), "freeDirections");
			}
			if (it->mX() == 22. && it->mY() == 21. && !was[4])
			{
				Crash(window, it->getX() + PIXEL, it->getY(), it->getX() + 2 * PIXEL, it->getY());
				Assert(false, it->crashAround(), "crashAround");
				was[4] = true;
			}
			if (it->mX() == 6. && it->mY() == 8. && !was[5])
			{
				Assert(3, it->getStopDirection(), "stopDirection");
				was[5] = true;
			}
			if (it->getX() == 1220 && it->getY() == 1440 && !was[6])
			{
				Assert(std::pair<float, float>(1320.0, 1440.0), std::pair<float, float>(it->okrugl(it->getX()), it->okrugl(it->getY())), "okruglenie");
				was[6] = true;
			}
			if (map.getTM()[it->mY()][it->mX()] == EXIT && !was[7])
			{
				Assert(true, it->entryExit(map), "entryExit");
				was[7] = true;
			}
			if (it->mX() == 3 && it->mY() == 13 && !was[8])
			{
				Assert(0, it->getBeginDirection(map), "getBeginDirection");
				was[8] = true;
			}
			if (it->mX() == 13 && it->mY() == 3 && !was[9])
			{
				it->setDirection(it->getBeginDirection(map));
				Assert(std::pair<int, int>(0, 1), std::pair<int, int>(it->mdX(), it->mdY()), "setDirection");
				was[9] = true;
			}
			if (it->mX() == 10 && it->mY() == 13 && !was[10])
			{
				it->setSpeed(MAX_SPEED1);
				Assert(std::pair<int, int>(1, 0), std::pair<int, int>(it->mdX(), it->mdY()), "setSpeed");
				was[10] = true;
			}
		}
		for (size_t i = 0; i < was.size(); ++i)
		{
			if (!was[i]) return false;
		}
		return true;
	}
	return false;
}


bool UTest_Classes(const Map & map, sf::RenderWindow & window, std::vector<bool> & was)
{
	if (map.getScale() == MIDDLE_MAP)
	{
		if (!was[0])
		{
			std::cerr << "Unit Tests for classes Traffic Light, RoadSign and Crash : " << std::endl;
			was[0] = true;
		}
		for (auto it = TrafficLight::Vec().begin(); it != TrafficLight::Vec().end(); ++it)
		{
			if (it->getColor() == sf::Color::Green && !was[1])
			{
				Assert(true, it->getLastColor(), "getLastColor");
				was[1] = true;
			}
		}
		for (auto it = RoadSign::Vec().begin(); it != RoadSign::Vec().end(); ++it)
		{
			if (map.getTM()[size_t(it->getY())][size_t(it->getX())] == SPEED_LIMIT_ON && !was[2])
			{
				Assert(MIN_SPEED1, it->getLimit(), "getLimit");
				was[2] = true;
			}
		}
		for (auto it = Crash::Vec().begin(); it != Crash::Vec().end(); ++it)
		{
			if (!was[3])
			{
				Assert(false, it->work(window) > CRASH_END, "getLimit");
				was[3] = true;
			}
		}
		for (size_t i = 0; i < was.size(); ++i)
		{
			if (!was[i]) return false;
		}
		return true;
	}
	return  false;
}