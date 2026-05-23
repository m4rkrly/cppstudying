#pragma once

#include "map.hpp"
#include "objects.hpp"

namespace m4rkrly 
{
    class Level
    {
        private:
            NPC** npcList;
            Interactive** interactList;
            Object** brickList;
            Player mario;

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
            void putObjectsOnMap(Map& map);
            void putScoreOnMap(Map& map);
        
        private:
            void moveNPC(NPC* npc);
            void horizMoveMario(float dx);
            bool horizonMoveNPC(NPC& npc);
            int marioCollision(); 
            bool isColliding();
            void increaseScore();

            bool verticMoveObj(Moving& obj);
            bool isOutOfBounds();

            template <typename T>
            void deleteList(T**& l, int& lSize);
            template <typename T>
            void deleteFromList(int i, T**& l, int& lSize);

            void addNewNPC(
                NPC* newNpc
            );
            void addNewInteractive(
                Interactive* newInter
            );
            void addNewBrick(
                Object* newBrick 
            );
            
    };
}