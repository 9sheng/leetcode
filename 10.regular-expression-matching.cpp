#include "testharness.h"
#include <stack>
#include <set>
#include <iostream>

using namespace std;

bool isMatch(char *s, char *p) {
    if (*s == '\0') {
        while (*p != '\0') {
            if (*(p+1) != '*') return false;
            p += 2;
        }
        return true;
    }

    if (*(p+1) == '*') {
        while (*s != '\0' && (*p == *s || *p == '.')) {
            if (isMatch(s++, p + 2)) return true;
        }
        return isMatch(s, p + 2);
    }

    return (*p == *s || *p == '.') ? isMatch(s+1, p+1) : false;
}

class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        return ::isMatch((char*)s.c_str(), (char*)p.c_str());
    }
};

TEST(Solution, test) {
    ASSERT_EQ(true, isMatch("aa", ".*aa"));
    ASSERT_EQ(true, isMatch("aa","aa"));
    ASSERT_EQ(false, isMatch("aaa","aa"));
    ASSERT_EQ(false, isMatch("aa","aaaa"));
    ASSERT_EQ(true, isMatch("aa", "a*"));
    ASSERT_EQ(true, isMatch("aa", ".*"));
    ASSERT_EQ(true, isMatch("ab", ".*"));
    ASSERT_EQ(true, isMatch("aab", "c*a*b"));
    ASSERT_EQ(true, isMatch("aaab", "a*a*c*aaab"));
    ASSERT_EQ(true, isMatch("aaab", "a*a*c*.aab"));
    ASSERT_EQ(false, isMatch("acaabbaccbbacaabbbb", "a*.*b*.*a*aa*a*"));
}
