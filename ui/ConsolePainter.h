#ifndef SHIPSFIGHT_CONSOLEPAINTER_H
#define SHIPSFIGHT_CONSOLEPAINTER_H


#include "IPainter.h"
#include "../game/Turn_type.h"
#include "../game/settings.h"


enum Cell_type {
    WATER = ' ',
    SHIP = '#',
    BROKEN_SHIP = '%'
};

class ConsolePainter : public IPainter {
public:
    void draw_ship(Ship &ship) override;

    void draw_prev_turn(Turn_type type) override;

    void draw_string(std::string string) override;

    void flush() override;

    void clear() override;

private:
    std::string string_buffer = std::string();

    char my_playfield[PLAYFIELD_WIDTH][PLAYFIELD_HEIGHT] = {0};
    char enemy_playfield[PLAYFIELD_WIDTH][PLAYFIELD_HEIGHT] = {0};
};


#endif //SHIPSFIGHT_CONSOLEPAINTER_H
