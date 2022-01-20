//
// Created by romchirik on 20.01.2022.
//

#ifndef SHIPSFIGHT_PLAYER_H
#define SHIPSFIGHT_PLAYER_H


class Player {
public:
    Player() = default;
    virtual ~Player() = default;
    virtual void do_turn() = 0;
};


#endif //SHIPSFIGHT_PLAYER_H
