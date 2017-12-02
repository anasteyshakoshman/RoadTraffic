
#include "Car.h"
#include <math.h>
#include <ctime>
#include "Map.h"
#include "TrafficLight.h"
#include "RoadSign.h"
#include "Crash.h"

std::vector<Car> Car::AllCars;

Car::Car(const sf::Texture & texture, const sf::Color col, const Map &  map, sf::RenderWindow & window)
{
	Sprite.setTexture(texture);
	Sprite.setColor(col);
	srand(time(0));
	int random = rand() % 2;
	switch (map.getScale())
	{
		case BIG_MAP:
		{
					if (random)
					{
						X = 7 * PIX;
						Y = 7 * PIX;
						Speed = MAX_SPEED2;
					}
					else
					{
						X = 11 * PIX;
						Y = 33 * PIX;
						Speed = MIN_SPEED2;
					}
					break;
		}
		case MIDDLE_MAP:
		{
					if (random)
					{
						X = 3 * PIX;
						Y = 3 * PIX;
						Speed = MIN_SPEED1;
					}
					else
					{
						X = 3 * PIX;
						Y = 11 * PIX;
						Speed = MAX_SPEED1;
					}
					break;
		}
		case LITTLE_MAP:
		{
					if (random)
					{
						X = 3 * PIX;
						Y = 3 * PIX;
						Speed = MAX_SPEED1;
					}
					else
					{
						X = 3 * PIX;
						Y = 9 * PIX;
						Speed = MIN_SPEED1;
					}
					break;
		}
	}
	Sprite.setPosition(X, Y);
	dX = Speed;
	dY = 0;
	Direction = X_PLUS;                                                                           
	ChangeDir = false;                                  
	Life = true;
	CreateTime = 0;
	StopTime = 0;
	AllCars.push_back(*this);                         
};

int Car::getSpeed() const
{
	return Speed;
};

int Car::okrugl(const int xy) const
{
	if (xy % PIX == 0) return xy;
	int ost = xy;
	while (ost > PIX) ost -= PIX;
	if (Direction == X_PLUS || Direction == Y_PLUS) return (xy - ost);   //floor
	else return (xy - ost + PIX);    //ceil
};

void Car::setDirection(const int direct)   
{
	Direction = direct;
	ChangeDir = true;              
	switch (Direction)
	{
		case X_PLUS:
		{
			dX = Speed;
			dY = 0;
			Sprite.setTextureRect(sf::IntRect(0, 0, PIX, PIX));
			break;
		}
		case Y_PLUS:
		{
			dX = 0;
			dY = Speed;
			Sprite.setTextureRect(sf::IntRect(PIX, 0, PIX, PIX));
			break;
		}
		case X_MINUS:
		{
			dX = -Speed;
			dY = 0;
			Sprite.setTextureRect(sf::IntRect(0, PIX, PIX, PIX));
			break;
		}
		case Y_MINUS:
		{
			dX = 0;
			dY = -Speed;
			Sprite.setTextureRect(sf::IntRect(PIX, PIX, PIX, PIX));
			break;
		}
	}
};

std::vector<int> Car::freeDirections(const Map &  map) const  
{                                                                    
	std::vector<int> vec;	
	if (X % PIX == 0 && Y % PIX == 0)
	{
		int koef = pow(-1, Direction);
		if (map.getTM()[mY() + mdY()][mX() + mdX()] == 'r' || \
			map.getTM()[mY() + mdY()][mX() + mdX()] == 'p' && \
			(map.getTM()[mY() + 2 * mdY()][mX() + 2 * mdX()] == 'p' || \
			map.getTM()[mY() + 2 * mdY()][mX() + 2 * mdX()] == 'r' || \
			map.getTM()[mY() + mdY() - 2 * mdX() * koef][mX() + mdX() - 2 * mdY() * koef] == 'r'))\
			vec.push_back(Direction);

		if (map.getTM()[mY() + mdX() * koef][mX() + mdY() * koef] == 'r' && \
			map.getTM()[mY() + mdY() + mdX()][mX() + mdX() * koef + mdY() * koef] == 'r' && !ChangeDir)
			vec.push_back((Direction + 1) % 4);

		if (map.getTM()[mY() - 2 * mdX() * koef][mX() - 2 * mdY() * koef] == 'r' &&\
			map.getTM()[mY() - mdY() - 2 * mdX() *koef][mX() - mdX() - 2 * mdY() * koef] == 'r'&& !ChangeDir)
			vec.push_back((Direction + 3) % 4);
	}	
	else vec.push_back(Direction);
	return vec;
};

int Car::carAround(const Map & map, sf::RenderWindow & window, const bool crash)  
{
	int pos = -1, koef = 1;
	if (Direction == 2 || Direction == 3) koef = -1;
	for (int i = 0; i < AllCars.size(); ++i)
	{
		if (Direction == 0 || Direction == 2)
		{
			if ((X + mdX() * PIX + dX) * koef > koef * AllCars[i].X  && AllCars[i].X * koef > X * koef &&  mod(Y - AllCars[i].Y) < PIX)
			{
				crash ? pos = i : pos = -2;
				break;
			}
		}
		else
		{
			if ((Y + mdY() * PIX + dY) * koef > koef * AllCars[i].Y && AllCars[i].Y * koef > Y * koef &&  mod(X - AllCars[i].X) < PIX)
			{
				crash ? pos = i : pos = -2;
				break;
			}
		}
	}
	if (pos >= 0) AllCars[pos].Life = false;
	return pos;	
};

void Car::setSpeed(const int newSpeed)
{
	if (Speed != newSpeed)
	{
		Speed = newSpeed;
		if (dX < 0) dX = -Speed;
		else if(dX > 0) dX = Speed;
		if (dY < 0) dY = -Speed;
		else if(dY > 0) dY = Speed;
	}
};

bool Car::lightAround(const Map & map) const      
{                                              
	if (map.getTM()[mY() + mdY()][mX() + mdX()] == 'p' && X % PIX == 0 && Y % PIX == 0)  
	{
		int koef = 1;
		if (Direction == Y_PLUS || Direction == Y_MINUS) koef = -1;
		for (auto it = TrafficLight::Vec().begin(); it != TrafficLight::Vec().end(); ++it)
		{
			if (mX() + koef * mdY() == it->getX()  && mY() + koef * mdX() == it->getY() && (it->getColor() == sf::Color::Red || it->getColor() == sf::Color::Yellow)) 
				return false;
		}  
	}	
	return true;
};

void Car::signAround(const Map & map)
{
	if (X % PIX == 0 && Y % PIX == 0)
	{
		int koef = 1;
		if (Direction == Y_PLUS || Direction == Y_MINUS) koef = -1;
		for (auto it = RoadSign::Vec().begin(); it != RoadSign::Vec().end(); ++it)
		{
			if (mX() + koef * mdY() == it->getX() && mY() + koef * mdX() == it->getY())
			{
				setSpeed(it->getLimit());
				break;
			}
		}
	}	
};

bool Car::crashAround() const
{
	if (X % PIX == 0 && Y % PIX == 0)
	{
		for (auto it = Crash::Vec().begin(); it != Crash::Vec().end(); ++it)
		{
			if ((X + mdX() * PIX == it->getX1() && Y + mdY() * PIX == it->getY1()) || (X + mdX() * PIX == it->getX2() && Y + mdY() * PIX == it->getY2()))
				return false;
		}
	}
	return true;
};

void Car::go(sf::RenderWindow & window, const Map &  map, bool & crash)        
{
	if (CreateTime <= 120)
	{
		++CreateTime;
		Sprite.setTextureRect(sf::IntRect(PIX - CreateTime, 0,  CreateTime, PIX));
	}
	else 
	{
		std::vector<int> freeDir;
		srand(time(0));
		bool change = false;
		if ((map.getTM()[mY()][mX()] == 'r' || StopTime < (-1) * (TIME_YELLOW_LIGHT + CRASH_END)) && ChangeDir)  ChangeDir = false;      
		signAround(map);                                       
		if ( lightAround(map)) freeDir = freeDirections(map);    
		if (freeDir.size())
		{
			int random = rand() % freeDir.size();          
			if (Direction != freeDir[random])
			{
				setDirection(freeDir[random]);
				change = true;
			}
			int motion = carAround(map, window, crash);
			if (!change && motion > -2 && Life && crashAround())                 
			{
				X += dX;
				Y += dY;
				if (StopTime > 0) StopTime = 0;
				--StopTime;
				Sprite.setPosition(X, Y);
			}
			else
			{
				if (StopTime < 0) StopTime = 0;
				++StopTime;
			}
			if (motion > -1)
			{
				Life = false;
				Crash(window, okrugl(X - dX), okrugl(Y - dY), okrugl(AllCars[motion].X), okrugl(AllCars[motion].Y));
				crash = false;
			}
		}
	}	
	window.draw(Sprite);    
};

std::vector<Car> & Car::Vec()
{
	return AllCars;
};

int Car::mod(const int num) const
{
	return sqrt(num * num);
};

Car::~Car()
{
	X = 0;
	Y = 0;
	dX = 0;
	dY = 0;
	Speed = 0;
};

int Car::getX() const
{
	return X;
};

int Car::getY() const
{
	return Y;
};

bool Car::getLife() const
{
	return Life;
};

int Car::mX() const
{
	return X / PIX;
};

int Car::mY() const
{
	return Y / PIX;
};

int Car::mdX() const
{
	return dX / Speed;
};

int Car::mdY() const
{
	return dY / Speed;
};