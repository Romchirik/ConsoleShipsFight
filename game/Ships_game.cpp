#include "Ships_game.h"
#include <iostream>
#include "../players/Player_factory.h"

Ships_game::Ships_game(Game_config &config) {
    players.push_back(Player_factory::getInstance().create(config.player1_type));
    players.push_back(Player_factory::getInstance().create(config.player2_type));
}

Game_stats Ships_game::run() {
    Game_stats stats = Game_stats();
    init();

    while (tick()) {
        stats.steps++;
    }

    for (int i = 0; i < players.size(); i++) {
        if (players[i]->get_ships_left() == 0) {
            stats.winner = i;
            break;
        }
    }
    return stats;
}

bool Ships_game::tick() {
    painter->clear();

    players[0]->add_context_info(painter);
    painter->flush();
    Turn_result result = players[1]->get_turn_result(players[0]->do_turn());
    players[0]->push_turn_result(result);
    painter->clear();

    players[1]->add_context_info(painter);
    painter->flush();
    result = players[0]->get_turn_result(players[1]->do_turn());
    players[1]->push_turn_result(result);

    //check if we should continue game

    for (auto &i: players) {
        if (i->get_ships_left() == 0) {
            return false;
        }
    }
    return true;
}

void Ships_game::init() {
    for (auto &i: players) {
        i->init_playfield();
    }
}
