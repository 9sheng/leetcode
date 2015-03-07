#include "testharness.h"
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int lastWordLength = 0;
        const char *lastWordStartPos = s;

        while (*s != '\0') {
            if (*s == ' ') {
                if (lastWordStartPos != NULL) {
                    lastWordLength = s - lastWordStartPos;
                    lastWordStartPos = NULL;
                }
            } else {
                if (lastWordStartPos == NULL) {
                    lastWordStartPos = s;
                }
            }
            ++s;
        }

        return lastWordStartPos == NULL ? lastWordLength : s - lastWordStartPos;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(6, lengthOfLastWord("hello worldd"));
    ASSERT_EQ(1, lengthOfLastWord("a "));
    ASSERT_EQ(1, lengthOfLastWord("a"));
}
