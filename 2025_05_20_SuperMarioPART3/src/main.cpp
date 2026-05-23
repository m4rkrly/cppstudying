#include <windows.h>

#include "derived.hpp"
#include "init.hpp"
#include "level.hpp"
#include "map.hpp"
#include "objects.hpp"

int main()
{   
    int level = 1; 
    m4rkrly::Map map;
    m4rkrly::Level lvl;
    Status st = NOTHING;

    while (st != EXIT) 
    {
        lvl.createLevel(level);
        while (true)
        { 
            map.clearMap();
            st = lvl.playLevel();
            
            if (st == EXIT or st == LOSE) break;
            if (st == WIN) { break; }

            lvl.putObjectsOnMap(map);
            lvl.putScoreOnMap(map);
            map.returnCur();
            map.showMap();
            Sleep(10);

        } 
    }

    return 0;
}