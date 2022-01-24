#include "Player.h"
#include "../playfield/ships/Ships_factory.h"

void Player::init_playfield() {
    for (auto i: available_ships) {
        std::unique_ptr<Ship> tmp_ship = Ships_factory::getInstance().create(i, random_direction());

        while (true) {
            tmp_ship->set_x(rand() % PLAYFIELD_WIDTH);
            tmp_ship->set_y(rand() % PLAYFIELD_HEIGHT);
            tmp_ship->finalize();

            if (validate_ship(*tmp_ship)) {
                my_ships.push_back(std::move(tmp_ship));
                break;
            }
        }
    }
}

bool Player::validate_ship(Ship &ship) const {

    //checking that ship doesn't collide with other already placed ships
    for (auto &i: my_ships) {
        for (auto placed: i->get_body()) {
            for (auto j: ship.get_body()) {
                if ((placed == j) ||
                    (placed == j + Point{0, 1}) ||
                    (placed == j + Point{0, -1}) ||
                    (placed == j + Point{-1, 0}) ||
                    (placed == j + Point{1, 0})) {
                    return false;
                }
            }
        }
    }
    //check that ship bounds
    Point head = ship.get_body().front();
    Point back = ship.get_body().back();

    if ((0 <= head.x && head.x < PLAYFIELD_WIDTH) &&
        (0 <= back.x && back.x < PLAYFIELD_WIDTH) &&
        (0 <= head.y && head.y < PLAYFIELD_HEIGHT) &&
        (0 <= back.y && back.y < PLAYFIELD_HEIGHT)) {
        return true;
    }
    return false;
}

size_t Player::get_ships_left() {
    return my_ships.size();
}

Turn_result Player::get_turn_result(Point point) {
    Turn_result result = MISS;
    bool killed[10] = {false};

    for (size_t i = 0; i < my_ships.size(); i++) {
        if (my_ships[i]->on_collide(point)) { result = HIT; }
        if (my_ships[i]->is_dead()) {
            killed[i] = true;
            result = KILL;
        }
    }
    if (result == MISS) { return result; }
    for (size_t i = 0; i < 10; i++) {
        if (killed[i]) {
            my_ships.erase(my_ships.begin() + i);
        }
    }

    return result;
}

std::vector<std::unique_ptr<Ship>> &Player::get_ships() {
    return my_ships;
}

void Player::add_context_info(std::shared_ptr<IPainter> &painter) {

}

bool Player::if_verbose() {
    return verbose;
}
