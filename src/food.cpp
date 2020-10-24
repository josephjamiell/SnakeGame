#include <iostream>
#include "food.h"

Food::Food()
{
    _objectType = GameObjectType::foodObject;
}
bool Food::getIsSuper()
{
    return _isSuper;
}