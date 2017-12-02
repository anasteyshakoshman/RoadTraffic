#include "Crash.h"

std::vector<Crash> Crash::AllCrash;

Crash::Crash(sf::RenderWindow & window, int x1, const int y1, const int x2, const int y2)
{
	Time = 0;
	X1 = x1;                  //��������� �������� ���������
	X2 = x2;
	Y1 = y1;
	Y2 = y2;

	RadiusRed = 1;
	RadiusYellow = 0;

	Red1.setRadius(RadiusRed);       //��������� ��������
	Red2.setRadius(RadiusRed);
	sf::Vector2f size(PIX, PIX);

	Red1.setFillColor(sf::Color::Red);        //��������� �����
	Red2.setFillColor(sf::Color::Red);
	Yellow1.setFillColor(sf::Color::Yellow);      
	Yellow2.setFillColor(sf::Color::Yellow);

	Red1.setPosition(X1 + PIX / 2 - RadiusRed, Y1 + PIX / 2 - RadiusRed);   //��������� �������
	Red2.setPosition(X2 + PIX / 2 - RadiusRed, Y2 + PIX / 2 - RadiusRed);

	window.draw(Red1);             //���������� ����� ������ ������� �����
	window.draw(Red2);

	AllCrash.push_back(*this);
};

int Crash::work(sf::RenderWindow & window)
{
	++Time;
	if (Time % 5 == 0)
	{
		++RadiusRed;
		Red1.setRadius(RadiusRed);
		Red2.setRadius(RadiusRed);
		Red1.setPosition(X1 + PIX / 2 - RadiusRed, Y1 + PIX / 2 - RadiusRed);
		Red2.setPosition(X2 + PIX / 2 - RadiusRed, Y2 + PIX / 2 - RadiusRed);
		if (Time >= CRASH_TIME)
		{
			++RadiusYellow;
			Yellow1.setRadius(RadiusYellow);
			Yellow2.setRadius(RadiusYellow);
			Yellow1.setPosition(X1 + PIX / 2 - RadiusYellow, Y1 + PIX / 2 - RadiusYellow);
			Yellow2.setPosition(X2 + PIX / 2 - RadiusYellow, Y2 + PIX / 2 - RadiusYellow);
		}
	}	
	if (RadiusRed == PIX / 2) RadiusRed = 1;
	if (RadiusYellow == PIX / 2) RadiusYellow = 1;
	window.draw(Red1);
	window.draw(Red2);
	if (Time >= CRASH_TIME)
	{
		window.draw(Yellow1);
		window.draw(Yellow2);
	}
	return Time;	
};

std::vector<Crash> & Crash::Vec()
{
	return AllCrash;
};

int Crash::getX1() const
{
	return X1;
};

int Crash::getY1() const
{
	return Y1;
};

int Crash::getX2() const
{
	return X2;
};

int Crash::getY2() const
{
	return Y2;
};

Crash::~Crash()
{
	Time = 0;
	X1 = 0;
	X2 = 0;
	Y1 = 0;
	Y2 = 0;
};