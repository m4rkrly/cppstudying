#pragma once

#include "init.hpp"

namespace m4rkrly 
{
    class Map
    {
        private:
            char map[MAPHEIGHT][MAPWIDTH + 1]; // Поменяй на map[height][width]

        public:
            Map() = default;

            Map(const Map&) = delete;
            Map& operator = (const Map&) = delete;
            Map(Map&&) = delete;
            Map& operator = (Map&&) = delete;

            void clearMap();
            bool isPosOnMap(int x, int y);
            void putSymbol(int x, int y, char texture);
            void putScoreOnMap(int& score);
            void returnCur();
            void showMap();
    };
}