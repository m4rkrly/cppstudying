#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>

#include "view.hpp"
#include "config.hpp"

void m4rly::view::clearMap(char map[m4rly::cfg::mapHeight][m4rly::cfg::mapWidth+1]) 
{
	for (int i = 0; i < m4rly::cfg::mapWidth;  i++) 
		map[0][i] = ' ';
	map[0][m4rly::cfg::mapWidth] = '\0';
	for (int j = 1; j < m4rly::cfg::mapHeight; j++)
		sprintf(map[j], map[0]);
}


bool m4rly::view::isPosInMap(int x, int y) 
{
	return ((x >= 0) && (x < m4rly::cfg::mapWidth) && (y >= 0) && (y < m4rly::cfg::mapHeight));
}


void m4rly::view::putObjectOnMap(m4rly::TObject obj, char map[m4rly::cfg::mapHeight][m4rly::cfg::mapWidth+1]) 
{
	int ix = (int)round(obj.x);
	int iy = (int)round(obj.y);
	int iWidth = (int)round(obj.width);
	int iHeight = (int)round(obj.height);

	for (int i = ix; i < (ix + iWidth); i++)
		for (int j = iy; j < (iy + iHeight); j++)
			if (m4rly::view::isPosInMap(i, j))
				map[j][i] = obj.cType;
}


void m4rly::view::putScoreOnMap(int& score, char map[m4rly::cfg::mapHeight][m4rly::cfg::mapWidth+1]) 
{
	char c[30];
	sprintf(c, "Score: %d", score);
	int len = strlen(c);
	for (int i = 0; i < len; i++) {
		map[1][i+5] = c[i];
	}
}

void m4rly::view::setCur(int x, int y) 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void m4rly::view::showMap(char map[m4rly::cfg::mapHeight][m4rly::cfg::mapWidth+1]) 
{
	map[m4rly::cfg::mapHeight - 1][m4rly::cfg::mapWidth - 1] = '\0';
	for (int j = 0; j < m4rly::cfg::mapHeight; j++)
		std::cout << map[j] << '\0';
}
