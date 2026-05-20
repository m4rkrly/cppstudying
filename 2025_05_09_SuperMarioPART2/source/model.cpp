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


void m4rly::model::initObject(m4rly::TObject* obj, float xPos, float yPos, float oWidth, float oHeight, char inType) 
{
	m4rly::model::setObjectPos(obj, xPos, yPos);
	(*obj).width = oWidth;
	(*obj).height = oHeight;
	(*obj).vertSpeed = 0;
	(*obj).cType = inType;
	(*obj).horizSpeed = 0.2; 
}

void m4rly::model::setObjectPos(m4rly::TObject* obj, float xPos, float yPos) 
{
	(*obj).x = xPos;
	(*obj).y = yPos;
}