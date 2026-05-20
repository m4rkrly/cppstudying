#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#include "config.hpp"
#include "view.hpp"
#include "structs.hpp"

void showMap(char map[m4rly::cfg::mapHeight][m4rly::cfg::mapWidth+1]);
void setCur(int x, int y);
void createLevel(m4rly::TObject& mario, m4rly::TObject*& brick, m4rly::TObject*& moving, int& brickLength, int& movingLength, int lvl, int& maxLvl, int& score);
void deleteMoving(int i, m4rly::TObject*& moving, int& movingLength);
m4rly::TObject* getNewBrick(m4rly::TObject*& brick, int& brickLength);
m4rly::TObject* getNewMoving(m4rly::TObject*& moving, int& movingLength);
void horizonMoveMap(m4rly::TObject& mario, m4rly::TObject*& brick, m4rly::TObject*& moving, int& brickLength, int& movingLength, float dx);
void horizonMoveObject(m4rly::TObject* obj, m4rly::TObject& mario, m4rly::TObject*& brick, m4rly::TObject*& moving, int& brickLength, int& movingLength, int& score, int& level, int maxLvl);
void initObject(m4rly::TObject* obj, float xPos, float yPos, float oWidth, float oHeight, char inType);
bool isCollision(m4rly::TObject o1, m4rly::TObject o2);
void marioCollision(m4rly::TObject mario, m4rly::TObject*& brick, m4rly::TObject*& moving, int& brickLength, int& movingLength, int& score, int level, int maxLvl);
void playerDead(m4rly::TObject& mario, m4rly::TObject*& brick, m4rly::TObject*& moving, int& brickLength, int& movingLength, int level, int maxLvl, int& score);
void setObjectPos(m4rly::TObject* obj, float xPos, float yPos);
void vertMoveObject(m4rly::TObject* obj, m4rly::TObject& mario, m4rly::TObject*& brick, m4rly::TObject*& moving, int& brickLength, int& movingLength, int& score, int& level, int maxLvl);

int main() 
{
	char map[m4rly::cfg::mapHeight][m4rly::cfg::mapWidth+1];

	m4rly::TObject mario;
	m4rly::TObject* brick = nullptr;
	int brickLength;
	m4rly::TObject* moving = nullptr;
	int movingLength;

	int level = 1;
	int maxLvl;
	int score;

	createLevel(mario, brick, moving, brickLength, movingLength, level, maxLvl, score);

	do 
	{
		m4rly::view::clearMap(map);

		if ((mario.IsFly == false) && (GetAsyncKeyState(VK_SPACE) < 0))
			mario.vertSpeed = -1;
		if (GetAsyncKeyState('A') < 0) 
			horizonMoveMap(mario, brick, moving, brickLength, movingLength, 1);
		if (GetAsyncKeyState('D') < 0) 
			horizonMoveMap(mario, brick, moving, brickLength, movingLength, -1);

		if (mario.y > m4rly::cfg::mapHeight)
		 	playerDead(mario, brick, moving, brickLength, movingLength, level, maxLvl, score); 

		vertMoveObject(&mario, mario, brick, moving, brickLength, movingLength, score, level, maxLvl);
		marioCollision(mario, brick, moving, brickLength, movingLength, score, level, maxLvl);

		for (int i = 0; i < brickLength; i++) 
			m4rly::view::putObjectOnMap(brick[i], map);
		for (int i = 0; i < movingLength; i++) 
		{
			vertMoveObject(moving + i, mario, brick, moving, brickLength, movingLength, score, level, maxLvl);
			horizonMoveObject(moving + i, mario, brick, moving, brickLength, movingLength, score, level, maxLvl);
			if (moving[i].y > m4rly::cfg::mapHeight) 
			{
				deleteMoving(i, moving, movingLength);
				i--;
				continue;
			}
			m4rly::view::putObjectOnMap(moving[i], map);
		}
		m4rly::view::putObjectOnMap(mario, map);
		m4rly::view::putScoreOnMap(score, map);
		setCur(0, 0);
		showMap(map); 

		Sleep(10);
	} while (GetAsyncKeyState(VK_ESCAPE) >= 0);
	
	return 0;
}


void createLevel(m4rly::TObject& mario, m4rly::TObject*& brick, m4rly::TObject*& moving, int& brickLength, int& movingLength, int lvl, int& maxLvl, int& score) 
{
	system("color 9F");
	brickLength = 0;
	movingLength = 0;
	brick = static_cast<m4rly::TObject*>(realloc(brick, 0));
	moving = static_cast<m4rly::TObject*>(realloc(moving, 0));

	initObject(&mario, 39, 10, 3, 3, '@');
	score = 0;

	maxLvl = 3; 
	if (lvl == 1) 
	{ 
		initObject(getNewBrick(brick, brickLength), 20, 20, 40, 5, '#');
			initObject(getNewBrick(brick, brickLength), 30, 10, 5, 3, '?');
			initObject(getNewBrick(brick, brickLength), 50, 10, 5, 3, '?');
		initObject(getNewBrick(brick, brickLength), 60, 15, 10, 10, '#');
			initObject(getNewBrick(brick, brickLength), 60, 5, 10, 3, '-');
			initObject(getNewBrick(brick, brickLength), 70, 5, 5, 3, '?');
			initObject(getNewBrick(brick, brickLength), 75, 5, 5, 3, '-');
			initObject(getNewBrick(brick, brickLength), 80, 5, 5, 3, '?');
			initObject(getNewBrick(brick, brickLength), 85, 5, 10, 3, '-');
		initObject(getNewBrick(brick, brickLength), 100, 20, 40, 5, '#');
		initObject(getNewBrick(brick, brickLength), 120, 15, 10, 10, '#');
		initObject(getNewBrick(brick, brickLength), 150, 20, 40, 5, '#');
		initObject(getNewBrick(brick, brickLength), 210, 15, 10, 10, '+');	
	
		initObject(getNewMoving(moving, movingLength), 25, 10, 3, 2, 'o');
		initObject(getNewMoving(moving, movingLength), 80, 10, 3, 2, 'o');
	}

	if (lvl == 2) 
	{ 
		initObject(getNewBrick(brick, brickLength), 20, 20, 40, 5, '#');
		initObject(getNewBrick(brick, brickLength), 60, 15, 10, 10, '#');
		initObject(getNewBrick(brick, brickLength), 80, 20, 40, 5, '#');
		initObject(getNewBrick(brick, brickLength), 120, 15, 10, 10, '#');
		initObject(getNewBrick(brick, brickLength), 150, 20, 40, 5, '#');
		initObject(getNewBrick(brick, brickLength), 210, 15, 10, 10, '+');	
		
		initObject(getNewMoving(moving, movingLength), 25, 10, 3, 2, 'o');
		initObject(getNewMoving(moving, movingLength), 80, 10, 3, 2, 'o');
		initObject(getNewMoving(moving, movingLength), 65, 10, 3, 2, 'o');
		initObject(getNewMoving(moving, movingLength), 120, 10, 3, 2, 'o');
		initObject(getNewMoving(moving, movingLength), 160, 10, 3, 2, 'o');
		initObject(getNewMoving(moving, movingLength), 175, 10, 3, 2, 'o');
	}
	
	if (lvl == 3) 
	{
		initObject(getNewBrick(brick, brickLength), 20, 20, 40, 5, '#');
		initObject(getNewBrick(brick, brickLength), 80, 20, 15, 5, '#');
		initObject(getNewBrick(brick, brickLength), 120, 15, 15, 10, '#');
		initObject(getNewBrick(brick, brickLength), 160, 10, 15, 15, '+');

		initObject(getNewMoving(moving, movingLength), 25, 10, 3, 2, 'o');
		initObject(getNewMoving(moving, movingLength), 50, 10, 3, 2, 'o');
		initObject(getNewMoving(moving, movingLength), 80, 10, 3, 2, 'o');
		initObject(getNewMoving(moving, movingLength), 90, 10, 3, 2, 'o');
		initObject(getNewMoving(moving, movingLength), 120, 10, 3, 2, 'o');
		initObject(getNewMoving(moving, movingLength), 130, 10, 3, 2, 'o');
	}
}


void deleteMoving(int i, m4rly::TObject*& moving, int& movingLength) 
{
	movingLength -= 1;
	moving[i] = moving[movingLength];
	moving = static_cast<m4rly::TObject*>(realloc( moving, sizeof(*moving) * movingLength));
}


m4rly::TObject* getNewBrick(m4rly::TObject*& brick, int& brickLength) 
{
	brickLength++;
	brick = static_cast<m4rly::TObject*>(realloc(brick, sizeof(*brick) * brickLength));
	return brick + brickLength - 1;
}


m4rly::TObject* getNewMoving(m4rly::TObject*& moving, int& movingLength) 
{
	movingLength++;
	moving = static_cast<m4rly::TObject*>(realloc(moving, sizeof(*moving) * movingLength));
	return moving + movingLength - 1;
}


void horizonMoveMap(m4rly::TObject& mario, m4rly::TObject*& brick, m4rly::TObject*& moving, int& brickLength, int& movingLength, float dx) 
{
	mario.x -= dx;
	for (int i = 0; i < brickLength; i++) 
		if (isCollision(mario, brick[i]))
		{
			mario.x += dx;
			return;
		}
	mario.x += dx;

	for (int i = 0; i < brickLength; i++)
		brick[i].x += dx;
	for (int i = 0; i < movingLength; i++)
		moving[i].x += dx;
}


void horizonMoveObject(m4rly::TObject* obj, m4rly::TObject& mario, m4rly::TObject*& brick, m4rly::TObject*& moving, int& brickLength, int& movingLength, int& score, int& level, int maxLvl) 
{
	(*obj).x += (*obj).horizSpeed;

	for (int i = 0; i < brickLength; i++) 
		if (isCollision(obj[0], brick[i])) 
		{
			(*obj).x -= (*obj).horizSpeed;
			(*obj).horizSpeed = -(*obj).horizSpeed;
			return;
		}

	if ((*obj).cType == 'o') 
	{
		m4rly::TObject temp = *obj;
		vertMoveObject(&temp, mario, brick, moving, brickLength, movingLength, score, level, maxLvl);
		if (temp.IsFly == true) 
		{
			(*obj).x -= (*obj).horizSpeed;
			(*obj).horizSpeed = -(*obj).horizSpeed;
		}
	}
}


void initObject(m4rly::TObject* obj, float xPos, float yPos, float oWidth, float oHeight, char inType) 
{
	setObjectPos(obj, xPos, yPos);
	(*obj).width = oWidth;
	(*obj).height = oHeight;
	(*obj).vertSpeed = 0;
	(*obj).cType = inType;
	(*obj).horizSpeed = 0.2; 
}


bool isCollision(m4rly::TObject o1, m4rly::TObject o2) 
{
	return ((o1.x + o1.width > o2.x) && (o1.x < (o2.x + o2.width))) &&
	((o1.y + o1.height) > o2.y) && (o1.y < (o2.y + o2.height)); 
}


void marioCollision(m4rly::TObject mario, m4rly::TObject*& brick, m4rly::TObject*& moving, int& brickLength, int& movingLength, int& score, int level, int maxLvl) {
	for (int i = 0; i < movingLength; i++) 
	{ 
		if (isCollision(mario, moving[i])) 
		{
			if (moving[i].cType == 'o') 
			{
				if ((mario.IsFly == true) 
					&& (mario.vertSpeed > 0)
					&& (mario.y + mario.height < moving[i].y + moving[i].height * 0.5)
					) 
				{
					score += 50;
					deleteMoving(i, moving, movingLength);
					i--;
					continue;
				} else
					playerDead(mario, brick, moving, brickLength, movingLength, level, maxLvl, score); 
			}

			if (moving[i].cType == '$') 
			{
				score += 100;
				deleteMoving(i, moving, movingLength);
				i--;
				continue;
			}
		}
	}
}


void playerDead(m4rly::TObject& mario, m4rly::TObject*& brick, m4rly::TObject*& moving, int& brickLength, int& movingLength, int level, int maxLvl, int& score) 
{
	system("color 4F");
	Sleep(500);
	createLevel(mario, brick, moving, brickLength, movingLength, level, maxLvl, score);
}


void setObjectPos(m4rly::TObject* obj, float xPos, float yPos) 
{
	(*obj).x = xPos;
	(*obj).y = yPos;
}


void showMap(char map[m4rly::cfg::mapHeight][m4rly::cfg::mapWidth+1]) 
{
	map[m4rly::cfg::mapHeight - 1][m4rly::cfg::mapWidth - 1] = '\0';
	for (int j = 0; j < m4rly::cfg::mapHeight; j++)
		printf("%s", map[j]);
}


void setCur(int x, int y) 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void vertMoveObject(m4rly::TObject* obj, m4rly::TObject& mario, m4rly::TObject*& brick, m4rly::TObject*& moving, int& brickLength, int& movingLength, int& score, int& level, int maxLvl) 
{
	(*obj).IsFly = true;
	(*obj).vertSpeed += 0.05;
	setObjectPos(obj, (*obj).x, (*obj).y + (*obj).vertSpeed);
	
	for (int i = 0; i < brickLength; i++) 
	{	
		if (isCollision(*obj, brick[i])) 
		{
			if ((*obj).vertSpeed > 0)
				(*obj).IsFly = false;

			if ((brick[i].cType == '?') && ((*obj).vertSpeed < 0) && (obj == &mario)) 
			{
				brick[i].cType = '-';
				initObject(getNewMoving(moving, movingLength), brick[i].x, brick[i].y - 3, 3, 2, '$');
				moving[movingLength - 1].vertSpeed = -0.7;
			}
			(*obj).y -= (*obj).vertSpeed;
			(*obj).vertSpeed = 0;
			
			if (brick[i].cType == '+') 
			{
				level += 1;
				if (level > maxLvl) level = 1;
				system("color 2F");
				Sleep(500);
				createLevel(mario, brick, moving, brickLength, movingLength, level, maxLvl, score);
			}
			break;
		}
	}
}