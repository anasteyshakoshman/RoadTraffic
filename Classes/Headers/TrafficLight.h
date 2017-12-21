#pragma once

#include "Include.h"

class Map;

/// @brief ��������
class TrafficLight
{
	/// ����������� ����������� ������� - ����
	sf::CircleShape Circle;

	/// ����������� ����������� ������� - ������� ������ �����
	sf::CircleShape BlackCircle;

	/// ���� 
	sf::Color Color;

	/// ���������� �� ��� �
	float X;

	/// ���������� �� ��� �
	float Y;

	/// ���� �� ����� �� ������ : true - ���� ��� �������, false - ���� ��� �������
	bool LastColor;

	/// ����� ��������� �����
	int TimeChange;

	/// ������, �������� ��� ������� ������� ������
	static std::vector<TrafficLight> AllTrafficLight;

public:

	/// @param map - ����� 
	/// @param x - ���������� �� ��� �
	/// @param y - ���������� �� ��� Y
	TrafficLight(const Map & map, const float x, const float y);

	/// ���������� - �������� ���� �������
	~TrafficLight();

	/// ����� ��� ��������� ������������ ������� ������
	/// @return AllTrafficLight - ����������� ������, �������� ��� ������� ������� ������
	static std::vector<TrafficLight> & Vec();

	/// �����, ����������� ����� ����� ������� � ����������� �� �������
	/// @param  clock - ������� �����
	/// @param  window - ���� 
	void work(const int clock, sf::RenderWindow & window);

	/// ����� ��� ��������� �������� ����� �������
	/// @return Color - ���� �������
	sf::Color getColor() const;


	/// ����� ��� ��������� �������� ���������� �� ��� �
	/// @return X - ���������� �� ��� X
	float getX() const;

	/// ����� ��� ��������� �������� ���������� �� ��� Y
	/// @return Y - ���������� �� ��� Y
	float getY() const;

	/// ����� ��� ��������� �������� ������� �� ���������� ��������� ����� �������
	/// @return TimeChange
	int getTimeChange() const;

	/// ����� ��� ��������� �������� ����, ��������� ��������� ���� ��������� (����� ������ �� ������)
	/// @return ���� LastColor
	bool getLastColor() const;
};

