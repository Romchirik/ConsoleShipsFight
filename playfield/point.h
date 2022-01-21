#ifndef SHIPSFIGHT_POINT_H
#define SHIPSFIGHT_POINT_H

#include <cstddef>

struct Point {
    size_t x = 0;
    size_t y = 0;
};

bool operator==(const Point& point1, const Point& point2);
bool operator!=(const Point& point1, const Point& point2);

#endif //SHIPSFIGHT_POINT_H
