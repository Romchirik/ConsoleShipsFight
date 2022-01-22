#include <algorithm>
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

void Ship::set_x(size_t x) {
    head.x = x;
}

void Ship::set_y(size_t y) {
    head.y = y;
}

void Ship::set_head(Point p) {
    head = p;
}

std::vector<Point> &Ship::get_body() {
    return body;
}
