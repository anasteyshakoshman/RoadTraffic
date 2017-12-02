#include "Include.h"

#pragma once
class Map;

/// ��������
class TrafficLight
{

	sf::CircleShape Circle;
	sf::CircleShape BlackCircle;
	sf::Color Color;

	/// ���������� �� ��� �
	int X;

	/// ���������� �� ��� �
	int Y;

	/// ���� �� ����� �� ������ : true - ���� ��� �������, false - ���� ��� �������
	bool LastColor;

	/// ����� ��������� �����
	int TimeChange;

	/// ������, �������� ��� ������� ������� ������
	static std::vector<TrafficLight> AllTrafficLight;

public:

	/// �������������� ���� �������
	/// @param window - ���� 
	/// @param map - ����� 
	/// @param t x - ���������� �� ��� �
	/// @param y - ���������� �� ��� Y
	TrafficLight(sf::RenderWindow & window, const Map & map, const int x, const int y);

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
	int getX() const;
	
	/// ����� ��� ��������� �������� ���������� �� ��� Y
	/// @return Y - ���������� �� ��� Y
	int getY() const;
};

