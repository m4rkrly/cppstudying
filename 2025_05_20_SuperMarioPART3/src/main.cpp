#include "derived.hpp"
#include "init.hpp"
#include "map.hpp"
#include "objects.hpp"

int main()
{
    m4rkrly::Map map;
    m4rkrly::Player mario(10, 10);
    m4rkrly::Goomba g1(20, 15, 0, 0);

    map.clearMap();

    mario.putOnMap(map);
    g1.putOnMap(map);

    map.showMap();
    return 0;
}