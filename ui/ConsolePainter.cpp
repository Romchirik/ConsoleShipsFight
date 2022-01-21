#include <cstring>
#include <iostream>
#include "ConsolePainter.h"

#include <cstdlib>

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

        for (int x = 0; x < PLAYFIELD_WIDTH; x++) {
            printf("%c ", my_playfield[x][y]);
        }
        printf("    ");
        for (int x = 0; x < PLAYFIELD_WIDTH; x++) {
            printf("%c ", enemy_playfield[x][y]);
        }

        printf("\n");
    }
    std::cout << string_buffer << std::endl;
}
