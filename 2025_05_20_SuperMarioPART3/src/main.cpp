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

    while (st != EXIT) {
        lvl.createLevel(level);
        do 
        {
            map.clearMap();
            st = lvl.playLevel();
            
            // if (st == WIN) nextLevel();

            lvl.putObjectsOnMap(map);
            map.returnCur();
            map.showMap();
            Sleep(10);
        } while (st != LOSE or st != WIN or st != EXIT);
    }

    return 0;
}