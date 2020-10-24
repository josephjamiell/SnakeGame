#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <map>
#include <mutex>
#include <thread>
#include "SDL.h"

enum GameObjectType
{
    noObject,
    foodObject,
    obstacleObject,
    wallObject,
    snakeObject
};

class GameObject
{
    public:
    // constructor / destructor
    GameObject();
    //getter / setter
    int getID() { return _id; }
    void setPosition(int x, int y);
    SDL_Point getPosition();
    GameObjectType getType();

    protected:
    GameObjectType _objectType;
    SDL_Point _pos;
    int _id;

    private:
    static int _idCnt;
};

#endif