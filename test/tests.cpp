#include <ctest.h>
#include <libmatches/parser.hpp>
#include <math.h>
#include <stdio.h>
#include <string.h>

CTEST(suite1, test_clear_console)
{
    int expected = clear_cosole();
    int result = 1;

    ASSERT_EQUAL(expected, result);
    ASSERT_TRUE(result);
}
