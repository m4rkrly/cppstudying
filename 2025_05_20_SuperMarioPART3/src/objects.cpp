#include "objects.hpp"
#include "map.hpp"

m4rkrly::Object::Object(
    float x, float y, 
    float width, float height, 
    char texture
) 
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->texture = texture;
}

float m4rkrly::Object::getX() const { return x; }
float m4rkrly::Object::getY() const { return y; }
float m4rkrly::Object::getWidth() const { return width; }
float m4rkrly::Object::getHeight() const { return height; }

void m4rkrly::Object::setPos(float x, float y)
{
    this->x = x;
    this->y = y;
}

// TODO
void m4rkrly::Object::putOnMap(m4rkrly::Map map)
{
    return;
}
//



m4rkrly::Moving::Moving(
    float x, float y, 
    float width, float height, 
    char texture, 
    float vSpeed, float hSpeed
) : Object(x, y, width, height, texture)
{
    this->vSpeed = vSpeed;
    this->hSpeed = hSpeed;
}

float m4rkrly::Moving::getVSpeed() const { return vSpeed; }
float m4rkrly::Moving::getHSpeed() const { return vSpeed; }

void m4rkrly::Moving::setVSpeed(float vSpeed) {
    this->vSpeed = vSpeed;
}
void m4rkrly::Moving::setHSpeed(float hSpeed) {
    this->hSpeed = hSpeed;
}



m4rkrly::Interactive::Interactive(
    float x, float y, 
    float width, float height, 
    char texture
) : Object(x, y, width, height, texture) {}



// Возможно стоит создать возможность задавать размеры Марио в init
m4rkrly::Player::Player(float x, float y)
    : Moving(x, y, 3, 3, '@', 0, 0), isFlying(false) {}
//



m4rkrly::NPC::NPC(
    float x, float y, 
    float width, float height, 
    char texture, 
    float hSpeed, float vSpeed
) : Moving(x, y, width, height, texture, vSpeed, hSpeed) {}

int m4rkrly::NPC::getPrice() const { return price; }
