#pragma once

#include "objects.hpp"

namespace m4rkrly {
    class Level
    {
        private:
            m4rkrly::NPC* Moving;
            m4rkrly::Interactive* interactList;
            m4rkrly::Object* brickList;
            m4rkrly::Player mario;

            int npcSize;
            int interactSize;
            int brickSize;
            int score;
        
        public:
            Level() = delete;
            Level(m4rkrly::NPC* npcList, m4rkrly::Interactive* interactList, m4rkrly::Object* brickList, m4rkrly::Player mario);

            // КК и ОПК удалять было не обязательно
            // Но я не могу тратить время на их реализацию
            Level(const Level&) = delete;
            Level& operator = (const Level&) = delete;

            Level(Level&& other);
            Level& operator = (Level&& other);
            ~Level();

            int playLevel();
            void putObjectsOnMap(m4rkrly::Map map);
            void putScoreOnMap(m4rkrly::Map map);
        
        private:
            void horizMoveMap();
            int marioCollision(); 
            bool isColliding();
            void increaseScore();

            void horizMoveObj();
            void verticMoveObj();
            bool isOutOfBounds();

    };
}