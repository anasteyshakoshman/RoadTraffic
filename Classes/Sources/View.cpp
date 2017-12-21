#include "View.h"
#include "Map.h"

View::View(const Map & map)
{
	switch (map.getScale())
	{
	case MIDDLE_MAP:
	{
					   Size.x = 6.3f * WIDTH_WINDOW;
					   Size.y = 6.3f * HEIGHT_WINDOW;
					   Size.z = 100.f;
					   break;
	}
	case BIG_MAP:
	{
					Size.x = 15.f * WIDTH_WINDOW;
					Size.y = 15.f * HEIGHT_WINDOW;
					Size.z = Size.y / 8.f;
					break;
	}
	case LITTLE_MAP:
	{
					   Size.x = 6.f * WIDTH_WINDOW;
					   Size.y = 6.f * HEIGHT_WINDOW;
					   Size.z = Size.y / 4.f;
					   break;
	}
	default:
	{
			   float big_size = FLOAT(map.getWidth());
			   if (map.getWidth() < map.getHeight()) big_size = FLOAT(map.getHeight());
			   Size.x = big_size * WIDTH_WINDOW / 5.f;
			   Size.y = big_size * HEIGHT_WINDOW / 5.f;
			   Size.z = 100.f;
			   break;
	}
	}
	Camera.reset(sf::FloatRect(0.f, 0.f, Size.x, Size.y));
	Camera.setCenter(Size.x / 2.f, (Size.y / 2.f) - Size.z);
}

void View::work(sf::RenderWindow & window, const float time)
{
	if (Camera.getSize().x < Size.x || Camera.getSize().y < Size.y)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			Camera.move(time, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			Camera.move(0.f, time);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			Camera.move(-time, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			Camera.move(0.f, -time);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			Camera.zoom(1.0051f);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && Camera.getSize().x > 400. && Camera.getSize().y > 400.)
	{
		Camera.zoom(0.9955f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Camera.reset(sf::FloatRect(0., 0., Size.x / 2.f, Size.y / 2.f));
		Camera.setCenter(Size.x / 2.f, Size.y / 2.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Camera.reset(sf::FloatRect(0., 0., Size.x, Size.y));
		Camera.setCenter(Size.x / 2.f, (Size.y / 2.f) - Size.z);
	}
	window.setView(Camera);
}

View::~View()
{
	Size.x = 0.f;
	Size.y = 0.f;
	Size.z = 0.f;
}