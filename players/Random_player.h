//
// Created by romchirik on 20.01.2022.
//

#ifndef SHIPSFIGHT_RANDOM_PLAYER_H
#define SHIPSFIGHT_RANDOM_PLAYER_H


#include "Player.h"

class Random_player : public Player {
public:
    void do_turn() override;
    Random_player() = default;
    ~Random_player() override = default;
};


#endif //SHIPSFIGHT_RANDOM_PLAYER_H
