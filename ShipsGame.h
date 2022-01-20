#ifndef SHIPSFIGHT_SHIPSGAME_H
#define SHIPSFIGHT_SHIPSGAME_H

#include "game_config.h"

class ShipsGame {
public:
    ShipsGame(GameConfig &config);
    void start();
    void getStats();

private:
    ShipsGame() = default;
    bool tick();
};


#endif //SHIPSFIGHT_SHIPSGAME_H



