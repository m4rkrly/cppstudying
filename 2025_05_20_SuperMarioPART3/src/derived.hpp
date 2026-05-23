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
            bool decide(NPC& temp) override;
            int collisionMario(Player mario) override;      
    };


    class LuckyBlock : public Interactive
    {
        public:
            LuckyBlock(float x, float y);
            int collisionMario(Player mario) override;
    };

}