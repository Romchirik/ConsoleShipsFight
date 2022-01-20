//
// Created by romchirik on 20.01.2022.
//

#ifndef SHIPSFIGHT_OPTIMAL_PLAYER_H
#define SHIPSFIGHT_OPTIMAL_PLAYER_H


#include "Player.h"

class Optimal_player: public Player{
public:
    Optimal_player() =default;
    ~Optimal_player() override =default;
    void do_turn() override;
};


#endif //SHIPSFIGHT_OPTIMAL_PLAYER_H
