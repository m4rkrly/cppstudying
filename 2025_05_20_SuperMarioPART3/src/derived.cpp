#include "derived.hpp"
#include "objects.hpp"

// GOOMBA CLASS
m4rkrly::Goomba::Goomba(
    float x, float y, 
    float hSpeed, float vSpeed
) : NPC(x, y, 2, 2, 'o', hSpeed, vSpeed, 50) {}

bool m4rkrly::Goomba::toMoveHoriz(bool isCollidingHoriz)
{
    if (isCollidingHoriz == true) { return false; }
    return true;
}

bool m4rkrly::Goomba::toMoveVertic(bool isCollidingVertic)
{
    if (isCollidingVertic == false) { return false; }
    return true;
}

Status m4rkrly::Goomba::collisionMario(Player& mario) 
{
    bool collIsVert = (mario.getY() + mario.getHeight() < y + height * 0.5);
    if (mario.getIsFlying() && mario.getVSpeed() > 0 && collIsVert)
    {
        return KILL;
    }
    return LOSE;
}
// END OF GOOMBA CLASS



// LUCKYBLOCK CLASS
m4rkrly::LuckyBlock::LuckyBlock(float x, float y) 
    : Interactive(x, y, 4, 3, '?') {}

Status m4rkrly::LuckyBlock::collisionMario(Player& mario)
{
    // bool collIsFromBottom = (mario.getY() > y + height);
    // if (mario.getIsFlying() 
    // && mario.getVSpeed() < 0 
    // && collIsFromBottom)
    // {
    //     return SPAWN_COIN;
    // }
    //return NOTHING;
    return SPAWN_COIN;
}
// END OF LUCKYBLOCK CLASS



// COIN CLASS

m4rkrly::Coin::Coin(
    Interactive& lb
) : NPC(lb.getX() + 1, lb.getY() + 1, 2, 2, '$', 0.2, -0.7, 150) {}

Status m4rkrly::Coin::collisionMario(Player& mario)
{
    return KILL;
}

// END OF COIN CLASS
