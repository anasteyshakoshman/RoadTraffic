#pragma once
#include <iostream>

/// @brief Карта
class Map
{
	/// Спрайт обьекта
	sf::Sprite Sprite;

	/// Тeкстура для спрайта
	sf::Texture Texture;

	/// Высота карты
	size_t Height;

	/// Ширина карты
	size_t Width;

	/// Вектор, определяющий карту
	vector2d TileMap;

	/// Маркер, определяющий тип карты
	char Scale;

public:

	/// @param scale - маркер, определяющий тип карты
	Map(const char scale);

	/// @param tilemap - схема карты
	Map(const vector2d tilemap);


	/// Метод вывода спрайта карты
	/// @param window - окно
	void work(sf::RenderWindow & window);

	/// Деструктор - обнуляет поля 
	~Map();

	/// Метод для получения высоты карты
	/// @return Height - высота
	size_t getHeight() const;

	/// Метод для получения ширины карты
	/// @return Weight - ширина
	size_t getWidth() const;

	/// Метод для получения вектора, определяющего карту
	/// @return TileMap
	std::vector<std::string>  getTM() const;

	/// Метод для получения маркера, определяещего тип и размер карты
	/// @return Scale
	char getScale() const;

	/// Метод для выбора спрайта обьекта RoadSign
	/// @param x - координата по оси Х
	/// @param у - координата по оси У
	void createRoadSign(const size_t y, const size_t x);

	/// Метод для выбора спрайта дороги
	/// @param x - координата по оси Х
	/// @param у - координата по оси У
	void createRoad(const size_t y, const size_t x);
};









