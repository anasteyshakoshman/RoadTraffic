#pragma once
#include "Include.h"
#include "Car.h"
#include "Map.h"
#include "View.h"
#include "TrafficLight.h"
#include "RoadSign.h"
#include "Crash.h"


/// Функция для проверки корректности скорости
/// @return true, если заданная #define скорость корректна для данной прогаммы
/// @return false - если не корректна
bool checkSpeed();

/// Функция для создания обьектов TrafficLight и RoadSign
/// @param  window - окно 
/// @param map - карта 
void createTrLightAndRSign(sf::RenderWindow & window, const Map & map);

/// Функция для добавления нового обьекта Car
/// @param texture - текстура для спрайта обьекта
/// @param  window - окно 
/// @param map - карта 
/// @param currentClock - вектор, в котором в поле х хранится текущее время, в поле y - время последнего добавления новой машины
void addCar(const sf::Texture & texture, sf::RenderWindow & window, const Map & map, sf::Vector3i & currentClock);

/// Функция для определения возможности аварии
/// @param currentClock - вектор, в котором в поле х хранится текущее время, в поле z - время последней аварии
/// @param map - карта 
/// @return true - если авария возможна
/// @return false - если не возможна
bool isCrash(sf::Vector3i & currentClock, const Map & map);

/// Функция для запуска основных методов движения, изменения и создания возможных обьектов
/// @param  window - окно 
/// @param map - карта 
/// @param  view - камера вида 
/// @param currentClock - вектор, в котором в поле х хранится текущее время, в поле y - время последнего добавления новой машины, в поле z - время последней аварии
/// @param time - время для для правильной работы камеры вида
void Work(sf::RenderWindow & window, Map & map, View & view, const sf::Texture & texture, sf::Vector3i & currentClock, float time, bool & crash);



