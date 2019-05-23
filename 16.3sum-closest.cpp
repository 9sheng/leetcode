#include "testharness.h"
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        int closest = 0;
        int minMinus = INT_MAX;

        for (int i = 0; i < size - 2; i++) {
            for (int j = i + 1; j < size - 1; j++) {
                int t = target - nums[i] - nums[j];
                int k = binarySearch(nums, j + 1, size - 1, t);

                int tmpMinus = abs(t - nums[k]);
                if (minMinus > tmpMinus) {
                    minMinus = tmpMinus;
                    closest = nums[i] + nums[j] + nums[k];
                }

                if (k != size - 1) {
                    int tmpMinus = abs(t - nums[k+1]);
                    if (minMinus > tmpMinus) {
                        minMinus = tmpMinus;
                        closest = nums[i] + nums[j] + nums[k+1];
                    }
                }

                if (nums[j] > 0 && nums[i] + nums[j] > target) return closest;
            }
        }
        return closest;
    }

private:
    int binarySearch(vector<int>& nums, int l, int h, int t) {
        if (nums[l] > t) return l;
        if (nums[h] < t) return h;

        while (l < h) {
            int m = (l + h) / 2;
            if (nums[m] == t) return m;
            if (nums[m] > t) h = m - 1;
            else l = m + 1;
        }
        return l;
    }
};


TEST(Solution, test) {
    vector<int> nums = {13,2,0,-14,-20,19,8,-5,-13,-3,20,15,20,5,13,14,-17,-7,12,-6,0,20,-19,-1,-15,-2,8,-2,-9,13,0,-3,-18,-9,-9,-19,17,-14,-19,-4,-16,2,0,9,5,-7,-4,20,18,9,0,12,-1,10,-17,-11,16,-13,-14,-3,0,2,-18,2,8,20,-15,3,-13,-12,-2,-19,11,11,-10,1,1,-10,-2,12,0,17,-19,-7,8,-19,-17,5,-5,-10,8,0,-12,4,19,2,0,12,14,-9,15,7,0,-16,-5,16,-12,0,2,-16,14,18,12,13,5,0,5,6};
    ASSERT_EQ(-58, threeSumClosest(nums, -59));
}
