#include "Include.h"
#include "Map.h"
#include "Function.h"

Map::Map(const std::vector<std::string> tilemap)
{
	Texture.loadFromFile(TEXTURE_MAP);
	Sprite.setTexture(Texture);
	TileMap = tilemap;
	Height = TileMap.size();
	Width = TileMap[0].size();
	Scale = CUSTOM;
}

Map::Map(const char scale)
{
	Texture.loadFromFile(TEXTURE_MAP);
	Sprite.setTexture(Texture);
	Scale = scale;
	switch (Scale)
	{
	case BIG_MAP:
	{
					TileMap =
					{
						"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
						"f                                                                              f",
						"f pprrrrrrrrrrrrpprrrrrrrrrrrrpprrrrrrrpprrrrpprrrrrrrrrrrrrrrrrrrrrrrpprrrrpp f",
						"f pprrrrrrrrrrrrpprrrrrrrrrrrrpprrrrrrrpprrrrpprrrrrrrrrrrrrrrrrrrrrrrpprrrrpp f",
						"f rr            rr            rr       rr    rr                       rr    rr f",
						"f rr           srrs           rr       rr    rr     pprrrrrrrrrrpp    rr    rr f",
						"f rr hl pprrrrrrpprrrrpprrrrrrpp    hl pprrrrpp     pprrrrrrrrrrpp    rr    rr f",
						"f rr mnrpprrrrrrpprrrrpprrrrrrpp    mnrpprrrrpp     rr          rr    rr    rr f",
						"f rr    rr     srrs   rr      rr             rr     rr         srrs   rr    rr f",
						"f rr    rr      rr    rr      pprrrrrrpp     rr     pprrrrrrrrrrpprrrrpprrrrpp f",
						"f rr    rr      rr    rr      pprrrrrrpp     rr     pprrrrrrrrrrpprrrrpprrrrpp f",
						"f rr    rr      rr    rr  hl          rr     rr                srrs         rr f",
						"f pprrrrpp      rr    rr  mn         srrs    rr                 rr   hl     rr f",
						"f pprrrrpp  pprrpprrrrpp       pprrrrrpprrrrrpprrrrrrrrpprrrrrrrpp   mn     rr f",
						"f rr        pprrpprrrrpp       pprrrrrpprrrrrpprrrrrrrrpprrrrrrrpp          rr f",
						"f rr        rr        rr       rr    srrs              rr                   rr f",
						"f rr       srrs      srrs      rr     rr               rr  pprrrrrrpp   hl  rr f",
						"f pprrrrrrrrpprrrrrrrrpprrrrrrrpp     pprrrrrrpprrrrrrrpp  pprrrrrrpp   mn  rr f",
						"f pprrrrrrrrpprrrrrrrrpprrrrrrrpp     pprrrrrrpprrrrrrrpp  rr      rr       rr f",
						"f rr       srrs      srrs      rr             rr           rr     srrs      rr f",
						"f rr        rr        rr       rr     hl      rr    hl     pprrrrrrpprrrrrrrpp f",
						"f pprrrrrrrrpprrpprrrrpprrrpprrpp     mn      rr    mn     pprrrrrrpprrrrrrrpp f",
						"f pprrrrrrrrpprrpprrrrpprrrpprrpp     r      srrs                 srrs      rr f",
						"f rr            rr         rr      hl pprrrrrrpprrrrrrpprrrpp      rr       rr f",
						"f rr    hl      rr         rr      mnrpprrrrrrpprrrrrrpprrrpp      rr       rr f",
						"f rr    mn      rr         rr         rr     srrs     rr   rr      rr   hl  rr f",
						"f rr            rr      hl pprrrrrrrrrpp      rr      rr   pprrrrrrpp   mn  rr f",
						"f pprrrrrrrrrrrrpp      mnrpprrrrrrrrrpp      rr      rr   pprrrrrrpp       rr f",
						"f pprrrrrrrrrrrrpp         rr         rr      rr      rr                    rr f",
						"f rr            rr    hl   rr         rr      rr      pprrrrrrrrrrrrrrrrrrrrpp f",
						"f rr            rr    mn   rr         rr      rr      pprrrrrrrrrrrrrrrrrrrrpp f",
						"f rr            rr         rr        srrs     rr      rr                    rr f",
						"f rr     hl pprrpprrrrpprrrpp  pprrrrrpprrrrrrpp      rr           hl       rr f",
						"f rr     mnrpprrpprrrrpprrrpp  pprrrrrpprrrrrrpp      rr           mn       rr f",
						"f rr        rr        rr       rr    srrs     rr      rr           r        rr f",
						"f rr        rr   hl   rr       rr     rr      rr   hl pprrrrrrrrrrrpp       rr f",
						"f pprrrrrrrrpp   mn   rr       rr     rr      rr   mnrpprrrrrrrrrrrpp       rr f",
						"f pprrrrrrrrpp   r    rr       rr     rr      rr      rr           rr       rr f",
						"f rr        rr   pprrrpprrrrrrrpp     rr     srrs    srrs          rr       rr f",
						"f rr        rr   pprrrpprrrrrrrpp     pprrrrrrpprrrrrrpprrrrpprrrrrpprrrrrrrpp f",
						"f pprrrrrrrrpp   rr            rr     pprrrrrrpprrrrrrpprrrrpprrrrrpprrrrrrrpp f",
						"f pprrrrrrrrpp   rr       hl   rr     rr     srrs    srrs   rr              rr f",
						"f rr        rr   rr       mn   rr     rr      rr      rr    rr       hl     rr f",
						"f rr        rr   rr            rr     rr      rr      rr    rr       mn     rr f",
						"f pprrrrrrrrpprrrpprrrrrrrrrrrrpprrrrrpprrrrrrpprrrrrrpprrrrpprrrrrrrrrrrrrrpp f",
						"f pprrrrrrrrpprrrpprrrrrrrrrrrrpprrrrrpprrrrrrpprrrrrrpprrrrpprrrrrrrrrrrrrrpp f",
						"f                                                                              f",
						"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
					};
					break;
	}
	case MIDDLE_MAP:
	{
					   TileMap =
					   {
						   "ffffffffffffffffffffffffffffffffff",
						   "f            hl                  f",
						   "f            mn                  f",
						   "f         y  r                   f",
						   "f   pprrrrrrrpprrrrrrrrrrrrrpp   f",
						   "f   pprrrrrrrpprrrrrrrrrrrrrpp   f",
						   "f   rr  y    rr          k  rr   f",
						   "f   rr 3    srrs       y    rr   f",
						   "f   pprrrrrrrpprrrrrrrrrrrrrpp   f",
						   "f   pprrrrrrrpprrrrrrrrrrrrrpp   f",
						   "f   rr  y  1srrs        y   rr   f",
						   "f   rr   y   rr         k   rr   f",
						   "f   pprrrrrrrpprrrpprrrrrrrrpp   f",
						   "f   pprrrrrrrpprrrpprrrrrrrrpp   f",
						   "f   rr            rr     k  rr   f",
						   "f   rr    k      srrs       rr   f",
						   "f   pprrrrrrrrrrrrpprrrrrrrrpp hlf",
						   "f   pprrrrrrrrrrrrpprrrrrrrrppemnf",
						   "f   rr    y      srrs     1 rr   f",
						   "f   rr      y     rr k      rr   f",
						   "fhl pprrrrrrrrrrrrpprrrrrrrrpp   f",
						   "fmnrpprrrrrrrrrrrrpprrrrrrrrpp   f",
						   "f       k              y         f",
						   "ffffffffffffffffffffffffffffffffff"
					   };
					   break;
	}
	case LITTLE_MAP:
	{
					   TileMap =
					   {
						   "ffffffffffffffffffffffffffff",
						   "f                          f",
						   "fhl pprrrrrrrrrrrrrrrrrrpp f",
						   "fmnrpprrrrrrrrrrrrrrrrrrpp f",
						   "f   rr                  rr f",
						   "f   rr                  rr f",
						   "f   rr                  rr f",
						   "fhl pprrrrrrrrrrrrrrrrrrpp f",
						   "fmnrpprrrrrrrrrrrrrrrrrrpp f",
						   "f                          f",
						   "ffffffffffffffffffffffffffff"
					   };
					   break;
	}
	default:
	{
			   throw std::logic_error("Uncorrect paremetr in constructor of Map (chack 'Main.cpp' line 15 \n or Use constructor with paremetr : std::vector<std::string>");
			   break;
	}
	}
	Height = size_t(TileMap.size());
	Width = size_t(TileMap[0].size());
}

char Map::getScale() const
{
	return Scale;
}

size_t Map::getHeight() const
{
	return Height;
}

size_t Map::getWidth() const
{
	return Width;
}

/*Заполнение карты в зависимости от маркеров типа char
r - дорога ( #define ROAD 'r')
p - перекресток ( #define CROSSROAD 'p')
e - выезд ( #define EXIT 'e')
space - зеленый фон
f - контур карты
hl
mn - маркеры для сборки пункта выезда/вьезда обьекта Car ( автомобиль)
s - обьект TrafficLight ( светофор )
0 - обьект RoadSign ( дорожный знак ), запрещающий поворот в направлении X_PLUS
1 - обьект RoadSign ( дорожный знак ), запрещающий поворот в направлении Y_PLUS
2 - обьект RoadSign ( дорожный знак ), запрещающий поворот в направлении X_MINUS
3 - обьект RoadSign ( дорожный знак ), запрещающий поворот в направлении Y_MINUS
k - обьект RoadSign ( дорожный знак ), ограничивающий скорость ( #define SPEED_LIMIT_ON 'k' )
y - обьект RoadSign ( дорожный знак ), снимающий ограничение по скорости  ( #define SPEED_LIMIT_OFF 'y' ) */
void Map::work(sf::RenderWindow & window)
{
	int x = 0, y = 0;
	for (size_t i = 0; i < Height; ++i)
	{
		for (size_t j = 0; j < Width; ++j)
		{


			switch (TileMap[i][j])
			{
			case 'f':
			{
						Sprite.setTextureRect(sf::IntRect(3 * PIXEL, 0, PIXEL, PIXEL));
						break;
			}
			case 'r':
			{
						createRoad(i, j);
						break;
			}
			case 'e':
			{
						createRoad(i, j);
						break;
			}
			case 'p':
			{
						createRoad(i, j);
						break;
			}
			case 'h':
			{
						Sprite.setTextureRect(sf::IntRect(3 * PIXEL, PIXEL, PIXEL, PIXEL));
						break;
			}
			case 'l':
			{
						Sprite.setTextureRect(sf::IntRect(4 * PIXEL, PIXEL, PIXEL, PIXEL));
						break;
			}
			case 'm':
			{
						Sprite.setTextureRect(sf::IntRect(3 * PIXEL, 2 * PIXEL, PIXEL, PIXEL));
						break;
			}
			case 'n':
			{
						Sprite.setTextureRect(sf::IntRect(4 * PIXEL, 2 * PIXEL, PIXEL, PIXEL));
						break;
			}
			case ' ':
			{
						Sprite.setTextureRect(sf::IntRect(4 * PIXEL, 0, PIXEL, PIXEL));
						break;
			}
			case 's':
			{
						Sprite.setTextureRect(sf::IntRect(4 * PIXEL, 0, PIXEL, PIXEL));
						break;
			}
			default:   createRoadSign(i, j);
			}
			Sprite.setPosition(FLOAT(j * PIXEL), FLOAT(i * PIXEL));
			window.draw(Sprite);
		}
	}
}

void Map::createRoadSign(const size_t y, const size_t x)
{
	char marker = TileMap[y][x];
	int poz_x = 5 * PIXEL, poz_y = 0;                                 //direction ==  X_PLUS
	if (x <= Width - 2)                                             //direction == Y_PLUS
	{
		if (TileMap[y][x + 1] == ROAD && TileMap[y][x + 2] == ROAD)
			poz_x += PIXEL;
	}
	if (y <= Height - 2)                                            //direction == X_MINUS
	{
		if (TileMap[y + 1][x] == ROAD && TileMap[y + 2][x] == ROAD)
			poz_x += 2 * PIXEL;
	}
	if (x >= 2)                                                     //direction == Y_MINUS
	{
		if (TileMap[y][x - 1] == ROAD && TileMap[y][x - 2] == ROAD)
			poz_x += 3 * PIXEL;
	}
	if (marker == SPEED_LIMIT_OFF) poz_y = PIXEL;
	else if (marker != SPEED_LIMIT_ON)
	{
		if (static_cast<int>(marker)-48 < 2) poz_y = 2 * PIXEL;
		else poz_y = 3 * PIXEL;
	}
	Sprite.setTextureRect(sf::IntRect(poz_x, poz_y, PIXEL, PIXEL));
}

void Map::createRoad(const size_t y, const size_t x)
{
	int poz_y = 0, poz_x = 0;
	if (TileMap[y][x] == EXIT || TileMap[y][x - 1] == 'n')
	{
		poz_x = 4;
		poz_y = 3;
	}
	else if (TileMap[y - 1][x] == 'm')
	{
		poz_x = 3;
		poz_y = 3;
	}
	else if (TileMap[y][x] == CROSSROAD && TileMap[y][x - 2] == 'n')  //
	{
		poz_x = 9;
		poz_y = 2;
	}
	else if (TileMap[y][x] == CROSSROAD && TileMap[y - 2][x] == 'm')   //
	{
		poz_x = 9;
		poz_y = 0;
	}
	else if (TileMap[y][x] == CROSSROAD && TileMap[y][x + 2] == 'm')   //
	{
		poz_x = 9;
		poz_y = 1;
	}
	else if(!IsRoad(TileMap[y][x - 1]) && !IsRoad(TileMap[y - 1][x]))     //3
	{
		poz_x = 2;
		poz_y = 0;
	}
	else if (!IsRoad(TileMap[y][x - 1]) && !IsRoad(TileMap[y + 1][x]))
	{
		poz_x = 2;
		poz_y = 1;
	}
	else if (!IsRoad(TileMap[y][x + 1]) && !IsRoad(TileMap[y - 1][x]))
	{
		poz_x = 2;
		poz_y = 3;
	}
	else if (!IsRoad(TileMap[y][x + 1]) && !IsRoad(TileMap[y + 1][x]))
	{
		poz_x = 2;
		poz_y = 2;
	}
	else if (!IsRoad(TileMap[y][x + 1]) && IsRoad(TileMap[y][x - 1])) poz_y = 2;    //1
	else if (!IsRoad(TileMap[y][x - 1]) && IsRoad(TileMap[y][x + 1])) poz_y = 1;
	else if (!IsRoad(TileMap[y - 1][x]) && IsRoad(TileMap[y + 1][x])) poz_y = 3;
	else if (IsRoad(TileMap[y][x - 1]) && IsRoad(TileMap[y + 1][x]) && !IsRoad(TileMap[y + 1][x - 1]))   //2
	{
		poz_y = 3;
		poz_x = 1;
	}
	else if (IsRoad(TileMap[y][x - 1]) && IsRoad(TileMap[y - 1][x]) && !IsRoad(TileMap[y - 1][x - 1]))
	{
		poz_y = 2;
		poz_x = 1;
	}
	else if (IsRoad(TileMap[y][x + 1]) && IsRoad(TileMap[y - 1][x]) && !IsRoad(TileMap[y - 1][x + 1]))
	{
		poz_y = 1;
		poz_x = 1;
	}
	else if (IsRoad(TileMap[y][x + 1]) && IsRoad(TileMap[y + 1][x]) && !IsRoad(TileMap[y + 1][x + 1]))
	{
		poz_y = 0;
		poz_x = 1;
	}
	Sprite.setTextureRect(sf::IntRect(poz_x * PIXEL, poz_y * PIXEL, PIXEL, PIXEL));
}

Map::~Map()
{
	Scale = '\0';
	Width = 0;
	Height = 0;
	TileMap.clear();
}

std::vector<std::string>  Map::getTM() const
{
	return TileMap;
}


