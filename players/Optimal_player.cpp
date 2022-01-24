#include "Optimal_player.h"

Point Optimal_player::do_turn() {
    int x, y;
    while (true) {
        x = rand() % PLAYFIELD_WIDTH;
        y = rand() % PLAYFIELD_HEIGHT;

        if (turn_history[x][y] != NONE) {
            continue;
        } else {
            break;
        }
    }

    last_shoot = Point{x, y};
    return last_shoot;
}

void Optimal_player::push_turn_result(Turn_result result) {
    turn_history[last_shoot.x][last_shoot.y] = result;
}

void Optimal_player::add_context_info(std::shared_ptr<IPainter> &painter) {

}

Optimal_player::Optimal_player() {
    for (int y = 0; y < PLAYFIELD_HEIGHT; y++) {
        for (int x = 0; x < PLAYFIELD_WIDTH; x++) {
            turn_history[x][y] = NONE;
        }
    }
}

