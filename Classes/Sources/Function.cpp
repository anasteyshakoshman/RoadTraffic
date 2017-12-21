#include "Function.h"



bool IsRoadSign(const char marker)
{
	return (marker == SPEED_LIMIT_OFF || marker == SPEED_LIMIT_ON || marker == '0' || marker == '1' || marker == '2' || marker == '3');
}

bool IsRoad(const char marker)
{
	return (marker == ROAD || marker == CROSSROAD);
}

float Mod(const float num)
{
	return sqrt(num * num);
}

