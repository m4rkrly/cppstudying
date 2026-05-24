#include <cmath>

#include "init.hpp"
#include "map.hpp"
#include "objects.hpp"

// OBJECT CLASS
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

void m4rkrly::Object::changePos(float dx, float dy)
{
    x += dx;
    y += dy;
}


float m4rkrly::Object::getX() const {return x; }
float m4rkrly::Object::getY() const {return y; }
float m4rkrly::Object::getWidth() const {return width; }
float m4rkrly::Object::getHeight() const {return height; }


bool m4rkrly::Object::isCollidingWith(Object& other)
{
    bool collisionX = ((x + width > other.x) && (x < (other.x + other.width)));
    bool collisionY = ((y + height) > other.y) && (y < (other.y + other.height));
    return collisionX && collisionY;
}


bool m4rkrly::Object::isFallen() { return y > init::MAPHEIGHT; }


void m4rkrly::Object::putOnMap(m4rkrly::Map& map)
{
    int ix = (int)round(this->x);
	int iy = (int)round(this->y);
	int iWidth = (int)round(this->width);
	int iHeight = (int)round(this->height);

	for (int i = ix; i < (ix + iWidth); i++)
		for (int j = iy; j < (iy + iHeight); j++)
			if (map.isPosOnMap(i, j))
				map.putSymbol(i, j, this->texture);
}

void m4rkrly::Object::setPos(float x, float y) { this->x = x; this->y = y; }
// END OF OBJECT CLASS



// MOVING CLASS
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

void m4rkrly::Moving::applyGravity()
{
    isFlying = true;
    vSpeed += 0.05;
    changePos(0, vSpeed);
}

void m4rkrly::Moving::discardGravity()
{
    if (vSpeed > 0)
        isFlying = false;
    changePos(0, -vSpeed);
    vSpeed = 0;
}

float m4rkrly::Moving::getVSpeed() const { return vSpeed; }
bool m4rkrly::Moving::getIsFlying() const { return isFlying; }
// END OF MOVING CLASS



// PLAYER CLASS
m4rkrly::Player::Player()
    : Moving(0, 0, 3, 3, '@', 0, 0) {}


m4rkrly::Player::Player(float x, float y)
    : Moving(x, y, 3, 3, '@', 0, 0) {}


void m4rkrly::Player::jump(float vSpeed) 
{
    if (isFlying != true)
        this-> vSpeed = vSpeed;    
}
// END OF PLAYER CLASS



// INTERACTIVE CLASS
m4rkrly::Interactive::Interactive(
    float x, float y, 
    float width, float height, 
    char texture
) : Object(x, y, width, height, texture) {}
// END OF INTERACTIVE CLASS



// NPC CLASS
m4rkrly::NPC::NPC(
    float x, float y, 
    float width, float height, 
    char texture, 
    float hSpeed, float vSpeed,
    int price
) : Moving(x, y, width, height, texture, vSpeed, hSpeed), price(price) {}     


Status m4rkrly::NPC::collisionMario(Player& mario) { return NOTHING; }
void m4rkrly::NPC::changeDirection() { hSpeed = -hSpeed; }
void m4rkrly::NPC::discardMove() { changePos(-hSpeed, 0); }
int m4rkrly::NPC::getPrice() const { return price; }
void m4rkrly::NPC::move() { changePos(hSpeed, 0); }
bool m4rkrly::NPC::toMoveHoriz(bool isCollidingHoriz) { return true; }
bool m4rkrly::NPC::toMoveVertic(bool isCollidingVertic) { return true; }
// END OF NPC CLASS