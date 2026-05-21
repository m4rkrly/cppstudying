#pragma once

#include "map.hpp"
#include "objects.hpp"

namespace m4rkrly 
{
    class Level
    {
        private:
            m4rkrly::NPC* npcList;
            m4rkrly::Interactive* interactList;
            m4rkrly::Object* brickList;
            m4rkrly::Player mario;

            int npcSize;
            int interactSize;
            int brickSize;
            int score;

            const int MAXLVL = 3;
            int lvl = 1;
        public:
            Level(); 

            // КК и ОПК удалять было не обязательно
            // Но я не могу тратить время на их реализацию
            Level(const Level&) = delete;
            Level& operator = (const Level&) = delete;

            Level(Level&& other) = default;
            Level& operator = (Level&& other) = default;

            ~Level();

            int playLevel();
            void createLevel(int level);
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

            m4rkrly::NPC* addNewNPC(
                m4rkrly::NPC newNpc,  
                m4rkrly::NPC* npcList, int& npcSize
            );
            m4rkrly::Interactive* addNewInteractive(
                m4rkrly::Interactive newInter, 
                m4rkrly::Interactive* interactList, int& interactSize
            );
            m4rkrly::Object* addNewBrick(
                m4rkrly::Object newBrick, 
                m4rkrly::Object* brickList, int& brickSize
            );
    };
}