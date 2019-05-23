#include "testharness.h"
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> result;
        result.reserve(digits.size());

        bool hasCarryOn = true;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (hasCarryOn) {
                if (digits[i] == 9) {
                    result.push_back(0);
                } else {
                    result.push_back(digits[i] + 1);
                    hasCarryOn = false;
                }
            } else {
                result.push_back(digits[i]);
            }
        }

        vector<int> ret;
        ret.reserve(digits.size());
        if (hasCarryOn) ret.push_back(1);
        copy(result.rbegin(), result.rend(), back_inserter(ret));
        return ret;
    }
};

TEST(Solution, test) {
    vector<int> rhs = {1, 0};
    vector<int> result = plusOne(rhs);
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << "  ";
    cout << endl;
}
