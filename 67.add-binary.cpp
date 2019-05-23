#include "testharness.h"
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string& first = a.size() > b.size() ? a : b;
        string& second = a.size() > b.size() ? b : a;

        int rs = first.size();
        int ts = second.size();

        bool hasCarryOn = false;

        while (ts >= 0) {
            if (first[rs] == '1') {
                if (second[ts] == '1') {
                    if (!hasCarryOn) {
                        first[rs] = '0';
                        hasCarryOn = true;
                    }
                } else {
                    if (hasCarryOn) {
                        first[rs] = '0';
                    }
                }
            } else {
                if (second[ts] == '1') {
                    first[rs] = hasCarryOn ? '0' : '1';
                } else {
                    if (hasCarryOn) {
                        first[rs] = '1';
                        hasCarryOn = false;
                    }
                }
            }

            rs--;
            ts--;
        }

        for (; rs >= 0; rs--) {
            if (first[rs] == '1') {
                if (hasCarryOn) {
                    first[rs] = '0';
                } else {
                    break;
                }
            } else {
                if (hasCarryOn) {
                    first[rs] = '1';
                    hasCarryOn = false;
                }
                break;
            }
        }

        return hasCarryOn ? "1" + first : first;
    }
};

TEST(Solution, test) {
    ASSERT_EQ("100", addBinary("11", "1"));
    ASSERT_EQ("100", addBinary("1", "11"));
    ASSERT_EQ("110", addBinary("11", "11"));
}
