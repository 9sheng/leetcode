#include "testharness.h"
#include <map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t size = s.size();
        if (size < 2) return size;

        int pos[128];
        for (int i = 0; i < sizeof(pos)/sizeof(*pos); i++)
            pos[i] = -1;

        int maxLength = 0;
        int basePos = -1;
        for (size_t i = 0; i < size; i++) {
            int index = s[i];
            int oldPos = pos[index];
            int tmpLen = 0;


            if (oldPos < basePos) {
                tmpLen = i - basePos;
            } else {
                tmpLen = i - oldPos;
                basePos = oldPos;
            }

            pos[index] = i;

            if (maxLength < tmpLen) {
                maxLength = tmpLen;
                if (maxLength == 128) return 128;
            }
        }
	    
	    return basePos == -1 ? size : maxLength;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(1, lengthOfLongestSubstring("a"));
    ASSERT_EQ(1, lengthOfLongestSubstring("aa"));
    ASSERT_EQ(2, lengthOfLongestSubstring("abba"));
    ASSERT_EQ(4, lengthOfLongestSubstring("abcdabd"));
    ASSERT_EQ(7, lengthOfLongestSubstring("abcdefg"));
    ASSERT_EQ(12, lengthOfLongestSubstring("abcdefgefghijklmopq"));
}
