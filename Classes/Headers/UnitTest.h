#pragma once

#include "Include.h"

class Map;

/// Шаблонная функция, сравнивающая два значения
/// @param true_value - изначально известное, правильное значение
/// @param  chack_value - значение, которое надо проверить
/// @param functionName - имя функции/метода, результат которой/которого проверяется
template <typename T>
void Assert(const T true_value, const T check_value, const std::string functionName);

/// Функция, тестирующая методы класса Car 
/// @param map - карта 
/// @param  window - окно 
/// @param was - вектор, хранящий значение истина/ложь, в котором каждый элемент отвечает за тестирование одного метода
/// @return true - все тесты были пройдены, исход каждого выведен на экран
/// @return false - не все тесты были пройдены
bool UTest_Car(const Map & map, sf::RenderWindow & window, std::vector<bool> & was);

/// Функция, тестирующая методы классов TrafficLight, RoadSign и Crash
/// @param map - карта
/// @param  window - окно 
/// @param was - вектор, хранящий значение истина/ложь, в котором каждый элемент отвечает за тестирование одного метода
/// @return true - все тесты были пройдены, исход каждого выведен на экран
/// @return false - не все тесты были пройдены
bool UTest_Classes(const Map & map, sf::RenderWindow & window, std::vector<bool> & was);
