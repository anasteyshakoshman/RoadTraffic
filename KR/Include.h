#pragma once

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <exception>
#include <ctime>

/// Каждый квадратик имеет размер 120 * 120
#define PIX 120  

/// Mаксимальная скорость для Release для маленьких карт (примечание :  120 % SPEED == 0)  
#define MAX_SPEED1 2   

/// Mинимальная скорость для Release для маленьких карт (примечание :  120 % SPEED == 0)  
#define MIN_SPEED1 1

///  Mаксимальная скорость для Release для BIG_MAP  (примечание :  120 % SPEED == 0)  
#define MAX_SPEED2 12   

///  Mинимальная скорость для Release для BIG_MAP  (примечание :  120 % SPEED == 0)  
#define MIN_SPEED2 10


/// Положительное направлениe по оси Х
#define X_PLUS 0 

/// Положительное направлениe по оси Y
#define Y_PLUS 1

/// Отрицательное направлениe по оси X
#define X_MINUS 2

/// Отрицательное направлениe по оси Y
#define Y_MINUS 3

/// Для анимации аварии
#define CRASH_TIME 450

/// Длительность аварии
#define CRASH_END 3000 

/// Период между авариями 
#define LIMIT_CRASH1 4500  

/// Период между авариями
#define LIMIT_CRASH2 3500


/// Постоянная текстура для спрайта обьекта Car
#define TEXTURE_MAP "images/map.png"   

/// Постоянная текстура для спрайта обьекта Map
#define TEXTURE_CAR "images/car.png"


/// Ширина окна
#define HEIGHT_WINDOW 480

/// Высота окна
#define WIDTH_WINDOW 640


/// Время смены цвета светофора 
#define TIME_CHANGE_LIGHT 300  

/// Время смены цвета светофора 
#define TIME_YELLOW_LIGHT 1000


/// Период между добавлениями новых машин
#define LIMIT_ADD_CAR 600        

/// Количество машин, при достижении которого возможны аварии
#define BIG_NUM_CAR 30        

/// Количество машин, при достижении которого частота аварий увеличивается
#define LARGE_NUM_CAR 60

/// Максимальное кол-во машин для маленькой карты
#define MAX_NUM_CAR 100      

/// Маркер для создания большой карты
#define BIG_MAP 'a'

/// Маркер для создания средней карты
#define MIDDLE_MAP 'b'

/// Маркер для создания маленькой карты
#define LITTLE_MAP 'c'


           

