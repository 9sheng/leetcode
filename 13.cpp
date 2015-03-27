#include "testharness.h"
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        size_t size = s.size();
        if (size == 0) return 0;

        int num = 0;
        size_t i = 0;
        while (i < size) {
            switch (s[i]) {
            case 'M':
                num += 1000;
                break;
            case 'D':
                num += 500;
                break;
            case 'C':
                num += i < size - 1 && (s[i+1] == 'D' || s[i+1] == 'M') ? -100 : 100;
                break;
            case 'L':
                num += 50;
                break;
            case 'X':
                num += i < size - 1 && (s[i+1] == 'L' || s[i+1] == 'C') ? -10 : 10;
                break;
            case 'V':
                num += 5;
                break;
            case 'I':
                num += i < size - 1 && (s[i+1] == 'V' || s[i+1] == 'X') ? -1 : 1;
                break;
            }
            i++;
        }
        return num;
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, romanToInt("II"));
    ASSERT_EQ(9, romanToInt("IX"));
    ASSERT_EQ(3999, romanToInt("MMMCMXCIX"));
}
