#pragma once

#include "Include.h"

class Map;



/// @brief Дорожный знак
class RoadSign
{
	/// @brief Ограничение скорости
	float Limit;

	/// @brief Координата по оси Х
	float X;

	/// @brief Координата по оси Y
	float Y;

	/// @brief Вектор, хранящий все обьекты данного класса
	static std::vector<RoadSign> AllRoadSign;

public:

	/// @param map - карта
	/// @param x - координата по оси Х
	/// @param y - координата по оси Y
	RoadSign(const Map & map, const float x, const float y);

	/// @brief Обнуляет поля обьекта
	~RoadSign();

	/// @brief Метод для получения статического вектора класса
	/// @return AllRoadSign - статический вектор, хранящий все обьекты данного класса
	static std::vector<RoadSign> & Vec();

	/// @brief Метод получения значения ограничения скорости
	/// @return ограничение скорости
	float getLimit() const;

	/// @brief Метод получения значения координаты по оси Х
	/// @return координата по оси Х
	float getX() const;

	/// @brief Метод получения значения координаты по оси Y
	/// @return координата по оси Y
	float getY() const;
};



