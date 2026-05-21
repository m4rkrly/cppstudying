#include <windows.h>

#include "map.hpp"
#include "level.hpp"
#include "objects.hpp"

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

    switch(lvl)
    {
        case 1:
            addNewBrick(m4rkrly::Object(20, 20, 40, 5, '#'), brickList, brickSize);
            break;
        case 2:
            break;
        case 3:
            break;
    }
    
}

m4rkrly::NPC* m4rkrly::Level::addNewNPC(
    m4rkrly::NPC newNpc,  
    m4rkrly::NPC* npcList, int& npcSize
)
{
    npcSize++;
    m4rkrly::NPC* temp = new m4rkrly::NPC[npcSize];

    if (npcList != nullptr) {
        for (int i = 0; i < npcSize - 1; i++) 
            temp[i] = npcList[i];
        delete [] npcList;
    }

    temp[npcSize - 1] = newNpc;
    npcList = temp;
    temp = nullptr;
}


m4rkrly::Interactive* m4rkrly::Level::addNewInteractive(
    m4rkrly::Interactive newInter, 
    m4rkrly::Interactive* interactList, int& interactSize
)
{
    interactSize++;
    m4rkrly::Interactive* temp = new m4rkrly::Interactive[interactSize];

    if (interactList != nullptr) {
        for (int i = 0; i < interactSize - 1; i++) 
            temp[i] = interactList[i];
        delete [] interactList;
    }
    
    temp[interactSize - 1] = newInter;
    interactList = temp;
    temp = nullptr;
}


m4rkrly::Object* m4rkrly::Level::addNewBrick(
    m4rkrly::Object newBrick, 
    m4rkrly::Object* brickList, int& brickSize
)
{
    brickSize++;
    m4rkrly::Object* temp = new m4rkrly::Object[brickSize];

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