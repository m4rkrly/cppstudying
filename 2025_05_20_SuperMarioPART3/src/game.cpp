#include <windows.h>

#include "init.hpp"
#include "game.hpp"
#include "map.hpp"

void m4rkrly::Game::playGame()
{
    while (st != EXIT) 
    {
        level.createLevel(levelNumber);
        while (true)
        { 
            map.clearMap();
            st = level.playLevel();
            
            if (st == EXIT or st == LOSE) break;
            if (st == WIN) 
            {
                nextLevel();
                break; 
            }

            level.putObjectsOnMap(map);
            level.putScoreOnMap(map);
            map.returnCur();
            map.showMap();
            Sleep(10);

        } 
    }
}

void m4rkrly::Game::nextLevel()
{
    if (init::MAXLEVEL == levelNumber)
    {
        levelNumber = 1;
        return;
    }
    levelNumber++;
    
}