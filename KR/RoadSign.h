#pragma once
#include "Include.h"

class Map;

/// �������� ����
class RoadSign
{
	/// @brief ����������� ��������
	int Limit;

	/// @brief ����������
	int X, Y;

	/// @brief ������, �������� ��� ������� ������� ������
	static std::vector<RoadSign> AllRoadSign;

public:

	/// @brief �������������� ���� �������
	/// @param x - ���������� �� ��� �
	/// @param y - ���������� �� ��� Y
	/// @param map - �����
	RoadSign(const int x, const int y, const Map & map);

	/// @brief �������� ���� �������
	~RoadSign();

	/// @brief ����� ��� ��������� ������������ ������� ������
	/// @return AllRoadSign - ����������� ������, �������� ��� ������� ������� ������
	static std::vector<RoadSign> & Vec();

	/// @brief ����� ��������� �������� ����������� ��������
	/// @return ����������� ��������
	int getLimit() const;

	/// @brief ����� ��������� �������� ���������� �� ��� �
	/// @return ���������� �� ��� �
	int getX() const;

	/// @brief ����� ��������� �������� ���������� �� ��� Y
	/// @return ���������� �� ��� Y
	int getY() const;
};



