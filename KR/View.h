#include "Include.h"

class Map;

/// Вид
class View
{
	/// Камера вида
	sf::View Camera;

	/// Размер
	sf::Vector3f Size;

public:

	/// Инициализирует поля обьекта
	/// @param map - карта 
	View(const Map & map);

	/// Метод движения, приближения и отдаления камеры вида 
	/// @param  window - окно 	
	/// @param time - время
	void work(sf::RenderWindow & window, const float time);
};







