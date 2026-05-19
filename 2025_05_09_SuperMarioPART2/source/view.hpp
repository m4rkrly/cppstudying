#pragma once

#include "config.hpp"
#include "structs.hpp"

namespace m4rly {
    namespace view {
        void clearMap(char map[m4rly::cfg::mapHeight][m4rly::cfg::mapWidth+1]);
        bool isPosInMap(int x, int y);
        void putObjectOnMap(m4rly::TObject obj, char map[m4rly::cfg::mapHeight][m4rly::cfg::mapWidth+1]);
        void putScoreOnMap(int& score, char map[m4rly::cfg::mapHeight][m4rly::cfg::mapWidth+1]);
        void showMap(char map[m4rly::cfg::mapHeight][m4rly::cfg::mapWidth+1]);
        void setCur(int x, int y);
    }
}