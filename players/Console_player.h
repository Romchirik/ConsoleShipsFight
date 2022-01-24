//
// Created by romchirik on 20.01.2022.
//

#ifndef SHIPSFIGHT_CONSOLE_PLAYER_H
#define SHIPSFIGHT_CONSOLE_PLAYER_H


#include "Player.h"

class Console_player : public Player {
public:
    Console_player();

    ~Console_player() override = default;

    Point do_turn() override;

    void push_turn_result(Turn_result result) override;

    void add_context_info(std::shared_ptr<IPainter> &painter) override;

private:
    Turn_result turn_history[PLAYFIELD_WIDTH][PLAYFIELD_HEIGHT];
};


#endif //SHIPSFIGHT_CONSOLE_PLAYER_H
