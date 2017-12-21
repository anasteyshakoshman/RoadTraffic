#pragma once

#include "Include.h"

class Map;



/// @brief �������� ����
class RoadSign
{
	/// @brief ����������� ��������
	float Limit;

	/// @brief ���������� �� ��� �
	float X;

	/// @brief ���������� �� ��� Y
	float Y;

	/// @brief ������, �������� ��� ������� ������� ������
	static std::vector<RoadSign> AllRoadSign;

public:

	/// @param map - �����
	/// @param x - ���������� �� ��� �
	/// @param y - ���������� �� ��� Y
	RoadSign(const Map & map, const float x, const float y);

	/// @brief �������� ���� �������
	~RoadSign();

	/// @brief ����� ��� ��������� ������������ ������� ������
	/// @return AllRoadSign - ����������� ������, �������� ��� ������� ������� ������
	static std::vector<RoadSign> & Vec();

	/// @brief ����� ��������� �������� ����������� ��������
	/// @return ����������� ��������
	float getLimit() const;

	/// @brief ����� ��������� �������� ���������� �� ��� �
	/// @return ���������� �� ��� �
	float getX() const;

	/// @brief ����� ��������� �������� ���������� �� ��� Y
	/// @return ���������� �� ��� Y
	float getY() const;
};



