#pragma once

namespace init {
    const int MAXLEVEL = 2; 

    const int MAPHEIGHT = 25;
    const int MAPWIDTH = 80;
}

enum Status {
    LOSE = -1,
    NOTHING = 0,
    KILL = 1,
    SPAWN_COIN = 2,
    WIN = 3,
    EXIT = 4
};