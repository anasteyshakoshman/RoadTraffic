#pragma once

#include "TrafficLight.h"
#include "RoadSign.h"
#include "UnitTest.h"
#include "Include.h"
#include "Crash.h"
#include "View.h"
#include "Car.h"
#include "Map.h"

/// Функция для проверки корректности скорости
void CheckSpeed();

/// Функция для создания обьектов TrafficLight и RoadSign
/// @param map - карта 
void CreateTrLightAndRSign(const Map & map);

/// Функция для добавления нового обьекта Car
/// @param map - карта 
/// @param texture - текстура для спрайта обьекта
/// @param currentClock - вектор, в котором в поле х хранится текущее время, в поле y - время последнего добавления новой машины
void AddCar(const Map & map, const sf::Texture & texture, sf::Vector3i & currentClock);

/// Функция для определения возможности аварии
/// @param map - карта 
/// @param currentClock - вектор, в котором в поле х хранится текущее время, в поле z - время последней аварии
/// @return true - если авария возможна
/// @return false - если не возможна
bool IsCrash(const Map &  map, sf::Vector3i & currentClock);

/// Функция для запуска основных методов движения, изменения и создания возможных обьектов
/// @param  window - окно 
/// @param map - карта 
/// @param  view - камера вида 
/// @param texture1  - текстура для  спрайта обьекта Car
/// @param  texture2 - текстура для  спрайта обьекта Car
/// @param currentClock - вектор, в котором в поле х хранится текущее время, в поле y - время последнего добавления новой машины, в поле z - время последней аварии
/// @param time - время для правильной работы камеры вида
void Work(sf::RenderWindow & window, Map & map, View & view, const sf::Texture & texture1, const sf::Texture & texture2, sf::Vector3i & currentClock, float time, bool & crash, bool & pause);


/// Функция, возвращающая цвет, выбранный с помощью функции rand()
sf::Color & chooseColor();