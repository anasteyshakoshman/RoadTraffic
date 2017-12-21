#include "RoadSign.h"
#include "Map.h"

std::vector<RoadSign> RoadSign::AllRoadSign;

RoadSign::RoadSign(const Map & map, const float x, const float y) : X(x), Y(y)
{
	char marker = map.getTM()[size_t(Y)][size_t(X)];
	if (marker != SPEED_LIMIT_OFF && marker != SPEED_LIMIT_ON) Limit = -(static_cast<float>(marker)-48);
	else
	{
		if (map.getScale() == BIG_MAP)
		{
			if (marker == SPEED_LIMIT_OFF) Limit = MAX_SPEED2;
			else Limit = MIN_SPEED2;
		}
		else
		{
			if (marker == SPEED_LIMIT_OFF) Limit = MAX_SPEED1;
			else Limit = MIN_SPEED1;
		}
	}
	AllRoadSign.push_back(*this);
}

std::vector<RoadSign> & RoadSign::Vec()
{
	return AllRoadSign;
}

RoadSign::~RoadSign()
{
	X = 0;
	Y = 0;
	Limit = 0;
}

float RoadSign::getLimit() const
{
	return Limit;
}

float RoadSign::getX() const
{
	return X;
}

float RoadSign::getY() const
{
	return Y;
}