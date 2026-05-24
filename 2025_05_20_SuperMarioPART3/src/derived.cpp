#include "derived.hpp"
#include "objects.hpp"

// GOOMBA CLASS
m4rkrly::Goomba::Goomba(
    float x, float y, 
    float hSpeed, float vSpeed
) : NPC(x, y, 2, 2, 'o', hSpeed, vSpeed, 50) {}


Status m4rkrly::Goomba::collisionMario(Player& mario) 
{
    bool collIsVert = (mario.getY() + mario.getHeight() < y + height * 0.5);
    if (mario.getIsFlying() && mario.getVSpeed() > 0 && collIsVert)
    {
        return KILL;
    }
    return LOSE;
}


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
// END OF GOOMBA CLASS



// LUCKYBLOCK CLASS
m4rkrly::LuckyBlock::LuckyBlock(float x, float y) 
    : Interactive(x, y, 5, 3, '?') {}


Status m4rkrly::LuckyBlock::collisionMario(Player& mario)
{
    if (texture == '?')
    {
        bool collFromBottom = mario.getY() > y + height - 1;
        if (mario.getVSpeed() < 0 && collFromBottom)
        {
            texture = '-';
            return SPAWN_COIN;
        }
    }
    return NOTHING;
}
// END OF LUCKYBLOCK CLASS



// COIN CLASS

m4rkrly::Coin::Coin(
    Interactive& lb
) : NPC(lb.getX() + 2, lb.getY() - 2, 2, 2, '$', 0.2, -0.7, 150) {}

Status m4rkrly::Coin::collisionMario(Player& mario) { return KILL; }

// END OF COIN CLASS



// WINTUBE CLASS
m4rkrly::WinTube::WinTube(
    float x, float y,
    float width, float height
) : Interactive(x, y, width, height, '|') {}

Status m4rkrly::WinTube::collisionMario(Player& mario) { return WIN; }
// END OF WINTUBE CLASS


// WINTUBE CLASS
m4rkrly::DestructableBrick::DestructableBrick(float x, float y) 
    : Interactive(x, y, 5, 3, '~') {}

    
Status m4rkrly::DestructableBrick::collisionMario(Player& mario)
{
    bool collFromBottom = mario.getY() > y + height - 1;
        if (mario.getVSpeed() < 0 && collFromBottom)
        {
            return KILL;
        }
    return NOTHING;
}
// END OF WINTUBE CLASS