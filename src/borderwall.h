#ifndef BORDERWALL_H
#define BORDERWALL_H

#include <vector>

#include "SDL.h"
#include "gameobject.h"

class BorderWall : public GameObject
{
    public:
    // constructor / destructor
    BorderWall();
    // getters / setters
    std::vector<SDL_Point> getTopBorder() { return _topBorder; }
    std::vector<SDL_Point> getLeftBorder() { return _leftBorder; }
    std::vector<SDL_Point> getBottomBorder() { return _bottomBorder; }
    std::vector<SDL_Point> getRightBorder() { return _rightBorder; }
    void DestroyWall();
    void CreateWall();
    
    private:
    bool _hasWall{false};
    int _gSize{32};
    int _bSize{20};
    std::vector<SDL_Point> _topBorder;
    std::vector<SDL_Point> _leftBorder;
    std::vector<SDL_Point> _bottomBorder;
    std::vector<SDL_Point> _rightBorder;
};

#endif