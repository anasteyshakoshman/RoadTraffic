#pragma once
#include "Include.h"

class Map;

/// Дорожный знак
class RoadSign
{
	/// @brief Ограничение скорости
	int Limit;

	/// @brief Координаты
	int X, Y;

	/// @brief Вектор, хранящий все обьекты данного класса
	static std::vector<RoadSign> AllRoadSign;

public:

	/// @brief Инициализирует поля обьекта
	/// @param x - координата по оси Х
	/// @param y - координата по оси Y
	/// @param map - карта
	RoadSign(const int x, const int y, const Map & map);

	/// @brief Обнуляет поля обьекта
	~RoadSign();

	/// @brief Метод для получения статического вектора класса
	/// @return AllRoadSign - статический вектор, хранящий все обьекты данного класса
	static std::vector<RoadSign> & Vec();

	/// @brief Метод получения значения ограничения скорости
	/// @return ограничение скорости
	int getLimit() const;

	/// @brief Метод получения значения координаты по оси Х
	/// @return координата по оси Х
	int getX() const;

	/// @brief Метод получения значения координаты по оси Y
	/// @return координата по оси Y
	int getY() const;
};



