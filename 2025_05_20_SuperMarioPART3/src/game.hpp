#pragma once

#include "level.hpp"

namespace m4rkrly
{
    class Game final
    {
        private:
            m4rkrly::Level* lvlList;
            int lvlSize;
            int level;

        public:
            Game();

            Game(const Game&) = delete;
            Game& operator = (const Game&) = delete;
            Game(Game&&) = delete;
            Game& operator = (Game&&) = delete;
            
            ~Game(); 

            void playGame();
            void nextLevel();
    }; 
} 
