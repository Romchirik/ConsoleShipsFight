#include "point.h"

bool operator==(const Point &point1, const Point &point2) {
    return (point1.x == point2.x) && (point1.y == point2.y);
}

bool operator!=(const Point &point1, const Point &point2) {
    return !(point1 == point2);
}

Point Point::operator+(const Point &other) const {
    return Point{this->x + other.x, this->y + other.y};
}

Point Point::operator-(const Point &other) const {
    return Point{this->x - other.x, this->y - other.y};
}
