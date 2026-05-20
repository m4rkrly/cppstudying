#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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