#include "testharness.h"
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        unordered_map<int, int> occurNum;

        int halfSize = (num.size() - 1) / 2 + 1;
        for (size_t i = 0; i < num.size(); ++i) {
            if (++occurNum[num[i]] >= halfSize) {
                return num[i];
            }
        }

    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}


