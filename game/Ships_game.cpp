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

    return stats;
}

bool Ships_game::tick() {
    for(auto i: players) {
        i.get()->init_playfield();
    }


    return false;
}

void Ships_game::init() {

}
