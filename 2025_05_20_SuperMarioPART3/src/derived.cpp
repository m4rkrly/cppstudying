#include "derived.hpp"

m4rkrly::Goomba::Goomba(
    float x, float y, 
    float hSpeed, float vSpeed
) : NPC(x, y, 2, 2, 'o', hSpeed, vSpeed, 50) {}

int m4rkrly::Goomba::collisionMario(Player mario) {
    return 0;
}
