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

            void putOnMap(m4rkrly::Map& map);
    };

    class Moving : public Object {
        private:
            float vSpeed;
            float hSpeed;
        
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

            void setVSpeed(float vSpeed);
            void setHSpeed(float hSpeed);
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
        private:
            bool isFlying;

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