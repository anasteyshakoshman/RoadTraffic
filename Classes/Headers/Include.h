#pragma once
#include <SFML/Graphics.hpp>
#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

/// ������ ������� ����� ������ 120 * 120
const int PIXEL = 120;

/// M����������� �������� ��� Release ��� MIDDLE_MAP ��� LITTLE_MAP  
const float MAX_SPEED1 = 2.f;

/// M���������� �������� ��� Release ���  MIDDLE_MAP ��� LITTLE_MAP  
const float MIN_SPEED1 = 1.f;

///  M����������� �������� ��� Release ��� BIG_MAP  
const float MAX_SPEED2 = 60.f;

///  M���������� �������� ��� Release ��� BIG_MAP    
const float MIN_SPEED2 = 40.f;

/// ����������� �������� ������� Car
enum { X_PLUS, Y_PLUS, X_MINUS, Y_MINUS };

/// ��� �������� ������
const size_t CRASH_TIME = 450;

/// ������������ ������
const size_t  CRASH_END = 4000;

/// ������ ����� �������� 
const size_t  LIMIT_CRASH1 = 5500;

/// ������ ����� ��������
const size_t  LIMIT_CRASH2 = 3500;

/// ���������� �������� ��� ������� ������� Car
#define TEXTURE_CAR1  "Images/car.png"

/// ���������� ����� - �������� ��� ������� ������� Car
#define TEXTURE_CAR2  "Images/sport_car.png"

/// ���������� �������� ��� ������� ������� Map
#define TEXTURE_MAP  "Images/map.png"

/// ���������� �������� ������������� �����
#define  FLOAT(a) static_cast<float>(a)

/// ���������� �������� ������������� �����
#define  INT(a) static_cast<int>(a)

/// ���������� �������� �������� ����
#define vector2d std::vector<std::string>

/// ������ ����
const float  HEIGHT_WINDOW = 480.f;

/// ������ ����
const float  WIDTH_WINDOW = 640.f;

/// ����� ����� ����� ��������� 
const size_t  TIME_CHANGE_LIGHT = 300;

/// ����� ����� ����� ��������� 
const size_t  TIME_YELLOW_LIGHT = 1000;

/// ������ ����� ������������ ����� �����
const size_t  LIMIT_ADD_CAR = 400;

/// ���������� �����, ��� ���������� �������� �������� ������
const size_t  BIG_NUM_CAR = 40;

/// ���������� �����, ��� ���������� �������� ������� ������ �������������
const size_t  LARGE_NUM_CAR = 100;

/// ������������ ���-�� ����� ��� ��������� �����
const size_t  MAX_NUM_CAR = 120;

/// ������ ��� �������� ������� �����
const char BIG_MAP = 'a';

/// ������ ��� �������� ������� �����
const char MIDDLE_MAP = 'b';

/// ������ ��� �������� ��������� �����
const char LITTLE_MAP = 'c';

/// ������ ���������������� ����� �����
const char CUSTOM = 'u';

/// ������, ������������ � ������� Map ������
const char ROAD = 'r';

/// ������, ������������ � ������� Map �����������
const char CROSSROAD = 'p';

/// ������, ������������ � ������� Map �����
const char EXIT = 'e';

/// ������, ������������ � ������� Map ���� ��������� ��������, �������������� ��������
const char SPEED_LIMIT_ON = 'k';

/// ������, ������������ � ������� Map ���� ��������� ��������, ��������� ����������� �� ��������
const char SPEED_LIMIT_OFF = 'y';

/// ��������� �������� ��� ���� �������
const int  UNKNOWN_VALUE = -1;

/// ������ ��� ��������� ������� �������
const int  TRUE = -1;

/// ���� ��� ��������� ������� �������
const int  FALSE = -2;










