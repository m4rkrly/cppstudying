#pragma once

#include "config.hpp"
#include "structs.hpp"

namespace m4rly {
    namespace view {
        void clearMap(char map[m4rly::cfg::mapHeight][m4rly::cfg::mapWidth+1]);
    }
}