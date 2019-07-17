/*
 * 35. Search Insert Position
 *
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array.
 *
 * Example 1:
 *    Input: [1,3,5,6], 5
 *    Output: 2
 *
 * Example 2:
 *    Input: [1,3,5,6], 2
 *    Output: 1
 *
 * Example 3:
 *    Input: [1,3,5,6], 7
 *    Output: 4
 *
 * Example 4:
 *    Input: [1,3,5,6], 0
 *    Output: 0
 */

#include "testharness.h"

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    return searchRange(nums, 0, nums.size()-1, target);
  }

 private:
  int searchRange(vector<int>& nums, int l, int h, int t) {
    if (l > h) return l;

    int m = (l + h) / 2;

    if (nums[m] < t)
      return searchRange(nums, m+1, h, t);
    else if (nums[m] > t)
      return searchRange(nums, l, m-1, t);
    else
      return m;
  }
};

TEST(Solution, test) {
  vector<int> input{1,3,5,6};
  ASSERT_EQ(searchInsert(input, 5), 2);
  ASSERT_EQ(searchInsert(input, 2), 1);
  ASSERT_EQ(searchInsert(input, 7), 4);
  ASSERT_EQ(searchInsert(input, 0), 0);
}
