#include "testharness.h"
#include <algorithm>    // std::swap

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1) return n;

        int i = 0;
        int j = 1;

        while (j < n) {
            if (A[i] == A[j]) {
                j++;
            } else {
                i++;
                A[i] = A[j];
            }
        }

        return i + 1;
    }
};


TEST(Solution, test) {
    int A[] = {1, 3, 3, 3, 5, 7};

    ASSERT_EQ(4, removeDuplicates(A, 6));
    ASSERT_EQ(2, removeDuplicates(A, 2));
}
