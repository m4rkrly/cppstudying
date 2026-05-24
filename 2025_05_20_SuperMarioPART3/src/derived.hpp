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
            Status collisionMario(Player& mario) override;   
            bool toMoveHoriz(bool isCollidingHoriz) override;
            bool toMoveVertic(bool isCollidingVertic) override; 
    };


    class LuckyBlock : public Interactive
    {
        public:
            LuckyBlock(float x, float y);
            Status collisionMario(Player& mario) override;
    };


    class Coin : public NPC
    {
        public:
            Coin(Interactive& lb);
            Status collisionMario(Player& mario) override;
    };

    class WinTube : public Interactive
    {
        public:
            WinTube(float x, float y, float width, float height);
            Status collisionMario(Player& mario) override;
    };

    class DestructableBrick : public Interactive
    {
        public:
            DestructableBrick(float x, float y);
            Status collisionMario(Player& mario) override;
    };

}