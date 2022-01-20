#ifndef SHIPSFIGHT_POINT_H
#define SHIPSFIGHT_POINT_H

#include <cstddef>

struct Point {
    size_t x;
    size_t y;
};

bool operator==(const Point& point1, const Point& point2){
    return (point1.x == point2.x) && (point1.y == point2.y);
}

bool operator!=(const Point& point1, const Point& point2){
    return !(point1 == point2);
}

#endif //SHIPSFIGHT_POINT_H
