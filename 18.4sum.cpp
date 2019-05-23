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
    struct FourInt {
        FourInt(int a, int b, int c, int d) {
            this->a = a;
            this->b = b;
            this->c = c;
            this->d = d;
        }

        int a;
        int b;
        int c;
        int d;

        bool operator<(const FourInt& rhs) const {
            if (a != rhs.a) return a < rhs.a;
            if (b != rhs.b) return b < rhs.b;
            if (c != rhs.c) return c < rhs.c;
            return d < rhs.d;
        }
    };

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        if (size < 4) return vector<vector<int>>();

        set<FourInt> result;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < size - 3; i++) {
            if (nums[i] > 0 && nums[i] > target) break;

            for (int j = i + 1; j < size - 2; j++) {
                int s_ij = nums[i] + nums[j];
                if (nums[j] > 0 &&  s_ij > target) break;

                for (int m = j + 1; m < size - 1; m++) {
                    int s_ijm = s_ij + nums[m];
                    if (nums[m] > 0 && s_ijm > target) break;

                    int n = binarySearch(nums, m + 1, size - 1, target - s_ijm);
                    for (; n < size; n++) {
                        int s_ijmn = s_ijm + nums[n];
                        if (s_ijmn == target) {
                            FourInt tmp(nums[i], nums[j], nums[m], nums[n]);
                            if (result.find(tmp) == result.end()) {
                                result.insert(tmp);
                            }
                        } else if (s_ijmn > target) {
                            break;
                        }
                    }
                }
            }
        }

        vector<vector<int>> vecResult;
        for (auto iter = result.begin(); iter != result.end(); ++iter)
            vecResult.push_back({iter->a, iter->b, iter->c, iter->d});
        return vecResult;
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
    vector<int> nums = {-3,-2,-1,0,0,1,2,3};
    auto result = fourSum(nums, 0);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << "  ";
        }
        std::cout << endl;
    }
}
