#include "Include.h"

class Map;

/// ���
class View
{
	/// ������ ����
	sf::View Camera;

	/// ������
	sf::Vector3f Size;

public:

	/// �������������� ���� �������
	/// @param map - ����� 
	View(const Map & map);

	/// ����� ��������, ����������� � ��������� ������ ���� 
	/// @param  window - ���� 	
	/// @param time - �����
	void work(sf::RenderWindow & window, const float time);
};







