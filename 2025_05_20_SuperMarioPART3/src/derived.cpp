#include "derived.hpp"
#include "objects.hpp"

// GOOMBA CLASS
m4rkrly::Goomba::Goomba(
    float x, float y, 
    float hSpeed, float vSpeed
) : NPC(x, y, 2, 2, 'o', hSpeed, vSpeed, 50) {}

bool m4rkrly::Goomba::decide(NPC& temp)
{
    if (temp.getIsFlying() == true)
        return false;
    return true;
}

int m4rkrly::Goomba::collisionMario(Player mario) {
    // TODO
    return 0;
}
// END OF GOOMBA CLASS



// LUCKYBLOCK CLASS
m4rkrly::LuckyBlock::LuckyBlock(float x, float y) 
    : Interactive(x, y, 4, 3, '?') {}

int m4rkrly::LuckyBlock::collisionMario(Player mario)
{
    // TODO
    return 0;
}
// END OF LUCKYBLOCK CLASS