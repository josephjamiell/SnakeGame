#ifndef FOOD_H
#define FOOD_H

#include "gameobject.h"

class Food : public GameObject
{
    public:
    // constructor / destructor
    Food();
    // getter / setter
    bool getIsSuper();

    private:
    bool _isSuper{false};
};

#endif