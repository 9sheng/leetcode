#include "testharness.h"
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result;

        if (num >= 1000) {
            result += string(num / 1000, 'M');
            num = num % 1000;
        }

        if (num >= 900) {
            result += "CM";
            num -= 900;
        } else if (num >= 500) {
            result += "D";
            num -= 500;
        } else if (num >= 400) {
            result += "CD";
            num -= 400;
        }
        ///////
        if (num >= 100) {
            result += string(num / 100, 'C');
            num = num % 100;
        }

        if (num >= 90) {
            result += "XC";
            num -= 90;
        } else if (num >= 50) {
            result += "L";
            num -= 50;
        } else if (num >= 40) {
            result += "XL";
            num -= 40;
        }
        ///////
        if (num >= 10) {
            result += string(num / 10, 'X');
            num = num % 10;
        }

        if (num >= 9) {
            result += "IX";
            num -= 9;
        } else if (num >= 5) {
            result += "V";
            num -= 5;
        } else if (num >= 4) {
            result += "IV";
            num -= 4;
        }

        if (num >= 1) {
            result += string(num, 'I');
        }

        return result;
    }
};

TEST(Solution, test) {
    ASSERT_EQ("II", intToRoman(2));
    ASSERT_EQ("IX", intToRoman(9));
    ASSERT_EQ("MMMCMXCIX", intToRoman(3999));
    ASSERT_EQ("M", intToRoman(1000));
}
