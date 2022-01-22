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

    Player(Player &&other) = default;

    virtual ~Player() = default;

    virtual void init_playfield();

    virtual void do_turn() = 0;

protected:
    std::vector<Ship_type> available_ships = {INCREDIBLY_HUGE, HUGE, HUGE, BIG, BIG, BIG, SMOL, SMOL, SMOL, SMOL};
    std::vector<std::unique_ptr<Ship>> my_ships = std::vector<std::unique_ptr<Ship>>();

    bool validate_ship(Ship &ship) const;

};


#endif //SHIPSFIGHT_PLAYER_H
