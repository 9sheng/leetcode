#include "testharness.h"
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int mid = (m + n - 1) / 2;
        bool odd = (m + n) % 2 == 1;

        int midValue = findKth(A, m, B, n, mid);
        if (odd) return midValue;

        midValue += findKth(A, m, B, n, mid + 1);
        return (double(midValue)) / 2;
    }

protected:
    int findKth(int A[], int m, int B[], int n, int k) {
        if (m < n) return findKth(B, n, A, m, k);

        if (n <= 0) return A[k];

        if (n == 1) {
            int index = binarySearch(A, m, B[0]);
            if (index == -1 && k == 0) return B[0];
            if (index == m) return k < m ? A[k] : B[0];
            return k < index ? A[k] : (k == index ? B[0] : A[k-1]);
        }

        int mid = m / 2;
        int index = binarySearch(B, n, A[mid]);
        return mid + index > k ? findKth(A, mid, B, index, k) : findKth(A+mid, m-mid, B+index, n-index, k-mid-index);
    }

    // return smallest index, such that A[index] >= t
    int binarySearch(int A[], int n, int t) {
        if (t < A[0]) return 0;
        if (t > A[n-1]) return n;

        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (A[mid] == t) return mid;

            if (A[mid] < t)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};

TEST(Solution, test) {

    {
        int A[] = {1, 2, 3, 7};
        int B[] = {3, 4, 5, 9};
        ASSERT_EQ(5, findKth(A, 3, B, 3, 5));
        ASSERT_EQ(4, findKth(A, 4, B, 3, 4));
    }

    {
        int A[] = {1, 0};
        int B[] = {1, 2, 3, 4, 5};
        ASSERT_EQ(3.0, findMedianSortedArrays(A, 0, B, 5));
        B[1] = 0;
        ASSERT_EQ(1.0, findMedianSortedArrays(A, 1, B, 1));
    }

    {
        int A[] = {10000, 0, 0};
        int B[] = {10001, 0, 0};
        ASSERT_EQ(10000.5, findMedianSortedArrays(A, 1, B, 1));
    }

    {
        int A[] = {1, 2};
        int B[] = {1, 2};
        ASSERT_EQ(1.5, findMedianSortedArrays(A, 2, B, 2));
    }

    {
        int A[] = {2};
        int B[] = {1, 3};
        ASSERT_EQ(2, findMedianSortedArrays(A, 1, B, 2));
    }

}
