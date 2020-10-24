#include <vector>
#include "borderwall.h"
#include <iostream>


BorderWall::BorderWall()
{
    _objectType = GameObjectType::wallObject;
}

void BorderWall::CreateWall()
{
    // top wall points
    for(int i = 0; i < _gSize; ++i){
        SDL_Point pnt {i * _bSize, 0};
        _topBorder.emplace_back(pnt);
    }
    // left wall points
    for(int i = 1; i < _gSize - 1; ++i){
         SDL_Point pnt {0, i * _bSize};
        _leftBorder.emplace_back(pnt);
    }
    // bottom wall points
    for(int i = 0; i < _gSize; ++i){
        SDL_Point pnt {i * _bSize, (_gSize - 1) * _bSize};
        _bottomBorder.emplace_back(pnt);
    } 
    // right wall points
    for(int i = 1; i < _gSize - 1; ++i){
        SDL_Point pnt {(_gSize - 1) * _bSize, i * _bSize};
        _rightBorder.emplace_back(pnt);
    }
}

void BorderWall::DestroyWall()
{
    _topBorder.clear();
    _leftBorder.clear();
    _rightBorder.clear();
    _bottomBorder.clear();
}