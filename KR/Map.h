#pragma once
#include "Include.h"

class RoadSign;

/// �����
class Map
{
	/// �������� ��� ������� �����
	sf::Texture Texture;

	/// ������ �����
	sf::Sprite Sprite;

	/// ������, ������������ �����
	std::vector<std::string> TileMap;

	/// ������ 
	int Height;

	/// ������
	int Width;

	/// ������, ������������ ��� �����
	char Scale;

public:

	/// @param scale - ������, ������������ ��� �����
	Map(const char scale);

	/// ����� ��� ��������� �����
	/// @param window - ����
	void work(sf::RenderWindow & window);
	
	/// ���������� - �������� ���� 
	~Map();

	/// ����� ��� ��������� ������ �����
	/// @return Height - ������
	int getHeight() const;

	/// ����� ��� ��������� ������ �����
	/// @return Weight - ������
	int getWidth() const;
	
	/// ����� ��� ��������� �������, ������������� �����
	/// @return TileMap
	std::vector<std::string>  getTM() const;

	/// ����� ��� ��������� �������, ������������� ��� �����
	/// @return Scale
	char getScale() const;

	/// ����� ��� ������ ������� �����
	/// @param x - ���������� �� ��� �
	/// @param � - ���������� �� ��� �
	void CreateRoadSign(const int x, const int y);
};









