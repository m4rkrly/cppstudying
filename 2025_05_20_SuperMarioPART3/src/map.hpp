#pragma once

#include "init.hpp"

namespace m4rkrly 
{
    class Map
    {
        private:
            char map[init::MAPHEIGHT][init::MAPWIDTH + 1];
        public:
            Map() = default;

            Map(const Map&) = delete;
            Map& operator = (const Map&) = delete;
            Map(Map&&) = delete;
            Map& operator = (Map&&) = delete;

            void clearMap();
            bool isPosOnMap(int x, int y);
            void putSymbol(int x, int y, char texture);
            void returnCur();
            void showMap();
    };
}