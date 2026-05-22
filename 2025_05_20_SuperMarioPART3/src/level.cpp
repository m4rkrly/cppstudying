#include <iostream>
#include <windows.h>

#include "map.hpp"
#include "level.hpp"
#include "objects.hpp"
#include "derived.hpp"

m4rkrly::Level::Level() 
{
    npcList = nullptr;
    interactList = nullptr;
    brickList = nullptr;
}

m4rkrly::Level::~Level() 
{
    delete [] npcList;
    delete [] interactList;
    delete [] brickList;
    npcList = nullptr;
    interactList = nullptr;
    brickList = nullptr;
    
    npcSize = 0;
    interactSize = 0;
    brickSize = 0;
    score = 0;
}

int m4rkrly::Level::playLevel()
{
    if (GetAsyncKeyState(VK_SPACE) < 0)
        mario.jump(-1);

    if (GetAsyncKeyState('A') < 0)
        horizMoveMap(-1);

    if (GetAsyncKeyState('D') < 0)
        horizMoveMap(1);

    verticMoveObj(mario);
    
    return 0;
}

void m4rkrly::Level::verticMoveObj(Moving& mov)
{
    mov.applyGravity(0.05);
    
    for (int i = 0; i < brickSize; i++)
    {
    // Возможно стоит убрать повторяющийся код
        if (mov.isCollidingWith(brickList[i]))
        {
            mov.discardGravity();
            break;
        }
    }

    for (int i = 0; i < interactSize; i++)
    {
        if (mov.isCollidingWith(interactList[i]))
        {
            mov.discardGravity();
            break;
        }
    }
    //

} 

void m4rkrly::Level::horizMoveMap(float dx)
{
    mario.changePos(dx, 0);

    bool collidingWithBrick = false;
    bool collidingWithInter = false;
    for (int i = 0; i < brickSize; i++) 
    {
        if (mario.isCollidingWith(brickList[i]))
        {
            collidingWithBrick = true;
            break;
        }
    }  

    for (int i = 0; i < interactSize; i++)
    {
        if (mario.isCollidingWith(interactList[i]))
        {
            collidingWithInter = true;
            //interactList[i].collisionMario(mario);
            break;
        }
    }
    
    if (collidingWithBrick or collidingWithInter)
    {
        mario.changePos(-dx, 0);
        return;
    }
    mario.changePos(-dx, 0);

    for (int i = 0; i < brickSize; i++)
        brickList[i].changePos(-dx, 0);
    for (int i = 0; i < interactSize; i++)
        interactList[i].changePos(-dx, 0);
    for (int i = 0; i < npcSize; i++)
        npcList[i].changePos(-dx, 0);
}


void m4rkrly::Level::createLevel(int level) {
    npcList = nullptr;
    interactList = nullptr;
    brickList = nullptr;
    
    npcSize = 0;
    interactSize = 0;
    brickSize = 0;
    score = 0;

    system("color 9F");
    this->mario = Player(39, 10);

    switch(level)
    {

        // TODO
        case 1:
            addNewBrick(Object(20, 20, 40, 5, '#'));
            addNewInteractive(Interactive(25, 15, 3, 3, '!'));
            addNewNPC(Goomba(25, 10, 0.2, 0));
            break;
        case 2:
            break;
        case 3:
            break;
    }
}

void m4rkrly::Level::putObjectsOnMap(Map& map)
{   
    mario.putOnMap(map);

    for (int i = 0; i < brickSize; i++) 
        brickList[i].putOnMap(map);   

    for (int i = 0; i < interactSize; i++) 
        interactList[i].putOnMap(map);

    for (int i = 0; i < npcSize; i++) 
        npcList[i].putOnMap(map);
}

void m4rkrly::Level::addNewNPC(
    NPC newNpc
)
{
    npcSize++;
    NPC* temp = new NPC[npcSize];

    if (npcList != nullptr) {
        for (int i = 0; i < npcSize - 1; i++) 
            temp[i] = npcList[i];
        delete [] npcList;
    }

    temp[npcSize - 1] = newNpc;
    npcList = temp;
    temp = nullptr;
}


void m4rkrly::Level::addNewInteractive(
    Interactive newInter
)
{
    interactSize++;
    Interactive* temp = new Interactive[interactSize];

    if (interactList != nullptr) {
        for (int i = 0; i < interactSize - 1; i++) 
            temp[i] = interactList[i];
        delete [] interactList;
    }
    
    temp[interactSize - 1] = newInter;
    interactList = temp;
    temp = nullptr;
}


void m4rkrly::Level::addNewBrick(
    Object newBrick
)
{
    brickSize++;
    Object* temp = new Object[brickSize];

    if (brickList != nullptr) 
    {
        for (int i = 0; i < brickSize - 1; i++) 
            temp[i] = brickList[i];
        delete [] brickList;
    }

    temp[brickSize - 1] = newBrick;
    brickList = temp;
    temp = nullptr;
}