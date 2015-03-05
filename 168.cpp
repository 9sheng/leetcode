#include "testharness.h"
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string result;

        while (n > 0) {
            char c = (n - 1) % 26 + 'A';
            result = string(1, c) + result;
            n = (n - 1) / 26;
        }

        return result;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(string("A"), convertToTitle(1));
    ASSERT_EQ(string("Z"), convertToTitle(26));
    ASSERT_EQ(string("AB"), convertToTitle(28));
    ASSERT_EQ(string("AAA"), convertToTitle(703));
}

