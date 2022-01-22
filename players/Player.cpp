#include "Player.h"
#include "../playfield/ships/Ships_factory.h"

void Player::init_playfield() {
    for (auto i: available_ships) {
        bool ship_accepted = false;
        std::unique_ptr<Ship> tmp_ship = Ships_factory::getInstance().create(i, random_direction());

        while (!ship_accepted) {
            tmp_ship->set_x(rand());
            tmp_ship->set_y(rand());
            tmp_ship->finalize();

            ship_accepted = validate_ship(*tmp_ship);
            if (ship_accepted) {
                my_ships.push_back(std::move(tmp_ship));
            }
        }

        my_ships.push_back(std::move(tmp_ship));
    }
}

bool Player::validate_ship(Ship &ship) const {

    //checking that ship doesn't collide with other already placed ships
    for (auto &i: my_ships) {
        for (auto placed: i->get_body()) {
            for (auto j: ship.get_body()) {
                if (placed == j ||
                    placed == j + Point{0, 1} ||
                    placed == j + Point{0, -1} ||
                    placed == j + Point{-1, 0} ||
                    placed == j + Point{1, 0}) {
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
