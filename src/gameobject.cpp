#include <iostream>
#include <gameobject.h>

int GameObject::_idCnt = 0;

GameObject::GameObject()
{
    _objectType = GameObjectType::noObject;
    _id = _idCnt++;
}

void GameObject::setPosition(int x, int y)
{
    _pos.x = x;
    _pos.y = y;
}

SDL_Point GameObject::getPosition()
{
    return _pos;
}

GameObjectType GameObject::getType()
{
    return _objectType;
}
