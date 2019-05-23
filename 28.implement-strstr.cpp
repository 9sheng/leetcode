#include "testharness.h"
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        return needle == NULL || *needle == '\0' ? 0 : kmp(haystack, needle);
    }

protected:
    int kmp(char *haystack, char *needle) {
        std::vector<int> next;
        getNext(needle, next);
        int hi = 0;
        int ni = 0;
        while (haystack[hi] != '\0') {
            if (ni == -1 || haystack[hi] == needle[ni]) {
                ++hi;
                ++ni;
                if (needle[ni] == '\0') return hi - ni;
            } else {
                ni = next[ni];
            }
        }
        return -1;
    }

    // next[0] = -1. according defination, if next[j] = k, then P[0...k-1] == P[j-k,j-1]
    // 1) if P[j] == P[k] then P[0..k] == P[j-k,j], so we have next[j+1] = next[j]+1 = k+1;
    // 2) if P[j] != P[k], it is a problem of string match, how to set k when match failure, then k = next[k]。
    void getNext(const char* pattern, std::vector<int>& next) {
        int len = strlen(pattern);
        next.resize(len+1, 0);
        next[0] = -1;

        int k = -1;
        int j = 0;
        while (pattern[j] != '\0') {
            if (k == -1 || pattern[k] == pattern[j]) {
                ++j; ++k;
                next[j] = k;
            } else {
                k = next[k];
            }
        }
    }
};

TEST(Solution, test) {
    {
        std::vector<int> next;
        const char* pattern = "abcdabd";
        getNext(pattern, next);
        for (int i = 0; i < 7; i++)
            std::cout << pattern[i] << ": " << next[i+1] << std::endl;
    }
    std::cout << "=============" << std::endl;
    {
        std::vector<int> next;
        const char* pattern = "issipi";
        getNext(pattern, next);
        for (int i = 0; i < 6; i++)
            std::cout << pattern[i] << ": " << next[i+1] << std::endl;
    }

    ASSERT_EQ(1, strStr((char*)"abcdeabcdabdaa", (char*)"bcd"));
    ASSERT_EQ(5, strStr((char*)"abcdeabcdabdaa", (char*)"abcdabd"));
    ASSERT_EQ(-1, strStr((char*)"mississippi", (char*)"issipi"));
    ASSERT_EQ(0, strStr((char*)"a", (char*)"a"));
}

