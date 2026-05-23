#include "derived.hpp"

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
    return 0;
}
