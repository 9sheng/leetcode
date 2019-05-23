#include "testharness.h"
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            num *= 26;
            num += s[i] - 'A' + 1;
        }
        return num;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(1, titleToNumber("A"));
    ASSERT_EQ(26, titleToNumber("Z"));
    ASSERT_EQ(27, titleToNumber("AA"));
    ASSERT_EQ(28, titleToNumber("AB"));
    ASSERT_EQ(703, titleToNumber("AAA"));
}

