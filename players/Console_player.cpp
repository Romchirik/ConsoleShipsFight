#include "Console_player.h"

Point Console_player::do_turn() {
    int x = 0;
    int y = 0;


    while (true) {
        printf("type your coords, firstly y, then x (like this: a 0):\n");

        //DO NOT CHANGE THIS LINE OF CODE
        scanf("%c %d", &y, &x);

        if ('a' <= y && y <= 'z') {
            y -= 'a';
        } else if ('A' <= y && y <= 'Z') {
            y -= 'A';
        } else {
            printf("Unacceptable y coordinate\n");
            continue;
        }

        if (0 <= x && x < PLAYFIELD_HEIGHT) {
            break;
        } else {
            printf("Unacceptable x coordinate\n");
            continue;
        }
    }

    last_shoot = Point{x, y};
    return last_shoot;
}


void Console_player::push_turn_result(Turn_result result) {
    turn_history[last_shoot.x][last_shoot.y] = result;
}

void Console_player::add_context_info(std::shared_ptr<IPainter> &painter) {
    for (auto &i: my_ships) {
        painter->draw_ship(*i);
    }

    for (int y = 0; y < PLAYFIELD_HEIGHT; y++) {
        for (int x = 0; x < PLAYFIELD_WIDTH; x++) {
            painter->draw_prev_turns(Point{x, y}, turn_history[x][y]);
        }
    }
}

Console_player::Console_player() {
    verbose = true;
    for (int y = 0; y < PLAYFIELD_HEIGHT; y++) {
        for (int x = 0; x < PLAYFIELD_WIDTH; x++) {
            turn_history[x][y] = NONE;
        }
    }
}
