#pragma once

#include "TrafficLight.h"
#include "RoadSign.h"
#include "UnitTest.h"
#include "Include.h"
#include "Crash.h"
#include "View.h"
#include "Car.h"
#include "Map.h"

/// ������� ��� �������� ������������ ��������
void CheckSpeed();

/// ������� ��� �������� �������� TrafficLight � RoadSign
/// @param map - ����� 
void CreateTrLightAndRSign(const Map & map);

/// ������� ��� ���������� ������ ������� Car
/// @param map - ����� 
/// @param texture - �������� ��� ������� �������
/// @param currentClock - ������, � ������� � ���� � �������� ������� �����, � ���� y - ����� ���������� ���������� ����� ������
void AddCar(const Map & map, const sf::Texture & texture, sf::Vector3i & currentClock);

/// ������� ��� ����������� ����������� ������
/// @param map - ����� 
/// @param currentClock - ������, � ������� � ���� � �������� ������� �����, � ���� z - ����� ��������� ������
/// @return true - ���� ������ ��������
/// @return false - ���� �� ��������
bool IsCrash(const Map &  map, sf::Vector3i & currentClock);

/// ������� ��� ������� �������� ������� ��������, ��������� � �������� ��������� ��������
/// @param  window - ���� 
/// @param map - ����� 
/// @param  view - ������ ���� 
/// @param texture1  - �������� ���  ������� ������� Car
/// @param  texture2 - �������� ���  ������� ������� Car
/// @param currentClock - ������, � ������� � ���� � �������� ������� �����, � ���� y - ����� ���������� ���������� ����� ������, � ���� z - ����� ��������� ������
/// @param time - ����� ��� ���������� ������ ������ ����
void Work(sf::RenderWindow & window, Map & map, View & view, const sf::Texture & texture1, const sf::Texture & texture2, sf::Vector3i & currentClock, float time, bool & crash, bool & pause);


/// �������, ������������ ����, ��������� � ������� ������� rand()
sf::Color & chooseColor();