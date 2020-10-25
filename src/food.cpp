#include <iostream>
#include "food.h"

Food::Food()
{
    _objectType = GameObjectType::foodObject;
}
bool Food::GetIsSuper()
{
    return _isSuper;
}