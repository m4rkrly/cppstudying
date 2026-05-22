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
    lvl.createLevel(level);
    do 
    {
        map.clearMap();
        lvl.playLevel();
        lvl.putObjectsOnMap(map);
        map.returnCur();
        map.showMap();

        Sleep(10);
    } while (true);

    return 0;
}