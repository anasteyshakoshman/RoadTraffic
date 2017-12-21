#pragma once
#include <SFML/Graphics.hpp>
#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

/// Каждый квадрат имеет размер 120 * 120
const int PIXEL = 120;

/// Mаксимальная скорость для Release для MIDDLE_MAP или LITTLE_MAP  
const float MAX_SPEED1 = 2.f;

/// Mинимальная скорость для Release для  MIDDLE_MAP или LITTLE_MAP  
const float MIN_SPEED1 = 1.f;

///  Mаксимальная скорость для Release для BIG_MAP  
const float MAX_SPEED2 = 60.f;

///  Mинимальная скорость для Release для BIG_MAP    
const float MIN_SPEED2 = 40.f;

/// Направления движения обьекта Car
enum { X_PLUS, Y_PLUS, X_MINUS, Y_MINUS };

/// Для анимации аварии
const size_t CRASH_TIME = 450;

/// Длительность аварии
const size_t  CRASH_END = 4000;

/// Период между авариями 
const size_t  LIMIT_CRASH1 = 5500;

/// Период между авариями
const size_t  LIMIT_CRASH2 = 3500;

/// Постоянная текстура для спрайта обьекта Car
#define TEXTURE_CAR1  "Images/car.png"

/// Постоянная спорт - текстура для спрайта обьекта Car
#define TEXTURE_CAR2  "Images/sport_car.png"

/// Постоянная текстура для спрайта обьекта Map
#define TEXTURE_MAP  "Images/map.png"

/// Сокращение длинного пребразования типов
#define  FLOAT(a) static_cast<float>(a)

/// Сокращение длинного пребразования типов
#define  INT(a) static_cast<int>(a)

/// Сокращение длинного названия типа
#define vector2d std::vector<std::string>

/// Ширина окна
const float  HEIGHT_WINDOW = 480.f;

/// Высота окна
const float  WIDTH_WINDOW = 640.f;

/// Время смены цвета светофора 
const size_t  TIME_CHANGE_LIGHT = 300;

/// Время смены цвета светофора 
const size_t  TIME_YELLOW_LIGHT = 1000;

/// Период между добавлениями новых машин
const size_t  LIMIT_ADD_CAR = 400;

/// Количество машин, при достижении которого возможны аварии
const size_t  BIG_NUM_CAR = 40;

/// Количество машин, при достижении которого частота аварий увеличивается
const size_t  LARGE_NUM_CAR = 100;

/// Максимальное кол-во машин для маленькой карты
const size_t  MAX_NUM_CAR = 120;

/// Маркер для создания большой карты
const char BIG_MAP = 'a';

/// Маркер для создания средней карты
const char MIDDLE_MAP = 'b';

/// Маркер для создания маленькой карты
const char LITTLE_MAP = 'c';

/// Маркер пользовательской схемы карты
const char CUSTOM = 'u';

/// Символ, обозначающий в обьекте Map дорогу
const char ROAD = 'r';

/// Символ, обозначающий в обьекте Map перекресток
const char CROSSROAD = 'p';

/// Символ, обозначающий в обьекте Map выезд
const char EXIT = 'e';

/// Символ, обозначающий в обьекте Map знак дорожного движения, ограничивающий скорость
const char SPEED_LIMIT_ON = 'k';

/// Символ, обозначающий в обьекте Map знак дорожного движения, снимающий ограничение по скорости
const char SPEED_LIMIT_OFF = 'y';

/// Временное значение для поля обьекта
const int  UNKNOWN_VALUE = -1;

/// Истина для некоторых методов обьекта
const int  TRUE = -1;

/// Ложь для некоторых методов обьекта
const int  FALSE = -2;










