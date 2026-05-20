#include <stdlib.h>
#include <windows.h>

#include "model.hpp"

void m4rly::model::createLevel(m4rly::TObject& mario, m4rly::TObject*& brick, m4rly::TObject*& moving, int& brickLength, int& movingLength, int lvl, int& maxLvl, int& score) 
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


void m4rly::model::deleteMoving(int i, m4rly::TObject*& moving, int& movingLength) 
{
	movingLength -= 1;
	moving[i] = moving[movingLength];
	moving = static_cast<m4rly::TObject*>(realloc( moving, sizeof(*moving) * movingLength));
}


m4rly::TObject* m4rly::model::getNewBrick(m4rly::TObject*& brick, int& brickLength) 
{
	brickLength++;
	brick = static_cast<m4rly::TObject*>(realloc(brick, sizeof(*brick) * brickLength));
	return brick + brickLength - 1;
}

 
m4rly::TObject* m4rly::model::getNewMoving(m4rly::TObject*& moving, int& movingLength) 
{
	movingLength++;
	moving = static_cast<m4rly::TObject*>(realloc(moving, sizeof(*moving) * movingLength));
	return moving + movingLength - 1;
}


void m4rly::model::horizonMoveMap(m4rly::TObject& mario, m4rly::TObject*& brick, m4rly::TObject*& moving, int& brickLength, int& movingLength, float dx) 
{
	mario.x -= dx;
	for (int i = 0; i < brickLength; i++) 
		if (m4rly::model::isCollision(mario, brick[i]))
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


void m4rly::model::horizonMoveObject(m4rly::TObject* obj, m4rly::TObject& mario, m4rly::TObject*& brick, m4rly::TObject*& moving, int& brickLength, int& movingLength, int& score, int& level, int maxLvl) 
{
	(*obj).x += (*obj).horizSpeed;

	for (int i = 0; i < brickLength; i++) 
		if (m4rly::model::isCollision(obj[0], brick[i])) 
		{
			(*obj).x -= (*obj).horizSpeed;
			(*obj).horizSpeed = -(*obj).horizSpeed;
			return;
		}

	if ((*obj).cType == 'o') 
	{
		m4rly::TObject temp = *obj;
		m4rly::model::vertMoveObject(&temp, mario, brick, moving, brickLength, movingLength, score, level, maxLvl);
		if (temp.IsFly == true) 
		{
			(*obj).x -= (*obj).horizSpeed;
			(*obj).horizSpeed = -(*obj).horizSpeed;
		}
	}
}


bool m4rly::model::isCollision(m4rly::TObject o1, m4rly::TObject o2) 
{
	return ((o1.x + o1.width > o2.x) && (o1.x < (o2.x + o2.width))) &&
	((o1.y + o1.height) > o2.y) && (o1.y < (o2.y + o2.height)); 
}


void m4rly::model::initObject(m4rly::TObject* obj, float xPos, float yPos, float oWidth, float oHeight, char inType) 
{
	m4rly::model::setObjectPos(obj, xPos, yPos);
	(*obj).width = oWidth;
	(*obj).height = oHeight;
	(*obj).vertSpeed = 0;
	(*obj).cType = inType;
	(*obj).horizSpeed = 0.2; 
}


void m4rly::model::marioCollision(m4rly::TObject mario, m4rly::TObject*& brick, m4rly::TObject*& moving, int& brickLength, int& movingLength, int& score, int level, int maxLvl) {
	for (int i = 0; i < movingLength; i++) 
	{ 
		if (m4rly::model::isCollision(mario, moving[i])) 
		{
			if (moving[i].cType == 'o') 
			{
				if ((mario.IsFly == true) 
					&& (mario.vertSpeed > 0)
					&& (mario.y + mario.height < moving[i].y + moving[i].height * 0.5)
					) 
				{
					score += 50;
					m4rly::model::deleteMoving(i, moving, movingLength);
					i--;
					continue;
				} else
					m4rly::model::playerDead(mario, brick, moving, brickLength, movingLength, level, maxLvl, score); 
			}

			if (moving[i].cType == '$') 
			{
				score += 100;
				m4rly::model::deleteMoving(i, moving, movingLength);
				i--;
				continue;
			}
		}
	}
}


void m4rly::model::playerDead(m4rly::TObject& mario, m4rly::TObject*& brick, m4rly::TObject*& moving, int& brickLength, int& movingLength, int level, int maxLvl, int& score) 
{
	system("color 4F");
	Sleep(500);
	m4rly::model::createLevel(mario, brick, moving, brickLength, movingLength, level, maxLvl, score);
}


void m4rly::model::setObjectPos(m4rly::TObject* obj, float xPos, float yPos) 
{
	(*obj).x = xPos;
	(*obj).y = yPos;
}

void m4rly::model::vertMoveObject(m4rly::TObject* obj, m4rly::TObject& mario, m4rly::TObject*& brick, m4rly::TObject*& moving, int& brickLength, int& movingLength, int& score, int& level, int maxLvl) 
{
	(*obj).IsFly = true;
	(*obj).vertSpeed += 0.05;
	m4rly::model::setObjectPos(obj, (*obj).x, (*obj).y + (*obj).vertSpeed);
	
	for (int i = 0; i < brickLength; i++) 
	{	
		if (m4rly::model::isCollision(*obj, brick[i])) 
		{
			if ((*obj).vertSpeed > 0)
				(*obj).IsFly = false;

			if ((brick[i].cType == '?') && ((*obj).vertSpeed < 0) && (obj == &mario)) 
			{
				brick[i].cType = '-';
				m4rly::model::initObject(m4rly::model::getNewMoving(moving, movingLength), brick[i].x, brick[i].y - 3, 3, 2, '$');
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
				m4rly::model::createLevel(mario, brick, moving, brickLength, movingLength, level, maxLvl, score);
			}
			break;
		}
	}
}