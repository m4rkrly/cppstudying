#pragma once

#include "structs.hpp"

namespace m4rly {   
    namespace model {
        void createLevel(m4rly::TObject& mario, m4rly::TObject*& brick, m4rly::TObject*& moving, int& brickLength, int& movingLength, int lvl, int& maxLvl, int& score);
        m4rly::TObject* getNewBrick(m4rly::TObject*& brick, int& brickLength);
        m4rly::TObject* getNewMoving(m4rly::TObject*& moving, int& movingLength);
        void initObject(m4rly::TObject* obj, float xPos, float yPos, float oWidth, float oHeight, char inType);
        void setObjectPos(m4rly::TObject* obj, float xPos, float yPos);
    }
}