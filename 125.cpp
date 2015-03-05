#include "testharness.h"
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        size_t high = s.length();
        size_t low = 0;

        while (low < high) {
            if (!isalnum(s[low])) {
                low++;
                continue;
            }

            if (!isalnum(s[high])) {
                high--;
                continue;
            }

            if (toupper(s[low]) != toupper(s[high])) {
                return false;
            } else if (high - low < 3) {
                return true;
            } else {
                low++;
                high--;
            }
        }

        return true;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
