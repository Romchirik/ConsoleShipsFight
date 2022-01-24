#ifndef SHIPSFIGHT_PLAYER_H
#define SHIPSFIGHT_PLAYER_H


#include "../playfield/ships/Ship_type.h"
#include "../playfield/ships/Ship.h"
#include <vector>
#include <cstdint>
#include <memory>
#include "../game/settings.h"
#include "../ui/IPainter.h"

class Player {
public:
    Player() = default;

    Player(Player &&other) = default;

    size_t get_ships_left();


    virtual ~Player() = default;

    virtual void init_playfield();

    virtual Point do_turn() = 0;

    //called if we shoot to point (method arg)
    Turn_result get_turn_result(Point point);

    //saving result uf needed
    virtual void push_turn_result(Turn_result result) = 0;

    std::vector<std::unique_ptr<Ship>> &get_ships();

    //if player need to paint something on screen
    virtual void add_context_info(std::shared_ptr<IPainter> &painter);

    bool if_verbose();
protected:
    std::vector<Ship_type> available_ships = {INCREDIBLY_HUGE};
    std::vector<std::unique_ptr<Ship>> my_ships = std::vector<std::unique_ptr<Ship>>();

    bool validate_ship(Ship &ship) const;
    bool verbose = false;
    Point last_shoot = Point{0, 0};
};


#endif //SHIPSFIGHT_PLAYER_H
