#include "testharness.h"
#include <cstring>
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        switch(divisor) {
        case 0:
            return INT_MAX;
        case 1:
            return dividend;
        case -1:
            return dividend == INT_MIN ? INT_MAX : -dividend;
        default:
            {
                int flag = 0;
                if (dividend < 0) {
                    flag ^= 1;
                    dividend = -dividend;
                }
                if (divisor < 0) {
                    flag ^= 1;
                    divisor = -divisor;
                }
                int ret = do_divide(dividend, divisor);
                return flag == 0 ? ret : -ret;
            }
        }
    }

    int do_divide(unsigned int a, unsigned int b) {
        if (a < b) return 0;

        int divisor = b;
        int ret = 1;
        while (true) {
            int t = (b << 1);
            if (a > t) {
                ret <<= 1;
                b = t;
            } else {
                break;
            }
        }

        return ret + do_divide(a - b, divisor);
    }
};


TEST(Solution, test) {
    ASSERT_EQ(5 / 2, divide(5, 2));
    ASSERT_EQ(2147483647 / 2, divide(2147483647, 2));
    ASSERT_EQ(-2147483648 / 2, divide((int)2147483648, 2));
}

