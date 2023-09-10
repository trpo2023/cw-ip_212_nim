#include <game_nim_lib/is_nim.h>

int is_nim(int a, int b, int c)
{
    return (a ^ b ^ c) == 0;
}