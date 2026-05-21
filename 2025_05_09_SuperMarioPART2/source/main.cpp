#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#include "config.hpp"
#include "model.hpp"
#include "view.hpp"
#include "structs.hpp"

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

	m4rly::model::createLevel(
		mario, 
		brick, moving, 
		brickLength, movingLength, 
		level, maxLvl, score
	);

	do 
	{
		m4rly::view::clearMap(map);

		if ((mario.IsFly == false) && (GetAsyncKeyState(VK_SPACE) < 0))
			mario.vertSpeed = -1;
		if (GetAsyncKeyState('A') < 0) 
			m4rly::model::horizonMoveMap(
				mario, 
				brick, moving,  
				brickLength, movingLength, 
				1
			);
		if (GetAsyncKeyState('D') < 0) 
			m4rly::model::horizonMoveMap(
				mario, 
				brick, moving, 
				brickLength, movingLength, 
				-1
			);

		if (mario.y > m4rly::cfg::mapHeight)
		 	m4rly::model::playerDead(
				mario, 
				brick, moving, 
				brickLength, movingLength, 
				level, maxLvl, score
			); 

		m4rly::model::vertMoveObject(
			&mario, 
			mario, brick, moving, 
			brickLength, movingLength, score, level, maxLvl
		);
		m4rly::model::marioCollision(
			mario, 
			brick, moving, 
			brickLength, movingLength, 
			score, level, maxLvl
		);

		for (int i = 0; i < brickLength; i++) 
			m4rly::view::putObjectOnMap(brick[i], map);
		for (int i = 0; i < movingLength; i++) 
		{
			m4rly::model::vertMoveObject(
				moving + i, mario, 
				brick, moving, 
				brickLength, movingLength, 
				score, level, maxLvl
			);
			m4rly::model::horizonMoveObject(
				moving + i, mario, 
				brick, moving, 
				brickLength, movingLength, 
				score, level, maxLvl
			);
			if (moving[i].y > m4rly::cfg::mapHeight) 
			{
				m4rly::model::deleteMoving(i, moving, movingLength);
				i--;
				continue;
			}
			m4rly::view::putObjectOnMap(moving[i], map);
		}
		m4rly::view::putObjectOnMap(mario, map);
		m4rly::view::putScoreOnMap(score, map);
		m4rly::view::setCur(0, 0);
		m4rly::view::showMap(map); 

		Sleep(10);
	} while (GetAsyncKeyState(VK_ESCAPE) >= 0);
	
	return 0;
}