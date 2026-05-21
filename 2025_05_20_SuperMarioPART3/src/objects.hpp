#pragma once

#include "level.hpp"
#include "map.hpp"

namespace m4rkrly {
    class Object
    {
        private:
            float x, y;
            float width, height;
            char type;

        public:
            Object() = delete;
            Object(float x, float y, float width, float height, char type);
            
            float getX() const;
            float getY() const;
            float getWidth() const;
            float getHeight() const;

            void setPos(float x, float y);

            void draw(m4rkrly::Map map);
    };

    class Moving : public Object {
        private:
            float vSpeed;
            float hSpeed;
        
        public:
            float getVSpeed() const;
            float getHSpeed() const;

            void setVSpeed(float vSpeed);
            void setHSpeed(float hSpeed);
    };

    class Interactive : public Object
    {
        public:
            Interactive() = delete;
            Interactive(float x, float y, float width, float height, char type);

            virtual void collisionMario() = 0;
    };

    // Зачем нужен этот класс?
    // В Level имеем три динамических массива.
    // Если сделать один из них под базовый класс object
    // то рискуем иметь возможность закидывать туда 
    // вообще любые производные классы, что плохо.
    // Так блоки всегда будут только блоками.
    class NonInteractive : public Object {
        public:
            NonInteractive() = delete;
            NonInteractive(float x, float y, float width, float height, char type);
    };



    class Player : public Moving 
    {
        private:
            bool isFlying;

        public:
            Player() = delete;
            Player(float x, float y, float width, float height, char type, float vSpeed);

            Player(const Player&) = delete;
            Player& operator = (const Player&) = delete;
            Player(Player&&) = delete;
            Player& operator = (Player&&) = delete;
    };


    class NPC : public Moving
    {
        private:
            int price;

        public:
            NPC() = delete;
            NPC(float x, float y, float width, float height, char type, float hSpeed, float vSpeed);

            int getPrice() const;

            virtual int collisionMario(Player mario) = 0;

    };

    class Goomba : public NPC 
    {
        public:
            Goomba(float x, float y, float hSpeed, float vSpeed);
            int collisionMario(Player mario) override;      
    };

    class Coin : public NPC 
    {
        public:
            Coin(float x, float y, float hSpeed, float vSpeed);
            int collisionMario(Player mario) override;
    };
}