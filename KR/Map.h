#pragma once
#include "Include.h"

class RoadSign;

/// Карта
class Map
{
	/// Тукстура для спрайта карты
	sf::Texture Texture;

	/// Спрайт карты
	sf::Sprite Sprite;

	/// Вектор, определяющий карту
	std::vector<std::string> TileMap;

	/// Высота 
	int Height;

	/// Ширина
	int Width;

	/// Маркер, определяющий тип карты
	char Scale;

public:

	/// @param scale - маркер, определяющий тип карты
	Map(const char scale);

	/// Метод для рисования карты
	/// @param window - окно
	void work(sf::RenderWindow & window);
	
	/// Деструктор - обнуляет поля 
	~Map();

	/// Метод для получения высоты карты
	/// @return Height - высота
	int getHeight() const;

	/// Метод для получения ширины карты
	/// @return Weight - ширина
	int getWidth() const;
	
	/// Метод для получения вектора, определяющего карту
	/// @return TileMap
	std::vector<std::string>  getTM() const;

	/// Метод для получения маркера, определяещего тип карты
	/// @return Scale
	char getScale() const;

	/// Метод для выбора спрайта знака
	/// @param x - координата по оси Х
	/// @param у - координата по оси У
	void CreateRoadSign(const int x, const int y);
};









