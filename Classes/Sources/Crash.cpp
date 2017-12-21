#include "Crash.h"

std::vector<Crash> Crash::AllCrash;

Crash::Crash(sf::RenderWindow & window, const float x1, const float y1, const float x2, const float y2)
{
	Time = 0;
	X1 = x1;                  //установка значений координат
	X2 = x2;
	Y1 = y1;
	Y2 = y2;

	RadiusRed = 1.f;
	RadiusYellow = 0.f;

	Red1.setRadius(FLOAT(RadiusRed));       //установка резмеров
	Red2.setRadius(FLOAT(RadiusRed));

	Red1.setFillColor(sf::Color::Red);        //установка цвета
	Red2.setFillColor(sf::Color::Red);
	Yellow1.setFillColor(sf::Color::Yellow);
	Yellow2.setFillColor(sf::Color::Yellow);

	Red1.setPosition(X1 + PIXEL / 2 - RadiusRed, Y1 + PIXEL / 2 - RadiusRed);   //установка позиции
	Red2.setPosition(X2 + PIXEL / 2 - RadiusRed, Y2 + PIXEL / 2 - RadiusRed);

	window.draw(Red1);             //изначально прорисовка только красны кругов
	window.draw(Red2);

	AllCrash.push_back(*this);
}

int Crash::work(sf::RenderWindow & window)
{
	++Time;
	if (Time % 2 == 0)
	{
		RadiusRed += 1.f;
		Red1.setRadius(RadiusRed);
		Red2.setRadius(RadiusRed);
		Red1.setPosition(X1 + PIXEL / 2 - RadiusRed, Y1 + PIXEL / 2 - RadiusRed);
		Red2.setPosition(X2 + PIXEL / 2 - RadiusRed, Y2 + PIXEL / 2 - RadiusRed);
		if (Time >= CRASH_TIME)
		{
			RadiusYellow += 1.f;
			Yellow1.setRadius(RadiusYellow);
			Yellow2.setRadius(RadiusYellow);
			Yellow1.setPosition(X1 + PIXEL / 2 - RadiusYellow, Y1 + PIXEL / 2 - RadiusYellow);
			Yellow2.setPosition(X2 + PIXEL / 2 - RadiusYellow, Y2 + PIXEL / 2 - RadiusYellow);
		}
	}
	if (RadiusRed == FLOAT(PIXEL / 2)) RadiusRed = 1.f;
	if (RadiusYellow == FLOAT(PIXEL / 2)) RadiusYellow = 1.f;
	window.draw(Red1);
	window.draw(Red2);
	if (Time >= CRASH_TIME)
	{
		window.draw(Yellow1);
		window.draw(Yellow2);
	}
	return Time;
}

std::vector<Crash> & Crash::Vec()
{
	return AllCrash;
}

float Crash::getX1() const
{
	return X1;
}

float Crash::getY1() const
{
	return Y1;
}

float Crash::getX2() const
{
	return X2;
}

float Crash::getY2() const
{
	return Y2;
}

Crash::~Crash()
{
	X1 = 0;
	X2 = 0;
	Y1 = 0;
	Y2 = 0;
	Time = 0;
	RadiusRed = 0;
	RadiusYellow = 0;
}