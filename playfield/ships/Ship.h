
#ifndef SHIPSFIGHT_SHIP_H
#define SHIPSFIGHT_SHIP_H


#include <vector>
#include "../point.h"

class Ship {
    virtual bool on_collide(const Point& point) {
        for(auto i: body){

        }
    }

private:
    std::vector<Point> body = std::vector<Point>(body);
};
#endif //SHIPSFIGHT_SHIP_H
