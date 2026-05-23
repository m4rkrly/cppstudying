#include <iostream>
#include <windows.h>

#include "init.hpp"
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

template <typename T>
void m4rkrly::Level::deleteList(T**& l, int& lSize)
{
    if (l == nullptr) return;

    for (int i = 0; i < lSize; i++)
    {
        delete l[i];
    }
    lSize = 0;
    delete [] l;
    l = nullptr;
}

template <typename T>
void m4rkrly::Level::deleteFromList(int i, T**& l, int& lSize)
{
    if (lSize == 1)
    {
        delete [] l; 
        l = nullptr;
        lSize = 0;
        return;
    }
    
    delete l[i];
    l[i] = l[lSize - 1];

    lSize--;
    T** temp = new T*[lSize];
    for (int j = 0; j < lSize; j++)
    {
        temp[j] = l[j];
    }

    delete [] l;
    l = temp;
    temp = nullptr;
}

m4rkrly::Level::~Level() 
{
    deleteList(npcList, npcSize);
    deleteList(interactList, interactSize);
    deleteList(brickList, brickSize);
}

Status m4rkrly::Level::playLevel()
{
    try 
    {
        if (GetAsyncKeyState(VK_ESCAPE) < 0) 
            throw EXIT;

        if (GetAsyncKeyState(VK_SPACE) < 0)
            mario.jump(-1);

        if (GetAsyncKeyState('A') < 0)
            horizMoveMario(-1);

        if (GetAsyncKeyState('D') < 0)
            horizMoveMario(1);

        verticMoveMario();

        if (mario.isFallen())
        {
            playerDead();
            return LOSE;
        }
        
        for (int i = 0; i < npcSize; i++)
        {
            moveNPC(npcList[i]);
            if (npcList[i]->isFallen() == true) 
            {
                deleteFromList(i, npcList, npcSize);
                i--;
                continue;
            }
        }

        marioCollisionNPC();
        return NOTHING;
    }
    catch(Status st)
    {
        return st;
    }
}


void m4rkrly::Level::marioCollisionNPC()
{
    for (int i = 0; i < npcSize; i++)
    {
        if (mario.isCollidingWith(*npcList[i]))
        {
            Status interactionStatus = npcList[i]->collisionMario(mario);
            
            switch(interactionStatus)
            {
                case LOSE:
                    playerDead();
                    throw LOSE;

                case KILL:
                    addToScore(npcList[i]);
                    deleteFromList(i, npcList, npcSize);
                    i--;
                    continue;

                case NOTHING:
                    continue;
                
                case WIN:
                    deleteFromList(i, npcList, npcSize);
                    playerWin();
                    throw WIN;
            }
        }
    }
}

void m4rkrly::Level::marioCollisionInter(int& i)
{   
    Status interactionStatus = interactList[i]->collisionMario(mario);

    switch(interactionStatus)
    {
        case LOSE:
            playerDead();
            throw LOSE;

        case SPAWN_COIN:
            addNewNPC(new Coin(*interactList[i]));

        case NOTHING:
            return;
        
        case WIN:
            deleteFromList(i, npcList, npcSize);
            playerWin();
            throw WIN;
    }
}


void m4rkrly::Level::putScoreOnMap(Map& map)
{
    char c[30];
	sprintf(c, "Score: %d", score);
	int len = strlen(c);
	for (int i = 0; i < len; i++) 
        map.putSymbol(i+5, 1, c[i]);
}

void m4rkrly::Level::addToScore(NPC* npc)
{
    score += npc->getPrice();
}

void m4rkrly::Level::playerDead()
{
    system("color 4F");
	Sleep(400);
}

void m4rkrly::Level::playerWin()
{
    system("color 2F");
	Sleep(400);
}

void m4rkrly::Level::moveNPC(NPC* npc)
{
    bool collisionHoriz = horizonMoveNPC(*npc);
    if (collisionHoriz == true
        && npc->toMoveHoriz(collisionHoriz) == false) 
    {
        npc->changeDirection();
    }

    if (collisionHoriz == false
        && npc->toMoveHoriz(collisionHoriz) == true)
    {
        NPC temp = *npc;
        bool collisionVertic = verticMoveNPC(temp);
        if (collisionVertic == false
            && npc->toMoveVertic(collisionVertic) == false)
        {
            npc->discardMove();
            npc->changeDirection();
        }
    }
    // ОСТОРОЖНО ЗДЕСЬ!
    // Если мобы стали неправильно себя вести
    // перенеси эту функцию в if выше
    verticMoveNPC(*npc);
}

bool m4rkrly::Level::horizonMoveNPC(NPC& npc)
{
    npc.move();
    bool brickCollision = false;
    bool interactCollision = false;

    for (int i = 0; i < brickSize; i++) 
    {
        if (npc.isCollidingWith(*brickList[i])) 
        {
            brickCollision = true;
            break;
        }
    }

    for (int i = 0; i < interactSize; i++)
    {
        if (npc.isCollidingWith(*interactList[i])) 
        {
            interactCollision = true;
            break;
        }
    }

    if (brickCollision || interactCollision)
    {
        npc.discardMove();
        return true;
    }
    return false;
}

bool m4rkrly::Level::verticMoveNPC(NPC& npc)
{
    npc.applyGravity();
    
    bool brickCollision = false;
    bool interactCollision = false;
    for (int i = 0; i < brickSize; i++)
    {
        if (npc.isCollidingWith(*brickList[i]))
        {
            brickCollision = true;
            break;
        }
    }

    for (int i = 0; i < interactSize; i++)
    {
        if (npc.isCollidingWith(*interactList[i]))
        {
            interactCollision = true;
            break;
        }
    }
    
    if (brickCollision || interactCollision)
    {
        npc.discardGravity();
        return true;
    }
    return false;
    //

} 


void m4rkrly::Level::verticMoveMario()
{
    mario.applyGravity();
    
    bool brickCollision = false;
    bool interactCollision = false;
    for (int i = 0; i < brickSize; i++)
    {
        if (mario.isCollidingWith(*brickList[i]))
        {
            mario.discardGravity();
            break;
        }
    }

    for (int i = 0; i < interactSize; i++)
    {
        if (mario.isCollidingWith(*interactList[i]))
        {
            marioCollisionInter(i);
            mario.discardGravity();
            break;
        }
    }
} 

void m4rkrly::Level::horizMoveMario(float dx)
{
    mario.changePos(dx, 0);

    for (int i = 0; i < brickSize; i++) 
    {
        if (mario.isCollidingWith(*brickList[i]))
        {
            mario.changePos(-dx, 0);
            return;
        }
    }  

    for (int i = 0; i < interactSize; i++)
    {
        if (mario.isCollidingWith(*interactList[i]))
        {
            mario.changePos(-dx, 0);
            marioCollisionInter(i);
            return;
        }
    }
    
    mario.changePos(-dx, 0);

    for (int i = 0; i < brickSize; i++)
        brickList[i]->changePos(-dx, 0);
    for (int i = 0; i < interactSize; i++)
        interactList[i]->changePos(-dx, 0);
    for (int i = 0; i < npcSize; i++)
        npcList[i]->changePos(-dx, 0);
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
            addNewBrick(new Object(20, 20, 40, 5, '#'));
            addNewInteractive(new LuckyBlock(25, 10));
            addNewNPC(new Goomba(30, 10, 0.2, 0));
            addNewInteractive(new WinTube(65, 20, 10, 10));
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
        brickList[i]->putOnMap(map);   

    for (int i = 0; i < interactSize; i++) 
        interactList[i]->putOnMap(map);

    for (int i = 0; i < npcSize; i++) 
        npcList[i]->putOnMap(map);
}

void m4rkrly::Level::addNewNPC(
    NPC* newNpc
)
{
    if (newNpc == nullptr) return;
    npcSize++;
    NPC** temp = new NPC*[npcSize];

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
    Interactive* newInter
)
{
    if (newInter == nullptr) return;
    interactSize++;
    Interactive** temp = new Interactive*[interactSize];

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
    Object* newBrick 
)
{
    if (newBrick == nullptr) return;
    brickSize++;
    Object** temp = new Object*[brickSize];

    if (brickList != nullptr) {
        for (int i = 0; i < brickSize - 1; i++) 
            temp[i] = brickList[i];
        delete [] brickList;
    }

    temp[brickSize - 1] = newBrick;
    brickList = temp;
    temp = nullptr;
}