#include <cstring>
#include <iostream>
#include "ConsolePainter.h"


void clear_cli() {
#ifdef WINDOWS
    std::system("cls");
#else
    std::system("clear");
#endif
}

void ConsolePainter::clear() {
    string_buffer.clear();

    memset(my_playfield, ' ', PLAYFIELD_HEIGHT * PLAYFIELD_WIDTH);
    memset(enemy_playfield, ' ', PLAYFIELD_HEIGHT * PLAYFIELD_WIDTH);

    clear_cli();
}

void ConsolePainter::flush() {
    printf("  0 1 2 3 4 5 6 7 8 9     0 1 2 3 4 5 6 7 8 9\n");
    char heading_symbol = 'a';
    for (size_t y = 0; y < PLAYFIELD_HEIGHT; y++) {
        printf("%c ", heading_symbol);
        heading_symbol++;

        for (auto &x: my_playfield) {
            printf("%c ", x[y]);
        }

        printf("    ");
        for (auto &x: enemy_playfield) {
            printf("%c ", x[y]);
        }

        printf("\n");
    }
    std::cout << string_buffer << std::endl;
}