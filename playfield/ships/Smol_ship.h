//
// Created by romchirik on 21.01.2022.
//

#ifndef SHIPSFIGHT_SMOL_SHIP_H
#define SHIPSFIGHT_SMOL_SHIP_H


#include "Ship.h"
#include "../direction.h"

class Smol_ship : public Ship{
public:
    explicit Smol_ship(Direction dir);
};


#endif //SHIPSFIGHT_SMOL_SHIP_H
