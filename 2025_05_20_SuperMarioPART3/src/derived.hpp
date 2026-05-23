#pragma once

#include "objects.hpp"


namespace m4rkrly {
    class Player : public Moving 
    {
        public:
            Player();
            Player(float x, float y);

            Player(const Player&) = delete;
            Player& operator = (const Player&) = delete;
            Player(Player&&) = default;
            Player& operator = (Player&&) = default;
        
        void jump(float vSpeed);
    };


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

    class Coin : public NPC 
    {
        public:
            Coin(float x, float y, float hSpeed, float vSpeed);
            int collisionMario(Player mario) override;
    };
}