#include "testharness.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];

        int strsSize = strs.size();

        size_t maxCommonLen = strs[0].size();
        for (int j = 0; j < strsSize; j++) {
            if (maxCommonLen > strs[j].size())
                maxCommonLen = strs[j].size();
        }

        string result;
        for (int i = 0; i < maxCommonLen; i++) {
            bool flag = true;
            for (int j = 0; j < strsSize - 1; ++j) {
                if (strs[j][i] != strs[j+1][i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result += strs[0][i];
            } else {
                return result;
            }

        }

        return result;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
