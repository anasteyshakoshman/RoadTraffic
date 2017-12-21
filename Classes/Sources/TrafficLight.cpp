#include "TrafficLight.h"
#include "Map.h"

std::vector<TrafficLight> TrafficLight::AllTrafficLight;


TrafficLight::TrafficLight(const Map & map, const float x, const float y)
{
	BlackCircle.setRadius(PIXEL / 4); //черная оконтовка
	Circle.setRadius(PIXEL / 4 - 5);  //чтобы светофоры были меньше машин
	X = x * PIXEL;
	Y = y * PIXEL;
	if (map.getTM()[y + 1][x + 1] == CROSSROAD)  // direction = Y_PLUS
	{
		Color = sf::Color::Red;         //изначально присваиваю разные цвета противополжным светофорам, затем просто их меняю
		LastColor = false;
		BlackCircle.setPosition(X + PIXEL / 2, Y + PIXEL / 2);
		Circle.setPosition(X + PIXEL / 2 + 5, Y + PIXEL / 2 + 5);
	}
	else if (map.getTM()[y + 1][x - 1] == CROSSROAD)   // direction = X_MINUS
	{
		Color = sf::Color::Green;
		LastColor = true;
		BlackCircle.setPosition(X, Y + PIXEL / 2);
		Circle.setPosition(X + 5, Y + PIXEL / 2 + 5);
	}
	else if (map.getTM()[y - 1][x - 1] == CROSSROAD)   // direction = Y_MINUS
	{
		Color = sf::Color::Red;
		LastColor = false;
		BlackCircle.setPosition(X, Y);
		Circle.setPosition(X + 5, Y + 5);
	}
	else if (map.getTM()[y - 1][x + 1] == CROSSROAD)    // direction = X_PLUS
	{
		Color = sf::Color::Green;
		LastColor = true;
		BlackCircle.setPosition(X + PIXEL / 2, Y);
		Circle.setPosition(X + PIXEL / 2 + 5, Y + 5);
	}
	BlackCircle.setFillColor(sf::Color::Black);
	Circle.setFillColor(Color);
	TimeChange = 0;
	AllTrafficLight.push_back(*this);
}

void TrafficLight::work(const int clock, sf::RenderWindow & window)
{
	if (clock - TimeChange == TIME_YELLOW_LIGHT)
	{
		Color = sf::Color::Yellow;
		Circle.setFillColor(Color);
		TimeChange = clock;
	}
	else if (clock - TimeChange == TIME_CHANGE_LIGHT  && Color == sf::Color::Yellow)
	{
		if (LastColor == true)
		{
			Color = sf::Color::Red;
			LastColor = false;
		}
		else
		{
			Color = sf::Color::Green;
			LastColor = true;
		}
		TimeChange = clock;
		Circle.setFillColor(Color);
	}
	window.draw(BlackCircle);
	window.draw(Circle);
}

float TrafficLight::getX() const
{
	return X / PIXEL;
}

float TrafficLight::getY() const
{
	return Y / PIXEL;
}

int TrafficLight::getTimeChange() const
{
	return TimeChange;
}

bool TrafficLight::getLastColor() const
{
	return LastColor;
}

std::vector<TrafficLight> & TrafficLight::Vec()
{
	return AllTrafficLight;
}

sf::Color TrafficLight::getColor() const
{
	return Color;
}

TrafficLight::~TrafficLight()
{
	X = 0;
	Y = 0;
	TimeChange = 0;
	LastColor = false;
}
