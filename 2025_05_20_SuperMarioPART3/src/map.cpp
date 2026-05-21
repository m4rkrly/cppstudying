#include <cmath>
#include <cstdio>
#include <iostream>
#include <windows.h>

#include "init.hpp"
#include "map.hpp"

void m4rkrly::Map::clearMap() 
{
    for (int i = 0; i < MAPWIDTH;  i++) 
		this->map[0][i] = '.';
	this->map[0][MAPWIDTH] = '\0';
	for (int j = 1; j < MAPHEIGHT; j++)
		sprintf(this->map[j], this->map[0]);
}


bool m4rkrly::Map::isPosOnMap(int x, int y) 
{
    return ((x >= 0) && (x < MAPWIDTH)) &&
        ((y >= 0) && (y < MAPHEIGHT));
}


void m4rkrly::Map::putSymbol(int x, int y, char texture) 
{
    this->map[x][y] = texture;
}


void m4rkrly::Map::putScoreOnMap(int& score) 
{
    char c[30];
	sprintf(c, "Score: %d", score);
	int len = strlen(c);
	for (int i = 0; i < len; i++) {
		map[1][i+5] = c[i];
	}
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
    map[MAPHEIGHT - 1][MAPWIDTH - 1] = '\0';
	for (int j = 0; j < MAPHEIGHT; j++)
		std::cout << map[j];
}