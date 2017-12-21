#pragma once

#include "Include.h"

class Map;

/// @brief ����������
class Car
{
	/// ���������� �� ��� � 
	float X;

	/// ���������� �� ��� Y
	float Y;

	/// ���������� �� ��� �
	float dX;

	/// ���������� �� ��� �
	float dY;

	/// ��������
	float Speed;

	/// �����������
	int Direction;

	/// ������ �������
	sf::Sprite Sprite;

	/// ����
	sf::Color Color;

	/// ����� �����������
	bool ChangeDir;

	/// �����
	bool Life;

	/// ����������, ���������� �� �������� ������ �� ����� � ������ � ��� ������� Car
	int EntryExit;

	/// �����������, ������� � �������,  ��������
	int StopDirection;

	/// ���������� ���� �� ����������� 
	bool Crossroad;

	/// ������, �������� ��� ������� ������� ������
	static std::vector<Car> AllCars;

public:

	/// @param map - ����� 
	/// @param texture - �������� ��� ������� �������
	/// @param col - ���� ������� 
	Car(const Map & map, const sf::Texture & texture, sf::Color col);

	/// @param texture - �������� ��� ������� �������
	/// @param col - ���� �������
	/// @param x - ��������� ���������� �� ��� x 
	/// @param y - ��������� ���������� �� ��� y 
	/// @param direction - ��������� ����������� �������� ������� 
	Car(const sf::Texture & texture, sf::Color col, const float x, const float y, const int direction);

	/// �e�������� - �������� ���� �������
	~Car();

	/// ����� ��� ��������� ������������ ������� ������
	/// @return AllCars - ����������� ������, �������� ��� ������� ������� ������
	static std::vector<Car> & Vec();

	/// ����� �������� � ������ � ���� ������� �������
	/// @param  window - ���� 
	/// @param map - ����� 	
	/// @param  crash - ����������� ������	
	void go(sf::RenderWindow & window, const Map &  map, bool & crash, bool & pause);

	/// ����� ����������� ��������� ����������� �������� �������
	/// @param map - ����� 
	/// @return ������ ��������� ����������� �������� �������
	std::vector<int> freeDirections(const Map &  map);

	/// ����� �������� ������ �� ����� � ������ � ��� ������� 
	/// @param map - ����� 
	/// @return true - ����� / ����� ���������
	/// @return false - ������ / ������ �� ����
	bool entryExit(const Map & map);

	/// ����� ����������� ����������� ��������� � �������� �����������, ��������� ����������� ���������� ������� Crash �� ����������� ������� Car
	/// @return true - ����� ���������
	/// @return false - �������� ���������
	bool crashAround() const;

	/// ����� ����������� ����������� ���������� ������� Sign, ������ �������� ������� (Speed) �� ��������, �������� � Sign (Limit)
	/// @param map - ����� 
	void signAround(const Map & map);

	/// ����� ����������� ����������� ��������� � �������� �����������, ��������� ����������� ���������� ������� ������� ������� ������ �� ����������� ������������ ������� 
	/// @param map - ����� 
	/// @param  crash - ����������� ������
	/// @return TRUE - ����� ���������
	/// @return FALSE - �������� ���������
	/// @return ������� ������� Car � �������, �������� ��� ������� Car, �������� ���������
	int carAround(const Map & map, const bool crash);

	/// ����� ����������� ����������� ��������� � �������� �����������, ��������� ����������� ���������� ������� TrafficLight �� ����������� ������� Car
	/// @param map - ����� 
	/// @return true - ����� ���������
	/// @return false - �������� ���������
	bool lightAround(const Map & map) const;

	/// ����� ���������� ���� �hangeDir � Crossroad ��� ��������� ������� ������� ������ �����������
	void leaveCrossroad(const Map & map);

	/// �����, ��������������� �������� ����������� 
	/// @param direct - ����� �������� �����������
	void setDirection(const int direct);

	/// �����, ��������������� �������� �������� 
	/// @param newSpeed - ����� �������� ��������
	void setSpeed(const float newSpeed);

	/// �����, ��������������� ������ �������
	void setSizeSprite();

	/// ����� ��������� �������� ����� 
	/// @return ���� Life
	bool getLife() const;

	/// ����� ��������� �������� �������� 
	/// @return ��������
	float getSpeed() const;

	/// ����� ��������� �������� ���������� �� ��� �
	/// @return ���������� �� ��� �
	float getX() const;

	/// ����� ��������� �������� ���������� �� ��� Y
	/// @return ���������� �� ��� Y
	float getY() const;

	/// ����� ��������� �������� ����������� 
	/// @return ���� Direction
	int getDirection() const;

	/// ����� ��������� �������� ������� ������������ ����������� 
	/// @return ���� StopDirection
	int getStopDirection() const;

	/// ����� ��������� �������� ����������, ���������� �� ����� ����������� �� ������ �����������
	/// @return ���� ChangeDir
	bool getChangeDir() const;

	/// �����, ������� ������� � ���������� ����������� �������� �������, ����� �� ������ ������
	/// @param map - ����� 
	/// @return ��������� ����������� �������� �������
	int getBeginDirection(const Map & map);

	/// ����� �������a ���������� X ������� � ��������� ��� ����������� � �����
	/// @return ����������� ���������� �� ��� �
	int mX() const;

	/// ����� �������a ���������� Y ������� � ��������� ��� ����������� � �����
	/// @return ����������� ���������� �� ��� Y
	int mY() const;

	/// ����� �������a ���������� dX ������� � ��������� ��� ����������� � �����
	/// @return ����������� ���������� �� ��� �
	int mdX() const;

	/// ����� ������� ���������� dY ������� � ��������� ��� ����������� � �����
	/// @return ����������� ������������ ��� Y
	int mdY() const;

	/// ����� �������� ��������� � ��������� ��� ����������� � �����, ���������� � ������� �������, ���� ����������� �������������, � �������, ���� �������������
	/// @param xy - ����������
	/// @return ����������� ����������
	float okrugl(const float xy) const;

};

