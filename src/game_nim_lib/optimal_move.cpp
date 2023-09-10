#include <game_nim_lib/is_nim.h>
#include <game_nim_lib/optimal_move.h>
#include <stdlib.h>

int optimal_move(int a, int b, int c)
{
    for (int i = 1; i <= a; i++) {
        if (is_nim(a - i, b, c)) {
            return i;
        }
    }
    for (int i = 1; i <= b; i++) {
        if (is_nim(a, b - i, c)) {
            return i;
        }
    }
    for (int i = 1; i <= c; i++) {
        if (is_nim(a, b, c - i)) {
            return i;
        }
    }
    int min = a < b ? (a < c ? a : c) : (b < c ? b : c);
    return rand() % min + 1;
}