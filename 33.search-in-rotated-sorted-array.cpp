/**
 * 33. Search in Rotated Sorted Array
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 *
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 *     You may assume no duplicate exists in the array.
 *
 *     Your algorithm's runtime complexity must be in the order of O(log n).
 *
 *     Example 1:
 *     Input: nums = [4,5,6,7,0,1,2], target = 0
 *     Output: 4
 *
 *     Example 2:
 *     Input: nums = [4,5,6,7,0,1,2], target = 3
 *     Output: -1
 */

#include "testharness.h"

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    return binarySearch(nums, 0, nums.size() - 1, target);
  }

  int binarySearch(const vector<int>& N, int l, int h, int t) {
    // std::cout << l << "\t" << h << "\n";
    if (h - l < 5) {
      for (int i = l; i <= h; i++) {
        if (N[i] == t)
          return i;
      }
      return -1;
    }

    int m = (h+l)/2;

    if (N[m] == t)
      return m;

    if (N[l] < N[h]) {
      if (t < N[l] || t > N[h])
        return -1;
      else if (t < N[m])
        return binarySearch(N, l, m-1, t);
      else
        return binarySearch(N, m+1, h, t);
    }

    // here we have N[l] > N[h]
    if (t > N[h] && t < N[l])
      return -1;

    if (N[l] < N[m]) {
      if (t >= N[l] && t < N[m])
        return binarySearch(N, l, m-1, t);
      else
        return binarySearch(N, m+1, h, t);
    }

    if (t <= N[h] && t > N[m])
      return binarySearch(N, m+1, h, t);
    else
      return binarySearch(N, l, m-1, t);
  }
};

TEST(Solution, test0) {
  vector<int> nums = {6,7,1,2,3,4,5};
  ASSERT_EQ(0, search(nums, 6));
}
TEST(Solution, test) {
  vector<int> nums = {4,5,6,7,0,1,2};
  ASSERT_EQ(6, search(nums, 2));
  ASSERT_EQ(4, search(nums, 0));
  ASSERT_EQ(-1, search(nums, 3));
}

TEST(Solution, test2) {
  vector<int> nums = {0,1,2,4,5,6,7};
  ASSERT_EQ(3, search(nums, 4));
  ASSERT_EQ(-1, search(nums, 3));
}

TEST(Solution, test3) {
  vector<int> nums = {3,1};
  ASSERT_EQ(1, search(nums, 1));
}
