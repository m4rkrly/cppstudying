#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <windows.h>

#define mapWidth 80
#define mapHeight 25

typedef struct SObject 
{
	float x, y;
	float width, height;
	float vertSpeed;
	bool IsFly;
	char cType;
	float horizSpeed;
} TObject;

char map[mapHeight][mapWidth+1];


TObject* moving = nullptr;


int movingLength;

void clearMap();
void createLevel(TObject& mario, TObject*& brick, int& brickLength, int lvl, int& maxLvl, int& score);
void deleteMoving(int i);
TObject* getNewBrick(TObject*& brick, int& brickLength);
TObject* getNewMoving();
void horizonMoveMap(TObject mario, TObject* brick, int& brickLength, float dx);
void horizonMoveObject(TObject *obj, TObject& mario, TObject*& brick, int& brickLength, int& score, int& level, int maxLvl);
void initObject(TObject *obj, float xPos, float yPos, float oWidth, float oHeight, char inType);
bool isCollision(TObject o1, TObject o2);
bool isPosInMap(int x, int y);
void marioCollision(TObject mario, TObject*& brick, int& brickLength, int& score, int level, int maxLvl);
void playerDead(TObject& mario, TObject*& brick, int& brickLength, int level, int maxLvl, int& score);
void putObjectOnMap(TObject obj);
void putScoreOnMap(int& score);
void setObjectPos(TObject *obj, float xPos, float yPos);
void showMap();
void setCur(int x, int y);
void vertMoveObject(TObject *obj, TObject& mario, TObject*& brick, int& brickLength, int& score, int& level, int maxLvl);

int main() 
{
	TObject mario;
	TObject* brick = nullptr;
	int brickLength;

	int level = 1;
	int maxLvl;
	int score;

	createLevel(mario, brick, brickLength, level, maxLvl, score);

	do 
	{
		clearMap();

		if ((mario.IsFly == false) && (GetAsyncKeyState(VK_SPACE) < 0))
			mario.vertSpeed = -1;
		if (GetAsyncKeyState('A') < 0) 
			horizonMoveMap(mario, brick, brickLength, 1);
		if (GetAsyncKeyState('D') < 0) 
			horizonMoveMap(mario, brick, brickLength, -1);

		if (mario.y > mapHeight)
		 	playerDead(mario, brick, brickLength, level, maxLvl, score); 

		vertMoveObject(&mario, mario, brick, brickLength, score, level, maxLvl);
		marioCollision(mario, brick, brickLength, score, level, maxLvl);

		for (int i = 0; i < brickLength; i++) 
			putObjectOnMap(brick[i]);
		for (int i = 0; i < movingLength; i++) 
		{
			vertMoveObject(moving + i, mario, brick, brickLength, score, level, maxLvl);
			horizonMoveObject(moving + i, mario, brick, brickLength, score, level, maxLvl);
			if (moving[i].y > mapHeight) 
			{
				deleteMoving(i);
				i--;
				continue;
			}
			putObjectOnMap(moving[i]);
		}
		putObjectOnMap(mario);
		putScoreOnMap(score);
		setCur(0, 0);
		showMap(); 

		Sleep(10);
	} while (GetAsyncKeyState(VK_ESCAPE) >= 0);
	
	return 0;
}


void clearMap() 
{
	for (int i = 0; i < mapWidth;  i++) 
		map[0][i] = ' ';
	map[0][mapWidth] = '\0';
	for (int j = 1; j < mapHeight; j++)
		sprintf(map[j], map[0]);
}


void createLevel(TObject& mario, TObject*& brick, int& brickLength, int lvl, int& maxLvl, int& score) 
{
	system("color 9F");
	brickLength = 0;
	movingLength = 0;
	brick = static_cast<TObject*>(realloc(brick, 0));
	moving = static_cast<TObject*>(realloc(moving, 0));

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
	
		initObject(getNewMoving(), 25, 10, 3, 2, 'o');
		initObject(getNewMoving(), 80, 10, 3, 2, 'o');
	}

	if (lvl == 2) 
	{ 
		initObject(getNewBrick(brick, brickLength), 20, 20, 40, 5, '#');
		initObject(getNewBrick(brick, brickLength), 60, 15, 10, 10, '#');
		initObject(getNewBrick(brick, brickLength), 80, 20, 40, 5, '#');
		initObject(getNewBrick(brick, brickLength), 120, 15, 10, 10, '#');
		initObject(getNewBrick(brick, brickLength), 150, 20, 40, 5, '#');
		initObject(getNewBrick(brick, brickLength), 210, 15, 10, 10, '+');	
		
		initObject(getNewMoving(), 25, 10, 3, 2, 'o');
		initObject(getNewMoving(), 80, 10, 3, 2, 'o');
		initObject(getNewMoving(), 65, 10, 3, 2, 'o');
		initObject(getNewMoving(), 120, 10, 3, 2, 'o');
		initObject(getNewMoving(), 160, 10, 3, 2, 'o');
		initObject(getNewMoving(), 175, 10, 3, 2, 'o');
	}
	
	if (lvl == 3) 
	{
		initObject(getNewBrick(brick, brickLength), 20, 20, 40, 5, '#');
		initObject(getNewBrick(brick, brickLength), 80, 20, 15, 5, '#');
		initObject(getNewBrick(brick, brickLength), 120, 15, 15, 10, '#');
		initObject(getNewBrick(brick, brickLength), 160, 10, 15, 15, '+');

		initObject(getNewMoving(), 25, 10, 3, 2, 'o');
		initObject(getNewMoving(), 50, 10, 3, 2, 'o');
		initObject(getNewMoving(), 80, 10, 3, 2, 'o');
		initObject(getNewMoving(), 90, 10, 3, 2, 'o');
		initObject(getNewMoving(), 120, 10, 3, 2, 'o');
		initObject(getNewMoving(), 130, 10, 3, 2, 'o');
	}
}


void deleteMoving(int i) 
{
	movingLength -= 1;
	moving[i] = moving[movingLength];
	moving = static_cast<TObject*>(realloc( moving, sizeof(*moving) * movingLength));
}


TObject* getNewBrick(TObject*& brick, int& brickLength) 
{
	brickLength++;
	brick = static_cast<TObject*>(realloc(brick, sizeof(*brick) * brickLength));
	return brick + brickLength - 1;
}


TObject* getNewMoving() 
{
	movingLength++;
	moving = static_cast<TObject*>(realloc(moving, sizeof(*moving) * movingLength));
	return moving + movingLength - 1;
}


void horizonMoveMap(TObject mario, TObject* brick, int& brickLength, float dx) 
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


void horizonMoveObject(TObject *obj, TObject& mario, TObject*& brick, int& brickLength, int& score, int& level, int maxLvl) 
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
		TObject temp = *obj;
		vertMoveObject(&temp, mario, brick, brickLength, score, level, maxLvl);
		if (temp.IsFly == true) 
		{
			(*obj).x -= (*obj).horizSpeed;
			(*obj).horizSpeed = -(*obj).horizSpeed;
		}
	}
}


void initObject(
	TObject *obj, float xPos, float yPos, 
	float oWidth, float oHeight, char inType
) 
{
	setObjectPos(obj, xPos, yPos);
	(*obj).width = oWidth;
	(*obj).height = oHeight;
	(*obj).vertSpeed = 0;
	(*obj).cType = inType;
	(*obj).horizSpeed = 0.2; 
}


bool isCollision(TObject o1, TObject o2) 
{
	return ((o1.x + o1.width > o2.x) && (o1.x < (o2.x + o2.width))) &&
	((o1.y + o1.height) > o2.y) && (o1.y < (o2.y + o2.height)); 
}


bool isPosInMap(int x, int y) 
{
	return ((x >= 0) && (x < mapWidth) && (y >= 0) && (y < mapHeight));
}


void marioCollision(TObject mario, TObject*& brick, int& brickLength, int& score, int level, int maxLvl) {
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
					deleteMoving(i);
					i--;
					continue;
				} else
					playerDead(mario, brick, brickLength, level, maxLvl, score); 
			}

			if (moving[i].cType == '$') 
			{
				score += 100;
				deleteMoving(i);
				i--;
				continue;
			}
		}
	}
}


void playerDead(TObject& mario, TObject*& brick, int& brickLength, int level, int maxLvl, int& score) 
{
	system("color 4F");
	Sleep(500);
	createLevel(mario, brick, brickLength, level, maxLvl, score);
}


void putObjectOnMap(TObject obj) 
{
	int ix = (int)round(obj.x);
	int iy = (int)round(obj.y);
	int iWidth = (int)round(obj.width);
	int iHeight = (int)round(obj.height);

	for (int i = ix; i < (ix + iWidth); i++)
		for (int j = iy; j < (iy + iHeight); j++)
			if (isPosInMap(i, j))
				map[j][i] = obj.cType;
}


void putScoreOnMap(int& score) 
{
	char c[30];
	sprintf(c, "Score: %d", score);
	int len = strlen(c);
	for (int i = 0; i < len; i++) {
		map[1][i+5] = c[i];
	}
}

void setObjectPos(TObject *obj, float xPos, float yPos) 
{
	(*obj).x = xPos;
	(*obj).y = yPos;
}


void showMap() 
{
	map[mapHeight - 1][mapWidth - 1] = '\0';
	for (int j = 0; j < mapHeight; j++)
		printf("%s", map[j]);
}


void setCur(int x, int y) 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void vertMoveObject(TObject *obj, TObject& mario, TObject*& brick, int& brickLength, int& score, int& level, int maxLvl) 
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
				initObject(getNewMoving(), brick[i].x, brick[i].y - 3, 3, 2, '$');
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
				createLevel(mario, brick, brickLength, level, maxLvl, score);
			}
			break;
		}
	}
}