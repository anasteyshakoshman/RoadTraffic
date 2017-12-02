#pragma once

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <exception>
#include <ctime>

/// ������ ��������� ����� ������ 120 * 120
#define PIX 120  

/// M����������� �������� ��� Release ��� ��������� ���� (���������� :  120 % SPEED == 0)  
#define MAX_SPEED1 2   

/// M���������� �������� ��� Release ��� ��������� ���� (���������� :  120 % SPEED == 0)  
#define MIN_SPEED1 1

///  M����������� �������� ��� Release ��� BIG_MAP  (���������� :  120 % SPEED == 0)  
#define MAX_SPEED2 12   

///  M���������� �������� ��� Release ��� BIG_MAP  (���������� :  120 % SPEED == 0)  
#define MIN_SPEED2 10


/// ������������� ����������e �� ��� �
#define X_PLUS 0 

/// ������������� ����������e �� ��� Y
#define Y_PLUS 1

/// ������������� ����������e �� ��� X
#define X_MINUS 2

/// ������������� ����������e �� ��� Y
#define Y_MINUS 3

/// ��� �������� ������
#define CRASH_TIME 450

/// ������������ ������
#define CRASH_END 3000 

/// ������ ����� �������� 
#define LIMIT_CRASH1 4500  

/// ������ ����� ��������
#define LIMIT_CRASH2 3500


/// ���������� �������� ��� ������� ������� Car
#define TEXTURE_MAP "images/map.png"   

/// ���������� �������� ��� ������� ������� Map
#define TEXTURE_CAR "images/car.png"


/// ������ ����
#define HEIGHT_WINDOW 480

/// ������ ����
#define WIDTH_WINDOW 640


/// ����� ����� ����� ��������� 
#define TIME_CHANGE_LIGHT 300  

/// ����� ����� ����� ��������� 
#define TIME_YELLOW_LIGHT 1000


/// ������ ����� ������������ ����� �����
#define LIMIT_ADD_CAR 600        

/// ���������� �����, ��� ���������� �������� �������� ������
#define BIG_NUM_CAR 30        

/// ���������� �����, ��� ���������� �������� ������� ������ �������������
#define LARGE_NUM_CAR 60

/// ������������ ���-�� ����� ��� ��������� �����
#define MAX_NUM_CAR 100      

/// ������ ��� �������� ������� �����
#define BIG_MAP 'a'

/// ������ ��� �������� ������� �����
#define MIDDLE_MAP 'b'

/// ������ ��� �������� ��������� �����
#define LITTLE_MAP 'c'


           

