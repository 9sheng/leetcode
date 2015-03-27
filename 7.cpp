#include "testharness.h"
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x > -10 && x < 10) return x;

        bool sign = x > 0;
        if (!sign) x = -x;

        queue<int> s;
        while (x > 0) {
            s.push( x % 10);
            x /= 10;
        }

        const unsigned int OverflowSentry = 2147483648U / 10;
        int num = 0;
        while (!s.empty()) {
            if (num > OverflowSentry) return 0;
            num *= 10;
            num += s.front();
            s.pop();
        }

        return sign ? num : -num;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(-123, reverse(-321));
    ASSERT_EQ(0, reverse(1534236469));
}
