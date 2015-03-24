#include "testharness.h"
#include <algorithm>    // std::swap

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        int j = n;
        while (i < j) {
            if (A[i] == elem) {
                j--;
                std::swap(A[i], A[j]);
            } else {
                i++;
            }
        }
        return j;
    }
};

TEST(Solution, test) {
    int A[] = {1, 3, 4, 3, 3, 5, 7};

    ASSERT_EQ(4, removeElement(A, 7, 3));
    ASSERT_EQ(6, removeElement(A, 7, 1));
}
