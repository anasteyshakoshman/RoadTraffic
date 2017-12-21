#pragma once

#include "Include.h"

class Map;

/// @brief Светофор
class TrafficLight
{
	/// Графическое изображение обьекта - круг
	sf::CircleShape Circle;

	/// Графическое изображение обьекта - обводка вокруг круга
	sf::CircleShape BlackCircle;

	/// Цвет 
	sf::Color Color;

	/// Координата по оси Х
	float X;

	/// Координата по оси У
	float Y;

	/// Цвет до смены на желтый : true - если был зеленый, false - если был красный
	bool LastColor;

	/// Время изменения цвета
	int TimeChange;

	/// Вектор, хранящий все обьекты данного класса
	static std::vector<TrafficLight> AllTrafficLight;

public:

	/// @param map - карта 
	/// @param x - координата по оси Х
	/// @param y - координата по оси Y
	TrafficLight(const Map & map, const float x, const float y);

	/// Деструктор - обнуляет поля обьекта
	~TrafficLight();

	/// Метод для получения статического вектора класса
	/// @return AllTrafficLight - статический вектор, хранящий все обьекты данного класса
	static std::vector<TrafficLight> & Vec();

	/// Метод, запускающий смену цвета обьекта в зависимости от времени
	/// @param  clock - текущее время
	/// @param  window - окно 
	void work(const int clock, sf::RenderWindow & window);

	/// Метод для получения значения цвета обьекта
	/// @return Color - цвет обьекта
	sf::Color getColor() const;


	/// Метод для получения значения координаты по оси Х
	/// @return X - координата по оси X
	float getX() const;

	/// Метод для получения значения координаты по оси Y
	/// @return Y - координата по оси Y
	float getY() const;

	/// Метод для получения значения времени от последнего изменения цвета обьекта
	/// @return TimeChange
	int getTimeChange() const;

	/// Метод для получения значения поля, хранящего прдыдущий цвет светофора (перед сменой на желтый)
	/// @return поле LastColor
	bool getLastColor() const;
};

