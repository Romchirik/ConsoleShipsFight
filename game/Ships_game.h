#ifndef SHIPSFIGHT_SHIPS_GAME_H
#define SHIPSFIGHT_SHIPS_GAME_H

#include <vector>
#include <memory>
#include "game_config.h"
#include "Game_stats.h"
#include "../players/Player.h"

class Ships_game {
public:
    explicit Ships_game(Game_config &config);
    Game_stats run();
private:
    void init();
    bool tick();

    std::vector<std::unique_ptr<Player>> players = std::vector<std::unique_ptr<Player>>();
};

#endif //SHIPSFIGHT_SHIPS_GAME_H



