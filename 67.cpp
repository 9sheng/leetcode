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
        string& result = a.size() > b.size() ? a : b;
        string& tmp = a.size() > b.size() ? b : a;

        int rs = result.size();
        int ts = tmp.size();

        bool hasCarryBit = false;

        while (ts >= 0) {
            if (result[rs] == '1') {
                if (tmp[ts] == '1') {
                    if (!hasCarryBit) {
                        result[rs] = '0';
                        hasCarryBit = true;
                    }
                } else {
                    if (hasCarryBit) {
                        result[rs] = '0';
                    }
                }
            } else {
                if (tmp[ts] == '1') {
                    result[rs] = hasCarryBit ? '0' : '1';
                } else {
                    if (hasCarryBit) {
                        result[rs] = '1';
                        hasCarryBit = false;
                    }
                }
            }

            rs--;
            ts--;
        }

        for (; rs >= 0; rs--) {
            if (result[rs] == '1') {
                if (hasCarryBit) {
                    result[rs] = '0';
                } else {
                    break;
                }
            } else {
                if (hasCarryBit) {
                    result[rs] = '1';
                    hasCarryBit = false;
                }
                break;
            }
        }

        return hasCarryBit ? "1" + result : result;
    }
};

TEST(Solution, test) {
    ASSERT_EQ("100", addBinary("11", "1"));
    ASSERT_EQ("100", addBinary("1", "11"));
    ASSERT_EQ("110", addBinary("11", "11"));
}
