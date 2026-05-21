#pragma once

#include "init.hpp"

namespace m4rkrly {
    class Map
    {
        private:
            char map; // Поменяй на map[height][width]

        public:
            Map();

            Map(const Map&) = delete;
            Map& operator = (const Map&) = delete;
            Map(Map&&) = delete;
            Map& operator = (Map&&) = delete;

            void clearMap();
            bool isPosInMap();
            void putObjOnMap();
            void putScoreOnMap();
            void setCur();
            void showMap();
    };
}