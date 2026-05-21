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
            int collisionMario(Player mario) override;      
    };

    class Coin : public NPC 
    {
        public:
            Coin(float x, float y, float hSpeed, float vSpeed);
            int collisionMario(Player mario) override;
    };
}