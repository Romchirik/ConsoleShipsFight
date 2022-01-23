#include "Random_player.h"

Point Random_player::do_turn() {
    int x = rand() % PLAYFIELD_WIDTH;
    int y = rand() % PLAYFIELD_HEIGHT;

    return Point{x, y};
}

void Random_player::push_turn_result(Turn_result result) {
    //random player do nothing
}

void Random_player::add_context_info(std::shared_ptr<IPainter> &painter) {

}
