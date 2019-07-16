/*
 * 34. Find First and Last Position of Element in Sorted Array
 *
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * Example 1:
 *
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 *
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 */


#include "testharness.h"

#include <iostream>

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int min = -1;
    int max = -1;
    searchRange(nums, 0, nums.size()-1, target, &min, &max);
    return vector<int>{min, max};
  }

 private:
  void searchRange(vector<int>& nums, int l, int h, int t, int* min, int* max) {
    if (l > h)
      return;

    int m = (l+h)/2;
    // std::cout << l << "\t" << h << "\t" << m << "\n";

    if (nums[m] > t) {
      searchRange(nums, l, m-1, t, min, max);
      return;
    }

    if (nums[m] < t) {
      searchRange(nums, m+1, h, t, min, max);
      return;
    }

    if (l != h) {
      searchRange(nums, l, m-1, t, min, max);
      searchRange(nums, m+1, h, t, min, max);
    }

    if (*max == -1 || *max < m)
      *max = m;
    if (*min == -1 || *min > m)
      *min = m;
  }
};

TEST(Solution, test) {
  vector<int> input{5,7,7,8,8,10};
  int target = 8;
  vector<int> output = searchRange(input, target);

  ASSERT_EQ(output[0], 3);
  ASSERT_EQ(output[1], 4);
}

TEST(Solution, test2) {
  vector<int> input{5,7,7,8,8,10};
  int target = 6;
  vector<int> output = searchRange(input, target);

  ASSERT_EQ(output[0], -1);
  ASSERT_EQ(output[1], -1);
}
