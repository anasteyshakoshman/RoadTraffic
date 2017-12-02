#include "Include.h"

#pragma once
class Map;

/// Светофор
class TrafficLight
{

	sf::CircleShape Circle;
	sf::CircleShape BlackCircle;
	sf::Color Color;

	/// Координата по оси Х
	int X;

	/// Координата по оси У
	int Y;

	/// Цвет до смены на желтый : true - если был зеленый, false - если был красный
	bool LastColor;

	/// Время изменения цвета
	int TimeChange;

	/// Вектор, хранящий все обьекты данного класса
	static std::vector<TrafficLight> AllTrafficLight;

public:

	/// Инициализирует поля обьекта
	/// @param window - окно 
	/// @param map - карта 
	/// @param t x - координата по оси Х
	/// @param y - координата по оси Y
	TrafficLight(sf::RenderWindow & window, const Map & map, const int x, const int y);

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
	int getX() const;
	
	/// Метод для получения значения координаты по оси Y
	/// @return Y - координата по оси Y
	int getY() const;
};

