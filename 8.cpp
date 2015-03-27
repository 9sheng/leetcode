#include "testharness.h"
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int myAtoi(const char* str)
{
    if (str == NULL) return 0;

    while (isspace(*str))
        str++;

    bool overflow = false;
    bool sign = true;
    unsigned int num = 0;

    if (*str == '-') {
        sign = false;
        str++;
    } else if (*str == '+') {
        str++;
    }

    const unsigned int OverflowSentry = 2147483648U / 10;
    while (isdigit(*str)) {
        if (num > OverflowSentry) {
            overflow = true;
            break;
        }
        num *= 10;
        num += *str - '0';
        str++;
    }

    if (!overflow && num > (2147483648U - (sign ? 1 : 0))) {
        overflow = true;
    }

    if (overflow) {
        return sign ? 2147483647 : -2147483648;
    } else {
        int tmp = num;
        return sign ? tmp : -tmp;
    }
}

class Solution {
};

struct TestCase {
    const char* str;
    int num;
};

TEST(Solution, test) {
    TestCase cases[] = {
        {"-2147483649", -2147483648},
        {"-2147483648", -2147483648},
        {"-2147483647", -2147483647},
        {"    10522545459", 2147483647},
        {"2147483647", 2147483647},
        {"2147483648", 2147483647},
        {"0", 0},
        {"01", 1},
        {"   1", 1},
        {"1   ", 1},
        {"b1", 0},
        {"+1", 1},
        {"+.1", 0},
        {"-1", -1},
        {"-0", 0},
        {"-b3", 0},
        {"-99999999999999999999", -2147483648},
        {"234b", 234},
        {"\t\n-100b", -100}};

    for (int i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        std::cout << i << ": " << cases[i].str << std::endl;
        ASSERT_EQ(cases[i].num, myAtoi(cases[i].str));
    }
}
