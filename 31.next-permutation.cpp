/**
 * 31. Next Permutation

 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place and use only constant extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 *
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

#include "testharness.h"
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int ti = -1;
    int tj = -1;
    int v = -1;
    // From right to left, i.e., for i = nums.size() .. 1,
    // find largest nums[j] such that j > i and nums[i] > nums[j].
    // If we find nums[j], we swap nums[i] and num[j], and sort nums[j:]
    for (int i = nums.size() - 1; i >= 0; i--) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] < nums[j] && (v == -1 || v > nums[j])) {
          ti = i;
          tj = j;
          v = nums[j];
        }
      }
      if (ti != -1) {
        int tmp = nums[ti];
        nums[ti] = nums[tj];
        nums[tj] = tmp;
        sort(&nums[ti+1], &nums[nums.size()]);
        return;
      }
    }

    sort(nums.begin(), nums.end());
  }
};

TEST(Solution, test) {
  vector<int> nums{1,2,3};
  nextPermutation(nums);
  ASSERT_EQ(nums[0], 1);
  ASSERT_EQ(nums[1], 3);
  ASSERT_EQ(nums[2], 2);
}

TEST(Solution, test2) {
  vector<int> nums{3,2,1};
  nextPermutation(nums);
  ASSERT_EQ(nums[0], 1);
  ASSERT_EQ(nums[1], 2);
  ASSERT_EQ(nums[2], 3);
}

TEST(Solution, test3) {
  vector<int> nums{1,1,5};
  nextPermutation(nums);
  ASSERT_EQ(nums[0], 1);
  ASSERT_EQ(nums[1], 5);
  ASSERT_EQ(nums[2], 1);
}

TEST(Solution, test4) {
  vector<int> nums{1,3,2};
  nextPermutation(nums);
  ASSERT_EQ(nums[0], 2);
  ASSERT_EQ(nums[1], 1);
  ASSERT_EQ(nums[2], 3);
}

TEST(Solution, test5) {
  vector<int> nums{4,2,0,2,3,2,0};
  nextPermutation(nums);
  ASSERT_EQ(nums[0], 4);
  ASSERT_EQ(nums[1], 2);
  ASSERT_EQ(nums[2], 0);
  ASSERT_EQ(nums[3], 3);
  ASSERT_EQ(nums[4], 0);
  ASSERT_EQ(nums[5], 2);
  ASSERT_EQ(nums[6], 2);
}
