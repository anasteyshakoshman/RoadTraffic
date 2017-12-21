#pragma once

#include "Include.h"

class Map;

/// ��������� �������, ������������ ��� ��������
/// @param true_value - ���������� ���������, ���������� ��������
/// @param  chack_value - ��������, ������� ���� ���������
/// @param functionName - ��� �������/������, ��������� �������/�������� �����������
template <typename T>
void Assert(const T true_value, const T check_value, const std::string functionName);

/// �������, ����������� ������ ������ Car 
/// @param map - ����� 
/// @param  window - ���� 
/// @param was - ������, �������� �������� ������/����, � ������� ������ ������� �������� �� ������������ ������ ������
/// @return true - ��� ����� ���� ��������, ����� ������� ������� �� �����
/// @return false - �� ��� ����� ���� ��������
bool UTest_Car(const Map & map, sf::RenderWindow & window, std::vector<bool> & was);

/// �������, ����������� ������ ������� TrafficLight, RoadSign � Crash
/// @param map - �����
/// @param  window - ���� 
/// @param was - ������, �������� �������� ������/����, � ������� ������ ������� �������� �� ������������ ������ ������
/// @return true - ��� ����� ���� ��������, ����� ������� ������� �� �����
/// @return false - �� ��� ����� ���� ��������
bool UTest_Classes(const Map & map, sf::RenderWindow & window, std::vector<bool> & was);
