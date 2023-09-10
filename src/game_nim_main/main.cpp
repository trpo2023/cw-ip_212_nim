#include <cstring>
#include <ctime>
#include <fstream>
#include <game_nim_lib/is_nim.h>
#include <game_nim_lib/optimal_move.h>
#include <game_nim_lib/print_piles.h>
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unistd.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int a = rand() % 10 + 1;
    int b = rand() % 10 + 1;
    int c = rand() % 10 + 1;

    printf("Добро пожаловать в игру \"ним\"!\n");
    printf("В этой игре есть три кучки камней. Вы можете взять любое "
           "количество камней из одной кучки за один ход. Выигрывает тот, кто "
           "возьмет последний камень.\n");

    int turn = rand() % 2;

    while (a > 0 || b > 0 || c > 0) {
        print_piles(a, b, c);

        if (turn == 0) {
            printf("Ход компьютера.\n");
            int move = optimal_move(a, b, c);

            int pile = rand() % 3;

            while ((pile == 0 && move > a) || (pile == 1 && move > b)
                   || (pile == 2 && move > c)) {
                pile = rand() % 3;
            }
            if (pile == 0) {
                a -= move;
                printf("Компьютер взял %d камней из кучки A.\n", move);
            } else if (pile == 1) {
                b -= move;
                printf("Компьютер взял %d камней из кучки B.\n", move);
            } else {
                c -= move;
                printf("Компьютер взял %d камней из кучки C.\n", move);
            }
        } else {
            printf("Ваш ход.\n");
            char pile;
            int move;
            printf("Введите букву кучки (A, B или C) и количество камней, "
                   "которые вы хотите взять.\n");
            scanf(" %c %d", &pile, &move);

            while ((pile != 'A' && pile != 'B' && pile != 'C') || (move < 1)
                   || (pile == 'A' && move > a) || (pile == 'B' && move > b)
                   || (pile == 'C' && move > c)) {
                printf("Неверный ввод. Попробуйте еще раз.\n");
                scanf(" %c %d", &pile, &move);
            }

            if (pile == 'A') {
                a -= move;
                printf("Вы взяли %d камней из кучки A.\n", move);
            } else if (pile == 'B') {
                b -= move;
                printf("Вы взяли %d камней из кучки B.\n", move);
            } else {
                c -= move;
                printf("Вы взяли %d камней из кучки C.\n", move);
            }
        }
        turn = 1 - turn;
    }
    if (turn == 0) {
        printf("Поздравляем! Вы выиграли!\n");
    } else {
        printf("К сожалению, вы проиграли. Попробуйте еще раз!\n");
    }
    return 0;
}
