#pragma once

#include "map.hpp"

namespace m4rkrly 
{
    class Object
    {
        private:
            float x, y;
            float width, height;
            char texture;

        public:
            Object();
            Object(
                float x, float y, 
                float width, float height, 
                char texture
            );
            
            float getX() const;
            float getY() const;
            float getWidth() const;
            float getHeight() const;

            void setPos(float x, float y);
            void changePos(float dx, float dy);

            bool isCollidingWith(Object& other);

            void putOnMap(m4rkrly::Map& map);
    };

    class Moving : public Object {
        private:
            float vSpeed;
            float hSpeed;
            bool isFlying = false;
        
        public:
            Moving() = delete;
            Moving(
                float x, float y, 
                float width, float height, 
                char texture, 
                float vSpeed, float hSpeed
            );

            float getVSpeed() const;
            float getHSpeed() const;
            bool getIsFlying() const;

            void setVSpeed(float vSpeed);
            void setHSpeed(float hSpeed);
            void setIsFlying(bool isFlying);

            void changeVSpeed(float dVSpeed);
            void changeHSpeed(float dHSpeed);

            void changePosOnVSpeed(float multiplier);
            void changePosOnHSpeed(float multiplier);

            void jump(float vSpeed);
            
    };

    class Interactive : public Object
    {
        public:
            Interactive();
            Interactive(
                float x, float y, 
                float width, float height, 
                char texture
            );

            virtual int collisionMario();
    };

    class Player : public Moving 
    {
        public:
            Player();
            Player(float x, float y);

            Player(const Player&) = delete;
            Player& operator = (const Player&) = delete;
            Player(Player&&) = default;
            Player& operator = (Player&&) = default;
    };


    class NPC : public Moving
    {
        private:
            int price;

        public:
            NPC();
            NPC(
                float x, float y, 
                float width, float height, 
                char texture, 
                float hSpeed, float vSpeed,
                int price
            );

            int getPrice() const;
            virtual int collisionMario(Player mario);
    };
}