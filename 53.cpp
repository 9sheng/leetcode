#include "testharness.h"
#include <string>
#include <string.h>
#include <vector>

class Solution {
public:
    int maxSubArray(int A[], int n) {

        int tmpSum = A[0];
        int maxSum = tmpSum;

        for (int i = 1; i < n; i++) {
            if (tmpSum < 0)
                tmpSum = A[i];
            else
                tmpSum += A[i];

            if (maxSum < tmpSum)
                maxSum = tmpSum;
        }

        return maxSum;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
 