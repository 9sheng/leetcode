#include "testharness.h"
#include <map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size < 2) return s;

        int maxLength = 0;
        int b = 0;

        for (int n = 0; n < size; n++) {
            for (int m = 0; m < 2; m++) {
                int i = n;
                int j = n + m;
                while (i >= 0 && j < size) {
                    if (s[i] == s[j]) {
                        i--;
                        j++;
                    } else {
                        break;
                    }
                }
                int tmpLength = j - i - 1;
                if (maxLength < tmpLength) {
                    b = i + 1;
                    maxLength = tmpLength;
                }
            }
        }

        return s.substr(b, maxLength);
    }
};

TEST(Solution, test) {
    ASSERT_EQ("", longestPalindrome(""));
    ASSERT_EQ("aba", longestPalindrome("abaa"));
    ASSERT_EQ("ababababababa", longestPalindrome("ababababababab"));
}
