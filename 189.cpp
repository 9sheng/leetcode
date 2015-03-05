#include "testharness.h"
#include <string.h>

using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k %= n;
        if (k == 0) return;
        if (k < 0) k += n;

        int* tmp = new int[k];

        memcpy(tmp, nums + n - k, k * sizeof(int));
        memmove(nums + k, nums, (n - k) * sizeof(int));
        memcpy(nums, tmp, k * sizeof(int));

        delete[] tmp;
    }

};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}


