#pragma once

#include "structs.hpp"

namespace m4rly {   
    namespace model {
        void createLevel(
            m4rly::TObject& mario, 
            m4rly::TObject*& brick, m4rly::TObject*& moving, 
            int& brickLength, int& movingLength, 
            int lvl, int& maxLvl, int& score
        );
        void deleteMoving(
            int i, m4rly::TObject*& moving, int& movingLength
        );
        m4rly::TObject* getNewBrick(
            m4rly::TObject*& brick, 
            int& brickLength
        );
        m4rly::TObject* getNewMoving(
            m4rly::TObject*& moving, 
            int& movingLength
        );
        void horizonMoveMap(
            m4rly::TObject& mario, 
            m4rly::TObject*& brick, m4rly::TObject*& moving, 
            int& brickLength, int& movingLength,
            float dx
        );
        void horizonMoveObject(
            m4rly::TObject* obj, m4rly::TObject& mario, 
            m4rly::TObject*& brick, m4rly::TObject*& moving, 
            int& brickLength, int& movingLength, 
            int& score, int& level, int maxLvl
        );
        bool isCollision(m4rly::TObject o1, m4rly::TObject o2);
        void initObject(
            m4rly::TObject* obj, float xPos, float yPos, 
            float oWidth, float oHeight, char inType
        );
        void marioCollision(
            m4rly::TObject mario, 
            m4rly::TObject*& brick, m4rly::TObject*& moving, 
            int& brickLength, int& movingLength, 
            int& score, int level, int maxLvl
        );
        void playerDead(
            m4rly::TObject& mario, 
            m4rly::TObject*& brick, m4rly::TObject*& moving, 
            int& brickLength, int& movingLength, 
            int level, int maxLvl, int& score
        );
        void setObjectPos(m4rly::TObject* obj, float xPos, float yPos);
        void vertMoveObject(
            m4rly::TObject* obj, m4rly::TObject& mario, 
            m4rly::TObject*& brick, m4rly::TObject*& moving, 
            int& brickLength, int& movingLength, 
            int& score, int& level, int maxLvl
        );
    }
}