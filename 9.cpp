#include "testharness.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;

        std::vector<int> flag;
        flag.reserve(12);

        while (x > 0) {
            flag.push_back(x % 10);
            x /= 10;
        }

        size_t i = 0;
        size_t j = flag.size() - 1;
        while (i < j) {
            if (flag[i] != flag[j]) return false;
            i++; j--;
        }

        return true;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(true, isPalindrome(11));
    ASSERT_EQ(true, isPalindrome(121));
    ASSERT_EQ(false, isPalindrome(100));
}
