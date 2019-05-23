#include "testharness.h"
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int max = 0;

        int size = height.size();
        for (int j = size - 1; j >= 0; j--) {
            int i = 0;
            for (;i < j; i++) {
                if (height[i] >= height[j]) {
                    int tmp = (j - i) * height[j];
                    if (max < tmp) max = tmp;
                    break;
                } else {
                    int tmp = (j - i) * height[i];
                    if (max < tmp) max = tmp;
                }
            }

            if (j == i) {
                return max;
            }
        }

        return max;
    }
};

TEST(Solution, test) {
}

