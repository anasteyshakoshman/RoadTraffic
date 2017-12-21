#include "FunctionForMain.h"
#include "TrafficLight.h"
#include "RoadSign.h"
#include "Function.h"
#include "Crash.h"
#include "Car.h"
#include "Map.h"

std::vector<Car> Car::AllCars;

Car::Car(const sf::Texture & texture, sf::Color col, const float x, const float y, const int direction)
{
	Sprite.setTexture(texture);
	Sprite.setColor(col);
	X = x * PIXEL;
	Y = y * PIXEL;
	Sprite.setPosition(X, Y);
	int random = rand() % 2;
	if (random) Speed = MAX_SPEED1;
	else Speed = MIN_SPEED1;
	setDirection(direction);
	ChangeDir = false;
	Life = true;
	EntryExit = 0;
	StopDirection = UNKNOWN_VALUE;
	Crossroad = false;
	AllCars.push_back(*this);
}

Car::Car(const Map &  map, const sf::Texture & texture, const sf::Color col)
{
	Sprite.setTexture(texture);
	Sprite.setColor(col);

	int random = rand() % 2;
	switch (map.getScale())
	{
	case BIG_MAP:
	{
					if (random)
					{
						X = 7 * PIXEL;
						Y = 7 * PIXEL;
						Speed = MAX_SPEED2;
					}
					else
					{
						X = 11 * PIXEL;
						Y = 33 * PIXEL;
						Speed = MIN_SPEED2;
					}
					break;
	}
	case MIDDLE_MAP:
	{
					   if (random)
					   {
						   X = 3 * PIXEL;
						   Y = 21 * PIXEL;
						   Speed = MIN_SPEED1;
					   }
					   else
					   {
						   X = 13 * PIXEL;
						   Y = 3 * PIXEL;
						   Speed = MAX_SPEED1;
					   }
					   break;
	}
	case LITTLE_MAP:
	{
					   X = 3 * PIXEL;
					   if (random)
					   {
						   Y = 3 * PIXEL;
						   Speed = MAX_SPEED1;
					   }
					   else
					   {
						   Y = 8 * PIXEL;
						   Speed = MIN_SPEED1;
					   }
					   break;
	}
	case CUSTOM:
	{
				   throw std::logic_error("Use constructor of  Car with paramtres : x, y, direction");
				   break;
	}
	}
	Sprite.setPosition(X, Y);
	setDirection(getBeginDirection(map));
	ChangeDir = false;
	Life = true;
	EntryExit = 1;
	StopDirection = UNKNOWN_VALUE;
	Crossroad = false;
	AllCars.push_back(*this);
}

int Car::getBeginDirection(const Map & map)
{
	if (map.getTM()[mY() + 1][mX()] == ROAD || map.getTM()[mY() + 1][mX()] == CROSSROAD)
	{
		return Y_PLUS;
	}
	if (map.getTM()[mY() - 1][mX()] == ROAD || map.getTM()[mY() - 1][mX()] == CROSSROAD)
	{
		return Y_MINUS;
	}
	if (map.getTM()[mY()][mX() + 1] == ROAD || map.getTM()[mY()][mX() + 1] == CROSSROAD)
	{
		return X_PLUS;
	}
	if (map.getTM()[mY()][mX() - 1] == ROAD || map.getTM()[mY()][mX() - 1] == CROSSROAD)
	{
		return X_MINUS;
	}
	else throw std::logic_error::logic_error("Uncorrect begin coordinate of car_object");
}

float Car::okrugl(const float xy) const
{
	if (INT(xy) % PIXEL == 0) return xy;
	float ost = xy;
	while (ost > PIXEL) ost -= PIXEL;
	if (Direction == X_PLUS || Direction == Y_PLUS) return (xy - ost);   //floor
	else return (xy - ost + PIXEL);                                      //ceil
}

void Car::setDirection(const int direct)
{
	Direction = direct;
	switch (Direction)
	{
	case X_PLUS:
	{
				   dX = Speed;
				   dY = 0;
				   break;
	}
	case Y_PLUS:
	{
				   dX = 0;
				   dY = Speed;
				   break;
	}
	case X_MINUS:
	{
					dX = -Speed;
					dY = 0;
					break;
	}
	case Y_MINUS:
	{
					dX = 0;
					dY = -Speed;
					break;
	}
	}
	setSizeSprite();
}

void Car::setSizeSprite()
{
	switch (Direction)
	{
	case X_PLUS:
	{
				   if (EntryExit > 0) Sprite.setTextureRect(sf::IntRect(PIXEL - EntryExit, 0, EntryExit, PIXEL));
				   else if (!EntryExit) Sprite.setTextureRect(sf::IntRect(0, 0, PIXEL, PIXEL));
				   else Sprite.setTextureRect(sf::IntRect(0, 0, PIXEL + EntryExit, PIXEL));
				   break;
	}
	case X_MINUS:
	{
					if (EntryExit > 0) Sprite.setTextureRect(sf::IntRect(0, PIXEL, EntryExit, PIXEL));
					else if (!EntryExit) Sprite.setTextureRect(sf::IntRect(0, PIXEL, PIXEL, PIXEL));
					else Sprite.setTextureRect(sf::IntRect(-EntryExit, PIXEL, PIXEL + EntryExit, PIXEL));
					break;
	}
	case Y_MINUS:
	{
					if (EntryExit > 0) Sprite.setTextureRect(sf::IntRect(PIXEL, PIXEL, PIXEL, EntryExit));
					else if (!EntryExit) Sprite.setTextureRect(sf::IntRect(PIXEL, PIXEL, PIXEL, PIXEL));
					else Sprite.setTextureRect(sf::IntRect(PIXEL, PIXEL - EntryExit, PIXEL, PIXEL + EntryExit));
					break;
	}
	case Y_PLUS:
	{
				   if (EntryExit > 0) Sprite.setTextureRect(sf::IntRect(PIXEL, PIXEL - EntryExit, PIXEL, EntryExit));
				   else if (!EntryExit) Sprite.setTextureRect(sf::IntRect(PIXEL, 0, PIXEL, PIXEL));
				   else Sprite.setTextureRect(sf::IntRect(PIXEL, EntryExit, PIXEL, PIXEL + EntryExit));
				   break;
	}
	}
}

std::vector<int> Car::freeDirections(const Map &  map)
{
	std::vector<int> vec;
	if (INT(X) % PIXEL == 0 && INT(Y) % PIXEL == 0)
	{
		int random = rand() % 2;
		int koef = INT(pow(-1.f, FLOAT(Direction)));
		if (map.getTM()[mY() + mdY()][mX() + mdX()] == ROAD || \
			(map.getTM()[mY() + mdY()][mX() + mdX()] == EXIT && random) || \
			(map.getTM()[mY() + mdY()][mX() + mdX()] == CROSSROAD && \
			(map.getTM()[mY() + 2 * mdY()][mX() + 2 * mdX()] == CROSSROAD || \
			map.getTM()[mY() + 2 * mdY()][mX() + 2 * mdX()] == ROAD || \
			(map.getTM()[mY() + 2 * mdY()][mX() + 2 * mdX()] == EXIT && random) || \
			map.getTM()[mY() + mdY() - 2 * mdX() * koef][mX() + mdX() - 2 * mdY() * koef] == ROAD) || \
			(map.getTM()[mY() + mdY() - 2 * mdX() * koef][mX() + mdX() - 2 * mdY() * koef] == EXIT && random)))
			vec.push_back(Direction);

		if (((map.getTM()[mY() + mdX() * koef][mX() + mdY() * koef] == ROAD && \
			map.getTM()[mY() + mdY() + mdX()][mX() + mdX() * koef + mdY() * koef] == ROAD) || \
			(map.getTM()[mY() + mdX() * koef][mX() + mdY() * koef] == EXIT && random)) && !ChangeDir)
			vec.push_back((Direction + 1) % 4);

		if (((map.getTM()[mY() - 2 * mdX() * koef][mX() - 2 * mdY() * koef] == ROAD &&\
			map.getTM()[mY() - mdY() - 2 * mdX() * koef][mX() - mdX() - 2 * mdY() * koef] == ROAD) || \
			(map.getTM()[mY() - 2 * mdX() * koef][mX() - 2 * mdY() * koef] == EXIT && random)) && !ChangeDir)
			vec.push_back((Direction + 3) % 4);
	}
	else vec.push_back(Direction);
	for (size_t i = 0; i < vec.size(); ++i)
	{
		if (vec[i] == StopDirection)
		{
			vec.erase(vec.begin() + i);
			Crossroad = true;
			break;
		}
	}
	return vec;
}

int Car::carAround(const Map & map, const bool crash)
{
	int pos = TRUE, koef = 1;
	if (Direction == X_MINUS || Direction == Y_MINUS) koef = -1;
	for (size_t i = 0; i < AllCars.size(); ++i)
	{
		if (Direction == X_PLUS || Direction == X_MINUS)
		{
			if ((X + mdX() * PIXEL + dX) * koef > koef * AllCars[i].X  && AllCars[i].X * koef > X * koef &&  Mod(Y - AllCars[i].Y) < PIXEL)
			{
				crash ? pos = i : pos = FALSE;
				break;
			}
		}
		else
		{
			if ((Y + mdY() * PIXEL + dY) * koef > koef * AllCars[i].Y && AllCars[i].Y * koef > Y * koef &&  Mod(X - AllCars[i].X) < PIXEL)
			{
				crash ? pos = i : pos = FALSE;
				break;
			}
		}
	}
	if (pos >= 0) AllCars[pos].Life = false;
	return pos;
}

void Car::setSpeed(const float newSpeed)
{
	if (Speed != newSpeed)
	{
		Speed = newSpeed;
		if (dX < 0) dX = -Speed;
		else if (dX > 0) dX = Speed;
		if (dY < 0) dY = -Speed;
		else if (dY > 0) dY = Speed;
	}
}

bool Car::lightAround(const Map & map) const
{
	if (map.getTM()[mY() + mdY()][mX() + mdX()] == CROSSROAD && INT(X) % PIXEL == 0 && INT(Y) % PIXEL == 0)
	{
		int koef = 1;
		if (Direction == Y_PLUS || Direction == Y_MINUS) koef = -1;
		if (map.getTM()[mY() + koef * mdX()][mX() + koef * mdY()] == 's')
		{
			for (auto it = TrafficLight::Vec().begin(); it != TrafficLight::Vec().end(); ++it)
			{
				if (mX() + koef * mdY() == it->getX() && mY() + koef * mdX() == it->getY() && it->getColor() != sf::Color::Green)
					return false;
			}
		}
	}
	return true;
}

void Car::signAround(const Map & map)
{
	if (INT(X) % PIXEL == 0 && INT(Y) % PIXEL == 0)
	{
		int koef = 1;
		if (Direction == Y_PLUS || Direction == Y_MINUS) koef = -1;
		if (IsRoadSign(map.getTM()[mY() + koef * mdX()][mX() + koef * mdY()]))
		{
			for (auto it = RoadSign::Vec().begin(); it != RoadSign::Vec().end(); ++it)
			{
				if (mX() + koef * mdY() == it->getX() && mY() + koef * mdX() == it->getY())
				{
					if (it->getLimit() > 0) setSpeed(it->getLimit());
					else StopDirection = -INT(it->getLimit());
					break;
				}
			}
		}
	}
}

bool Car::crashAround() const
{
	if (INT(X) % PIXEL == 0 && INT(Y) % PIXEL == 0)
	{
		for (auto it = Crash::Vec().begin(); it != Crash::Vec().end(); ++it)
		{
			if ((X + mdX() * PIXEL == it->getX1() && Y + mdY() * PIXEL == it->getY1()) || (X + mdX() * PIXEL == it->getX2() && Y + mdY() * PIXEL == it->getY2()))
				return false;
		}
	}
	return true;
}

bool Car::entryExit(const Map & map)
{
	if (EntryExit <= PIXEL && EntryExit >= 1)
	{
		++EntryExit;
		if (EntryExit == PIXEL + 1) EntryExit = 0;
		setSizeSprite();
		return true;
	}
	else if (map.getTM()[size_t(okrugl(Y) / PIXEL)][size_t(okrugl(X) / PIXEL)] == EXIT)
	{
		--EntryExit;
		X += mdX();
		Y += mdY();
		Sprite.setPosition(X, Y);
		if (-EntryExit == PIXEL) Life = false;
		setSizeSprite();
		return true;
	}
	else return false;
}

void Car::go(sf::RenderWindow & window, const Map &  map, bool & crash, bool & pause)
{
	if (!entryExit(map) && !pause)     // проверка на вьезд / выезд авто 
	{
		std::vector<int> freeDir;

		bool change = false;
		leaveCrossroad(map);
		signAround(map);                                               // проверка на знаки       
		if (lightAround(map)) freeDir = freeDirections(map);       // нахождение возможных направлений движения
		if (freeDir.size())
		{
			int random = rand() % freeDir.size();              // рандомный выбор одного из направлений
			if (Direction != freeDir[random])                   // смена направления
			{
				setDirection(freeDir[random]);
				ChangeDir = true;
				change = true;
			}
			int motion = carAround(map, crash);        // проверка на авто впереди
			if (!change && motion != FALSE && Life && crashAround())             // проверка на аварии впереди         
			{
				X += dX;
				Y += dY;
				Sprite.setPosition(X, Y);
				if (motion != TRUE)      // if ( motion == "позиции машины, в которую врезались")
				{
					Life = false;
					Crash(window, okrugl(X - dX), okrugl(Y - dY), okrugl(AllCars[motion].X), okrugl(AllCars[motion].Y));
					crash = false;
				}
			}
		}
	}
	window.draw(Sprite);
}

void Car::leaveCrossroad(const Map & map)
{
	if (map.getTM()[mY()][mX()] == ROAD)
	{
		if (ChangeDir) ChangeDir = false;
		if (Crossroad)
		{
			Crossroad = false;
			StopDirection = UNKNOWN_VALUE;
		}
	}
}

std::vector<Car> & Car::Vec()
{
	return AllCars;
}

Car::~Car()
{
	X = 0;
	Y = 0;
	dX = 0;
	dY = 0;
	Speed = 0;
	EntryExit = 0;
	Life = false;
	ChangeDir = false;
	Crossroad = false;
	Direction = UNKNOWN_VALUE;
	StopDirection = UNKNOWN_VALUE;
}

float Car::getX() const
{
	return X;
}

float Car::getY() const
{
	return Y;
}

bool Car::getLife() const
{
	return Life;
}

int Car::getDirection() const
{
	return Direction;
}

bool Car::getChangeDir() const
{
	return ChangeDir;
}

float Car::getSpeed() const
{
	return Speed;
}

int Car::getStopDirection() const
{
	return StopDirection;
}

int Car::mX() const
{
	return INT(X / PIXEL);
}

int Car::mY() const
{
	return INT(Y / PIXEL);
}

int Car::mdX() const
{
	return INT(dX / Speed);
}

int Car::mdY() const
{
	return INT(dY / Speed);
}




