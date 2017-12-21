#pragma once

#include "Include.h"

class Map;

/// @brief Автомобиль
class Car
{
	/// Координата по оси Х 
	float X;

	/// Координата по оси Y
	float Y;

	/// Приращение по оси Х
	float dX;

	/// Приращение по оси У
	float dY;

	/// Скорость
	float Speed;

	/// Направление
	int Direction;

	/// Спрайт обьекта
	sf::Sprite Sprite;

	/// Цвет
	sf::Color Color;

	/// Смена направления
	bool ChangeDir;

	/// Жизнь
	bool Life;

	/// Переменная, отвечающая за анимация вьезда на карту и выезда с нее обьекта Car
	int EntryExit;

	/// Направление, поворот в которое,  запрещен
	int StopDirection;

	/// Нахождение авто на перекрестке 
	bool Crossroad;

	/// Вектор, хранящий все обьекты данного класса
	static std::vector<Car> AllCars;

public:

	/// @param map - карта 
	/// @param texture - текстура для спрайта обьекта
	/// @param col - цвет обьекта 
	Car(const Map & map, const sf::Texture & texture, sf::Color col);

	/// @param texture - текстура для спрайта обьекта
	/// @param col - цвет обьекта
	/// @param x - начальная координата по оси x 
	/// @param y - начальная координата по оси y 
	/// @param direction - начальное направление движения обьекта 
	Car(const sf::Texture & texture, sf::Color col, const float x, const float y, const int direction);

	/// Дeструктор - обнуляет поля объекта
	~Car();

	/// Метод для получения статического вектора класса
	/// @return AllCars - статический вектор, хранящий все обьекты данного класса
	static std::vector<Car> & Vec();

	/// Метод движения и вывода в окно спрайта обьекта
	/// @param  window - окно 
	/// @param map - карта 	
	/// @param  crash - возможность аварии	
	void go(sf::RenderWindow & window, const Map &  map, bool & crash, bool & pause);

	/// Метод определения возможных направлений движения обьекта
	/// @param map - карта 
	/// @return вектор возможных направлений движения обьекта
	std::vector<int> freeDirections(const Map &  map);

	/// Метод анамации вьезда на карту и выезда с нее обьекта 
	/// @param map - карта 
	/// @return true - вьезд / выезд произошел
	/// @return false - вьезда / выезда не было
	bool entryExit(const Map & map);

	/// Метод определения возможности двигаться в заданном направлении, проверяет возможность нахождения обьекта Crash по координатам обьекта Car
	/// @return true - можно двигаться
	/// @return false - движение запрещено
	bool crashAround() const;

	/// Метод определения возможности нахождения обьекта Sign, меняет скорость обьекта (Speed) на значение, заданное в Sign (Limit)
	/// @param map - карта 
	void signAround(const Map & map);

	/// Метод определения возможности двигаться в заданном направлении, проверяет возможность нахождения другого обьекта данного класса по координатам действующего обьекта 
	/// @param map - карта 
	/// @param  crash - возможность аварии
	/// @return TRUE - можно двигаться
	/// @return FALSE - движение запрещено
	/// @return позицию обьекта Car в векторе, хранящем все обьекты Car, движение разрешено
	int carAround(const Map & map, const bool crash);

	/// Метод определения возможности двигаться в заданном направлении, проверяет возможность нахождения обьекта TrafficLight по координатам обьекта Car
	/// @param map - карта 
	/// @return true - можно двигаться
	/// @return false - движение запрещено
	bool lightAround(const Map & map) const;

	/// Метод изменяющий поля СhangeDir и Crossroad при покидании обьекта данного класса перекрестка
	void leaveCrossroad(const Map & map);

	/// Метод, устанавливающий значение направления 
	/// @param direct - новое значение направления
	void setDirection(const int direct);

	/// Метод, устанавливающий значение скорости 
	/// @param newSpeed - новое значение скорости
	void setSpeed(const float newSpeed);

	/// Метод, устанавливающий размер спрайта
	void setSizeSprite();

	/// Метод получения значения жизни 
	/// @return поле Life
	bool getLife() const;

	/// Метод получения значения скорости 
	/// @return скорость
	float getSpeed() const;

	/// Метод получения значения координаты по оси Х
	/// @return координата по оси Х
	float getX() const;

	/// Метод получения значения координаты по оси Y
	/// @return координата по оси Y
	float getY() const;

	/// Метод получения значения направления 
	/// @return поле Direction
	int getDirection() const;

	/// Метод получения значения времено запрещенного направления 
	/// @return поле StopDirection
	int getStopDirection() const;

	/// Метод получения значения переменной, отвечающей за смену направления на данном перекрестке
	/// @return поле ChangeDir
	bool getChangeDir() const;

	/// Метод, который находит и возвращает направление движения обьекта, когда он только создан
	/// @param map - карта 
	/// @return начальное направление движения обьекта
	int getBeginDirection(const Map & map);

	/// Метод переводa координаты X обьекта в доступную для подстановки в карту
	/// @return округленная координата по оси Х
	int mX() const;

	/// Метод переводa координаты Y обьекта в доступную для подстановки в карту
	/// @return округленная координата по оси Y
	int mY() const;

	/// Метод переводa приращения dX обьекта в доступное для подстановки в карту
	/// @return округленное приращение по оси Х
	int mdX() const;

	/// Метод перевод приращения dY обьекта в доступное для подстановки в карту
	/// @return округленное приращениепо оси Y
	int mdY() const;

	/// Метод перевода координат в доступные для подстановки в карту, округление в меньшую сторону, если направление положительное, в большую, если отрицательное
	/// @param xy - координата
	/// @return округленная координата
	float okrugl(const float xy) const;

};

