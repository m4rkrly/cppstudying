#pragma once

#include "objects.hpp"


namespace m4rkrly {

    class Goomba : public NPC 
    {
        public:
            Goomba(
                float x, float y, 
                float hSpeed, float vSpeed
            );
            bool toMoveHoriz(bool isCollidingHoriz) override;
            bool toMoveVertic(bool isCollidingVertic) override;
            int collisionMario(Player mario) override;      
    };


    class LuckyBlock : public Interactive
    {
        public:
            LuckyBlock(float x, float y);
            int collisionMario(Player mario) override;
    };

}