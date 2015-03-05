#include "testharness.h"
#include <map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    struct IntStr;

    string largestNumber(vector<int> &num) {

        map<IntStr, int> numSet;

        for (size_t i = 0; i < num.size(); ++i) {
            numSet[IntStr(num[i])]++;
        }

        string result;
        for (auto iter = numSet.rbegin(); iter != numSet.rend(); ++iter) {
            for (int i = 0; i < (*iter).second; ++i) {
                result += (*iter).first.value;
            }
        }

        if (result[0] == '0')
            return "0";
        else
            return result;
    }

    struct IntStr {
        IntStr(int n) {
            num = n;
            sprintf(value, "%d", n);
        }

        bool operator<(const IntStr& rhs) const {
            int i = 0;
            int j = 0;
            while (value[i] != '\0' || rhs.value[j] != '\0') {
                if (value[i] == '\0') i = 0;
                if (rhs.value[j] == '\0') j = 0;

                if (value[i] != rhs.value[j]) {
                    return value[i] < rhs.value[j];
                } else {
                    i++; j++;
                }
            }
            return num < rhs.num;
        }
        int num;
        char value[16];
    };

};

TEST(Solution, test) {
    ASSERT_EQ(2, 1+1);
}
