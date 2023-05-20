#include <ctest.h>
#include <libmatches/parser.hpp>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include<ctype.h>

CTEST(suite1, enter_numbers)
{
    int number;
    int expected =  InputUserNumber(number,"Введите число 4");
    int result = 4;

    ASSERT_EQUAL(expected, result);
    
}
CTEST(suite2, enter_numbers)
{
    int number;
    int expected =  InputUserNumber(number,"Введите число 4");
    int result = 4;

    ASSERT_NOT_EQUAL(expected, result);
    
}
CTEST(suite3, player_numbers)
{
    int number = 4;
    int expected = PlayerNumber(number);
    int result= 1;
    ASSERT_EQUAL(expected,result);
}

CTEST(suite4, player_numbers)
{
    int number = 4;
    int expected = PlayerNumber(number);
    int result= 0;
    ASSERT_NOT_EQUAL(expected,result);
}
