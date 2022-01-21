#include <vector>
#include "Game_controller.h"

void Game_controller::run() {
    auto results = std::vector<Game_stats>();
    for (int i = 0; i < config.rounds; i++) {
        Ships_game game = Ships_game(config);
        Game_stats _stats = game.run();
        results.push_back(_stats);
    }
}

Game_controller::Game_controller(Game_config &conf) : config(conf), game_core(Ships_game(conf)) {

}
