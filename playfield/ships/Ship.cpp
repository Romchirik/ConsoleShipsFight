#include "Ship.h"

bool Ship::if_collide(const Point &point) {
    for (auto i: body) {
        if (i == point) { return true; }
    }
    return false;
}

Ship::Ship(Direction direction) {
    dir = direction;
}
