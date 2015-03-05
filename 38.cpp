#include "testharness.h"
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result;
        for (int i = 0; i < n; i++) {
            result = getNextString(result);
        }

        return result;
    }

private:
    string getNextString(const string& str) {
        size_t strLen = str.length();

        if (strLen <= 0) return "1";

        char* buf = new char[2*strLen];
        char* ptr = buf;

        size_t i = 0;
        while (i < strLen) {
            size_t base = i;
            char c = str[base];
            i = strLen; // we want to break while loop
            for (size_t j = base + 1; j <= strLen; j++) {
                if (str[j] != c) {
                    ptr += sprintf(ptr ,"%d%c", j - base, c);
                    i = j; // continue loop
                    break;
                }
            }
        }

        return string(buf);
    }
};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
