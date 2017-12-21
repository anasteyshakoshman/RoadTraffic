#pragma once
#include <iostream>

/// @brief �����
class Map
{
	/// ������ �������
	sf::Sprite Sprite;

	/// �e������ ��� �������
	sf::Texture Texture;

	/// ������ �����
	size_t Height;

	/// ������ �����
	size_t Width;

	/// ������, ������������ �����
	vector2d TileMap;

	/// ������, ������������ ��� �����
	char Scale;

public:

	/// @param scale - ������, ������������ ��� �����
	Map(const char scale);

	/// @param tilemap - ����� �����
	Map(const vector2d tilemap);


	/// ����� ������ ������� �����
	/// @param window - ����
	void work(sf::RenderWindow & window);

	/// ���������� - �������� ���� 
	~Map();

	/// ����� ��� ��������� ������ �����
	/// @return Height - ������
	size_t getHeight() const;

	/// ����� ��� ��������� ������ �����
	/// @return Weight - ������
	size_t getWidth() const;

	/// ����� ��� ��������� �������, ������������� �����
	/// @return TileMap
	std::vector<std::string>  getTM() const;

	/// ����� ��� ��������� �������, ������������� ��� � ������ �����
	/// @return Scale
	char getScale() const;

	/// ����� ��� ������ ������� ������� RoadSign
	/// @param x - ���������� �� ��� �
	/// @param � - ���������� �� ��� �
	void createRoadSign(const size_t y, const size_t x);

	/// ����� ��� ������ ������� ������
	/// @param x - ���������� �� ��� �
	/// @param � - ���������� �� ��� �
	void createRoad(const size_t y, const size_t x);
};









