#include <ctest.h>
#include <game_nim_lib/is_nim.h>
#include <game_nim_lib/optimal_move.h>
#include <game_nim_lib/print_piles.h>
#include <stdlib.h>
#include <string>

CTEST(NimTest, IsNimTrue_test1)
{
    ASSERT_TRUE(is_nim(1, 2, 3));
}

CTEST(NimTest, IsNimTrue_test2)
{
    ASSERT_TRUE(is_nim(1, 3, 2));
}

CTEST(NimTest, IsNimTrue_test3)
{
    ASSERT_TRUE(is_nim(0, 0, 0));
}

CTEST(NimTest, IsNimFalse_test1)
{
    ASSERT_FALSE(is_nim(1, 1, 1));
}

CTEST(NimTest, IsNimFalse_test2)
{
    ASSERT_FALSE(is_nim(4, 4, 6));
}

CTEST(optimal_move, optimal_move_a)
{
    ASSERT_EQUAL(optimal_move(1, 2, 3), 1);
}

CTEST(optimal_move, optimal_move_b)
{
    ASSERT_EQUAL(optimal_move(3, 1, 2), 1);
}

CTEST(optimal_move, optimal_move_c)
{
    ASSERT_EQUAL(optimal_move(2, 3, 1), 1);
}

CTEST(optimal_move, no_optimal_move_all)
{
    ASSERT_EQUAL(optimal_move(2, 2, 2), 2);
}

CTEST(optimal_move, no_optimal_move_zero)
{
    ASSERT_EQUAL(optimal_move(0, 2, 3), 1);
}

CTEST(optimal_move, no_optimal_move_one)
{
    ASSERT_EQUAL(optimal_move(2, 1, 3), 1);
}

CTEST(optimal_move, optimal_random_test)
{
    srand(time(NULL));
    int a = rand() % 10 + 2;
    int b = rand() % 10 + 2;
    int c = rand() % 10 + 2;
    bool flag = false;
    if (optimal_move(a, b, c) >= 1) {
        flag = true;
    }
    ASSERT_TRUE(flag);
}
