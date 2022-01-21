//
// Created by romchirik on 20.01.2022.
//

#ifndef SHIPSFIGHT_PLAYER_H
#define SHIPSFIGHT_PLAYER_H


#include "../playfield/ships/Ship_type.h"
#include "../playfield/ships/Ship.h"
#include <vector>
#include <cstdint>
#include <memory>
#include "../game/settings.h"

class Player {
public:
    Player() = default;
    virtual ~Player() = default;
    virtual void init_playfield();
    virtual void do_turn() = 0;

protected:
    std::vector<Ship_type> ship_set = {SMOL, SMOL, SMOL, SMOL, BIG, BIG, BIG, HUGE, HUGE, INCREDIBLY_HUGE};
    std::vector<std::unique_ptr<Ship>> my_ships = std::vector<std::unique_ptr<Ship>>();
};


#endif //SHIPSFIGHT_PLAYER_H
