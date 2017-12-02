#include "Map.h"
#include "RoadSign.h"

Map::Map(const char scale)
{
	Texture.loadFromFile(TEXTURE_MAP);
	Sprite.setTexture(Texture);
	Scale = scale;
	try
	{
		switch (Scale)
		{
		case BIG_MAP:
		{
					TileMap =
					{
						"00000000000000000000000000000000000000000000000000000000000000000000000000000000",
						"0                                                                              0",
						"0 pprrrrrrrrrrrrpprrrrrrrrrrrrpprrrrrrrpprrrrpprrrrrrrrrrrrrrrrrrrrrrrpprrrrpp 0",
						"0 pprrrrrrrrrrrrpprrrrrrrrrrrrpprrrrrrrpprrrrpprrrrrrrrrrrrrrrrrrrrrrrpprrrrpp 0",
						"0 rr            rr            rr       rr    rr                       rr    rr 0",
						"0 rr           srrs           rr       rr    rr   hlpprrrrrrrrrrpp    rr    rr 0",
						"0 rr hl pprrrrrrpprrrrpprrrrrrpp  hl   pprrrrpp   mnpprrrrrrrrrrpp    rr    rr 0",
						"0 rr mnrpprrrrrrpprrrrpprrrrrrpp  mn   pprrrrpp     rr          rr    rr    rr 0",
						"0 rr    rr     srrs   rr      rr             rr     rr         srrs   rr    rr 0",
						"0 rr    rr      rr    rr      pprrrrrrpp     rr     pprrrrrrrrrrpprrrrpprrrrpp 0",
						"0 rr    rr      rr    rr      pprrrrrrpp     rr     pprrrrrrrrrrpprrrrpprrrrpp 0",
						"0 rr    rr      rr    rr  hl          rr     rr     hl         srrs         rr 0",
						"0 pprrrrpp      rr    rr  mn         srrs    rr     mn          rr   hl     rr 0",
						"0 pprrrrpp  pprrpprrrrpp       pprrrrrpprrrrrpprrrrrrrrpprrrrrrrpp   mn     rr 0",
						"0 rr        pprrpprrrrpp       pprrrrrpprrrrrpprrrrrrrrpprrrrrrrpp          rr 0",
						"0 rr        rr        rr       rr    srrs          hl  rr                   rr 0",
						"0 rr       srrs      srrs      rr     rr           mn  rr  pprrrrrrpp   hl  rr 0",
						"0 pprrrrrrrrpprrrrrrrrpprrrrrrrpp     pprrrrrrpprrrrrrrpp  pprrrrrrpp   mn  rr 0",
						"0 pprrrrrrrrpprrrrrrrrpprrrrrrrpp     pprrrrrrpprrrrrrrpp  rr      rr       rr 0",
						"0 rr       srrs      srrs      rr             rr           rr     srrs      rr 0",
						"0 rr        rr        rr       rr         hl  rr           pprrrrrrpprrrrrrrpp 0",
						"0 pprrrrrrrrpprrpprrrrpprrrpprrpp         mn  rr           pprrrrrrpprrrrrrrpp 0",
						"0 pprrrrrrrrpprrpprrrrpprrrpprrpp            srrs                 srrs      rr 0",
						"0 rr            rr         rr      hl pprrrrrrpprrrrrrpprrrpp      rr       rr 0",
						"0 rr    hl      rr         rr      mn pprrrrrrpprrrrrrpprrrpp      rr       rr 0",
						"0 rr    mn      rr         rr         rr     srrs     rr   rr      rr       rr 0",
						"0 rr            rr         pprrrrrrrrrpp      rr      rr   pprrrrrrpp       rr 0",
						"0 pprrrrrrrrrrrrpp         pprrrrrrrrrpp      rr      rr   pprrrrrrpp       rr 0",
						"0 pprrrrrrrrrrrrpp         rr         rr      rr      rr                    rr 0",
						"0 rr            rr         rr         rr      rr      pprrrrrrrrrrrrrrrrrrrrpp 0",
						"0 rr            rr         rr         rr      rr      pprrrrrrrrrrrrrrrrrrrrpp 0",
						"0 rr            rr         rr        srrs     rr      rr              hl    rr 0",
						"0 rr     hl pprrpprrrrpprrrpp  pprrrrrpprrrrrrpp      rr              mn    rr 0",
						"0 rr     mnrpprrpprrrrpprrrpp  pprrrrrpprrrrrrpp      rr                    rr 0",
						"0 rr        rr        rr       rr    srrs     rr      rr                    rr 0",
						"0 rr        rr        rr       rr     rr      rr      pprrrrrrrrrrrpp   hl  rr 0",
						"0 pprrrrrrrrpp        rr       rr     rr      rr      pprrrrrrrrrrrpp   mn  rr 0",
						"0 pprrrrrrrrpp        rr       rr     rr      rr      rr           rr       rr 0",
						"0 rr        rr   pprrrpprrrrrrrpp     rr     srrs    srrs          rr       rr 0",
						"0 rr        rr   pprrrpprrrrrrrpp     pprrrrrrpprrrrrrpprrrrpprrrrrpprrrrrrrpp 0",
						"0 pprrrrrrrrpp   rr            rr     pprrrrrrpprrrrrrpprrrrpprrrrrpprrrrrrrpp 0",
						"0 pprrrrrrrrpp   rr       hl   rr     rr     srrs    srrs   rr              rr 0",
						"0 rr        rr   rr       mn   rr     rr      rr      rr    rr       hl     rr 0",
						"0 rr        rr   rr            rr     rr      rr      rr    rr       mn     rr 0",
						"0 pprrrrrrrrpprrrpprrrrrrrrrrrrpprrrrrpprrrrrrpprrrrrrpprrrrpprrrrrrrrrrrrrrpp 0",
						"0 pprrrrrrrrpprrrpprrrrrrrrrrrrpprrrrrpprrrrrrpprrrrrrpprrrrpprrrrrrrrrrrrrrpp 0",
						"0                                                                              0",
						"00000000000000000000000000000000000000000000000000000000000000000000000000000000",
					};
					break;
		}
		case MIDDLE_MAP:
		{
					TileMap =
					{
						"00000000000000000000000000000000",
						"0         y               k    0",
						"0hl pprrrrrrrpprrrrrrrrrrrrrpp 0",
						"0mnrpprrrrrrrpprrrrrrrrrrrrrpp 0",
						"0   rr  y    rr          k  rr 0",   
						"0   rr      srrs       y    rr 0",
						"0   pprrrrrrrpprrrrrrrrrrrrrpp 0",
						"0   pprrrrrrrpprrrrrrrrrrrrrpp 0",
						"0   rr  y   srrs        y   rr 0",
						"0   rr   y   rr         k   rr 0",
						"0hl pprrrrrrrpprrrpprrrrrrrrpp 0",
						"0mnrpprrrrrrrpprrrpprrrrrrrrpp 0",
						"0   rr            rr     k  rr 0",
						"0   rr    k      srrs       rr 0",
						"0   pprrrrrrrrrrrrpprrrrrrrrpp 0",
						"0   pprrrrrrrrrrrrpprrrrrrrrpp 0",
						"0   rr    y      srrs       rr 0",
						"0   rr      y     rr k      rr 0",
						"0   pprrrrrrrrrrrrpprrrrrrrrpp 0",
						"0   pprrrrrrrrrrrrpprrrrrrrrpp 0",
						"0       k              y       0",
						"00000000000000000000000000000000"
					};
					break;
		}
		case LITTLE_MAP:
		{
					TileMap =
					{
						"0000000000000000000000000000",
						"0                          0",
						"0hl pprrrrrrrrrrrrrrrrrrpp 0",
						"0mnrpprrrrrrrrrrrrrrrrrrpp 0",
						"0   rr                  rr 0",
						"0   rr                  rr 0",
						"0   rr                  rr 0",
						"0   rr                  rr 0",
						"0hl pprrrrrrrrrrrrrrrrrrpp 0",
						"0mnrpprrrrrrrrrrrrrrrrrrpp 0",
						"0                          0",
						"0000000000000000000000000000"
					};
					break;
		}
		default:
		{
			throw std::exception("Uncorrect paremetr in constructor of Map (check 'Main.cpp' line 8 ");
			break;
		}
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	Height = TileMap.size();
	Width = TileMap[0].size();
};

char Map::getScale() const
{
	return Scale;
};

int Map::getHeight() const
{
	return Height;
};

int Map::getWidth() const
{
	return Width;
};

void Map::work(sf::RenderWindow & window)   //заполнение карты в зависимости от char
{
	int x = 0, y = 0;
	for (int i = 0; i < Height; ++i)
	{
		for (int j = 0; j < Width; ++j)
		{
			

			switch (TileMap[i][j])
			{
			case '0':
			{
						Sprite.setTextureRect(sf::IntRect(0, 0, PIX, PIX));
						break;
			}
			case 'r':
			{
						Sprite.setTextureRect(sf::IntRect(PIX, 0, PIX, PIX));
						break;
			}
			case 'p':
			{
						Sprite.setTextureRect(sf::IntRect(PIX, 0, PIX, PIX));
						break;
			}
			case 'h':
			{
						Sprite.setTextureRect(sf::IntRect(3 * PIX, PIX, PIX, PIX));
						break;
			}
			case 'l':
			{
						Sprite.setTextureRect(sf::IntRect(4 * PIX, PIX, PIX, PIX));
						break;
			}
			case 'm':
			{
						Sprite.setTextureRect(sf::IntRect(3 * PIX, 2 * PIX, PIX, PIX));
						break;
			}
			case 'n':
			{
						Sprite.setTextureRect(sf::IntRect(4 * PIX, 2 * PIX, PIX, PIX));
						break;
			}
			case ' ':
			{
						Sprite.setTextureRect(sf::IntRect(2 * PIX, 0, PIX, PIX));
						break;
			}
			case 's':
			{
						Sprite.setTextureRect(sf::IntRect(2 * PIX, 0, PIX, PIX));
						break;
			}
			default:
			{
					   CreateRoadSign(i, j);
			}
			}
			Sprite.setPosition(j * PIX, i * PIX);
			window.draw(Sprite);
		}
	}
};

void Map::CreateRoadSign(const int y, const int x)
{
	int poz_x = 5 * PIX, poz_y = 0;   //direction == 0
	if (x <= Width - 2)  //direction == 1
	{
		if (TileMap[y][x + 1] == 'r' && TileMap[y][x + 2] == 'r')
			poz_x += PIX;
	}
	if (y <= Height - 2)   //direction == 2
	{
		if (TileMap[y + 1][x] == 'r' && TileMap[y + 2][x] == 'r')
			poz_x += 2 * PIX;
	}
	if (x >= 2)                                                          //direction == 3
	{
		if (TileMap[y][x - 1] == 'r' && TileMap[y][x - 2] == 'r')
			poz_x += 3 * PIX;
	}
	if (TileMap[y][x] == 'y') poz_y += PIX;
	Sprite.setTextureRect(sf::IntRect(poz_x, poz_y, PIX, PIX));
};

Map::~Map()
{
	TileMap.clear();
};

std::vector<std::string>  Map::getTM() const
{
	return TileMap;
};


