
#ifndef SHIPSFIGHT_SHIP_H
#define SHIPSFIGHT_SHIP_H


#include <vector>
#include "../point.h"
#include "../direction.h"

class Ship {
public:
    explicit Ship(Direction direction);
    virtual ~Ship() = default;
    bool if_collide(const Point &point);

    virtual void finalize() = 0;

    std::vector<Point> &get_body();
    void set_x(size_t x);
    void set_y(size_t y);
    void set_head(Point p);

protected:
    Point head = Point{0, 0};
    Direction dir = UP;
    std::vector<Point> body = std::vector<Point>();
};

#endif //SHIPSFIGHT_SHIP_H
