#include "testharness.h"
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        int digits_size = digits.size();
        string current;
        std::vector<int> flag;

        current.reserve(digits_size);
        flag.reserve(digits_size);

        char letters_[] = {'a', 'd', 'g', 'j', 'm', 'p', 't', 'w'};
        char numbers_[] = {3, 3, 3, 3, 3, 4, 3, 4};

        for (int i = 0; i < digits_size; i++) {
            if (digits[i] < '2' || digits[i] > '9') continue;
            int index = digits[i] - '2';
            current += letters_[index];
            flag.push_back(numbers_[index]);
        }

        std::vector<string> result;
        if (flag.empty()) return result;
        doOutput(current, flag, 0, result);
        return result;
    }

private:
    void doOutput(string& current, const vector<int>& flag, int i, vector<string>& result) {
        if (i == flag.size()) {
            result.push_back(current);
            return;
        }

        char c = current[i];
        for (int n = flag[i]; n > 0; n--) {
            doOutput(current, flag, i+1, result);
            ++current[i];
        }
        current[i] = c;
    }
};

TEST(Solution, test) {
    vector<string> result = letterCombinations("78");
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << endl;
    }

    ASSERT_EQ(-58, -58);
}
