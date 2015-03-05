#include "testharness.h"
#include <string>
#include <string.h>
#include <vector>

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (n <= 0) return;

        int im = m - 1;
        int in = n - 1;
        int ia = m + n - 1;

        while (ia >= 0) {
            if (in < 0) return;
            if (im < 0) {
                while (in >= 0) {
                    A[ia--] = B[in--];
                }
                return;
            }
            A[ia--] = A[im] < B[in] ? B[in--] : A[im--];
        }
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
