#include "testharness.h"
#include <string>
#include <string.h>
#include <vector>

class Solution {
public:
    double pow(double x, int n) {
        if (n == -1) return 1 / x;
        if (n == 0) return 1;
        if (n == 1) return x;

        double ret = pow(x, n/2);
        ret *= ret;
        return n % 2 == 0 ? ret : n < 0 ? ret / x : ret * x;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
