#include <ctest.h>
#include <ctype.h>
#include <libmatches/parser.hpp>
#include <math.h>
#include <stdio.h>
#include <string.h>

CTEST(suite1, player_numbers)
{
    int number = 4;
    int expected = PlayerNumber(number);
    int result = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(suite2, player_numbers)
{
    int number = 4;
    int expected = PlayerNumber(number);
    int result = 0;
    ASSERT_NOT_EQUAL(expected, result);
}
CTEST(suite3, hard_computer)
{
    int comp = 1;
    int cash = 100;
    int MOD = 11;
    int expected = Hard_II(comp, cash, MOD);
    int result = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(suite4, easy_computer)
{
    int comp = 1;
    int cash = 100;
    int expected = Easy_II(comp, cash);
    int result = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(suite5, hard_computer)
{
    int comp = 1;
    int cash = 10;
    int MOD = 11;
    int expected = Hard_II(comp, cash, MOD);
    int result = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(suite6, easy_computer)
{
    int comp = 1;
    int cash = 10;
    int expected = Easy_II(comp, cash);
    int result = 0;
    ASSERT_EQUAL(expected, result);
}
