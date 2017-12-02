#pragma once
#include "Include.h"
#include "Car.h"
#include "Map.h"
#include "View.h"
#include "TrafficLight.h"
#include "RoadSign.h"
#include "Crash.h"


/// ������� ��� �������� ������������ ��������
/// @return true, ���� �������� #define �������� ��������� ��� ������ ��������
/// @return false - ���� �� ���������
bool checkSpeed();

/// ������� ��� �������� �������� TrafficLight � RoadSign
/// @param  window - ���� 
/// @param map - ����� 
void createTrLightAndRSign(sf::RenderWindow & window, const Map & map);

/// ������� ��� ���������� ������ ������� Car
/// @param texture - �������� ��� ������� �������
/// @param  window - ���� 
/// @param map - ����� 
/// @param currentClock - ������, � ������� � ���� � �������� ������� �����, � ���� y - ����� ���������� ���������� ����� ������
void addCar(const sf::Texture & texture, sf::RenderWindow & window, const Map & map, sf::Vector3i & currentClock);

/// ������� ��� ����������� ����������� ������
/// @param currentClock - ������, � ������� � ���� � �������� ������� �����, � ���� z - ����� ��������� ������
/// @param map - ����� 
/// @return true - ���� ������ ��������
/// @return false - ���� �� ��������
bool isCrash(sf::Vector3i & currentClock, const Map & map);

/// ������� ��� ������� �������� ������� ��������, ��������� � �������� ��������� ��������
/// @param  window - ���� 
/// @param map - ����� 
/// @param  view - ������ ���� 
/// @param currentClock - ������, � ������� � ���� � �������� ������� �����, � ���� y - ����� ���������� ���������� ����� ������, � ���� z - ����� ��������� ������
/// @param time - ����� ��� ��� ���������� ������ ������ ����
void Work(sf::RenderWindow & window, Map & map, View & view, const sf::Texture & texture, sf::Vector3i & currentClock, float time, bool & crash);



