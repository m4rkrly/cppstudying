#pragma once

#include "init.hpp"
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

        public:
            Level(); 

            // КК и ОПК удалять было не обязательно
            // Но я не могу тратить время на их реализацию
            Level(const Level&) = delete;
            Level& operator = (const Level&) = delete;

            Level(Level&& other) = default;
            Level& operator = (Level&& other) = default;

            ~Level();

            Status playLevel();
            
            void createLevel(int level);
            void putObjectsOnMap(Map& map);
            void putScoreOnMap(Map& map);
        
        private:
            
            void addNewBrick(
                Object* newBrick 
            );

            void addNewInteractive(
                Interactive* newInter
            );

            void addNewNPC(
                NPC* newNpc
            );
            
            void addToScore(NPC* npc);

            template <typename T>
            void deleteList(T**& l, int& lSize);

            template <typename T>
            void deleteFromList(int i, T**& l, int& lSize);

            void horizMoveMario(float dx);
            bool horizMoveNPC(NPC& npc);
            void marioCollisionInter(int& i);
            void marioCollisionNPC(); 
            void moveNPC(NPC* npc);
            void playerDead();
            void playerWin();
            void verticMoveMario();
            bool verticMoveNPC(NPC& npc);
    };
}