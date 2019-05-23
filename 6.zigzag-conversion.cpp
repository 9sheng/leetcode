#include "testharness.h"
#include <map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;


// 1,            9,              17
// 2,        8,  10,         16, 18
// 3,     7,     11,     15,     19
// 4,  6,        12, 14,         20
// 5,            13,             21

class Solution {
public:
    string convert(string s, int nRows) {
        int step = 2 * (nRows - 1);
        if (step == 0) return s;

        string result = s;
        int current = 0;

        for (int row = 0; row < nRows; row++) {
            int first = row;
            int second = (nRows - 1) * 2 - row;

            while (first < s.size()) {
                result[current++] = s[first];

                if (row != 0 && row != nRows - 1 && second < s.size())
                    result[current++] = s[second];

                first += step;
                second += step;
            }
        }

        return result;
    }
};

TEST(Solution, test) {
    ASSERT_EQ("PAHNAPLSIIGYIR", convert("PAYPALISHIRING", 3));
    ASSERT_EQ("ACB", convert("ABC", 2));
    ASSERT_EQ("ACBD", convert("ABCD", 2));
    ASSERT_EQ("A", convert("A", 1));
}
