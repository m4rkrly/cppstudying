#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <windows.h>

#include "init.hpp"
#include "map.hpp"

void m4rkrly::Map::clearMap() 
{
    for (int i = 0; i < init::MAPWIDTH;  i++) 
		map[0][i] = ' ';
	map[0][init::MAPWIDTH] = '\0';
	for (int j = 1; j < init::MAPHEIGHT; j++)
		sprintf(map[j], map[0]);
}


bool m4rkrly::Map::isPosOnMap(int x, int y) 
{
    bool xIsOnMap = (x >= 0) && (x < init::MAPWIDTH);
	bool yIsOnMap = (y >= 0) && (y < init::MAPHEIGHT);
	return xIsOnMap && yIsOnMap;
}


void m4rkrly::Map::putSymbol(int x, int y, char texture) 
{
    this->map[y][x] = texture;
}


void m4rkrly::Map::returnCur() 
{
    COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void m4rkrly::Map::showMap() 
{
    map[init::MAPHEIGHT - 1][init::MAPWIDTH - 1] = '\0';
	for (int j = 0; j < init::MAPHEIGHT; j++)
		std::cout << map[j];
}