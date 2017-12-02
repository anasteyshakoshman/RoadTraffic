#include "RoadSign.h"
#include "Map.h"
std::vector<RoadSign> RoadSign::AllRoadSign;


RoadSign::RoadSign(const int x, const int y, const Map & map) : X(x), Y(y)
{
	if (map.getScale() == BIG_MAP)
	{
		if (map.getTM()[y][x] == 'y') Limit = MAX_SPEED2;
		else Limit = MIN_SPEED2;
	}
	else
	{
		if (map.getTM()[y][x] == 'y') Limit = MAX_SPEED1;
		else Limit = MIN_SPEED1;
	}
	AllRoadSign.push_back(*this);
};

std::vector<RoadSign> & RoadSign::Vec()
{
	return AllRoadSign;
};

RoadSign::~RoadSign()
{
	X = 0;
	Y = 0;
	Limit = 0;
};

int RoadSign::getLimit() const
{
	return Limit;
};

int RoadSign::getX() const
{
	return X;
};

int RoadSign::getY() const
{
	return Y;
};
