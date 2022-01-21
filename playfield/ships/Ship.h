
#ifndef SHIPSFIGHT_SHIP_H
#define SHIPSFIGHT_SHIP_H


#include <vector>
#include "../point.h"
#include "../direction.h"

class Ship {
public:
    explicit Ship(Direction direction);
    virtual ~Ship() = default;
    virtual bool if_collide(const Point &point);

protected:
    Point head = Point{0, 0};
    Direction dir = UP;
    std::vector<Point> body = std::vector<Point>();
};

#endif //SHIPSFIGHT_SHIP_H
