#pragma once

#include "map.hpp"

namespace m4rkrly 
{
    class Object
    {
        protected:
            float x, y;
            float width, height;
            char texture;

        public:
            Object() = delete;
            Object(
                float x, float y, 
                float width, float height, 
                char texture
            );

            virtual ~Object() = default;

            float getX() const;
            float getY() const;
            float getWidth() const;
            float getHeight() const;

            void setPos(float x, float y);
            void changePos(float dx, float dy);
            bool isCollidingWith(Object& other);
            bool isFallen();
            void putOnMap(m4rkrly::Map& map);
    };


    class Moving : public Object {
        protected:
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
            virtual ~Moving() = default;

            float getVSpeed() const;
            bool getIsFlying() const;
            void applyGravity();
            void discardGravity();
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
        
        void jump(float vSpeed);
    };



    class Interactive : public Object
    {
        public:
            Interactive() = delete;
            Interactive(
                float x, float y, 
                float width, float height, 
                char texture
            );
            virtual ~Interactive() = default;

            virtual int collisionMario(Player mario) = 0;
    };


    
    class NPC : public Moving
    {
        private:
            int price;

        public:
            NPC() = delete;
            NPC(
                float x, float y, 
                float width, float height, 
                char texture, 
                float hSpeed, float vSpeed,
                int price
            );
            virtual ~NPC() = default;

            virtual Status collisionMario(Player& mario);
            virtual bool toMoveHoriz(bool isCollidingHoriz);
            virtual bool toMoveVertic(bool isCollidingVertic);
            
            int getPrice() const;
            void move();
            void discardMove();
            void changeDirection();
    };

    
}
