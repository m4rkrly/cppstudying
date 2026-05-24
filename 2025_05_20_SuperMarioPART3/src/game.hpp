#pragma once

#include "level.hpp"
#include "map.hpp"

namespace m4rkrly
{
    class Game final
    {
        private:
            m4rkrly::Level level = Level();
            m4rkrly::Map map = Map();
            Status st = NOTHING;
            int levelNumber = 1; 
            
        public:
            Game() = default;

            Game(const Game&) = delete;
            Game& operator = (const Game&) = delete;
            Game(Game&&) = delete;
            Game& operator = (Game&&) = delete;

            void playGame();
            void nextLevel();
    }; 
} 