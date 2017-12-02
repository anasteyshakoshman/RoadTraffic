#pragma once
#include "Include.h"

/// ������
class Crash
{
	/// ������� ���� ��� �������� ������, ������������� �� ����������� ������� ����������
	sf::CircleShape Red1;

	/// ������� ���� ��� �������� ������, ������������� �� ����������� ������� ����������
	sf::CircleShape Red2;

	/// ������ ���� ��� �������� ������, ������������� �� ����������� ������� ����������
	sf::CircleShape Yellow1;

	/// ������ ���� ��� �������� ������, ������������� �� ����������� ������� ����������
	sf::CircleShape Yellow2;

	/// ����� �������� ������
	int Time;

	/// ���������� �� ��� � ������� ����������  
	int X1;
	
	/// ���������� �� ��� � ������� ����������  
	int Y1;

	/// ���������� �� ��� � ������� ����������  
	int X2;

	/// ���������� �� ��� � ������� ����������  
	int Y2;

	/// ������ �������� �����
	int RadiusRed;
	
	/// ������ ������� �����
	int RadiusYellow;

	/// ������, �������� ��� ������� ������� ������
	static std::vector<Crash> AllCrash;

public:

	/// �������������� ���� �������
	/// @param  window - ���� 
	/// @param x1 - ���������� 1 �� ��� �
	/// @param y1 - ���������� 1 �� ��� Y
	/// @param x2 - ���������� 2 �� ��� �
	/// @param y2 - ���������� 2 �� ��� Y
	Crash(sf::RenderWindow & window, const int x1, const int y1, const int x2, const int y2);

	/// ���������� - �������� ���� �������
	~Crash();

	/// ����� ��� ��������� ������������ ������� ������
	/// @return AllCrash - ����������� ������, �������� ��� ������� ������� ������
	static std::vector<Crash> & Vec();

	/// ����� �������� ������ 
	/// @param  window - ���� 	
	/// @return �����
	int work(sf::RenderWindow & window);

	/// ����� ��������� ���������� 1 �� ��� �
	/// @return X1 - ���������� 1 �� ��� �
	int getX1() const;

	/// ����� ��������� ���������� 1 �� ��� Y
	/// @return Y1 - ���������� 1 �� ��� Y
	int getY1() const;

	/// ����� ��������� ���������� 2 �� ��� �
	/// @return X2 - ���������� 2 �� ��� X
	int getX2() const;

	/// ����� ��������� ���������� 2 �� ��� Y
	/// @return Y2 - ���������� 2 �� ��� Y
	int getY2() const;	
};
